// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HelloWorldWidget.generated.h"


UCLASS(Abstract)
class CARDTEST_API UHelloWorldWidget final : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UTextBlock* Title;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UHorizontalBox* CardDisplayField;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UCardDisplayWidget> CardDisplayClass;

	UPROPERTY(EditDefaultsOnly)
	class UDataTable* GlobalCardPool;

public:
	void SetTitle(FString InTitle) const;
};
