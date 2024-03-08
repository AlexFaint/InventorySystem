// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAttributeSet.h"
#include "AbilitySystemBlueprintLibrary.h"

UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_OverWeight, "Inventory.OverWeight");

	
void UMyAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	
	if (Attribute == GetInventoryMaxWeightAttribute())
	{
	
		if((NewValue <= GetInventoryMaxWeight()) && (!GetOwningAbilitySystemComponent()->HasMatchingGameplayTag(TAG_Gameplay_OverWeight)))
		{
			FGameplayEventData EventData;
			EventData.EventTag = TAG_Gameplay_OverWeight;
			UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningActor(),TAG_Gameplay_OverWeight,EventData);
		}

	if ((OldValue <= GetInventoryMaxWeight())&& (NewValue > GetInventoryMaxWeight()))
	{
		GetOwningAbilitySystemComponent()->RemoveLooseGameplayTag(TAG_Gameplay_OverWeight);
	}
	}
}

void UMyAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (GetInventoryWeightAttribute() == Attribute)
	{
		NewValue = FMath::Clamp(NewValue, 0, 100.f);
	}		
}