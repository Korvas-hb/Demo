// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DataAsset_HeroStartUpData.h"
#include "GameplayAbilitySpec.h"
#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/RPGGameplayAbility.h"

void UDataAsset_HeroStartUpData::GiveDataAssetAbilitiesToASC(URPGAbilitySystemComponent* ASC, int32 ApplyLevel)
{
	Super::GiveDataAssetAbilitiesToASC(ASC, ApplyLevel);

	if (HeroOnlyAbilities.IsEmpty()) return;
	
	for (const FHeroOnlyAbilitySet& HeroOnlyAbility :HeroOnlyAbilities)
	{
		if (HeroOnlyAbility.IsValid())
		{
			FGameplayAbilitySpec Spec(HeroOnlyAbility.InputHeroGA);
			Spec.Level = ApplyLevel;
			Spec.DynamicAbilityTags.AddTag(HeroOnlyAbility.InputAbilityTag);
			Spec.SourceObject = ASC->GetAvatarActor();

			ASC->GiveAbility(Spec);
		}
	}
	
}
