#include "Cost.h"

#include "CostType.h"

FString FCost::ToString() const
{
	TArray<FString> Result;
	for (auto Pair : Value)
	{
		if (const auto Name = CostTypeName(Pair.Key); ! Name.IsEmpty())
		{
			Result.Add(FString::Printf(TEXT("%ls:%d"), *Name, Pair.Value));
		}
	}
	return FString::Join(Result, TEXT(" "));
}

FString FCost::CostTypeName(const ECostType& InCostType)
{
	switch (InCostType)
	{
	case ECostType::Yin: return "Yin";
	case ECostType::Yang: return "Yang";
	case ECostType::Any: return "Any";
	default: return "";
	}
}
