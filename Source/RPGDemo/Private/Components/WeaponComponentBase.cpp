// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/WeaponComponentBase.h"

#include "Components/BoxComponent.h"
#include "Weapon/WeaponBase.h"

void UWeaponComponentBase::RegisterSpawnedWeapon(AWeaponBase* InWeapon, FGameplayTag InWeaponTag,
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

		if (bHasContain)
		{
			OnRegisterFinished.ExecuteIfBound(false, FGameplayTag());
			return;
		}

		FRegisterWeaponWithTag RegisterWeapon(InWeapon, InWeaponTag, bRegisterAsEquipped);
		RegisterWeaponWithTagArray.Push(RegisterWeapon);
		if (bRegisterAsEquipped)
		{
			CurrentCharacterEquippingTag = InWeaponTag;
		}

		OnRegisterFinished.ExecuteIfBound(true, InWeaponTag);
	}
}

AWeaponBase* UWeaponComponentBase::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
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

AWeaponBase* UWeaponComponentBase::GetCharacterCurrentEquipWeapon() const
{
	if (CurrentCharacterEquippingTag.IsValid())
	{
		return GetCharacterCarriedWeaponByTag(CurrentCharacterEquippingTag);
	}
	return nullptr;
}

void UWeaponComponentBase::SetCurrentEquipWeaponTag(FGameplayTag InWeaponTag)
{
	CurrentCharacterEquippingTag = CurrentCharacterEquippingTag != InWeaponTag
		                               ? InWeaponTag
		                               : CurrentCharacterEquippingTag;
}

void UWeaponComponentBase::RemoveCurrentEquipWeaponTag()
{
	CurrentCharacterEquippingTag = FGameplayTag();
}

void UWeaponComponentBase::ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamage)
{
	if (ToggleDamage == EToggleDamageType::CurrentEquipWeapon)
	{
		AWeaponBase* Weapon = GetCharacterCurrentEquipWeapon();

		if (bShouldEnable)
		{
			Weapon->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
			UE_LOG(LogTemp, Warning, TEXT("Open"));
		}
		else
		{
			Weapon->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
			UE_LOG(LogTemp, Warning, TEXT("Close"));
		}
	}
}
