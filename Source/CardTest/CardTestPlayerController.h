// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CardTestPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CARDTEST_API ACardTestPlayerController final : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;
	void ShowHelloWorldWidget();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UHelloWorldWidget> HelloWorldClass;

private:
	UHelloWorldWidget* HelloWorldWidget;
};
