// Fill out your copyright notice in the Description page of Project Settings.


#include "CardTestPlayerController.h"

#include "HelloWorldWidget.h"
#include "Blueprint/UserWidget.h"

void ACardTestPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	SetShowMouseCursor(true);
	UE_LOG(LogTemp, Warning, TEXT("HelloWorldClass is null? %hs"), HelloWorldClass ? "false" : "true");
	InputComponent->BindKey(EKeys::E, IE_Pressed, this, &ACardTestPlayerController::ShowHelloWorldWidget);
}

void ACardTestPlayerController::ShowHelloWorldWidget()
{
	if (!HelloWorldWidget)
	{
		if (HelloWorldClass)
		{
			HelloWorldWidget = CreateWidget<UHelloWorldWidget>(this, HelloWorldClass);
			HelloWorldWidget->AddToViewport();
		}
	}
	else
	{
		HelloWorldWidget->SetTitle("Current Time: " + FDateTime::UtcNow().ToString());
	}
}
