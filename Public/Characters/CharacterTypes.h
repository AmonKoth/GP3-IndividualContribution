#pragma once

UENUM(BlueprintType)
enum class EActionState : uint8
{
	EAS_Unoccupied UMETA(DisplayName = "Unoccupied"),
	EAS_Attacking UMETA(DosplayName = "Attacking"),
	EAS_CanAttack UMETA(DisplayName = "CanAttack"),
	EAS_HitEnemies UMETA(DisplayName = "Hitting"),
	EAS_Dashing UMETA(DisplayName = "Dashing"),
	EAS_HeavyAttack UMETA(DisplayName ="HeavyAttack")
};

UENUM(BlueprintType)
enum class EAbilityLevel : uint8
{
	EAL_Level0 UMETA(DisplayName = "Level 0"),
	EAL_Level1 UMETA(DisplayName = "Level 1"),
	EAL_Level2 UMETA(DisplayName = "Level 2"),
	EAL_Level3 UMETA(DisplayName = "Level 3")

};