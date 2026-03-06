// Fill out your copyright notice in the Description page of Project Settings.


#include "BoostPlatform.h"

#include "PlayerCharacter.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
ABoostPlatform::ABoostPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(FName("Root"));
	RootComponent = Root;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	StaticMesh->SetupAttachment(Root);
	
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(FName("ArrowComponent"));
	ArrowComponent->SetupAttachment(Root);
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(FName("BoxComponent"));
	BoxComponent->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ABoostPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ABoostPlatform::OnBeginOverlap);
}

// Called every frame
void ABoostPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABoostPlatform::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		if (APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor))
		{
			const FVector BoostVector = BoostStrength * ArrowComponent->GetForwardVector() + 100.f * FVector::UpVector;
			
			PlayerCharacter->LaunchCharacter(BoostVector, bOverrideXYMovement, bOverrideZMovement);
		}
	}
}

