// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/PawnCombatComponent.h"

UWeaponComponentBase* UPawnCombatComponent::GetWeaponComponentBase() const
{
	return nullptr;
}

void UPawnCombatComponent::OnHitTargetActor(AActor* InHitedActor)
{
}

void UPawnCombatComponent::OnLeaveHitTargetActor(AActor* InteractedActor)
{
}

void UPawnCombatComponent::OnRegisterFinishedCallBackFun(bool bIsFinished, FGameplayTag InWeaponTag)
{
}
