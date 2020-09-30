// Fill out your copyright notice in the Description page of Project Settings.


#include "AISpawnerBase.h"

// Sets default values
AAISpawnerBase::AAISpawnerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAISpawnerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAISpawnerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAISpawnerBase::SpawnEnemy(float& Speed, FVector& Offset)
{
	//create random vector within bounds and apply to actor spawn offset
	Offset.X = FMath::FRandRange(MinX, MaxX);
	Offset.Y = FMath::FRandRange(MinY, MaxY);
	Offset.Z = FMath::FRandRange(MinZ, MaxZ);

	FVector Location = GetActorLocation();
	Offset = Location + Offset;

	//set public vars for blueprint readability
	SpawnOffset = Offset;
	Speed = SpawnSpeed;

	UE_LOG(LogTemp, Warning, TEXT("AI Spawn"));

}

