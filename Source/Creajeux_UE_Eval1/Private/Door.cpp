// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	if (!StaticMeshComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("StaticMeshComponent is null"));
		return;
	}
	StaticMeshComponent->SetupAttachment(RootComponent);

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("DoorMesh");
	if (!DoorMesh)
	{
		UE_LOG(LogTemp, Error, TEXT("DoorMesh is null"));
		return;
	}
	DoorMesh->SetupAttachment(StaticMeshComponent);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	TargetRotation = FRotator::ZeroRotator;
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator Rotation = FMath::Lerp(DoorMesh->GetRelativeRotation(), TargetRotation, 10.f * DeltaTime);

	DoorMesh->SetRelativeRotation(Rotation);
}

void ADoor::SetDoorState(bool bOpen)
{
	IsOpen = bOpen;
	TargetRotation = IsOpen ? FRotator(0, -90, 0) : FRotator::ZeroRotator;
}
