// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interectable.h"
#include "DeathPlayer.generated.h"


UCLASS()
class SNAKEGAME_API ADeathPlayer : public AActor, public IInterectable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeathPlayer();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Interact(AActor* Interactor, bool IsHead) override;


};
