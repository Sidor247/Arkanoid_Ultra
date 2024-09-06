#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUDWidgetBase.generated.h"

/**
 *
 */
UCLASS()
class ARKANOID_ULTRA_API UHUDWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "UI") FString LivesText;
	UPROPERTY(BlueprintReadWrite, Category = "UI") FString ScoreText;

	UFUNCTION() void SetLives(int Lives);
	UFUNCTION() void SetScore(int Score);
};
