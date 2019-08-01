// Fill out your copyright notice in the Description page of Project Settings.

#include "TogglePlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "ToggleUserWidget.h"

ATogglePlayerController::ATogglePlayerController()
{
	static ConstructorHelpers::FClassFinder<UToggleUserWidget> UI_TOGGLE(TEXT("/Game/Resources/Widgets/01_Toggle/Toggle.Toggle_C"));
	if (UI_TOGGLE.Succeeded())
	{
		WidgetClass = UI_TOGGLE.Class;
	}
}

void ATogglePlayerController::BeginPlay()
{
	Super::BeginPlay();

	Widget = CreateWidget<UToggleUserWidget>(this, WidgetClass);
}

void ATogglePlayerController::ToggleWidget()
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
