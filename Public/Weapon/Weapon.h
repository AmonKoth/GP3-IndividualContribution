// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class UBoxComponent;
class APlayerCharacter;

UCLASS()
class GP3_TEAM4_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	float GetWeaponDamage() { return Damage; }
	UFUNCTION(BlueprintCallable)
	TArray<TSubclassOf<UDamageType>> GetDamageTypes() { return DamageTypes; }

	UFUNCTION(BlueprintCallable)
	void SetDamage(float Value, TSubclassOf<UDamageType> DamageType);

	UFUNCTION(BlueprintCallable)
	void RemoveDamageType(TSubclassOf<UDamageType> DamageType);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


private:

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	UBoxComponent* BoxComponent;


	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceStart;
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceEnd;

	UPROPERTY(EditDefaultsOnly, Category = Combat)
	float Damage = 20.0f;

	UPROPERTY(VisibleAnywhere)
	TArray<TSubclassOf<UDamageType>> DamageTypes;


	APlayerCharacter* Player;

};
