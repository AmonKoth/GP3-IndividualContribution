// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/GP3GameModeBase.h"
#include "Characters/PlayerCharacter.h"

#include "Kismet/GameplayStatics.h"

void AGP3GameModeBase::AddTankToArray(AActor* ActorToBeAdded)
{
	FString ActorName = ActorToBeAdded->GetName();
	QuestTanks.Add(ActorToBeAdded);
	UE_LOG(LogTemp, Warning, TEXT("Added %s , length : %d"), *ActorName,QuestTanks.Num() );
}

void AGP3GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

}

AActor* AGP3GameModeBase::GetClosestActor(float& Distance)
{
	AActor* ActorToReturn = nullptr;
	float CurrentDistance = 1000000.0f;


	for (AActor* Actor : QuestTanks)
	{
		float CheckDistance = FVector::Distance(Player->GetActorLocation(), Actor->GetActorLocation());
		if (CheckDistance < CurrentDistance)
		{
			CurrentDistance = CheckDistance;
			ActorToReturn = Actor;
		}
	}
	Distance = CurrentDistance;
	return ActorToReturn;

}