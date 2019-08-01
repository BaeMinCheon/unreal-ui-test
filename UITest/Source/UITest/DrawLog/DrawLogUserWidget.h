// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DrawLogUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API UDrawLogUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void Func01();

	UFUNCTION()
	void Func02();

	UFUNCTION()
	void UpdateLog(FString Message);

	UFUNCTION()
	void FadeOutLog();

	UPROPERTY()
	class UButton* Button01;

	UPROPERTY()
	class UButton* Button02;

	UPROPERTY()
	class UTextBlock* DrawLogText;

	FTimerHandle TimerHandle;
};
