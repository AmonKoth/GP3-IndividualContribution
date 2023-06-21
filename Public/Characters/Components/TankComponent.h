// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/ItemTypes.h"
#include "Characters/CharacterTypes.h"
#include "TankComponent.generated.h"

class APlayerCharacter;
class AGP3GameModeBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GP3_TEAM4_API UTankComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddEssence(ECollectableType Type, int Value, bool& bTankIsFull);
	void DrainEssence(int Value, bool& bIsOverflowing);
	void OverLoadTank(int Value, bool& bIsOverload);

	UFUNCTION(BlueprintCallable)
	void DrainTank(int Value);

	UFUNCTION(BlueprintCallable)
	float ReturnTankPercentage() { return (float)CurrentCapacity/(float)MaxCapacity; }
	UFUNCTION(BlueprintCallable)
	int GetCurrentCapacity() {return CurrentCapacity;}
	UFUNCTION(BlueprintCallable)
	int StormInTankAmount() { return EarthCap; }
	UFUNCTION(BlueprintCallable)
	int WindInTankAmount() { return WindCap ; }
	UFUNCTION(BlueprintCallable)
	int FireInTankAmount() { return FireCap ; }

	UFUNCTION(BlueprintCallable)
	float FireInTankPercentage() { return (float)FireCap / (float)MaxCapacity;	}
	UFUNCTION(BlueprintCallable)
	float WindInTankAmountPercentage() { return (float)WindCap / (float)MaxCapacity; }
	UFUNCTION(BlueprintCallable)
	float StormInTankAmountPercentage() { return (float)EarthCap/ (float)MaxCapacity; }

	UFUNCTION(BlueprintCallable)
	EAbilityLevel GetCurrentStormLevel() {return CurrentStormLevel;}
	UFUNCTION(BlueprintCallable)
	EAbilityLevel GetCurrentFireLevel() {return CurrentFireLevel;}
	UFUNCTION(BlueprintCallable)
	EAbilityLevel GetCurrentWindLevel() { return CurrentWindLevel; }

	EAbilityLevel CheckTypeLevel(ECollectableType Type);
	
	UFUNCTION(BlueprintCallable)
	ECollectableType GetAskedType() { return TankType; }	
	UFUNCTION(BlueprintCallable)
	int GetAskedAmmount() { return AskedAmmount; }

	void AddSelectedType(ECollectableType& AskedType, int Value, bool& bIsTankFull);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "QuestTank", meta = (ToolTip = "Ignore if player"))
		ECollectableType TankType = ECollectableType::ECT_Earth;
	UPROPERTY(EditAnywhere, Category = "QuestTank", meta = (ToolTip = "Ignore if player"))
		int AskedAmmount = 100;

private:

	APlayerCharacter* Player;

	void UpgradeALevel(int TypeContainer, EAbilityLevel& TypeLevel);
	void DowngradeALevel(int TypeContainer, EAbilityLevel& TypeLevel);

	UPROPERTY(EditDefaultsOnly, Category = Collect)
	int MaxCapacity = 300;
	int EarthCap = 0;
	int WindCap = 0;
	int FireCap = 0;
	int CurrentCapacity= 0;

	EAbilityLevel CurrentStormLevel = EAbilityLevel::EAL_Level0;
	EAbilityLevel CurrentWindLevel = EAbilityLevel::EAL_Level0;
	EAbilityLevel CurrentFireLevel = EAbilityLevel::EAL_Level0;

	AGP3GameModeBase* GameMode;

		
};
