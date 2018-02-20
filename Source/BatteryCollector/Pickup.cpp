// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "Pickup.h"


// Sets default values
APickup::APickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//set default active at true
	bIsActive = true;
	//create the UStaticMeshComponent
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;
	this->Name = this->GetName();
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APickup::IsActive() {
	return bIsActive;
}

void APickup::SetActive(bool newState) {
	bIsActive = newState;

}

void APickup::WasCollected_Implementation()
{
	//log a debug message
	FString  PickupDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("You have collcted %s"), *PickupDebugString);
}

