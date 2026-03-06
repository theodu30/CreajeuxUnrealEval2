// Fill out your copyright notice in the Description page of Project Settings.


#include "PillarLeftRight.h"

#include "Components/BillboardComponent.h"

void APillarLeftRight::BeginPlay()
{
	Super::BeginPlay();
	
	Alpha = FMath::RandRange(0.f, 1.f);
	
	bToB = FMath::RandBool();
}

void APillarLeftRight::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	FVector NewLocation = FMath::Lerp(PointA->GetRelativeLocation(), PointB->GetRelativeLocation(), Alpha);
	
	MovingMesh->SetRelativeLocation(NewLocation);
	
	if (bToB)
	{
		Alpha += Speed * DeltaSeconds;
		if (Alpha >= 1.f)
		{
			Alpha = 1.f;
			bToB = false;
		}
	}
	else
	{
		Alpha -= Speed * DeltaSeconds;
		if (Alpha <= 0.f)
		{
			Alpha = 0.f;
			bToB = true;
		}
	}
}
