// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "NativeGameplayTags.h"
#include "MyGameplayEffectCalculation2.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_OverWeight);
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UMyGameplayEffectCalculation2 : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public:
	UMyGameplayEffectCalculation2();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	 FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

private:
	//Item Health
	FGameplayEffectAttributeCaptureDefinition ItemWeight;
	//Weight
	FGameplayEffectAttributeCaptureDefinition InventoryWeight;
	FGameplayEffectAttributeCaptureDefinition InventoryMaxWeight;
	
};