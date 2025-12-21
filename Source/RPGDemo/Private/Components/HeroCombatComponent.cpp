// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HeroCombatComponent.h"

#include "Components/HeroWeaponComponent.h"
#include "Weapon/HeroWeapon.h"

UHeroCombatComponent::UHeroCombatComponent()
{
	HeroWeaponComponent = CreateDefaultSubobject<UHeroWeaponComponent>("HeroWeaponComponent");
	
}

AHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InTag) const
{
	return Cast<AHeroWeapon>(HeroWeaponComponent->GetCharacterCarriedWeaponByTag(InTag));
}

UWeaponComponentBase* UHeroCombatComponent::GetWeaponComponentBase() const
{
	return GetHeroWeaponComponent();
}
