// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoBlueprintFunctionLibrary.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/RPGAbilitySystemComponent.h"

URPGAbilitySystemComponent* UDemoBlueprintFunctionLibrary::NativeGetASCFromActor(AActor* InActor)
{
	if (InActor == nullptr) return nullptr;
	return CastChecked<URPGAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UDemoBlueprintFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag InAddTag)
{
	URPGAbilitySystemComponent* ASC = NativeGetASCFromActor(InActor);
	if (!ASC->HasMatchingGameplayTag(InAddTag))
	{
		ASC->AddLooseGameplayTag(InAddTag);
	}
}

void UDemoBlueprintFunctionLibrary::RemoveGameplayTagToActorIfHave(AActor* InActor, FGameplayTag InAddTag)
{
	URPGAbilitySystemComponent* ASC = NativeGetASCFromActor(InActor);
	if (ASC->HasMatchingGameplayTag(InAddTag))
	{
		ASC->RemoveLooseGameplayTag(InAddTag);
	}
}

bool UDemoBlueprintFunctionLibrary::NativeDoesHaveGameplayTag(AActor* InActor, FGameplayTag InTag)
{
	URPGAbilitySystemComponent* ASC = NativeGetASCFromActor(InActor);
	if (ASC->HasMatchingGameplayTag(InTag))
	{
		return true;
	}
	return false;
}

void UDemoBlueprintFunctionLibrary::K2_DoesHaveGameplayTag(AActor* InActor, FGameplayTag InTag,
                                                           EConfirmType& OutConfirm)
{
	URPGAbilitySystemComponent* ASC = NativeGetASCFromActor(InActor);
	if (ASC->HasMatchingGameplayTag(InTag))
	{
		OutConfirm = EConfirmType::Yes;
	}
	else
	{
		OutConfirm = EConfirmType::No;
	}
}
