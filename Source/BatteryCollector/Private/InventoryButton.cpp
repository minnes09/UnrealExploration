// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
//#include "InventoryButton.h"
#include "../Public/InventoryButton.h"

#define LOCTEXT_NAMESPACE "UMG"

UInventoryButton::UInventoryButton() {
	static ConstructorHelpers::FObjectFinder<USlateWidgetStyleAsset>InventoryButtonStyle(TEXT("/Game/UI/InventoryButtonWidgetStyle"));
	
	SButton::FArguments ButtonDefaults;
	ButtonDefaults.ButtonStyle(InventoryButtonStyle.Object);
	
	WidgetStyle = *ButtonDefaults._ButtonStyle;
}

#if WITH_EDITOR
const FText UInventoryButton::GetPaletteCategory()
{
	return LOCTEXT("", "My Custom Stuff");
}
#endif

#undef LOCTEXT_NAMESPACE