// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"
#include "PlatformerGameMode.h"
#include "Components/SphereComponent.h"

AChest::AChest()
{
	MainMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	ProximityComponent = CreateDefaultSubobject<USphereComponent>(FName("ProximityComponent"));
	ProximityComponent->SetupAttachment(RootComponent);
	
	LidMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("LidMeshComponent"));
	LidMeshComponent->SetupAttachment(MainMeshComponent);
	LidMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	CoinMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("CoinMeshComponent"));
	CoinMeshComponent->SetupAttachment(MainMeshComponent);
	CoinMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AChest::BeginPlay()
{
	Super::BeginPlay();
	
	SetEnabled(true);
	
	UWorld* World = GetWorld();
	if (World == nullptr) return;
	
	GameMode = Cast<APlatformerGameMode>(World->GetAuthGameMode());
	if (GameMode == nullptr) return;
	
	GameMode->AddToCoinTotal(10);
	
	GameMode->OnReset.AddDynamic(this, &AChest::OnReset);
	
	ProximityComponent->OnComponentBeginOverlap.AddDynamic(this, &AChest::OnProximityOverlap);
	ProximityComponent->OnComponentEndOverlap.AddDynamic(this, &AChest::OnProximityEndOverlap);
}

void AChest::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	FRotator TargetRotation = FMath::Lerp(LidMeshComponent->GetRelativeRotation(), TargetLidRotation, 10.f * DeltaSeconds);
	
	LidMeshComponent->SetRelativeRotation(TargetRotation);
}

void AChest::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                            int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		GameMode->AddCoin(10);
		SetEnabled(false);
	}
}

void AChest::OnProximityOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	TargetLidRotation = FRotator(0, 0, -45);
}

void AChest::OnProximityEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	TargetLidRotation = FRotator(0, 0, 0);
}

void AChest::OnReset()
{
	SetEnabled(true);
}

void AChest::SetEnabled(bool bEnable)
{
	Super::SetEnabled(bEnable);
	
	ProximityComponent->SetGenerateOverlapEvents(bEnable);
	LidMeshComponent->SetVisibility(bEnable);
	CoinMeshComponent->SetVisibility(bEnable);
}

