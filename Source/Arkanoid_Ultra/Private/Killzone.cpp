// Fill out your copyright notice in the Description page of Project Settings.


#include "Killzone.h"
#include <Components/BoxComponent.h>
#include <Ball.h>
#include <PlatformPawn.h>

// Sets default values
AKillzone::AKillzone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UBoxComponent* box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	box->InitBoxExtent(FVector(50.0));
	RootComponent = box;
	box->OnComponentBeginOverlap.AddDynamic(this, &AKillzone::OnEnter);
}

// Called when the game starts or when spawned
void AKillzone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKillzone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKillzone::OnEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult) {
	if (ABall* ball = Cast<ABall>(OtherActor)) {
		ball->Destroy();
		auto platformPawn = Cast<APlatformPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (platformPawn) {
			platformPawn->OnBallDestroy();
		}
	}
}

