#pragma once

#include "CoreMinimal.h"
#include "Food.h"
#include "Interectable.h"
#include "FoodBonuse.generated.h"

/**
 * 
 */
UCLASS()
class SNAKEGAME_API AFoodBonuse : public AFood
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFoodBonuse();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact(AActor* Interactor, bool bIsHead) override;

	void DelFood(AActor* Death, AActor* ScoreBlock, AActor* Food, AActor* FoodBonuse);
};
