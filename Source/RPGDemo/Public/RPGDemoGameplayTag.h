// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

namespace RPGDemoGameplayTags
{
	// #########################InputTag  Begin###############
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipWeapon);
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnEquipWeapon);
	// #########################InputTag  End#################

	// #########################Weapon  Begin###############
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);
	// #########################Weapon  End#################
	
	// #########################GA  Begin#####################
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GA_SpawnWeapon);
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GA_EquipWeapon_Axe);
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GA_UnEquipWeapon_Axe);
	
	// #########################GA  End#####################
}
