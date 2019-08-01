// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ParsingUserWidget.generated.h"

USTRUCT()
struct FNamePair
{
	GENERATED_BODY()

	UPROPERTY()
	FString Button;

	UPROPERTY()
	FString Function;
};

/**
 * 
 */
UCLASS(config=Widget)
class UITEST_API UParsingUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(config)
	TArray<struct FNamePair> NamePairs;

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
	TArray<class UButton*> Buttons;

	UPROPERTY()
	class UTextBlock* DrawLogText;

	FTimerHandle TimerHandle;
};