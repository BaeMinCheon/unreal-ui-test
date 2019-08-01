// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawLogPlayerController.h"
#include "ConstructorHelpers.h"
#include "DrawLogUserWidget.h"

ADrawLogPlayerController::ADrawLogPlayerController()
{
	static ConstructorHelpers::FClassFinder<UDrawLogUserWidget> UI_TOGGLE(TEXT("/Game/Resources/Widgets/03_DrawLog/DrawLog.DrawLog_C"));
	if (UI_TOGGLE.Succeeded())
	{
		WidgetClass = UI_TOGGLE.Class;
	}
}

void ADrawLogPlayerController::BeginPlay()
{
	Super::BeginPlay();

	Widget = CreateWidget<UDrawLogUserWidget>(this, WidgetClass);
}

void ADrawLogPlayerController::ToggleWidget()
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