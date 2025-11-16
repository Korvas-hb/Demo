// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RPGDemoPlayerCharacter.h"

#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "AbilitySystem/RPGAttributeSet.h"
#include "Components/HeroCombatComponent.h"
#include "DataAssets/DataAsset_StartUpDataBase.h"

ARPGDemoPlayerCharacter::ARPGDemoPlayerCharacter()
{
	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>("HeroCombatComponent");
}

void ARPGDemoPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* StartUpDataBase = CharacterStartUpData.LoadSynchronous())
		{
			StartUpDataBase->GiveDataAssetAbilitiesToASC(AbilitySystemComponent, 1);
		}
	}
}
