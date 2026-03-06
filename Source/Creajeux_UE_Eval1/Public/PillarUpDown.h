// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "PillarUpDown.generated.h"

/**
 * 
 */
UCLASS()
class CREAJEUX_UE_EVAL1_API APillarUpDown : public AObstacle
{
	GENERATED_BODY()
	
public:
	APillarUpDown();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<UStaticMeshComponent> SecondStaticMesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed = 1.f;
	
protected:
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaSeconds) override;
	
private:
	UPROPERTY()
	float Alpha;
	
	UPROPERTY()
	bool bToB;
	
};
