// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/RPGPlayerController.h"

#include "AbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "RPGDemoGameplayTag.h"
#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "Character/RPGDemoPlayerCharacter.h"
#include "DataAssets/DataAsset_InputConfig.h"
#include "EnhancedInputs/RPGDemoInputComponent.h"

void ARPGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	URPGDemoInputComponent* DemoInputComponent = CastChecked<URPGDemoInputComponent>(InputComponent);

	if (DemoInputComponent)
	{
		DemoInputComponent->BindNativeInputAction(InputConfig, RPGDemoGameplayTags::InputTag_Move,
		                                          ETriggerEvent::Triggered, this, &ThisClass::Move);
		DemoInputComponent->BindNativeInputAction(InputConfig, RPGDemoGameplayTags::InputTag_Look,
		                                          ETriggerEvent::Triggered, this, &ThisClass::Look);

		DemoInputComponent->BindGameplayAbilityInputAction(InputConfig, ETriggerEvent::Started,
		                                                   ETriggerEvent::Completed, this,
		                                                   &ThisClass::OnInputAbilityPressed,
		                                                   &ThisClass::OnInputAbilityReleased);
	}
}

void ARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	checkf(InputConfig, TEXT("请加入DataAsset"));

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (Subsystem)
	{
		Subsystem->AddMappingContext(InputConfig->DefaultMappingContext, 0);
	}
}

void ARPGPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D InputActionVector = Value.Get<FVector2D>();

	if (APawn* ControlPawn = GetPawn())
	{
		const FRotator NeedRotation = FRotator(0.f, GetControlRotation().Yaw, 0.f);

		const FVector ForwardDirection = FRotationMatrix(NeedRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(NeedRotation).GetUnitAxis(EAxis::Y);

		if (InputActionVector.X != 0.f)
		{
			ControlPawn->AddMovementInput(RightDirection, InputActionVector.X);
		}

		if (InputActionVector.Y != 0.f)
		{
			ControlPawn->AddMovementInput(ForwardDirection, InputActionVector.Y);
		}
	}
}

void ARPGPlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D InputActionVector = Value.Get<FVector2D>();

	if (APawn* ControlPawn = GetPawn())
	{
		if (InputActionVector.X != 0.f)
		{
			ControlPawn->AddControllerYawInput(InputActionVector.X);
		}

		if (InputActionVector.Y != 0.f)
		{
			ControlPawn->AddControllerPitchInput(InputActionVector.Y);
		}
	}
}

void ARPGPlayerController::OnInputAbilityPressed(FGameplayTag InInputTag)
{
	if (ARPGDemoPlayerCharacter* DemoPlayerCharacter = Cast<ARPGDemoPlayerCharacter>(GetPawn()))
	{
		URPGAbilitySystemComponent* ASC = CastChecked<URPGAbilitySystemComponent>(DemoPlayerCharacter->GetAbilitySystemComponent());
		ASC->InputAbilityPressed(InInputTag);
	}
}

void ARPGPlayerController::OnInputAbilityReleased(FGameplayTag InInputTag)
{
	if (ARPGDemoPlayerCharacter* DemoPlayerCharacter = Cast<ARPGDemoPlayerCharacter>(GetPawn()))
	{
		URPGAbilitySystemComponent* ASC = CastChecked<URPGAbilitySystemComponent>(DemoPlayerCharacter->GetAbilitySystemComponent());
		ASC->InputAbilityReleased(InInputTag);
	}
}
