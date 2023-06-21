// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GP3GameModeBase.generated.h"

class APlayerCharacter;

UCLASS()
class GP3_TEAM4_API AGP3GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	void AddTankToArray(AActor* ActorToBeAdded);

	AActor* GetClosestActor(float& Distance);

	UFUNCTION(BlueprintImplementableEvent)
	void TankIsFull(AActor* FullTank);

	UFUNCTION(BlueprintCallable)
		TArray<AActor*> GetQuestTanks() { return QuestTanks; }

protected:
	virtual void BeginPlay() override;

private:

	TArray<AActor*> QuestTanks;
	APlayerCharacter* Player;

};
