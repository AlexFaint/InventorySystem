// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "NativeGameplayTags.h"
#include "MyAttributeSet.generated.h"


/**
 * 
 */
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

//UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_OverWeight);

UCLASS()
class INVENTORYSYSTEM_API UMyAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	// Inventory info:
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	FGameplayAttributeData InventorySize;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, InventorySize)
	
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	FGameplayAttributeData InventoryWeight;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, InventoryWeight)
	
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	FGameplayAttributeData InventoryMaxWeight;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, InventoryMaxWeight)

	//Cell attribute info:
	UPROPERTY(BlueprintReadOnly, Category = "ItemInfo")
	FGameplayAttributeData ItemType;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, ItemType)	

	UPROPERTY(BlueprintReadOnly, Category = "ItemInfo")
	FGameplayAttributeData ItemName;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, ItemName)

	UPROPERTY(BlueprintReadOnly, Category = "ItemInfo")
	FGameplayAttributeData ItemStack;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, ItemStack)	

	UPROPERTY(BlueprintReadOnly, Category = "ItemInfo")
	FGameplayAttributeData ItemMaxStack;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, ItemMaxStack)

	UPROPERTY(BlueprintReadOnly, Category = "ItemInfo")
	FGameplayAttributeData ItemHealth;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, ItemHealth)

	UPROPERTY(BlueprintReadOnly, Category = "ItemInfo")
	FGameplayAttributeData ItemDamageDone;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, ItemDamageDone)

	UPROPERTY(BlueprintReadOnly, Category = "ItemInfo")
	FGameplayAttributeData ItemMaxHealth;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, ItemMaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "ItemInfo")
	FGameplayAttributeData ItemDamage;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, ItemDamage)

	UPROPERTY(BlueprintReadOnly, Category = "ItemInfo")
	FGameplayAttributeData ItemDefence;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, ItemDefence)

	UPROPERTY(BlueprintReadOnly, Category = "ItemInfo")
	FGameplayAttributeData ItemWeight;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, ItemWeight)

	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};