#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class ARKANOID_ULTRA_API ABall : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditInstanceOnly, Category = "Editables") UStaticMeshComponent* StaticMesh = nullptr;
	UPROPERTY(EditInstanceOnly, Category = "Editables") double Speed = 500.0;

	ABall();

public:
	virtual void Tick(float DeltaTime) override;

private:
	FVector2D direction;
	FHitResult outSweepHitResult;
};
