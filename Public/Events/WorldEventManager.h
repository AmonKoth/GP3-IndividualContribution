// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldEventManager.generated.h"

class AEventBase;
UCLASS()
class GP3_TEAM4_API AWorldEventManager : public AActor
{
	GENERATED_BODY()
	
public:	

	AWorldEventManager();
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintImplementableEvent)
		void CastEvent(AEventBase* Event);
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = WorldEvents)
		TArray<TSubclassOf< AEventBase>> WorldEvents;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

private:



};
