// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "BatteryCollectorCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateInventoryDelegate, const TArray<AInventoryPickup*>&, InventoryItems);

UCLASS(config=Game)
class ABatteryCollectorCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** Collection Sphere*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* CollectionSphere;

	/**Spawn Location*/
	UPROPERTY(VisibleAnywhere, Category = Spawning, meta = (AllowPrivateAccess = "true"))
	class UArrowComponent* SpawnLocation;
public:
	ABatteryCollectorCharacter();

	

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UFUNCTION(BlueprintPure, Category = "Power")
	float GetInitialPower();

	UFUNCTION(BlueprintPure, Category = "Power")
	float GetCurrentPower();

	/**
	Update the Character's power
	*@param PowerChange This is the amount to change the power by, it can be negative or positive.
	*/
	UFUNCTION(BlueprintCallable, Category = "Power")
	void UpdatePower(float PowerChange);

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	/**returns the CollectionSphere subobject**/
	FORCEINLINE class USphereComponent* GetSphere() const { return CollectionSphere; }

	//inventory features
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void AddToInventory(AInventoryPickup* Pickup);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void UpdateInventory();

	UPROPERTY(BlueprintAssignable, Category = "Pickup")
		FUpdateInventoryDelegate OnUpdateInventory;


protected:
	
	//the pickup to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning", Meta = (BlueprintProtected = "true"))
		TSubclassOf<class APickup> OnClickSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning", Meta = (BlueprintProtected = "true"))
		TSubclassOf<class APickup> TmpSpawn;
	FTimerHandle SpawnTimer;
	//minimum spawn delay 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelay;


	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

	/**called when we press a key to collect any pickups inside the CollectionSphere**/
	UFUNCTION(BlueprintCallable, Category = "Pickups")
	void CollectPickups();
	/**called when we press a key to spawn objects**/
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void Spawn();

	/**the starting power level of the character*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float InitialPower;

	/**multiplier for the character speed*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float SpeedFactor;

	/**base character's level speed*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float BaseSpeed;	

	UFUNCTION(BlueprintImplementableEvent, Category = "Power")
	void PowerChangeEffect();

private:
	UPROPERTY(VisibleAnywhere, Category = "Power")
	float CharacterPower;
	//inventory
	TArray<AInventoryPickup*> _inventory;

};

