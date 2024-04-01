// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAttributeSet.h"
#include "AbilitySystemBlueprintLibrary.h"

//UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_OverWeight, "Inventory.OverWeight");
UE_DEFINE_GAMEPLAY_TAG(TAG_INVENTORY_OVERWEIGHT, "Inventory.OverWeight");
	
void UMyAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	
	if (Attribute == GetInventoryMaxWeightAttribute())
	{
	
		if((NewValue <= GetInventoryMaxWeight()) && (!GetOwningAbilitySystemComponent()->HasMatchingGameplayTag(TAG_INVENTORY_OVERWEIGHT)))
		{
			FGameplayEventData EventData;
			EventData.EventTag = TAG_INVENTORY_OVERWEIGHT;
			UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningActor(),TAG_INVENTORY_OVERWEIGHT,EventData);
			GetOwningAbilitySystemComponent()->HandleGameplayEvent(TAG_INVENTORY_OVERWEIGHT, &EventData);
			GetOwningAbilitySystemComponent()->AddLooseGameplayTag(TAG_INVENTORY_OVERWEIGHT);
		}

	//if ((OldValue <= GetInventoryMaxWeight())&& (NewValue > GetInventoryMaxWeight()))
	if ((OldValue <= 40)&& (NewValue > GetInventoryMaxWeight()))
	{
		GetOwningAbilitySystemComponent()->RemoveLooseGameplayTag(TAG_INVENTORY_OVERWEIGHT);
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