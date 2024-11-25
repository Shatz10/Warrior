// Shatz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorBaseAnimInstance.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorCharacterInstance.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorCharacterInstance : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(EditAnywhere)
	AWarriorBaseCharacter* OwingCharacter;
	UPROPERTY(EditAnywhere)
	UCharacterMovementComponent* OwningMovementComponent;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimationData|LocomotionData")
	float GroundSpeed;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimationData|LocomotionData")
	bool bHasAcceleration;
};
