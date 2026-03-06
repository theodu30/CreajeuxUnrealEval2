// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickable.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class CREAJEUX_UE_EVAL1_API APickable : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickable();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<UStaticMeshComponent> MainMeshComponent;

protected:
	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetEnabled(bool bEnable);
};
