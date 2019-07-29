// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TogglePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API ATogglePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATogglePlayerController();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION(Exec)
	void ToggleWidget();

	UPROPERTY()
	TSubclassOf<class UToggleUserWidget> WidgetClass;

	UPROPERTY()
	class UToggleUserWidget* Widget;
};
