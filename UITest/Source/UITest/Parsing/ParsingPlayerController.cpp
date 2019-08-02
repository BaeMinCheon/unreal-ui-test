// Fill out your copyright notice in the Description page of Project Settings.

#include "ParsingPlayerController.h"
#include "ConstructorHelpers.h"
#include "ParsingUserWidget.h"

AParsingPlayerController::AParsingPlayerController()
{
	static ConstructorHelpers::FClassFinder<UParsingUserWidget> UI_TOGGLE(TEXT("/Game/Resources/Widgets/04_Parsing/Parsing.Parsing_C"));
	if (UI_TOGGLE.Succeeded())
	{
		WidgetClass = UI_TOGGLE.Class;
	}
}

void AParsingPlayerController::BeginPlay()
{
	Super::BeginPlay();

	Widget = CreateWidget<UParsingUserWidget>(this, WidgetClass);
}

void AParsingPlayerController::ToggleWidget()
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

void AParsingPlayerController::ReloadWidget()
{
	Widget->Reload();
}