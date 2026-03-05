// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformerHUD.h"
#include "Blueprint/UserWidget.h"

void APlatformerHUD::BeginPlay()
{
	Super::BeginPlay();
	
	Widget = CreateWidget(GetWorld(), WidgetClass);
	if (Widget != nullptr)
	{
		Widget->AddToViewport();
	}
}
