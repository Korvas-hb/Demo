// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGDemoGameplayTag.h"

namespace RPGDemoGameplayTags
{
	// #########################InputTag  Begin###############
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipWeapon, "InputTag.EquipWeapon");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(InputTag_UnEquipWeapon, "InputTag.UnEquipWeapon");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(InputTag_Attack_Light_Axe, "InputTag.Attack.Light.Axe");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(InputTag_Attack_Heavy_Axe, "InputTag.Attack.Heavy.Axe");

	// #########################InputTag  End#################

	// #########################Weapon  Begin###############
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe,"Player.Weapon.Axe");
	// #########################Weapon  End#################

	// #########################GA  Begin#####################
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(GA_SpawnWeapon, "GA.SpawnWeapon");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(GA_EquipWeapon_Axe, "GA.EquipWeapon.Axe");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(GA_UnEquipWeapon_Axe, "GA.UnEquipWeapon.Axe");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(GA_Attack_Light_Axe, "GA.Attack.Light.Axe");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(GA_Attack_Heavy_Axe, "GA.Attack.Heavy.Axe");

	// #########################GA  End#####################
	
	// #########################Event  Begin###############
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Axe, "Player.Event.Equip.Axe");
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(Player_Event_UnEquip_Axe, "Player.Event.UnEquip.Axe");
	// #########################Event  End#################

	// #########################State  Begin###############
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(Player_State_JumpToFinish, "Player.State.JumpToFinish");
	// #########################State  End#################

	// #########################Enemy Weapon  Begin###############
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon, "Enemy.Weapon");
	// #########################Enemy Weapon  End###############

	// #########################Shared Event  Begin###############
	RPGDEMO_API UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeleeHit, "Shared.Event.MeleeHit");
	// #########################Shared Event  End###############
	
}
