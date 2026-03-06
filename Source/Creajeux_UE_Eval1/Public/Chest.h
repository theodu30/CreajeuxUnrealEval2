// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickable.h"
#include "Chest.generated.h"

class APlatformerGameMode;
/**
 * 
 */
UCLASS()
class CREAJEUX_UE_EVAL1_API AChest : public APickable
{
	GENERATED_BODY()

public:
	AChest();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<UStaticMeshComponent> LidMeshComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<UStaticMeshComponent> CoinMeshComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<USphereComponent> ProximityComponent;
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

	
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                            const FHitResult& SweepResult) override;

	UFUNCTION()
	virtual void OnProximityOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                                const FHitResult& SweepResult);

	UFUNCTION()
	void OnProximityEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                           UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	UPROPERTY()
	TObjectPtr<APlatformerGameMode> GameMode;

	UFUNCTION()
	void OnReset();

	UFUNCTION()
	virtual void SetEnabled(bool bEnable) override;
	
	UPROPERTY()
	FRotator TargetLidRotation;
};
