// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "PillarLeftRight.generated.h"

/**
 * 
 */
UCLASS()
class CREAJEUX_UE_EVAL1_API APillarLeftRight : public AObstacle
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed = 1.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool RandomStart = false;
	
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
