// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "Spike.generated.h"

/**
 * 
 */
UCLASS()
class CREAJEUX_UE_EVAL1_API ASpike : public AObstacle
{
	GENERATED_BODY()

public:
	ASpike();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<UBoxComponent> DetectorComponent;

protected:
	UFUNCTION()
	void OnPlayerOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                     int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnPlayerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SpikeWaitingTime = .5f;
	
private:
	UPROPERTY()
	bool bOut = false;
	
	UPROPERTY()
	bool bIsPlayerIn = false;
	
	UPROPERTY()
	bool bWaiting = false;
	
	UPROPERTY()
	FTimerHandle FSpikeWaiting;
	
	UFUNCTION()
	void ExecuteAfterWaiting();
	
	UPROPERTY()
	FVector TargetPosition;
	
};
