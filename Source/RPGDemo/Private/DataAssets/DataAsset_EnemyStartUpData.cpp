// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DataAsset_EnemyStartUpData.h"

#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/EnemyGameplayAbility.h"

void UDataAsset_EnemyStartUpData::GiveDataAssetAbilitiesToASC(URPGAbilitySystemComponent* ASC, int32 ApplyLevel)
{
	Super::GiveDataAssetAbilitiesToASC(ASC, ApplyLevel);

	if (EnemyOnlyAbilities.IsEmpty()) return;

	for (const auto& Ability : EnemyOnlyAbilities)
	{
		if (Ability != nullptr)
		{
			FGameplayAbilitySpec Spec(Ability);
			Spec.Level = ApplyLevel;
			Spec.SourceObject = ASC->GetAvatarActor();
			
			ASC->GiveAbility(Spec);
		}
	}
}
