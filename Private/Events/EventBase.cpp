// Fill out your copyright notice in the Description page of Project Settings.


#include "Events/EventBase.h"

// Sets default values
AEventBase::AEventBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEventBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEventBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

