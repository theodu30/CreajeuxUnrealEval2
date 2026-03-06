// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlatformerGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCoinTotalDelegate, int, Total);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpgradeTotalDelegate, int, Total);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCoinCollectedDelegate, int, Total);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpgradeCollectedDelegate, int, Total);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeathDelegate, int, Total);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FKeyFoundDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FResetDelegate);

/**
 * 
 */
UCLASS()
class CREAJEUX_UE_EVAL1_API APlatformerGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
private:
	uint32 CoinCounter = 0;
	uint32 CoinTotalCounter = 0;
	uint32 UpgradeCounter = 0;
	uint32 UpgradeTotalCounter = 0;
	uint32 DeathCounter = 0;
	bool KeyFound = false;
	
public:
	UPROPERTY(BlueprintAssignable)
	FCoinTotalDelegate OnCoinTotal;
	
	UPROPERTY(BlueprintAssignable)
	FUpgradeTotalDelegate OnUpgradeTotal;
	
	UPROPERTY(BlueprintAssignable)
	FCoinCollectedDelegate OnCoinCollected;
	
	UPROPERTY(BlueprintAssignable)
	FUpgradeCollectedDelegate OnUpgradeCollected;
	
	UPROPERTY(BlueprintAssignable)
	FDeathDelegate OnDeath;
	
	UPROPERTY(BlueprintAssignable)
	FKeyFoundDelegate OnKeyFound;
	
	UPROPERTY(BlueprintAssignable)
	FResetDelegate OnReset;
	
	UFUNCTION(BlueprintCallable)
	void SetCoinTotal(const int Total);
	
	UFUNCTION(BlueprintCallable)
	void SetUpgradeTotal(const int Total);
	
	UFUNCTION(BlueprintCallable)
	void AddCoin(const int Amount);
	
	UFUNCTION(BlueprintCallable)
	void AddUpgrade();
	
	UFUNCTION(BlueprintCallable)
	void AddDeath();
	
	UFUNCTION(BlueprintCallable)
	void SetKeyFound();
	
	UFUNCTION(BlueprintCallable)
	void CallReset();
	
	UFUNCTION(BlueprintCallable)
	void AddToCoinTotal(const int Amount);
	
	UFUNCTION(BlueprintCallable)
	void AddToUpgradeTotal(const int Amount);

	UFUNCTION(BlueprintCallable)
	void CallUpdate();
	
};
