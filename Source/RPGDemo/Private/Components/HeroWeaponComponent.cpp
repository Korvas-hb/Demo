// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HeroWeaponComponent.h"

void UHeroWeaponComponent::RegisterSpawnedWeapon(AWeaponBase* InWeapon, FGameplayTag InWeaponTag,
                                                 bool bRegisterAsEquipped)
{
	if (InWeapon && InWeaponTag.IsValid())
	{
		bool bHasContain = false;
		for (const auto val : RegisterWeaponWithTagArray)
		{
			if (InWeaponTag == val.RegisterTag)
			{
				bHasContain = true;
			}
		}

		if (bHasContain) return;
		FRegisterWeaponWithTag RegisterWeapon(InWeapon, InWeaponTag, bRegisterAsEquipped);
		RegisterWeaponWithTagArray.Push(RegisterWeapon);
		if (bRegisterAsEquipped)
		{
			CurrentCharacterEquippingTag = InWeaponTag;
		}
	}
}

AWeaponBase* UHeroWeaponComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	for (const auto RegisterWeapon : RegisterWeaponWithTagArray)
	{
		if (RegisterWeapon.RegisterTag == InWeaponTagToGet)
		{
			return RegisterWeapon.RegisterWeapon;
		}
	}

	return nullptr;
}

AWeaponBase* UHeroWeaponComponent::GetCharacterCurrentEquipWeapon() const
{
	if (CurrentCharacterEquippingTag.IsValid())
	{
		return GetCharacterCarriedWeaponByTag(CurrentCharacterEquippingTag);
	}
	return nullptr;
}

void UHeroWeaponComponent::SetCurrentEquipWeaponTag(FGameplayTag InWeaponTag)
{
	CurrentCharacterEquippingTag = CurrentCharacterEquippingTag != InWeaponTag
		                               ? InWeaponTag
		                               : CurrentCharacterEquippingTag;
}

void UHeroWeaponComponent::RemoveCurrentEquipWeaponTag()
{
	CurrentCharacterEquippingTag = FGameplayTag();
}
