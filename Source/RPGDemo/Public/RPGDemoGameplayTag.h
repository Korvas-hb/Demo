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
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Attack_Light_Axe);
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Attack_Heavy_Axe);
	// #########################InputTag  End#################

	// #########################Weapon  Begin###############
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);
	// #########################Weapon  End#################
	
	// #########################GA  Begin#####################
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GA_SpawnWeapon);
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GA_EquipWeapon_Axe);
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GA_UnEquipWeapon_Axe);
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GA_Attack_Light_Axe);
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GA_Attack_Heavy_Axe);
	
	// #########################GA  End#####################


	// #########################Event  Begin###############
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_UnEquip_Axe);
	// #########################Event  End#################

	// #########################State  Begin###############
	RPGDEMO_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_State_JumpToFinish);
	// #########################State  End#################
}
