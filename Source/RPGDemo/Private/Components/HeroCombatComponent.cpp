// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HeroCombatComponent.h"

#include "Components/HeroWeaponComponent.h"
#include "Weapon/HeroWeapon.h"

UHeroCombatComponent::UHeroCombatComponent()
{
	HeroWeaponComponent = CreateDefaultSubobject<UHeroWeaponComponent>("HeroWeaponComponent");
	HeroWeaponComponent->OnRegisterFinished.BindUObject(this, &ThisClass::OnRegisterFinishedCallBackFun);
}

AHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InTag) const
{
	return Cast<AHeroWeapon>(HeroWeaponComponent->GetCharacterCarriedWeaponByTag(InTag));
}

UWeaponComponentBase* UHeroCombatComponent::GetWeaponComponentBase() const
{
	return GetHeroWeaponComponent();
}


void UHeroCombatComponent::OnRegisterFinishedCallBackFun(bool bIsFinished, FGameplayTag InWeaponTag)
{
	if (bIsFinished)
	{
		HeroWeaponComponent->GetCharacterCarriedWeaponByTag(InWeaponTag)->OnWeaponHitTarget.BindUObject(this,&ThisClass::OnHitTargetActor);
		HeroWeaponComponent->GetCharacterCarriedWeaponByTag(InWeaponTag)->OnWeaponLeaveFromHitTarget.BindUObject(this,&ThisClass::OnLeaveHitTargetActor);
	}
}

void UHeroCombatComponent::OnHitTargetActor(AActor* InHitedActor)
{
	Super::OnHitTargetActor(InHitedActor);
	UE_LOG(LogTemp, Warning, TEXT("UHeroCombatComponent::OnHitTargetActor"));
}

void UHeroCombatComponent::OnLeaveHitTargetActor(AActor* InteractedActor)
{
	Super::OnLeaveHitTargetActor(InteractedActor);
	UE_LOG(LogTemp, Warning, TEXT("UHeroCombatComponent::OnLeaveHitTargetActor"));
}

