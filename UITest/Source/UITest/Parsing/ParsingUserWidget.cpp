// Fill out your copyright notice in the Description page of Project Settings.

#include "ParsingUserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Public/TimerManager.h"
#include "Engine/World.h"
#include "ParsingPlayerController.h"
#include "Misc/Paths.h"
#include "Misc/ConfigCacheIni.h"

UParsingUserWidget::UParsingUserWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FunctionMap.Add(TEXT("Reload"), &UParsingUserWidget::Reload);
	FunctionMap.Add(TEXT("Func01"), &UParsingUserWidget::Func01);
	FunctionMap.Add(TEXT("Func02"), &UParsingUserWidget::Func02);
}

void UParsingUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Init();
}

void UParsingUserWidget::Init()
{
	Buttons.Empty();

	for (int i = 0; i < 2; ++i)
	{
		FName ButtonName(*NamePairs[i].ButtonName);
		Buttons.Add(Cast<UButton>(GetWidgetFromName(ButtonName)));

		FunctionPtrType FunctionPtr = FunctionMap[NamePairs[i].FunctionName];
		FName FunctionName(*NamePairs[i].FunctionName);
		Buttons[i]->OnClicked.Clear();
		Buttons[i]->OnClicked.__Internal_AddDynamic(this, FunctionPtr, FunctionName);

		UTextBlock* Button01Text = Cast<UTextBlock>(Buttons[i]->GetChildAt(0));
		Button01Text->SetText(FText::FromString(NamePairs[i].DisplayName));
	}

	FName TextName(TEXT("DrawLog_Text"));
	DrawLogText = Cast<UTextBlock>(GetWidgetFromName(TextName));
	DrawLogText->SetOpacity(0.0f);

	PlayerController = Cast<AParsingPlayerController>(GetWorld()->GetFirstPlayerController());
}

void UParsingUserWidget::UpdateLog(FString Message)
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UParsingUserWidget::FadeOutLog, 0.1f, false);
	DrawLogText->SetText(FText::FromString(Message));
	DrawLogText->SetOpacity(1.0f);
}

void UParsingUserWidget::FadeOutLog()
{
	float CurrentOpacity = DrawLogText->ColorAndOpacity.GetSpecifiedColor().A;
	DrawLogText->SetOpacity(CurrentOpacity - 0.02f);

	if (DrawLogText->GetRenderOpacity() <= 0.0f)
	{
		DrawLogText->SetText(FText::FromString(TEXT("")));
	}
	else
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UParsingUserWidget::FadeOutLog, 0.1f, false);
	}
}

void UParsingUserWidget::Reload()
{
	UE_LOG(LogTemp, Warning, TEXT("Reload Executed !"));
	UpdateLog(TEXT("Reload"));

	Init();
}

void UParsingUserWidget::Func01()
{
	UE_LOG(LogTemp, Warning, TEXT("Func01 Executed !"));
	UpdateLog(TEXT("Func01"));
}

void UParsingUserWidget::Func02()
{
	UE_LOG(LogTemp, Warning, TEXT("Func02 Executed !"));
	UpdateLog(TEXT("Func02"));
}