// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class CREAJEUX_UE_EVAL1_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<UStaticMeshComponent> DoorMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY()
	bool IsOpen = false;
	
	UPROPERTY()
	FRotator TargetRotation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetDoorState(bool bOpen);
	
	UPROPERTY()
	bool bIsLinked = false;
};
