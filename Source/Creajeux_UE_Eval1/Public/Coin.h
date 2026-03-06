// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickable.h"
#include "Coin.generated.h"

class APlatformerGameMode;

/**
 * 
 */
UCLASS()
class CREAJEUX_UE_EVAL1_API ACoin : public APickable
{
	GENERATED_BODY()

public:
	ACoin();
	
	virtual void BeginPlay() override;

	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                            const FHitResult& SweepResult) override;
	
private:
	UPROPERTY()
	TObjectPtr<APlatformerGameMode> GameMode;

	UFUNCTION()
	void OnReset();
};
