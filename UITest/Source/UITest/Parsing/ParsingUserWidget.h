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
	FString ButtonName;
	
	UPROPERTY()
	FString FunctionName;
	
	UPROPERTY()
	FString DisplayName;
};

/**
 * 
 */
UCLASS(config=Widget)
class UITEST_API UParsingUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UParsingUserWidget(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(config)
	TArray<struct FNamePair> NamePairs;

	typedef void (UParsingUserWidget::*FunctionPtrType) (void);
	TMap<FString, FunctionPtrType> FunctionMap;

protected:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void Init();

	UFUNCTION()
	void UpdateLog(FString Message);

	UFUNCTION()
	void FadeOutLog();

	UFUNCTION()
	void Reload();

	UFUNCTION()
	void Func01();

	UFUNCTION()
	void Func02();

	UPROPERTY()
	TArray<class UButton*> Buttons;

	UPROPERTY()
	class UTextBlock* DrawLogText;

	FTimerHandle TimerHandle;

	class AParsingPlayerController* PlayerController;
};