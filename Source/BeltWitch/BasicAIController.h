// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BasicAIController.generated.h"

/**
 * 
 */
UCLASS()
class BELTWITCH_API ABasicAIController : public AAIController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		float AcceptanceRadius = 200;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;

	
};
