#pragma once
#include "CardType.h"
#include "Cost.h"
#include "Engine/DataTable.h"
#include "Card.generated.h"

USTRUCT(BlueprintType)
struct CARDTEST_API FCard : public FTableRowBase
{
	GENERATED_BODY()

	explicit FCard(const FString& Name, const FString& Description, const ECardType Type, const TMap<ECostType, uint8> Cost)
		: Name(Name),
		  Description(Description),
		  Type(Type),
		  Cost(Cost)
	{
	}

	explicit FCard(): Name(FString()),
		  Description(FString()),
		  Type(ECardType::None),
		  Cost({})
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECardType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCost Cost;

	FLinearColor GetBackground() const;
};
