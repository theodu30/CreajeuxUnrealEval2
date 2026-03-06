// Fill out your copyright notice in the Description page of Project Settings.


#include "PillarUpDown.h"

#include "Components/BillboardComponent.h"

APillarUpDown::APillarUpDown()
{
	SecondStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("SecondStaticMesh");
	if (!StaticMesh)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create SecondStaticMesh"));
		return;
	}
	SecondStaticMesh->SetupAttachment(Root);
}

void APillarUpDown::BeginPlay()
{
	Super::BeginPlay();
	
	Alpha = FMath::RandRange(0.f, 1.f);
	
	bToB = FMath::RandBool();
}

void APillarUpDown::Tick(float DeltaSeconds)
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

