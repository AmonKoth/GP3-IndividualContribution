// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase.h"
#include "ItemTypes.h"
#include "CollectableBase.generated.h"


class APlayerCharacter;

UCLASS()
class GP3_TEAM4_API ACollectableBase : public AItemBase
{
	GENERATED_BODY()

public :
	ECollectableType GetCollectableType() { return CollectableType; }


protected:

	virtual void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:

	UPROPERTY(EditDefaultsOnly, Category = Collectable)
	ECollectableType CollectableType = ECollectableType::ECT_Earth;

	UPROPERTY(EditDefaultsOnly, Category = Collectable)
	int CollectableValue = 5;

	APlayerCharacter* Player;

	bool bIsCollectSuccess = false;
};
