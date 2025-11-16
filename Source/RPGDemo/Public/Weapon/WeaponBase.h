// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class RPGDEMO_API AWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	AWeaponBase();

	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const {return WeaponCollisionBox;};

protected:
	UPROPERTY(EditAnywhere, Category="Weapon")
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

	UPROPERTY(VisibleAnywhere,Category="Weapon")
	TObjectPtr<UBoxComponent> WeaponCollisionBox;

	
};
