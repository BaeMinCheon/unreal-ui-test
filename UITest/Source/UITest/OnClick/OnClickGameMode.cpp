// Fill out your copyright notice in the Description page of Project Settings.

#include "OnClickGameMode.h"
#include "OnClickPlayerController.h"

AOnClickGameMode::AOnClickGameMode()
{
	PlayerControllerClass = AOnClickPlayerController::StaticClass();
}
