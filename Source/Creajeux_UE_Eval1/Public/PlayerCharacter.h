// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;

struct FInputActionValue;

UCLASS()
class CREAJEUX_UE_EVAL1_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<USpringArmComponent> SpringArm;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	TObjectPtr<UCameraComponent> Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Inputs)
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Inputs)
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Inputs)
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Inputs)
	TObjectPtr<UInputMappingContext> InputMappingContext;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION()
	void Move(const FInputActionValue& InputActionValue);

	UFUNCTION()
	void Look(const FInputActionValue& InputActionValue);
};
