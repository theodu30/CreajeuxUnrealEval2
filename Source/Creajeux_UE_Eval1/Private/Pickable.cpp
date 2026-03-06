// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickable.h"

#include "Components/SphereComponent.h"

// Sets default values
APickable::APickable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(FName("SphereComponent"));
	if (SphereComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("SphereComponent is null"));
		return;
	}
	RootComponent = SphereComponent;

	MainMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("MainMeshComponent"));
	if (MainMeshComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("StaticMeshComponent is null"));
		return;
	}
	MainMeshComponent->SetupAttachment(RootComponent);
	MainMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void APickable::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                               UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                               const FHitResult& SweepResult)
{
}

// Called when the game starts or when spawned
void APickable::BeginPlay()
{
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &APickable::OnBeginOverlap);
}

// Called every frame
void APickable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AddActorLocalRotation(FRotator(0.0f, 90.f * DeltaTime, 0.0f));
}

void APickable::SetEnabled(bool bEnable)
{
	SphereComponent->SetGenerateOverlapEvents(bEnable);
	MainMeshComponent->SetVisibility(bEnable);
}
