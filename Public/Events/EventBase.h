// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EventBase.generated.h"

UCLASS()
class GP3_TEAM4_API AEventBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEventBase();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = EventFunctions)
	void EventActivation();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = EventFunctions)
	void EventExecution();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = EventFunctions)
	void EventConclusion();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:


};
