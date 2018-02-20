// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "CollisionTestPickup.h"


// Sets default values
ACollisionTestPickup::ACollisionTestPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->bGenerateOverlapEvents = true;
	BoxCollider->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ACollisionTestPickup::OnOverlapBegin);
	BoxCollider->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACollisionTestPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollisionTestPickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACollisionTestPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult) {
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Pickup collision"));
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Pickup collision true"));
		Destroy();
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("collision error"));
	}
}

