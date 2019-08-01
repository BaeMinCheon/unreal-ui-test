// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawLogUserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Public/TimerManager.h"
#include "Engine/World.h"

void UDrawLogUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button01 = Cast<UButton>(GetWidgetFromName(TEXT("Button_01")));
	check(Button01 != nullptr);
	Button01->OnClicked.AddDynamic(this, &UDrawLogUserWidget::Func01);
	UTextBlock* Button01Text = Cast<UTextBlock>(Button01->GetChildAt(0));
	check(Button01Text != nullptr);
	Button01Text->SetText(FText::FromString(TEXT("Func01")));

	Button02 = Cast<UButton>(GetWidgetFromName(TEXT("Button_02")));
	check(Button02 != nullptr);
	Button02->OnClicked.AddDynamic(this, &UDrawLogUserWidget::Func02);
	UTextBlock* Button02Text = Cast<UTextBlock>(Button02->GetChildAt(0));
	check(Button02Text != nullptr);
	Button02Text->SetText(FText::FromString(TEXT("Func02")));

	DrawLogText = Cast<UTextBlock>(GetWidgetFromName(TEXT("DrawLog_Text")));
	check(DrawLogText != nullptr);
}

void UDrawLogUserWidget::Func01()
{
	UE_LOG(LogTemp, Warning, TEXT("Func01 Executed !"));

	UpdateLog(TEXT("Func01"));
}

void UDrawLogUserWidget::Func02()
{
	UE_LOG(LogTemp, Warning, TEXT("Func02 Executed !"));

	UpdateLog(TEXT("Func02"));
}

void UDrawLogUserWidget::UpdateLog(FString Message)
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UDrawLogUserWidget::FadeOutLog, 0.1f, false);
	DrawLogText->SetText(FText::FromString(Message));
	DrawLogText->SetOpacity(1.0f);
}

void UDrawLogUserWidget::FadeOutLog()
{
	float CurrentOpacity = DrawLogText->ColorAndOpacity.GetSpecifiedColor().A;
	DrawLogText->SetOpacity(CurrentOpacity - 0.02f);

	if (DrawLogText->GetRenderOpacity() <= 0.0f)
	{
		DrawLogText->SetText(FText::FromString(TEXT("")));
	}
	else
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UDrawLogUserWidget::FadeOutLog, 0.1f, false);
	}
}
