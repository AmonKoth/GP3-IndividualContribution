#pragma once

UENUM(BlueprintType)
enum class ECollectableType : uint8
{
	ECT_Earth UMETA(DisplayName = "StormCollect"),
	ECT_Wind UMETA(DisplayName = "AirCollect"),
	ECT_Fire UMETA(DisplayName = "FireCollect")
};