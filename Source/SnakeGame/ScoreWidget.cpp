// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"
#include "Components/TextBlock.h"
#include "SnakeBase.h"

void UScoreWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ASnakeBase* SnakeBase = Cast<ASnakeBase>(Snake);
	if (IsValid(SnakeBase))
	{
		SnakeBase->OnScoreChanged.AddDynamic(this, &ThisClass::OnScoreChanged);
	}
}

void UScoreWidget::OnScoreChanged(int32 NewScore)
{
	check(ScoreTextBlock);
	ScoreTextBlock->SetText(FText::AsNumber(NewScore));
}
