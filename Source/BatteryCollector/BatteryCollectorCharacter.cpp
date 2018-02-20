// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollector.h"
#include "BatteryCollectorCharacter.h"
#include "Pickup.h"
#include "BatteryPickup.h"
#include "InventoryPickup.h"

//////////////////////////////////////////////////////////////////////////
// ABatteryCollectorCharacter


ABatteryCollectorCharacter::ABatteryCollectorCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	//Create the collection sphere
	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	CollectionSphere->SetupAttachment(RootComponent);
	CollectionSphere->SetSphereRadius(200.0f);

	//Create the Spawn Location
	SpawnLocation = CreateDefaultSubobject<UArrowComponent>(TEXT("SpawnLocation"));
	SpawnLocation->SetupAttachment(RootComponent);
	SpawnLocation->RelativeLocation = FVector(230.0f, 0.0f, 0.0f);

	//Initialize the spawn actors
	/*static ConstructorHelpers::FClassFinder<ABatteryPickup> TmpSpawnFinder(TEXT("/Game/Blueprints/BP_TmpBatteryPickup.BP_TmpBatteryPickup_C"));
	static ConstructorHelpers::FClassFinder<ABatteryPickup> OnCLickSpawnFinder(TEXT("'/Game/Blueprints/BP_TmpBatteryPickup.BP_BatteryPickup_C"));
	OnClickSpawn = OnCLickSpawnFinder.Class;
	TmpSpawn = TmpSpawnFinder.Class;
	if (!OnClickSpawn) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Battery not initialized"));
	}*/
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	InitialPower = 1000.f;
	CharacterPower = InitialPower;

	//set the dependece of the speed on the power level
	SpeedFactor = 0.75f;
	BaseSpeed = 10.0f;

	APlayerController* playerController = Cast<APlayerController>(GetController());
	if (playerController) {
		playerController->bShowMouseCursor = true;
		playerController->bEnableClickEvents = true;
		playerController->bEnableMouseOverEvents = true;
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void ABatteryCollectorCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// Set up gameplay key bindings
	check(InputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponent->BindAction("Collect", IE_Pressed, this, &ABatteryCollectorCharacter::CollectPickups);
	InputComponent->BindAction("Spawn", IE_Pressed, this, &ABatteryCollectorCharacter::Spawn);

	InputComponent->BindAxis("MoveForward", this, &ABatteryCollectorCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABatteryCollectorCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ABatteryCollectorCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ABatteryCollectorCharacter::LookUpAtRate);

	// handle touch devices
	InputComponent->BindTouch(IE_Pressed, this, &ABatteryCollectorCharacter::TouchStarted);
	InputComponent->BindTouch(IE_Released, this, &ABatteryCollectorCharacter::TouchStopped);

	
}


void ABatteryCollectorCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	// jump, but only on the first touch
	if (FingerIndex == ETouchIndex::Touch1)
	{
		Jump();
	}
}

void ABatteryCollectorCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (FingerIndex == ETouchIndex::Touch1)
	{
		StopJumping();
	}
}

void ABatteryCollectorCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABatteryCollectorCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ABatteryCollectorCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ABatteryCollectorCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);

	}
}

void ABatteryCollectorCharacter::CollectPickups() {
	//get all overlapping actors  and store in an array
	TArray<AActor*> CollectedActors;
	CollectionSphere->GetOverlappingActors(CollectedActors);
	
	//keep track of the collected battery power
	float CollectedPower = 0;

	//for each actor we collect
	for (int32 iCollected = 0; iCollected < CollectedActors.Num(); ++iCollected) {
		//cast the actor to a Pickup
		APickup* const TestPickup = Cast<APickup>(CollectedActors[iCollected]);
		//if the cast is successful and the pickup is valid and active
		if (TestPickup && !TestPickup->IsPendingKill() && TestPickup->IsActive()) {
			//call the pickups WasCollected()
			TestPickup->WasCollected();

			//check to see if the pickup has also battery
			ABatteryPickup* const TestBattery = Cast<ABatteryPickup>(TestPickup);
			if (TestBattery) {
				CollectedPower += TestBattery->GetPower();
			}
			//Deactivate the pickup
			TestPickup->SetActive(false);
			
		}
	}
	if (CollectedPower > 0) {
		UpdatePower(CollectedPower);
	}
}

float ABatteryCollectorCharacter::GetInitialPower() { return InitialPower; }

float ABatteryCollectorCharacter::GetCurrentPower() { return CharacterPower; }

void ABatteryCollectorCharacter::UpdatePower(float PowerChange) {

	//change power
	CharacterPower += PowerChange;
	
	//change speed
	GetCharacterMovement()->MaxWalkSpeed = BaseSpeed + SpeedFactor * CharacterPower;

	//call visual effect
	PowerChangeEffect();
}

void ABatteryCollectorCharacter::Spawn() {
	//if we have set something to spawn
	if (OnClickSpawn != NULL) {

		//Check for a valid world
		UWorld * const World = GetWorld();
		if (World) {
			//set the spawn parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.Instigator = Instigator;

			//get the point to spawn
			FVector SpawnVector = SpawnLocation->GetComponentLocation();

			//get random rotation for the spawned item
			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360.0f;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;
			SpawnRotation.Roll = FMath::FRand() * 360.0f;

			//spawn the pickup		
			ABatteryPickup * SpawnedBatteryPickup = World->SpawnActor<ABatteryPickup>(OnClickSpawn, SpawnVector, SpawnRotation, SpawnParams);
			
			if (SpawnedBatteryPickup) {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Pickup spawned"));
			}
			else {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("ERROR"));
			}
		}
		else {
			GLog->Log("Pickup is NULL");
		}
	}
}

void ABatteryCollectorCharacter::AddToInventory(AInventoryPickup * Pickup)
{
	_inventory.Add(Pickup);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Pickup is in the inventory"));
	UpdateInventory();
}

void ABatteryCollectorCharacter::UpdateInventory()
{
	FString inv = "";
	for (AInventoryPickup* actor : _inventory) {
		inv.Append(actor->Name);
		inv.Append(" | ");
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, *inv);
	OnUpdateInventory.Broadcast(_inventory);
	
}
