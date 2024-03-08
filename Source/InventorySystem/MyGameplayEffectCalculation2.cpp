// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameplayEffectCalculation2.h"

#include "MyAttributeSet.h"

UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_OverWeight, "Inventory.OverWeight");

UMyGameplayEffectCalculation2::UMyGameplayEffectCalculation2()
{
	ItemWeight = FGameplayEffectAttributeCaptureDefinition(UMyAttributeSet::GetItemWeightAttribute() ,
		EGameplayEffectAttributeCaptureSource::Target ,false);
	RelevantAttributesToCapture.Add(ItemWeight);

	InventoryWeight = FGameplayEffectAttributeCaptureDefinition(UMyAttributeSet::GetInventoryWeightAttribute() ,
		EGameplayEffectAttributeCaptureSource::Target ,false);
	RelevantAttributesToCapture.Add(InventoryWeight);

	InventoryMaxWeight = FGameplayEffectAttributeCaptureDefinition(UMyAttributeSet::GetInventoryMaxWeightAttribute() ,
		EGameplayEffectAttributeCaptureSource::Target ,false);
	RelevantAttributesToCapture.Add(InventoryMaxWeight);
}

void UMyGameplayEffectCalculation2::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);
	
	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
	
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = SourceTags;
	EvaluateParameters.TargetTags = TargetTags;

	float Weight = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(ItemWeight, EvaluateParameters,Weight);

	if(Weight > 0)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UMyAttributeSet::GetInventoryWeightAttribute(), EGameplayModOp::Additive, +Weight));
		OutExecutionOutput.MarkConditionalGameplayEffectsToTrigger();		
	}	
}