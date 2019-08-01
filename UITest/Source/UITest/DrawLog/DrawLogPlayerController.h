// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DrawLogPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API ADrawLogPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ADrawLogPlayerController();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION(Exec)
	void ToggleWidget();

	UPROPERTY()
	TSubclassOf<class UDrawLogUserWidget> WidgetClass;

	UPROPERTY()
	class UDrawLogUserWidget* Widget;
};
