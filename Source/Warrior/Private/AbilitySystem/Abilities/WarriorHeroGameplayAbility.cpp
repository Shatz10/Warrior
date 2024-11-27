// Shatz All Rights Reserved


#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"

AWarriorHeroCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!HeroCharacterCache.IsValid() && IsValid(GetAvatarActorFromActorInfo()))
	{
		HeroCharacterCache = CastChecked<AWarriorHeroCharacter>(GetAvatarActorFromActorInfo());
	}
	return HeroCharacterCache.IsValid() ? HeroCharacterCache.Get() : nullptr;
}

AWarriorHeroController* UWarriorHeroGameplayAbility::GetWarriorHeroPlayerController()
{
	if (!WarriorHeroPlayerControllerCache.IsValid() && GetActorInfo().PlayerController.IsValid(false))
	{
		WarriorHeroPlayerControllerCache = CastChecked<AWarriorHeroController>(GetActorInfo().PlayerController);
	}
	return WarriorHeroPlayerControllerCache.IsValid() ? WarriorHeroPlayerControllerCache.Get() : nullptr;
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
