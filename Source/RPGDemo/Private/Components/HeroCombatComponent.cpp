// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HeroCombatComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "RPGDemoGameplayTag.h"
#include "Components/HeroWeaponComponent.h"
#include "Weapon/HeroWeapon.h"

UHeroCombatComponent::UHeroCombatComponent()
{
	HeroWeaponComponent = CreateDefaultSubobject<UHeroWeaponComponent>("HeroWeaponComponent");
	HeroWeaponComponent->OnRegisterFinished.BindUObject(this, &ThisClass::OnRegisterFinishedCallBackFun);
	HeroWeaponComponent->OnResetArray.BindLambda([this]()-> void
	{
		HitTargetActors.Empty();
		UE_LOG(LogTemp,Warning,TEXT("Clear Hit Target Actors"));
	});
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
		HeroWeaponComponent->GetCharacterCarriedWeaponByTag(InWeaponTag)->OnWeaponHitTarget.BindUObject(
			this, &ThisClass::OnHitTargetActor);
		HeroWeaponComponent->GetCharacterCarriedWeaponByTag(InWeaponTag)->OnWeaponLeaveFromHitTarget.BindUObject(
			this, &ThisClass::OnLeaveHitTargetActor);
		HitTargetActors.Empty();
	}
}

void UHeroCombatComponent::OnHitTargetActor(AActor* InHitedActor)
{
	if (HitTargetActors.Contains(InHitedActor)) return;

	HitTargetActors.AddUnique(InHitedActor);

	FGameplayEventData Payload;
	Payload.Instigator = GetOwningPawn();
	Payload.Target = InHitedActor;
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(),RPGDemoGameplayTags::Shared_Event_MeleeHit,Payload);
	
	
	UE_LOG(LogTemp, Warning, TEXT("UHeroCombatComponent::OnHitTargetActor"));
}

void UHeroCombatComponent::OnLeaveHitTargetActor(AActor* InteractedActor)
{
	UE_LOG(LogTemp, Warning, TEXT("UHeroCombatComponent::OnLeaveHitTargetActor"));
}
