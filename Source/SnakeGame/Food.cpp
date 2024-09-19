// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "Components/StaticMeshComponent.h"
#include"SnakeBase.h"
#include "Interectable.h"
#include "DeathPlayer.h"
#include "FoodBonuse.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AFood::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			Snake->AddSnakeElement();
			Destroy(true, true);
			Snake->Score++;
			Snake->OnScoreChanged.Broadcast(Snake->Score);
			Snake->AmountFood--;
		}
	}
	else
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		Destroy(true, true);
		Snake->AmountFood--;
	}
}

void AFood::DelFood(AActor* Death, AActor* ScoreBlock, AActor* Food, AActor* FoodBonuse)
{
	auto DeathBlock = Cast<ADeathPlayer>(Death);
	auto SnakeScore = Cast<ASnakeBase>(ScoreBlock);
	auto FoodActor = Cast<AFood>(Food);
	auto FoodBonuseActor = Cast<AFoodBonuse>(FoodBonuse);

	if (IsValid(DeathBlock) or IsValid(FoodActor) or IsValid(FoodBonuseActor))
	{
		Destroy(true, true);
		SnakeScore->AmountFood--;
	}
}






