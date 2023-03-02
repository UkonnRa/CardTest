#pragma once
#include "CostType.h"
#include "Cost.generated.h"

USTRUCT(BlueprintType)
struct CARDTEST_API FCost
{
	GENERATED_BODY()

	explicit FCost(const TMap<ECostType, uint8>& Value)
		: Value(Value)
	{
	}

	explicit FCost(): Value({})
	{
	}

	FString ToString() const;

	static FString CostTypeName(const ECostType& InCostType);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<ECostType, uint8> Value;
};
