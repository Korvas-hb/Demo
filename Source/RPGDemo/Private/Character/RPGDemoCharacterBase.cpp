// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RPGDemoCharacterBase.h"

ARPGDemoCharacterBase::ARPGDemoCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;	
}

void ARPGDemoCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARPGDemoCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARPGDemoCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

