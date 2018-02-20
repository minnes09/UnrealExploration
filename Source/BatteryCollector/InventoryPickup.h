// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "InventoryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API AInventoryPickup : public APickup
{
	GENERATED_BODY()

public:
	AInventoryPickup();

	//override WasCollected function - use implementation because it's a blueprint native event
	void WasCollected_Implementation() override;

	virtual void OnInteract();
	//Box collider and overlap function
	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxCollider;

	

protected:
	virtual void Show(bool visible);

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);
	
private:
	ECollisionEnabled::Type collision;
};
