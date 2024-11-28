// Shatz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "DataAsset_HeroStartUpData.generated.h"

USTRUCT(BlueprintType)
struct WARRIOR_API FWarriorGameplayAbilitySet
{
	GENERATED_BODY()

	/** Tag via which the actor can trigger the Ability. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "Input"))
	FGameplayTag InputTag;

	/** The Ability. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarriorGameplayAbility> Ability;

	bool IsValid() const;
};


/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()
	/** Abilities that are granted to the actor at startup. */
	UPROPERTY(EditDefaultsOnly,
		Category = "Aeon|StartUpData",
		meta = (AllowAbstract = "false", TitleProperty = "InputTag"))
	TArray<FWarriorGameplayAbilitySet> StartUpAbilitySets;

public:
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InAbilitySystemComponent,
	                                          int32 ApplyLevel) override;
};
