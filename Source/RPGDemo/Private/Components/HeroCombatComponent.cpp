// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HeroCombatComponent.h"

#include "Components/HeroWeaponComponent.h"

UHeroCombatComponent::UHeroCombatComponent()
{
	HeroWeaponComponent = CreateDefaultSubobject<UHeroWeaponComponent>("HeroWeaponComponent");
	
}
