// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "RunTime/UMG/Public/UMG.h"
#include "Components/Button.h"
#include "InventoryButton.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API UInventoryButton : public UButton
{
	GENERATED_BODY()

	UInventoryButton();

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

	
};
