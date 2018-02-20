// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralTerrain.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API AProceduralTerrain : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TArray<UMaterialInterface *> Materials;
	UPROPERTY(EditAnywhere, BlueprinReadWrite, Meta = (ExposeOnSpawn = true))
		int32 randomSeed = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", Meta = (ExposeOnSpawn = true))
		int32 VoxelSize = 200;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", Meta = (ExposeOnSpawn = true))
		int32 width = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", Meta = (ExposeOnSpawn = true))
		int32 height = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", Meta = (ExposeOnSpawn = true))
		int32 ChunkLineElements = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", Meta = (ExposeOnSpawn = true))
		int32 ChunkXIndex = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", Meta = (ExposeOnSpawn = true))
		int32 ChunkYIndex = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural")
		int32 xMult = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural")
		int32 yMult = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural")
		int32 zMult = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural")
		int32 weight = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural")
		int32 freq = 1;
	UPROPERTY()
		int32 chunkTotalElements;
	UPROPERTY()
		int32 chunkZElements;
	UPROPERTY()
		int32 chunkLineElements;
	UPROPERTY()
		int32 VoxelSizeHalf;
	UPROPERTY()
		TArray<int32> chunkFields;
	UPROPERTY()
	class UProceduralMeshComponent * mesh;
	UPROPERTY()
	class UProceduralMeshComponent * proceduralComponent;

public:	
	// Sets default values for this actor's properties
	AProceduralTerrain();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void PostActorCreated();

	void PostLoad();

	void CreateSquare();
	void CreateTriangle(int32 i, int32 j);
	void CreateSquare(int32 i, int32 j, int32 section);

	
	


private:

	
	UFUNCTION(BlueprintCallable, Category = "Procedural")
	void GenerateChunk();
};
