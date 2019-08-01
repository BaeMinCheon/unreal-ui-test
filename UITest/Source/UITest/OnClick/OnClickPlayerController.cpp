// Fill out your copyright notice in the Description page of Project Settings.

#include "OnClickPlayerController.h"
#include "ConstructorHelpers.h"
#include "OnClickUserWidget.h"

AOnClickPlayerController::AOnClickPlayerController()
{
	static ConstructorHelpers::FClassFinder<UOnClickUserWidget> UI_TOGGLE(TEXT("/Game/Resources/Widgets/02_OnClick/OnClick.OnClick_C"));
	if (UI_TOGGLE.Succeeded())
	{
		WidgetClass = UI_TOGGLE.Class;
	}
}

void AOnClickPlayerController::BeginPlay()
{
	Super::BeginPlay();

	Widget = CreateWidget<UOnClickUserWidget>(this, WidgetClass);
}

void AOnClickPlayerController::ToggleWidget()
{
	if (Widget->IsInViewport())
	{
		Widget->RemoveFromViewport();
	}
	else
	{
		Widget->AddToViewport();
	}
}