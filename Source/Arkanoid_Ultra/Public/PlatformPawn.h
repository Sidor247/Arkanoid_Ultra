#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <EnhancedInputLibrary.h>
#include <HUDWidgetBase.h>
#include "PlatformPawn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathEvent);

UCLASS()
class ARKANOID_ULTRA_API APlatformPawn : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category = "Editables") UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditInstanceOnly, Category = "Editables") TSubclassOf<class ABall> BallClass;

	UPROPERTY(EditInstanceOnly, Category = "Editables") double Speed = 500.0;

	UPROPERTY(EditInstanceOnly, Category = "Editables") double BallOffset = 100.0;

	UPROPERTY(EditInstanceOnly, Category = "Editables") int RemainingBalls = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI") TSubclassOf<UHUDWidgetBase> WidgetClass;

	UPROPERTY(BlueprintAssignable, Category = "Custom Events") FOnDeathEvent OnDeathEvent;
	UFUNCTION(BlueprintCallable, Category = "Custom Events") void TriggerOnDeathEvent();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconsds) override;

	APlatformPawn();

	void Move(float AxisValue);
	void ReleaseBall();
	void OnBallDestroy();

private:
	ABall* ballToRelease = nullptr;
	UPROPERTY() UHUDWidgetBase* hudInstance = nullptr;
	void spawnNewBall();
};