// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EnumTypes.h"
#include "DemoBlueprintFunctionLibrary.generated.h"

class UPawnCombatComponent;
class URPGAbilitySystemComponent;

UCLASS()
class RPGDEMO_API UDemoBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static URPGAbilitySystemComponent* NativeGetASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Demo|Function Library")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag InAddTag);

	UFUNCTION(BlueprintCallable, Category = "Demo|Function Library")
	static void RemoveGameplayTagToActorIfHave(AActor* InActor, FGameplayTag InAddTag);

	static bool NativeDoesHaveGameplayTag(AActor* InActor, FGameplayTag InTag);

	UFUNCTION(BlueprintCallable, Category = "Demo|Function Library",
		meta = (DisplayName = "DoesActionHaveTag", ExpandEnumAsExecs="OutConfirm"))
	static void K2_DoesHaveGameplayTag(AActor* InActor, FGameplayTag InTag, EConfirmType& OutConfirm);

	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor);
	
	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary", meta = (DisplayName = "GetPawnCombatComponentFromActor", ExpandEnumAsExecs = "OutValidType"))
	static UPawnCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* InActor, EValidType& OutValidType);
};
