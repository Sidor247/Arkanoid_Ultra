#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBrickDestroy);

UCLASS()
class ARKANOID_ULTRA_API ABrick : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category = "Editables") UStaticMeshComponent* StaticMesh = nullptr;
	UPROPERTY(EditInstanceOnly, Category = "Editables") int Lives = 1;
	UPROPERTY(BlueprintAssignable, Category = "Custom Events") FOnBrickDestroy OnBrickDestroyEvent;
	UFUNCTION(BlueprintCallable, Category = "Custom Events") void TriggerOnBrickDestroyEvent();

	ABrick();

private:
	UFUNCTION() void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
	void HandleBallHit();
};