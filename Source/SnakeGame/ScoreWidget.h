
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "ScoreWidget.generated.h"


class UTextBlock;

UCLASS(Abstract)
class SNAKEGAME_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreTextBlock;

private:
	UFUNCTION()
	void OnScoreChanged( int32 NewScore);

public:
	int32 ScoreFood;

	AActor* Snake;
};
