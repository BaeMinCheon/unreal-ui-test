// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawLogGameMode.h"
#include "DrawLogPlayerController.h"

ADrawLogGameMode::ADrawLogGameMode()
{
	PlayerControllerClass = ADrawLogPlayerController::StaticClass();
}
