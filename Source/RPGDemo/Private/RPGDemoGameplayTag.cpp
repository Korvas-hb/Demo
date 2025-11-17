// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGDemoGameplayTag.h"

namespace RPGDemoGameplayTags
{
	// #########################InputTag  Begin###############
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipWeapon, "InputTag.EquipWeapon");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(InputTag_UnEquipWeapon, "InputTag.UnEquipWeapon");

	// #########################InputTag  End#################

	// #########################Weapon  Begin###############
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe,"Player.Weapon.Axe");
	// #########################Weapon  End#################


	// #########################GA  Begin#####################
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(GA_SpawnWeapon, "GA.SpawnWeapon");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(GA_EquipWeapon_Axe, "GA.EquipWeapon.Axe");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(GA_UnEquipWeapon_Axe, "GA.UnEquipWeapon.Axe");

	// #########################GA  End#####################
}
