// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/EnemyCombatComponent.h"

#include "Components/EnemyWeaponComponent.h"
#include "Weapon/WeaponBase.h"


UEnemyCombatComponent::UEnemyCombatComponent()
{
	EnemyWeaponComponent = CreateDefaultSubobject<UEnemyWeaponComponent>("EnemyWeaponComponent");
}

AWeaponBase* UEnemyCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InTag) const
{
	return Cast<AWeaponBase>(EnemyWeaponComponent->GetCharacterCarriedWeaponByTag(InTag));
}
