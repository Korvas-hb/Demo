// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DataAsset_StartUpDataBase.h"

#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/RPGGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveDataAssetAbilitiesToASC(URPGAbilitySystemComponent* ASC, int32 ApplyLevel)
{
	check(ASC);

	GrantDataAssetAbilites(OnGivenAbilities, ASC, ApplyLevel);
	GrantDataAssetAbilites(OnReactiveAbilities, ASC, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantDataAssetAbilites(const TArray<TSubclassOf<URPGGameplayAbility>> InAbilitiesGrant,
                                                        URPGAbilitySystemComponent* ASC, int32 ApplyLevel)
{
	check(ASC);

	if (InAbilitiesGrant.IsEmpty()) return;
	for (const auto AbilityClass : InAbilitiesGrant)
	{
		if (AbilityClass == nullptr) continue;

		FGameplayAbilitySpec AbilitySpec(AbilityClass);
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.SourceObject = ASC->GetAvatarActor();
		ASC->GiveAbility(AbilitySpec);
	}
}
