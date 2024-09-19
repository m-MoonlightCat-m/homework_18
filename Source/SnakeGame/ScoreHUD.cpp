// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreHUD.h"
#include "Blueprint/UserWidget.h"

void AScoreHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* UserWidget = CreateWidget <UUserWidget>(GetOwningPlayerController(), HUDWidget);
	if (UserWidget)
	{
		UserWidget->AddToViewport();
	}
}
