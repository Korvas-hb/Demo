// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/DemoCharacterAnimInstance.h"

#include "Character/RPGDemoCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UDemoCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	OwingCharacter = Cast<ARPGDemoCharacterBase>(TryGetPawnOwner());

	// 如果角色不为空
	if (OwingCharacter)
	{
		// 那就获得该角色的角色移动组件
		OwingMovementComponent = OwingCharacter->GetCharacterMovement();
	}
}

void UDemoCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwingCharacter || !OwingMovementComponent) return;

	GroundSpeed = OwingCharacter->GetVelocity().Size2D();

	bHasAcceleration = OwingMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
