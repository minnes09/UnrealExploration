// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "InventoryPickup.h"

AInventoryPickup::AInventoryPickup() {
	//GetMesh()->SetSimulatePhysics(true);
	
	//set box collider
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->bGenerateOverlapEvents = true;
	FVector scale = GetMesh()->GetComponentScale();
	BoxCollider->SetWorldScale3D(scale);
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AInventoryPickup::OnOverlapBegin);
	BoxCollider->SetupAttachment(RootComponent);

	collision = ECollisionEnabled::QueryAndPhysics;
}

void AInventoryPickup::WasCollected_Implementation() {
	Super::WasCollected_Implementation();

}

void AInventoryPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult) {
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Pickup collision"));
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Pickup collision true"));
		OnInteract();
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("collision error"));
	}
}

void AInventoryPickup::OnInteract()
{
	FString Spickup = FString::Printf(TEXT("picked up: %s"), *Name);
	ABatteryCollectorCharacter* player = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (player) {
		Show(false);

		player->AddToInventory(this);
	}
}

void AInventoryPickup::Show(bool visible)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Show begin"));
	this->collision = visible ?
		ECollisionEnabled::QueryAndPhysics :
		ECollisionEnabled::NoCollision;

	this->SetActorTickEnabled(visible);
	this->PickupMesh->SetVisibility(visible);
	this->PickupMesh->SetCollisionEnabled(this->collision);

	this->BoxCollider->SetCollisionEnabled(collision);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Show end"));
}


