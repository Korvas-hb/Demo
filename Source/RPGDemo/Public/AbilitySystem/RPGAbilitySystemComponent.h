// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "StructForNeedInfo.h"
#include "RPGAbilitySystemComponent.generated.h"


UCLASS()
class RPGDEMO_API URPGAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability", meta=(ApplyLevel="1"))
	void GrantHeroWeaponAbilities(const TArray<FHeroOnlyAbilitySet>& InHeroWeaponAbilities, int32 ApplyLevel,
	                              TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles);

	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability")
	void RemovedGrantedHeroWeaponAbilities(UPARAM(ref)
		TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove);

	void InputAbilityPressed(FGameplayTag InInputTag);
	void InputAbilityReleased(FGameplayTag InInputTag);
	
};
