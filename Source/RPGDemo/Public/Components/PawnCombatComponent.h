// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"

class UWeaponComponentBase;

UCLASS()
class RPGDEMO_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual UWeaponComponentBase* GetWeaponComponentBase() const;

protected:
	virtual void OnRegisterFinishedCallBackFun(bool bIsFinished, FGameplayTag InWeaponTag);
	virtual void OnHitTargetActor(AActor* InHitedActor);
	virtual void OnLeaveHitTargetActor(AActor* InteractedActor);
	
	UPROPERTY(VisibleAnywhere, Category="Weapon", meta=(AllowPrivateAccess=true))
	TObjectPtr<UWeaponComponentBase> WeaponComponent;

	TArray<AActor*> HitTargetActors;
	
};
