// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Models/Card.h"
#include "CardDisplayWidget.generated.h"


class UTextBlock;

UCLASS()
class CARDTEST_API UCardDisplayWidget final : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UBorder* Background;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* Name;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* Description;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* Cost;

public:
	void SetModel(const FCard* InCard) const;
	void SetBackground(const FLinearColor InColor) const;
	void SetName(const FString InName) const;
	void SetDescription(const FString InDescription) const;
	void SetCost(const FCost& InCost) const;
};
