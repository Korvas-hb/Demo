// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RPGDemoEnemyCharacter.h"

#include "Components/EnemyCombatComponent.h"
#include "DataAssets/DataAsset_EnemyStartUpData.h"
#include "Engine/AssetManager.h"
#include "GameFramework/CharacterMovementComponent.h"

ARPGDemoEnemyCharacter::ARPGDemoEnemyCharacter()
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 180.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>("EnemyCombatComponent");
}

void ARPGDemoEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (EnemyStartUpData.IsNull()) return;

	// 异步加载敌人的GA集合资产（在EnemyStartUpData里），然后加载成功后在下一Tick的时候调用lambda去进行授予GA给敌人的ASC。
	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		EnemyStartUpData.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[this]()
			{
				if (UDataAsset_EnemyStartUpData* LoadData = EnemyStartUpData.Get())
				{
					LoadData->GiveDataAssetAbilitiesToASC(AbilitySystemComponent,1);
				}
			}
			)
	);
}
