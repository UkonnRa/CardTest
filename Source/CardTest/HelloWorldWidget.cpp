// Fill out your copyright notice in the Description page of Project Settings.


#include "HelloWorldWidget.h"

#include "CardDisplayWidget.h"
#include "Components/GridPanel.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"


void UHelloWorldWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (Title)
	{
		SetTitle("Hello World");
	}

	TArray<FCard*> Results;
	GlobalCardPool->GetAllRows<FCard>(GetName(), Results);
	for (const auto Card: Results)
	{
		const auto CardDisplay = CreateWidget<UCardDisplayWidget>(this, CardDisplayClass);
		const auto Result = CardDisplayField->AddChildToHorizontalBox(CardDisplay);
		CardDisplay->SetPadding({5.0, 0.0});
		CardDisplay->SetModel(Card);
		Result->SetHorizontalAlignment(HAlign_Center);
		Result->SetVerticalAlignment(VAlign_Center);
	}
}

void UHelloWorldWidget::SetTitle(const FString InTitle) const
{
	Title->SetText(FText::FromString(InTitle));
}
