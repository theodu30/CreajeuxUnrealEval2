// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

class USplineComponent;

UCLASS()
class CREAJEUX_UE_EVAL1_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<USceneComponent> Root;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<USplineComponent> SplineComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float PlatformSpeed = 1.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY()
	float ElapsedTime = 0.f;
	
	UPROPERTY()
	bool bGoBackward = false;
};
