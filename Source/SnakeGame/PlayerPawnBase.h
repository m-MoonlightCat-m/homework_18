// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawnBase.generated.h"

class UCameraComponent;
class ASnakeBase;
class AFood;
class AFoodBonuse;

UCLASS()
class SNAKEGAME_API APlayerPawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawnBase();
	
	UPROPERTY(BlueprintReadWrite)
	UCameraComponent* PawnCamera;

	UPROPERTY(BlueprintReadWrite)
	ASnakeBase* SnakeActor;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASnakeBase> SnakeActorClass;

	UPROPERTY(BlueprintReadWrite)
	AFood* FoodActor;

	UPROPERTY(BlueprintReadWrite)
	AFoodBonuse* FoodBonuseActor;
	

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AFood> FoodActorClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AFoodBonuse> FoodBonuseActorClass;
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void CreateSnakeActor();

	UFUNCTION()
	void HandlePlayerVerticalInput(float value);
	UFUNCTION()
	void HandlePlayerHorizontalInput(float value);

	UFUNCTION(BlueprintCallable)
	int32 GetScore();

	float minX = -600.f; float maxX = 600.f;
	float minY = -1200.f; float maxY = 1200.f;
	float spawnZ = 35.f;
	int32 AmountMax;

	int32 GameMod = 0;

	UFUNCTION (BlueprintCallable)
	int32 GetGameMod() const { return GameMod; }

	void AddRandomFood();
};
