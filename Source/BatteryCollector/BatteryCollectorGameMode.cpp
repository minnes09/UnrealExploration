// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollector.h"
#include "BatteryCollectorGameMode.h"
#include "BatteryCollectorCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "SpawnVolume.h"

ABatteryCollectorGameMode::ABatteryCollectorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	//base decay rate
	DecayRate = 0.01f;
}

float ABatteryCollectorGameMode::GetPowerToWin() const
{
	return PowerToWin;
}

EBatteryPlayState ABatteryCollectorGameMode::GetCurrentState() const { return CurrentState; }

void ABatteryCollectorGameMode::SetCurrentState(EBatteryPlayState NewState) {

	CurrentState = NewState;
	HandleCurrentState(CurrentState);
}

void ABatteryCollectorGameMode::HandleCurrentState(EBatteryPlayState NewState) {
	switch (NewState) {
		//if the game is playing
		case EBatteryPlayState::EPlaying:
		{
			//spawn volumes to be active
			for (ASpawnVolume* Volume : SpawnVolumeActors) 
			{
				Volume->SetSpawningActive(true);
			}
		}
		break;
		//if we have won the came
		case EBatteryPlayState::EWon:
		{
			//spawn volumes to be inactive
			for (ASpawnVolume* Volume : SpawnVolumeActors)
			{
				Volume->SetSpawningActive(false);
			}
		}
		break;
		//if we have lost the game
		case EBatteryPlayState::EGameOver:
		{
			//spawn volumes to be inactive
			for (ASpawnVolume* Volume : SpawnVolumeActors)
			{
				Volume->SetSpawningActive(false);
			}
			//block player input
			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
			if (PlayerController) {
				PlayerController->SetCinematicMode(true, false, false, true, true);
			}
			//ragdoll the character
			ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
			if (MyCharacter) {
				MyCharacter->GetMesh()->SetSimulatePhysics(true);
				MyCharacter->GetMovementComponent()->MovementState.bCanJump = false;
			}
		}
		break;
		//Unknown state
		default:
		case EBatteryPlayState::EUnknown:
		{
			//do nothing
		}
		break;
	}
}


void ABatteryCollectorGameMode::BeginPlay() {

	Super::BeginPlay();

	//find all SpawnVolume actors
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundActors); //TODO WARNING very high computational cost in a big World!!!!!!!!!!

	for (auto Actor : FoundActors) {
		ASpawnVolume* SpawnVolumeActor = Cast<ASpawnVolume>(Actor);
		if (SpawnVolumeActor) {
			SpawnVolumeActors.AddUnique(SpawnVolumeActor);
		}
	}

	//set current playing state 
	SetCurrentState(EBatteryPlayState::EPlaying);
	//set the score to beat
	ABatteryCollectorCharacter* MyCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (MyCharacter) {
		PowerToWin = (MyCharacter->GetInitialPower()) * 1.25f;
	}
	if (HUDWidgetClass != nullptr) {
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (CurrentWidget != nullptr) {
			CurrentWidget->AddToViewport();
		}
	}
}

void ABatteryCollectorGameMode::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	//Check if we are using the BatteryCollectorCharacter
	ABatteryCollectorCharacter* MyCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	//power decay
	if (MyCharacter) {

		if (MyCharacter->GetCurrentPower() > PowerToWin) {
			SetCurrentState(EBatteryPlayState::EWon);
		}
		else if (MyCharacter->GetCurrentPower() > 0) {
			MyCharacter->UpdatePower(-DeltaTime*DecayRate*(MyCharacter->GetInitialPower()));
		}
		else {
			SetCurrentState(EBatteryPlayState::EGameOver);
		}
	}
}
