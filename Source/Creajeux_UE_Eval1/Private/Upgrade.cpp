// Fill out your copyright notice in the Description page of Project Settings.


#include "Upgrade.h"
#include "PlatformerGameMode.h"

AUpgrade::AUpgrade()
{
	MainMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AUpgrade::BeginPlay()
{
	Super::BeginPlay();
	
	SetEnabled(true);
	
	UWorld* World = GetWorld();
	if (World == nullptr) return;
	
	GameMode = Cast<APlatformerGameMode>(World->GetAuthGameMode());
	if (GameMode == nullptr) return;
	
	GameMode->AddToUpgradeTotal(1);
	
	GameMode->OnReset.AddDynamic(this, &AUpgrade::OnReset);
}

void AUpgrade::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
						   int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		GameMode->AddUpgrade();
		SetEnabled(false);
	}
}

void AUpgrade::OnReset()
{
	SetEnabled(true);
}

