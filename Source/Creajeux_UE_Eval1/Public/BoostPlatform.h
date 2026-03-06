// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoostPlatform.generated.h"

class UBoxComponent;
class UArrowComponent;

UCLASS()
class CREAJEUX_UE_EVAL1_API ABoostPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABoostPlatform();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<UArrowComponent> ArrowComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<UBoxComponent> BoxComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bOverrideXYMovement = true;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bOverrideZMovement = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float BoostStrength = 1000.f;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
