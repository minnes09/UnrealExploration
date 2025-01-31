// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickup.h"

// Sets default values for this actor's properties
ABatteryPickup::ABatteryPickup() {
	GetMesh()->SetSimulatePhysics(true);

	BatteryPower = 150.f;
}

void ABatteryPickup::WasCollected_Implementation() {
	//use the base pickup behaviour
	Super::WasCollected_Implementation();
	Destroy();
}

float ABatteryPickup::GetPower() { return BatteryPower; }
