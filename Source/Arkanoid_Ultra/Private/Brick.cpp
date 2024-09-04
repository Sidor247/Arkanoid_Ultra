#include "Brick.h"
#include <Ball.h>
#include <Kismet/KismetSystemLibrary.h>

ABrick::ABrick()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	OnActorHit.AddDynamic(this, &ABrick::OnBallHit);
}

void ABrick::OnBallHit(AActor*, AActor* OtherActor, FVector, const FHitResult&)
{
	if (dynamic_cast<ABall*>(OtherActor))
		Destroy();
}