// Shatz All Rights Reserved


#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"

bool FWarriorGameplayAbilitySet::IsValid() const
{
	return InputTag.IsValid() && Ability;
}

void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InAbilitySystemComponent,
	int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InAbilitySystemComponent, ApplyLevel);

	for (int32 i = 0; i < StartUpAbilitySets.Num(); i++)
	{
		// ReSharper disable once CppTooWideScopeInitStatement
		const auto& AbilitySet = StartUpAbilitySets[i];
		if (AbilitySet.IsValid())
		{
			FGameplayAbilitySpec AbilitySpec{ AbilitySet.Ability, ApplyLevel };
			AbilitySpec.SourceObject = InAbilitySystemComponent->GetAvatarActor();
			AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

			InAbilitySystemComponent->GiveAbility(AbilitySpec);
		}
	}
}
