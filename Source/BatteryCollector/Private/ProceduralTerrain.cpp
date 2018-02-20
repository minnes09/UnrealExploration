// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "ProceduralTerrain.h"


// Sets default values
AProceduralTerrain::AProceduralTerrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	proceduralComponent = mesh;
	/**
	*	Create/replace a section for this procedural mesh component.
	*	@param	SectionIndex		Index of the section to create or replace.
	*	@param	Vertices			Vertex buffer of all vertex positions to use for this mesh section.
	*	@param	Triangles			Index buffer indicating which vertices make up each triangle. Length must be a multiple of 3.
	*	@param	Normals				Optional array of normal vectors for each vertex. If supplied, must be same length as Vertices array.
	*	@param	UV0					Optional array of texture co-ordinates for each vertex. If supplied, must be same length as Vertices array.
	*	@param	VertexColors		Optional array of colors for each vertex. If supplied, must be same length as Vertices array.
	*	@param	Tangents			Optional array of tangent vector for each vertex. If supplied, must be same length as Vertices array.
	*	@param	bCreateCollision	Indicates whether collision should be created for this section. This adds significant cost.
	*/

}

// Called when the game starts or when spawned
void AProceduralTerrain::BeginPlay()
{
	Super::BeginPlay();
	GenerateChunk();
}

// Called every frame
void AProceduralTerrain::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// This is called when actor is spawned (at runtime or when you drop it into the world in editor)
void AProceduralTerrain::PostActorCreated()
{
	Super::PostActorCreated();
	//GenerateChunk();
}

// This is called when actor is already in level and map is opened
void AProceduralTerrain::PostLoad()
{
	Super::PostLoad();
	//GenerateChunk();
}

void AProceduralTerrain::CreateSquare()
{
	TArray<FVector> vertices;
	TArray<int32> Triangles;
	TArray<FVector> normals;
	TArray<FVector2D> UV0;
	TArray<FProcMeshTangent> tangents;
	TArray<FLinearColor> vertexColors;

	//triangle 1
	vertices.Add(FVector(0, 0, 0));
	vertices.Add(FVector(VoxelSize, 0, 0));
	vertices.Add(FVector(0, VoxelSize, 0));

	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);

	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));

	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(10, 0));
	UV0.Add(FVector2D(0, 10));


	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));


	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

	//triangle2 
	vertices.Add(FVector(VoxelSize, 0, 0));
	vertices.Add(FVector(VoxelSize, VoxelSize, 0 ));
	vertices.Add(FVector(0, VoxelSize, 0));

	Triangles.Add(3);
	Triangles.Add(4);
	Triangles.Add(5);

	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));

	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(10, 0));
	UV0.Add(FVector2D(0, 10));


	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));


	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

	mesh->CreateMeshSection_LinearColor(0, vertices, Triangles, normals, UV0, vertexColors, tangents, true);

	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}

void AProceduralTerrain::CreateTriangle(int32 i, int32 j)
{
	TArray<FVector> vertices;
	TArray<int32> Triangles;
	TArray<FVector> normals;
	TArray<FVector2D> UV0;
	TArray<FProcMeshTangent> tangents;
	TArray<FLinearColor> vertexColors;

	vertices.Add(FVector(VoxelSize * i, 0, VoxelSize * j ));
	vertices.Add(FVector(VoxelSize * (i + 1), 0, VoxelSize * j));
	vertices.Add(FVector(VoxelSize * i, 0, VoxelSize * (j + 1)));

	Triangles.Add(0 + i + j);
	Triangles.Add(1 + i + j);
	Triangles.Add(2 + i + j);
	
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(10, 0));
	UV0.Add(FVector2D(0, 10));

	
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));

	
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

	mesh->CreateMeshSection_LinearColor(i + j, vertices, Triangles, normals, UV0, vertexColors, tangents, true);

	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}


//Used one
void AProceduralTerrain::CreateSquare(int32 i, int32 j, int32 section)
{
	TArray<FVector> vertices;
	TArray<int32> Triangles;
	TArray<FVector> normals;
	TArray<FVector2D> UV0;
	TArray<FProcMeshTangent> tangents;
	TArray<FLinearColor> vertexColors;

	vertices.Add(FVector(VoxelSize * i, VoxelSize * j, 0));
	vertices.Add(FVector(VoxelSize * i, VoxelSize * (j + 1), 0));
	vertices.Add(FVector(VoxelSize * (i + 1 ), VoxelSize * j, 0));
	vertices.Add(FVector(VoxelSize * (i + 1), VoxelSize * (j + 1), 0));

	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);
	Triangles.Add(3);
	Triangles.Add(2);
	Triangles.Add(1);

	/*for (size_t t = 0; t < 5; t++)
	{
		normals.Add(FVector(1, 0, 0));
		tangents.Add(FProcMeshTangent(0, 1, 0));
		vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	}*/

	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(0, 1));
	UV0.Add(FVector2D(1, 0));
	UV0.Add(FVector2D(1, 1));

	mesh->CreateMeshSection_LinearColor(section, vertices, Triangles, normals, UV0, vertexColors, tangents, true);

	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}

void AProceduralTerrain::GenerateChunk() {
	int32 section = 0;
	for (size_t w = 0; w < this->width; w++)
	{
		for (size_t h = 0; h < this->height; h++)
		{
			CreateSquare(w, h, section);
			section++;
		}
		
	}
}
