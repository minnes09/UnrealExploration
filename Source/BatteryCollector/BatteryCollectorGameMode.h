// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "BatteryCollectorGameMode.generated.h"

// enum to store the current state of the gameplay
UENUM(BlueprintType)
enum class EBatteryPlayState {
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};


UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

	virtual void Tick(float DeltaTime) override;

	//returns the power to win - needed for the HUD
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetPowerToWin() const;

	virtual void BeginPlay() override;

	/* accessors for playing  state*/
	UFUNCTION(BlueprintPure, Category = "Power")
	EBatteryPlayState GetCurrentState() const;

	void SetCurrentState(EBatteryPlayState NewState);
protected:
	//the rate at which the character loses the power
	UPROPERTY(EditDefaultsOnly, BLueprintReadWrite, Category ="Power", Meta = (BlueprintProtected = "True"))
	float DecayRate;

	//The power needed to end the game
	UPROPERTY(EditDefaultsOnly, BLueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "True"))
	float PowerToWin;

	//the widget class to use for our  HUD screen
	UPROPERTY(EditDefaultsOnly, BLueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "True"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	//the instance of the HUD
	UPROPERTY()
	class UUserWidget* CurrentWidget;

private:
	//keeps track of the current playing state
	EBatteryPlayState CurrentState;

	TArray<class ASpawnVolume*> SpawnVolumeActors;

	/*handle any function call that rely on changing the play state*/
	void HandleCurrentState(EBatteryPlayState NewState);
};



