// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WinTrigger.generated.h"

class UBoxComponent;

UCLASS()
class CREAJEUX_UE_EVAL1_API AWinTrigger : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWinTrigger();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<UBoxComponent> BoxComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
