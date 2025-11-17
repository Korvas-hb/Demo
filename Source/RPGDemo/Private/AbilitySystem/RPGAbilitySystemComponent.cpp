// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/RPGAbilitySystemComponent.h"

void URPGAbilitySystemComponent::InputAbilityPressed(FGameplayTag InInputTag)
{
	if (InInputTag.IsValid())
	{
		ABILITYLIST_SCOPE_LOCK()
		for (const auto& AbilitySpec : ActivatableAbilities.Items)
		{
			if (!AbilitySpec.IsActive()&&AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag))
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void URPGAbilitySystemComponent::InputAbilityReleased(FGameplayTag InInputTag)
{
}
