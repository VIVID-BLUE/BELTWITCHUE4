// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AISpawnerBase.generated.h"

UCLASS()
class BELTWITCH_API AAISpawnerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAISpawnerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Spawner")
	float SpawnSpeed = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Spawner")
	int MaxEnemies = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Enemy Spawner")
	int EnemyCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Spawner")
	float MinX = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Spawner")
	float MaxX = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Spawner")
	float MinY = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Spawner")
	float MaxY = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Spawner")
	float MinZ = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Spawner")
	float MaxZ = 150;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Enemy Spawner")
	FVector SpawnOffset;

	UFUNCTION(BlueprintCallable, Category = "Enemy Spawner")
	void SpawnEnemy(float& Speed, FVector& Offset);

};
