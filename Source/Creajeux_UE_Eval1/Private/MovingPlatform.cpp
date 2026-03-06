// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

#include "Components/SplineComponent.h"


// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(Root);

	SplineComponent = CreateDefaultSubobject<USplineComponent>("SplineComponent");
	SplineComponent->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SplineComponent->IsClosedLoop())
	{
		ElapsedTime += PlatformSpeed * DeltaTime;
		
		if (ElapsedTime >= SplineComponent->Duration)
		{
			ElapsedTime = 0.f;
		}
	}
	else
	{
		if (!bGoBackward)
		{
			ElapsedTime += PlatformSpeed * DeltaTime;
			if (ElapsedTime >= SplineComponent->Duration)
			{
				ElapsedTime = SplineComponent->Duration;
				bGoBackward = true;
			}
		}
		else
		{
			ElapsedTime -= PlatformSpeed * DeltaTime;
			if (ElapsedTime <= 0)
			{
				ElapsedTime = 0.f;
				bGoBackward = false;
			}
		}
	}
	
	FVector PlatformLocation = SplineComponent->GetLocationAtTime(ElapsedTime, ESplineCoordinateSpace::Local);
	
	StaticMeshComponent->SetRelativeLocation(PlatformLocation, false, nullptr, ETeleportType::TeleportPhysics);
}
