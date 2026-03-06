// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyItem.h"

#include "Door.h"
#include "EngineUtils.h"
#include "PlatformerGameMode.h"

AKeyItem::AKeyItem()
{
	MainMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AKeyItem::BeginPlay()
{
	Super::BeginPlay();
	
	SetEnabled(true);
	
	UWorld* World = GetWorld();
	if (World == nullptr) return;
	
	GameMode = Cast<APlatformerGameMode>(World->GetAuthGameMode());
	if (GameMode == nullptr) return;
	
	GameMode->OnReset.AddDynamic(this, &AKeyItem::OnReset);
	
	for (FActorIterator It(World, ADoor::StaticClass()); It; ++It)
	{
		if (!*It || *It == this)
		{
			continue;
		}
		
		ADoor* Door = Cast<ADoor>(*It);
		
		if (!Door || Door->bIsLinked)
		{
			continue;
		}
		
		Door->bIsLinked = true;
		TargetDoor = Door;
		
		Door->SetDoorState(false);
	}
}

void AKeyItem::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
						   int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		GameMode->SetKeyFound();
		SetEnabled(false);
		
		if (TargetDoor)
		{
			TargetDoor->SetDoorState(true);
		}
	}
}

void AKeyItem::OnReset()
{
	SetEnabled(true);
	
	if (TargetDoor)
	{
		TargetDoor->SetDoorState(false);
	}
}

