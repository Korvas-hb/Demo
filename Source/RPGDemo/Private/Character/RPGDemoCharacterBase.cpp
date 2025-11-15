// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RPGDemoCharacterBase.h"

#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "AbilitySystem/RPGAttributeSet.h"

ARPGDemoCharacterBase::ARPGDemoCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	AbilitySystemComponent = CreateDefaultSubobject<URPGAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<URPGAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ARPGDemoCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

URPGAttributeSet* ARPGDemoCharacterBase::GetRPGAttributeSet() const
{
	return AttributeSet;
}

void ARPGDemoCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (URPGAbilitySystemComponent* RPGAbilitySystemComponent = Cast<URPGAbilitySystemComponent>(AbilitySystemComponent))
	{
		RPGAbilitySystemComponent->InitAbilityActorInfo(this,this);
		FString name = this->GetName();
		const FString FSText = FString::Printf(TEXT("Owner Actor: %s, AvatarActor: %s"),
											   *RPGAbilitySystemComponent->GetOwnerActor()->GetActorLabel(),
											   *RPGAbilitySystemComponent->GetAvatarActor()->GetActorLabel()
		);
		UE_LOG(LogTemp,Warning,TEXT("Ability System Component valid:%s"), *FSText);
	}
}


