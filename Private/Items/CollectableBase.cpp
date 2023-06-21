// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/CollectableBase.h"
#include "Characters/PlayerCharacter.h"




void ACollectableBase::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Player = Cast<APlayerCharacter>(OtherActor);
	if (Player)
	{
		Player->GotCollectable(CollectableType, CollectableValue, bIsCollectSuccess);
		if (bIsCollectSuccess)
		{
			Destroy();
		}
	}
}
