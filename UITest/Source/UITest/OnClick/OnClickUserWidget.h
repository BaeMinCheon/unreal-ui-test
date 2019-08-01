// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OnClickUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API UOnClickUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	
private:
	UFUNCTION()
	void Func();

	UPROPERTY()
	class UButton* OnClickButton;
};
