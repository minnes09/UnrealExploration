// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BatteryCollectorCharacter.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	//inventory features
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
		UTexture2D* image;
	//return the mesh for the pickup
	FORCEINLINE class UStaticMeshComponent * GetMesh() const { return PickupMesh; }

	UFUNCTION(BlueprintPure, Category = "Pickup")
		bool IsActive();

	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void SetActive(bool newState);

	UFUNCTION(BlueprintNativeEvent)
		void WasCollected();
	virtual void WasCollected_Implementation();

	
protected:
	//true if the object can be used, false otherwise
	bool bIsActive;

	//static mesh to represent in the level
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;

	
};
