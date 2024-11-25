// Shatz All Rights Reserved


#include "AnimInstances/WarriorCharacterInstance.h"

#include "GameFramework/CharacterMovementComponent.h"

void UWarriorCharacterInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	OwingCharacter = Cast<AWarriorBaseCharacter>(TryGetPawnOwner());
	if (OwingCharacter)
	{
		OwningMovementComponent = OwingCharacter->GetCharacterMovement();
		
	}
}

void UWarriorCharacterInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (!OwingCharacter|| !OwningMovementComponent)
	{
		return;
	}

	GroundSpeed = OwingCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
	
}
