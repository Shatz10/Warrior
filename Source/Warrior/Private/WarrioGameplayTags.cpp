#include "WarriorGameplayTags.h"

namespace WarriorGameplayTags
{
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move")
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look")
	UE_DEFINE_GAMEPLAY_TAG(Input_Ability_EquipAxe, "Input.Ability.EquipAxe")
	UE_DEFINE_GAMEPLAY_TAG(Input_Ability_UnequipAxe, "Input.Ability.UnequipAxe")
	
	UE_DEFINE_GAMEPLAY_TAG(PlayerTag_Weapon_Axe, "Player.Weapon.Axe")

	// Event Tags
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Axe, "Player.Event.Equip.Axe")
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_Axe, "Player.Event.Unequip.Axe")
}
