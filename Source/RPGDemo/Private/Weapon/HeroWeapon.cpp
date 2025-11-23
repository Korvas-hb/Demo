// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/HeroWeapon.h"

void AHeroWeapon::SaveGrantedWeaponAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles)
{
	GrantedWeaponAbilitySpecHandles = InSpecHandles;
}

TArray<FGameplayAbilitySpecHandle> AHeroWeapon::GetGrantedAbilitySpecHandles() const
{
	return GrantedWeaponAbilitySpecHandles;
}
