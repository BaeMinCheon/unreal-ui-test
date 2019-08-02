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

UCLASS()
class UButtonProxy : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ExecCommand();

	UFUNCTION()
	void UpdateLog(FString Message);

	UFUNCTION()
	void FadeOutLog();

	FString Command;
	FTimerHandle TimerHandle;
	class UTextBlock* DrawLogText;
	class AParsingPlayerController* PlayerController;
};

/**
 * 
 */
UCLASS(config=Widget)
class UITEST_API UParsingUserWidget : public UUserWidget
{
	GENERATED_BODY()
		
public:
	void Reload();

protected:
	virtual void NativeConstruct() override;
	void Parse();
	void Load();

private:
	UPROPERTY(config)
	TArray<struct FNamePair> NamePairs;
	
	FString ConfigSection;
	FString ConfigFile;
	TArray<class UButton*> Buttons;
	TArray<class UButtonProxy*> Proxies;
	class UTextBlock* DrawLogText;
	FTimerHandle TimerHandle;
	class AParsingPlayerController* PlayerController;
};