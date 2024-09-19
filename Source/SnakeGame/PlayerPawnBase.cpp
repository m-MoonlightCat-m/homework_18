// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnBase.h"
#include "Camera/CameraComponent.h"
#include "SnakeBase.h"
#include "Components/InputComponent.h"
#include "Food.h"
#include "FoodBonuse.h"

// Sets default values
APlayerPawnBase::APlayerPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	RootComponent = PawnCamera;
}

// Called when the game starts or when spawned
void APlayerPawnBase::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(-90, 0, 0));
	CreateSnakeActor();
	AddRandomFood();
}

// Called every frame
void APlayerPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SnakeActor->Score < 15)
	{
		AmountMax = 5;
	}
	else if (SnakeActor->Score > 15 && SnakeActor->Score < 25)
	{
		AmountMax = 3;
	}
	else if (SnakeActor->Score > 25)
	{
		AmountMax = 0;
	}

	if (SnakeActor->AmountFood < AmountMax)
	{
		AddRandomFood();
		SnakeActor->AmountFood++;
	}
}

// Called to bind functionality to input
void APlayerPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawnBase::HandlePlayerVerticalInput);
	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawnBase::HandlePlayerHorizontalInput);
}

void APlayerPawnBase::CreateSnakeActor()
{
	SnakeActor = GetWorld()->SpawnActor<ASnakeBase>(SnakeActorClass, FTransform());
}

void APlayerPawnBase::HandlePlayerVerticalInput(float value)
{
	if (IsValid(SnakeActor))
	{
		if (value > 0 && SnakeActor->LastMoveDorection!=EMovementDirection::DOWN)
		{
			SnakeActor->LastMoveDorection = EMovementDirection::UP;
		}
		else if (value < 0 && SnakeActor->LastMoveDorection!=EMovementDirection::UP)
		{
			SnakeActor->LastMoveDorection = EMovementDirection::DOWN;
		}
	}
}

void APlayerPawnBase::HandlePlayerHorizontalInput(float value)
{
	if (IsValid(SnakeActor))
	{
		if (value > 0 && SnakeActor->LastMoveDorection!=EMovementDirection::LEFT)
		{
			SnakeActor->LastMoveDorection = EMovementDirection::RIGHT;
		}
		else if (value < 0 && SnakeActor->LastMoveDorection!=EMovementDirection::RIGHT)
		{
			SnakeActor->LastMoveDorection = EMovementDirection::LEFT;
		}
	}
}

int32 APlayerPawnBase::GetScore()
{
	return SnakeActor->Score;
}

void APlayerPawnBase::AddRandomFood()
{
	FRotator StratPointRotation = FRotator(0, 0, 0);

	float SpawnX = FMath::FRandRange(minX, maxX);
	float SpawnY = FMath::FRandRange(minY, maxY);

	FVector StartPoint = FVector(SpawnX, SpawnY, spawnZ);

	int scale = rand() % 100;

	if (scale < 50)
	{
		GetWorld()->SpawnActor<AFood>(FoodActorClass, FTransform(StratPointRotation, StartPoint));
	}
	else if (scale > 50)
	{
		GetWorld()->SpawnActor<AFoodBonuse>(FoodBonuseActorClass, FTransform(StratPointRotation, StartPoint));
	}
 	

}


