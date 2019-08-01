// Fill out your copyright notice in the Description page of Project Settings.

#include "OnClickUserWidget.h"
#include "Components/Button.h"

void UOnClickUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	OnClickButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_69")));
	if (OnClickButton != nullptr)
	{
		OnClickButton->OnClicked.AddDynamic(this, &UOnClickUserWidget::Func);
	}
}

void UOnClickUserWidget::Func()
{
	UE_LOG(LogTemp, Warning, TEXT("OnClick Function Executed !"));
}
