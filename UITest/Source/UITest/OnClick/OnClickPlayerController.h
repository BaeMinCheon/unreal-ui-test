// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "OnClickPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API AOnClickPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AOnClickPlayerController();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION(Exec)
	void ToggleWidget();

	UPROPERTY()
	TSubclassOf<class UOnClickUserWidget> WidgetClass;

	UPROPERTY()
	class UOnClickUserWidget* Widget;
};
