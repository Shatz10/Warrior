// Shatz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "WarriorGameplayAbility.h"
#include "Characters/WarriorHeroCharacter.h"
#include "Controllers/WarriorHeroController.h"
#include "WarriorHeroGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()

	TWeakObjectPtr<AWarriorHeroCharacter> HeroCharacterCache;
	TWeakObjectPtr<AWarriorHeroController> WarriorHeroPlayerControllerCache;

public:
	/** Return the physical representation of the owner, used for targeting and animation. This will often be null! */
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorHeroCharacter* GetHeroCharacterFromActorInfo();

	/** Return the PlayerController associated with the owning actor. This will often be null! */
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorHeroController* GetWarriorHeroPlayerController();

	/** Return the CombatComponent from the associated Avatar Actor */
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();
};
