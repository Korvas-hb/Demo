// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/DemoHeroAnimInstance.h"

#include "Character/RPGDemoPlayerCharacter.h"

void UDemoHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwingCharacter)
	{
		OwingHeroCharacter = Cast<ARPGDemoPlayerCharacter>(OwingCharacter);
	}
}

void UDemoHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		bShouldEnterRelaxState = false;
		IdleElpasedTime = 0.f;
	}
	else
	{
		IdleElpasedTime += DeltaSeconds;
		bShouldEnterRelaxState = (IdleElpasedTime >= EnterRelaxStateThreshold);
	}
}
