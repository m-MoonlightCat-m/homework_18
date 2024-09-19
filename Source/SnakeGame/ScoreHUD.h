// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ScoreHUD.generated.h"


UCLASS(Abstract)
class SNAKEGAME_API AScoreHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> HUDWidget;
};
