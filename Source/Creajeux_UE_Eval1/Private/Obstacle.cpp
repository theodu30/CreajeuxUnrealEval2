// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	if (!Root)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create Root"));
		return;
	}
	RootComponent = Root;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	if (!StaticMesh)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create StaticMesh"));
		return;
	}
	StaticMesh->SetupAttachment(Root);
	
	MovingMesh = CreateDefaultSubobject<UStaticMeshComponent>("MovingMesh");
	if (!MovingMesh)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create MovingMesh"));
		return;
	}
	MovingMesh->SetupAttachment(Root);
	
	PointA = CreateDefaultSubobject<UBillboardComponent>("PointA");
	if (!PointA)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create PointA"));
		return;
	}
	PointA->SetupAttachment(Root);
	
	PointB = CreateDefaultSubobject<UBillboardComponent>("PointB");
	if (!PointB)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create PointB"));
		return;
	}
	PointB->SetupAttachment(Root);
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	if (!BoxComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create BoxComponent"));
		return;
	}
	BoxComponent->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

