// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Components/TankComponent.h"
#include "Characters/PlayerCharacter.h"
#include "GameMode/GP3GameModeBase.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankComponent::UTankComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankComponent::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));
	
	if (GetOwner() != Player)
	{
		GameMode = Cast<AGP3GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
		if (GameMode)
		{
			GameMode->AddTankToArray(GetOwner());
		}


	}
}


// Called every frame
void UTankComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UTankComponent::AddEssence(ECollectableType Type , int Value, bool& bTankIsFull)
{
	int CheckOverflow = Value + CurrentCapacity;
	if (CheckOverflow <= MaxCapacity)
	{
		switch (Type)
		{
		case ECollectableType::ECT_Earth:
			EarthCap += Value;
			UpgradeALevel(EarthCap, CurrentStormLevel);
			break;
		case ECollectableType::ECT_Wind:
			WindCap += Value;
			UpgradeALevel(WindCap, CurrentWindLevel);
			break;
		case ECollectableType::ECT_Fire:
			FireCap += Value;
			UpgradeALevel(FireCap, CurrentFireLevel);
			break;
		default:
			break;
		}
		CurrentCapacity = CheckOverflow;
		UE_LOG(LogTemp, Warning, TEXT("CurrentCap : %d"), CurrentCapacity);
		bTankIsFull = false;
		if (CurrentCapacity >=MaxCapacity)
		{
		UE_LOG(LogTemp, Warning, TEXT("Tank Full"), CurrentCapacity);
			bTankIsFull = true;
		}
		return;
	}
		bTankIsFull = true;
		return;
}

void UTankComponent::DrainEssence(int Value,bool& bIsOverflowing)
{
	int LowerAmount = 0;
	if(EarthCap >0 && CurrentStormLevel != EAbilityLevel::EAL_Level0)
	{ 
		EarthCap -= Value;
		if (EarthCap <= 0)
		{
			EarthCap = 0;
		}
		DowngradeALevel(EarthCap, CurrentStormLevel);
		LowerAmount+=Value;
	}
	if(WindCap >0 && CurrentWindLevel != EAbilityLevel::EAL_Level0)
	{ 
		WindCap -= Value;
		if (WindCap <= 0)
		{
			WindCap = 0;
		}
		DowngradeALevel(WindCap, CurrentWindLevel);
		LowerAmount += Value;
	}
	if (FireCap > 0 && CurrentFireLevel != EAbilityLevel::EAL_Level0)
	{
		FireCap -= Value;
		if (FireCap <= 0)
		{
			FireCap = 0;
		}
		DowngradeALevel(FireCap, CurrentFireLevel);
		LowerAmount += Value;
	}
	if (CurrentCapacity > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Lower amount : %d"), LowerAmount);
		CurrentCapacity -= LowerAmount;
		if (CurrentCapacity <= 0)
		{
			CurrentCapacity = 0;
		}
	}
}

void UTankComponent::OverLoadTank(int Value, bool& bIsOverload)
{

}

void UTankComponent::DrainTank(int Value)
{
	bool bDoesNothing = false;
	int LowerAmount = 0;
	if (EarthCap > 0)
	{
		EarthCap -= Value;
		if (EarthCap <= 0)
		{
			EarthCap = 0;
		}
		DowngradeALevel(EarthCap, CurrentStormLevel);
		LowerAmount += Value;
	}
	if (WindCap > 0)
	{
		WindCap -= Value;
		if (WindCap <= 0)
		{
			WindCap = 0;
		}
		DowngradeALevel(WindCap, CurrentWindLevel);
		LowerAmount += Value;
	}
	if (FireCap > 0)
	{
		FireCap -= Value;
		if (FireCap <= 0)
		{
			FireCap = 0;
		}
		DowngradeALevel(FireCap, CurrentFireLevel);
		LowerAmount += Value;
	}
	if (CurrentCapacity > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Lower amount : %d"), LowerAmount);
		CurrentCapacity -= LowerAmount;
		if (CurrentCapacity <= 0)
		{
			CurrentCapacity = 0;
		}
	}
}

EAbilityLevel UTankComponent::CheckTypeLevel(ECollectableType Type)
{
	switch (Type)
	{
	case ECollectableType::ECT_Earth:
		return CurrentStormLevel;
		break;
	case ECollectableType::ECT_Wind:
		return CurrentWindLevel;
		break;
	case ECollectableType::ECT_Fire:
		return CurrentFireLevel;
		break;
	default:
		return EAbilityLevel::EAL_Level0;
		break;
	}
}

void UTankComponent::AddSelectedType(ECollectableType& AskedType, int Value, bool& bIsTankFull )
{
	AskedType = TankType;
	if (AskedAmmount >= 0)
	{
		AskedAmmount -= Value;
		AddEssence(TankType, Value, bIsTankFull);
	}
	else
	{
		bIsTankFull = true;
		UE_LOG(LogTemp, Warning, TEXT("TankFull") );
	}
	if (bIsTankFull)
	{
		GameMode->TankIsFull(GetOwner());
	}
}



void UTankComponent::UpgradeALevel(int TypeContainer, EAbilityLevel& TypeLevel)
{

	if (TypeContainer >= 100 && TypeLevel == EAbilityLevel::EAL_Level0)
	{
		TypeLevel = EAbilityLevel::EAL_Level1;
	}
	else if (TypeContainer >= 200 && TypeLevel == EAbilityLevel::EAL_Level1)
	{
		TypeLevel = EAbilityLevel::EAL_Level2;
	}
	else if (TypeContainer >= 300&& TypeLevel == EAbilityLevel::EAL_Level2)
	{
		TypeLevel = EAbilityLevel::EAL_Level3;
	}
}

void UTankComponent::DowngradeALevel(int TypeContainer, EAbilityLevel& TypeLevel)
{
	if (TypeContainer <= 200 && TypeLevel == EAbilityLevel::EAL_Level3)
	{
		TypeLevel = EAbilityLevel::EAL_Level2;
	}
	else if (TypeContainer <= 100 && TypeLevel == EAbilityLevel::EAL_Level2)
	{
		TypeLevel = EAbilityLevel::EAL_Level1;
	}
	else if (TypeContainer <= 0 && TypeLevel == EAbilityLevel::EAL_Level1)
	{
		TypeLevel = EAbilityLevel::EAL_Level0;
	}
}
