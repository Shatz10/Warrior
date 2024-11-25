// Shatz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorCharacterInstance.h"
#include "Characters/WarriorHeroCharacter.h"
#include "WarriorHeroAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroAnimInstance : public UWarriorCharacterInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimationData|Refrences")
	AWarriorHeroCharacter* OwningHeroCharacter;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimationData|LocomotionData")
	bool bShouldEnterRelaxState;
		
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AnimationData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;

	float IdleElapsedTime = 0.f;
};
