// Fill out your copyright notice in the Description page of Project Settings.

#include "ToggleGameMode.h"
#include "TogglePlayerController.h"

AToggleGameMode::AToggleGameMode()
{
	PlayerControllerClass = ATogglePlayerController::StaticClass();
}
