// Shatz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "WarriorWeaponBase.generated.h"

UCLASS()
class WARRIOR_API AWarriorWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWarriorWeaponBase();

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapons")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapons")
	UBoxComponent* WeaponCollisionBox;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	FORCEINLINE UBoxComponent* GetWeaponCollionBox() const {return WeaponCollisionBox;}; 
	 
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
