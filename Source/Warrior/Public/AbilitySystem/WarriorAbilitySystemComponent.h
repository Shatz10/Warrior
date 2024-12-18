// Shatz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "WarriorAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:	
	void OnAbilityInputPressed(const FGameplayTag& Tag);

	void OnAbilityInputReleased(const FGameplayTag& Tag);
};
