// Fill out your copyright notice in the Description page of Project Settings.

#include "ParsingUserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Public/TimerManager.h"
#include "ParsingPlayerController.h"
#include "Misc/ConfigCacheIni.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

void UButtonProxy::ExecCommand()
{
	PlayerController->ConsoleCommand(Command, true);
	
	UpdateLog(Command);
}

void UButtonProxy::UpdateLog(FString Message)
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UButtonProxy::FadeOutLog, 0.1f, false);
	DrawLogText->SetText(FText::FromString(Message));
	DrawLogText->SetOpacity(1.0f);
}

void UButtonProxy::FadeOutLog()
{
	float CurrentOpacity = DrawLogText->ColorAndOpacity.GetSpecifiedColor().A;
	DrawLogText->SetOpacity(CurrentOpacity - 0.02f);

	if (DrawLogText->GetRenderOpacity() <= 0.0f)
	{
		DrawLogText->SetText(FText::FromString(TEXT("")));
	}
	else
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UButtonProxy::FadeOutLog, 0.1f, false);
	}
}

void UParsingUserWidget::Reload()
{
	TArray<FString> Lines;
	FFileHelper::LoadFileToStringArray(Lines, *ConfigFile);
	Lines.RemoveAt(0);
	for (int i = 0; i < Lines.Num(); ++i)
	{
		TArray<FString> Parts;
		Lines[i].ParseIntoArray(Parts, TEXT("NamePairs="), true);

		Parts[1] = Parts[1].LeftChop(1);
		Parts[1] = Parts[1].RightChop(1);

		TArray<FString> Names;
		Parts[1].ParseIntoArray(Names, TEXT(","), true);

		Names[0].ParseIntoArray(Parts, TEXT("="), true);
		Parts[1] = Parts[1].LeftChop(1);
		Parts[1] = Parts[1].RightChop(1);
		NamePairs[i].ButtonName = Parts[1];

		Names[1].ParseIntoArray(Parts, TEXT("="), true);
		Parts[1] = Parts[1].LeftChop(1);
		Parts[1] = Parts[1].RightChop(1);
		NamePairs[i].FunctionName = Parts[1];

		Names[2].ParseIntoArray(Parts, TEXT("="), true);
		Parts[1] = Parts[1].LeftChop(1);
		Parts[1] = Parts[1].RightChop(1);
		NamePairs[i].DisplayName = Parts[1];
	}

	Load();
}

void UParsingUserWidget::Load()
{
	Buttons.Empty();
	Proxies.Empty();
	for (int i = 0; i < 2; ++i)
	{
		FName ButtonName(*NamePairs[i].ButtonName);
		Buttons.Add(Cast<UButton>(GetWidgetFromName(ButtonName)));

		Proxies.Add(NewObject<UButtonProxy>(this));
		Proxies[i]->Command = NamePairs[i].FunctionName;
		Proxies[i]->TimerHandle = TimerHandle;
		Proxies[i]->DrawLogText = DrawLogText;
		Proxies[i]->PlayerController = PlayerController;

		Buttons[i]->OnClicked.Clear();
		Buttons[i]->OnClicked.AddDynamic(Proxies[i], &UButtonProxy::ExecCommand);

		UTextBlock* Button01Text = Cast<UTextBlock>(Buttons[i]->GetChildAt(0));
		Button01Text->SetText(FText::FromString(NamePairs[i].DisplayName));
	}
}

void UParsingUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ConfigSection = TEXT("/Script/UITest.ParsingUserWidget");
	ConfigFile = FString::Printf(TEXT("%sDefaultWidget.ini"), *FPaths::SourceConfigDir());
	PlayerController = Cast<AParsingPlayerController>(GetWorld()->GetFirstPlayerController());
	FName TextName(TEXT("DrawLog_Text"));
	DrawLogText = Cast<UTextBlock>(GetWidgetFromName(TextName));
	DrawLogText->SetOpacity(0.0f);

	Load();
}