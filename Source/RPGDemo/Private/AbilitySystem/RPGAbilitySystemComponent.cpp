// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/RPGGameplayAbility.h"

void URPGAbilitySystemComponent::GrantHeroWeaponAbilities(const TArray<FHeroOnlyAbilitySet>& InHeroWeaponAbilities,
                                                          int32 ApplyLevel,
                                                          TArray<FGameplayAbilitySpecHandle>&
                                                          OutGrantedAbilitySpecHandles)
{
	if (InHeroWeaponAbilities.IsEmpty()) return;

	for (const auto WeaponAbility : InHeroWeaponAbilities)
	{
		if (!WeaponAbility.IsValid()) continue;
		FGameplayAbilitySpec Spec(WeaponAbility.InputHeroGA);
		Spec.Level = ApplyLevel;
		Spec.SourceObject = GetAvatarActor();
		Spec.DynamicAbilityTags.AddTag(WeaponAbility.InputAbilityTag);

		OutGrantedAbilitySpecHandles.AddUnique(Spec.Handle);
		GiveAbility(Spec);
		StaticClass()->ChildProperties->
	}
}

void URPGAbilitySystemComponent::RemovedGrantedHeroWeaponAbilities(
	TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove)
{
	if (InSpecHandlesToRemove.IsEmpty()) return;

	for (const auto SpecHandle : InSpecHandlesToRemove)
	{
		if (SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		}
	}

	InSpecHandlesToRemove.Empty();
}

void URPGAbilitySystemComponent::InputAbilityPressed(FGameplayTag InInputTag)
{
	if (InInputTag.IsValid())
	{
		ABILITYLIST_SCOPE_LOCK()
		for (const auto& AbilitySpec : ActivatableAbilities.Items)
		{
			if (!AbilitySpec.IsActive() && AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag))
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void URPGAbilitySystemComponent::InputAbilityReleased(FGameplayTag InInputTag)
{
}
