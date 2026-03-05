// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformerGameMode.h"

void APlatformerGameMode::SetCoinTotal(const int Total)
{
	CoinTotalCounter = Total;
	OnCoinTotal.Broadcast(Total);
}

void APlatformerGameMode::SetUpgradeTotal(const int Total)
{
	UpgradeTotalCounter = Total;
	OnUpgradeTotal.Broadcast(Total);
}

void APlatformerGameMode::AddCoin(const int Amount)
{
	CoinCounter += Amount;
	OnCoinCollected.Broadcast(CoinCounter);
}

void APlatformerGameMode::AddUpgrade()
{
	++UpgradeCounter;
	OnUpgradeCollected.Broadcast(UpgradeCounter);
}

void APlatformerGameMode::AddDeath()
{
	++DeathCounter;
	OnDeath.Broadcast(DeathCounter);
}

void APlatformerGameMode::SetKeyFound()
{
	KeyFound = true;
	OnKeyFound.Broadcast();
}

void APlatformerGameMode::CallReset()
{
	CoinCounter = 0;
	UpgradeCounter = 0;
	DeathCounter = 0;
	KeyFound = false;
	
	OnReset.Broadcast();
}

void APlatformerGameMode::AddToCoinTotal(const int Amount)
{
	CoinTotalCounter += Amount;
	OnCoinTotal.Broadcast(CoinTotalCounter);
}

void APlatformerGameMode::AddToUpgradeTotal(const int Amount)
{
	UpgradeTotalCounter += Amount;
	OnUpgradeTotal.Broadcast(UpgradeTotalCounter);
}
