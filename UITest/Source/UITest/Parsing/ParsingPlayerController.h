// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ParsingPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API AParsingPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AParsingPlayerController();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION(Exec)
	void ToggleWidget();

	UPROPERTY()
	TSubclassOf<class UParsingUserWidget> WidgetClass;

	UPROPERTY()
	class UParsingUserWidget* Widget;
};
