// Fill out your copyright notice in the Description page of Project Settings.


#include "CardDisplayWidget.h"

#include "Components/Border.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/TextBlock.h"

void UCardDisplayWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCardDisplayWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
	UE_LOG(LogTemp, Warning, TEXT("Mouse enter Card: %s"), *Name->GetText().ToString());
	SetRenderScale({1.2, 1.2});
}

void UCardDisplayWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
	UE_LOG(LogTemp, Warning, TEXT("Mouse leave Card: %s"), *Name->GetText().ToString());
	SetRenderScale({1, 1});
	Background->SetRenderOpacity(1);
}

FReply UCardDisplayWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (const auto Reply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent); Reply.IsEventHandled())
	{
		return Reply;
	}

	UE_LOG(LogTemp, Warning, TEXT("Mouse click down Card: %s"), *Name->GetText().ToString());
	Background->SetRenderOpacity(0.8);
	return FReply::Handled();
}

FReply UCardDisplayWidget::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (const auto Reply = Super::NativeOnMouseButtonUp(InGeometry, InMouseEvent); Reply.IsEventHandled())
	{
		return Reply;
	}
	UE_LOG(LogTemp, Warning, TEXT("Mouse click release Card: %s"), *Name->GetText().ToString());
	Background->SetRenderOpacity(1);
	return FReply::Handled();
}

void UCardDisplayWidget::SetModel(const FCard* InCard) const
{
	SetBackground(InCard->GetBackground());
	SetName(InCard->Name);
	SetDescription(InCard->Description);
	SetCost(InCard->Cost);
}

void UCardDisplayWidget::SetBackground(const FLinearColor InColor) const
{
	UE_LOG(LogTemp, Warning, TEXT("Color: %s"), *InColor.ToString());
	Background->SetBrushColor({InColor.R * 0.6f, InColor.G* 0.6f , InColor.B* 0.6f, 1});
}

void UCardDisplayWidget::SetName(const FString InName) const
{
	Name->SetText(FText::FromString(InName));
}

void UCardDisplayWidget::SetDescription(const FString InDescription) const
{
	Description->SetText(FText::FromString(InDescription));
}

void UCardDisplayWidget::SetCost(const FCost& InCost) const
{
	Cost->SetText(FText::FromString(InCost.ToString()));
}
