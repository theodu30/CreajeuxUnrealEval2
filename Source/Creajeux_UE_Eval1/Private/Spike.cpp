// Fill out your copyright notice in the Description page of Project Settings.


#include "Spike.h"

#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"
#include "Misc/MapErrors.h"

ASpike::ASpike()
{
	DetectorComponent = CreateDefaultSubobject<UBoxComponent>("DetectorComponent");
	DetectorComponent->SetupAttachment(StaticMesh);
}

void ASpike::OnPlayerOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                             const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		bIsPlayerIn = true;
		if (!bWaiting)
		{
			bWaiting = true;
			if (UWorld* World = GetWorld())
			{
				World->GetTimerManager().SetTimer(FSpikeWaiting, this, &ASpike::ExecuteAfterWaiting, SpikeWaitingTime);
			}
		}
	}
}

void ASpike::OnPlayerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		bIsPlayerIn = false;
		if (!bWaiting)
		{
			bWaiting = true;
			if (UWorld* World = GetWorld())
			{
				World->GetTimerManager().SetTimer(FSpikeWaiting, this, &ASpike::ExecuteAfterWaiting, SpikeWaitingTime);
			}
		}
	}
}

void ASpike::BeginPlay()
{
	Super::BeginPlay();

	DetectorComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpike::OnPlayerOverlap);
	DetectorComponent->OnComponentEndOverlap.AddDynamic(this, &ASpike::OnPlayerEndOverlap);
	
	TargetPosition = PointA->GetRelativeLocation();
}

void ASpike::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	FVector NewLocation = FMath::Lerp(MovingMesh->GetRelativeLocation(), TargetPosition, 10.f * DeltaSeconds);
	
	MovingMesh->SetRelativeLocation(NewLocation);
}

void ASpike::ExecuteAfterWaiting()
{
	bWaiting = false;
	bOut = !bOut;
	
	TargetPosition = bOut ? PointB->GetRelativeLocation() : PointA->GetRelativeLocation();
	
	if (bOut && !bIsPlayerIn)
	{
		bWaiting = true;
		if (UWorld* World = GetWorld())
		{
			World->GetTimerManager().SetTimer(FSpikeWaiting, this, &ASpike::ExecuteAfterWaiting, .1f);
			return;
		}
	}
}
