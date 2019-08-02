// Fill out your copyright notice in the Description page of Project Settings.

#include "ParsingGameMode.h"
#include "ParsingPlayerController.h"

AParsingGameMode::AParsingGameMode()
{
	PlayerControllerClass = AParsingPlayerController::StaticClass();
}