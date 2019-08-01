// Fill out your copyright notice in the Description page of Project Settings.

#include "ParsingUserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Public/TimerManager.h"
#include "Engine/World.h"

void UParsingUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	FunctionMap.Add(TEXT("Func01"), &UParsingUserWidget::Func01);
	FunctionMap.Add(TEXT("Func02"), &UParsingUserWidget::Func02);

	Buttons.Add(Cast<UButton>(GetWidgetFromName(*NamePairs[0].Button)));
	check(Buttons[0] != nullptr);
	Buttons[0]->OnClicked.AddDynamic(this, FunctionMap[NamePairs[0].Function]);
	UTextBlock* Button01Text = Cast<UTextBlock>(Buttons[0]->GetChildAt(0));
	check(Button01Text != nullptr);
	Button01Text->SetText(FText::FromString(NamePairs[0].Function));

	Buttons.Add(Cast<UButton>(GetWidgetFromName(*NamePairs[1].Button)));
	check(Buttons[1] != nullptr);
	Buttons[1]->OnClicked.AddDynamic(this, FunctionMap[NamePairs[1].Function]);
	UTextBlock* Button02Text = Cast<UTextBlock>(Buttons[1]->GetChildAt(0));
	check(Button02Text != nullptr);
	Button02Text->SetText(FText::FromString(NamePairs[1].Function));

	DrawLogText = Cast<UTextBlock>(GetWidgetFromName(*NamePairs[1].Function));
	check(DrawLogText != nullptr);
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