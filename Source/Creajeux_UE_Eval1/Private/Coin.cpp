// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "PlatformerGameMode.h"

ACoin::ACoin()
{
	MainMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
	SetEnabled(true);
	
	UWorld* World = GetWorld();
	if (World == nullptr) return;
	
	GameMode = Cast<APlatformerGameMode>(World->GetAuthGameMode());
	if (GameMode == nullptr) return;
	
	GameMode->AddToCoinTotal(1);
	
	GameMode->OnReset.AddDynamic(this, &ACoin::OnReset);
}

void ACoin::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                           int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		GameMode->AddCoin(1);
		SetEnabled(false);
	}
}

void ACoin::OnReset()
{
	SetEnabled(true);
}
