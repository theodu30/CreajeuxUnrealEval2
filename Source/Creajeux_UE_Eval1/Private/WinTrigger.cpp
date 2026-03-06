// Fill out your copyright notice in the Description page of Project Settings.


#include "WinTrigger.h"

#include "Components/BoxComponent.h"


// Sets default values
AWinTrigger::AWinTrigger()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AWinTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AWinTrigger::OnBeginOverlap);
}

void AWinTrigger::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Yellow, "You win!!");
		}
	}
}

// Called every frame
void AWinTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

