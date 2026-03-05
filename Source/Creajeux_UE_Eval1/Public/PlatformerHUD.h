// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlatformerHUD.generated.h"

class UUserWidget;

/**
 * 
 */
UCLASS()
class CREAJEUX_UE_EVAL1_API APlatformerHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
	TSubclassOf<UUserWidget> WidgetClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HUD)
	TObjectPtr<UUserWidget> Widget;
	
public:
	virtual void BeginPlay() override;
};
