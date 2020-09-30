// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void ABasicAIController::BeginPlay() {
	
	Super::BeginPlay();
	if (AIBehavior != nullptr) {
		RunBehaviorTree(AIBehavior);
		UE_LOG(LogTemp, Warning, TEXT("AI Start"));

		APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());	

	}
}

void ABasicAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//get player pawn, check if line of sight, if yes, set blackboard components, if no clear focus.
	APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn != nullptr) {
		if (LineOfSightTo(PlayerPawn)) {
			GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
			GetBlackboardComponent()->SetValueAsVector(TEXT("PlayersLastKnownPosition"), PlayerPawn->GetActorLocation());
		}
		else {
			GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
		}
	}
}
