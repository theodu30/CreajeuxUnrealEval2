// Fill out your copyright notice in the Description page of Project Settings.


#include "KillBox.h"

#include "PlayerCharacter.h"
#include "Components/BoxComponent.h"

// Sets default values
AKillBox::AKillBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	if (BoxComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("BoxComponent is null"));
		return;
	}
	RootComponent = BoxComponent;
}

void AKillBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		if (APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor))
		{
			PlayerCharacter->KillPlayer();
		}
	}
}

// Called when the game starts or when spawned
void AKillBox::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AKillBox::OnBeginOverlap);
}

// Called every frame
void AKillBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

