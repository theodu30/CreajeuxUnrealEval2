// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

#include "PlayerCharacter.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(Root);
	
	MovingMesh = CreateDefaultSubobject<UStaticMeshComponent>("MovingMesh");
	MovingMesh->SetupAttachment(Root);
	
	PointA = CreateDefaultSubobject<UBillboardComponent>("PointA");
	PointA->SetupAttachment(Root);
	
	PointB = CreateDefaultSubobject<UBillboardComponent>("PointB");
	PointB->SetupAttachment(Root);
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->SetupAttachment(MovingMesh);
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AObstacle::AObstacle::OnBeginOverlap);
}

void AObstacle::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
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

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

