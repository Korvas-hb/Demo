// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RPGDemoPlayerCharacter.h"

#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "AbilitySystem/RPGAttributeSet.h"

ARPGDemoPlayerCharacter::ARPGDemoPlayerCharacter()
{

}

void ARPGDemoPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	

}
