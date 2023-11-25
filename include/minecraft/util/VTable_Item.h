#pragma once

#include "VTable.h"

#include "../client/resource/shared_ptr.h"
#include "../util/InteractionHand.h"
#include "../util/BlockPos.h"

namespace mc {
    struct VTable_Item : public VTable {
    public:
        MC_VFUNC(void,         struct Item, getDefaultInstance, const mc_boost::shared_ptr<struct ItemInstance>&);
        MC_VFUNC(void,         struct Item, verifyTagAfterLoad, struct CompoundTag*);
        MC_VFUNC(void,         struct Item, GetUseTooltip, const struct ItemToolTipDataHolder&);
        MC_VFUNC(void,         struct Item, __dt__Fv, bool);
        MC_VFUNC(void,         struct Item, useOn, const mc_boost::shared_ptr<struct Player>&, const BlockPos&, InteractionHand::EInteractionHand, struct Direction*, float, float, float, bool);
        MC_VFUNC(void,         struct Item, getDestroySpeed, const mc_boost::shared_ptr<struct ItemInstance>&, struct BlockState*);
        MC_VFUNC(void,         struct Item, TestUse, struct Level*, const mc_boost::shared_ptr<struct Player>&, InteractionHand::EInteractionHand);
        MC_VFUNC(void,         struct Item, use__FP5LevelQ2_5boost25shared_ptr__tm__8_6PlayerQ2_15InteractionHand16EInteractionHand);
        MC_VFUNC(void,         struct Item, finishUsingItem__F35not_null_ptr__tm__15_12ItemInstanceP5LevelQ2_5boost33shared_ptr__tm__15_12LivingEntity);
        MC_VFUNC(void,         struct Item, getMaxStackSize__Fv);
        MC_VFUNC(void,         struct Item, getLevelDataForAuxValue__Fi);
        MC_VFUNC(bool,         struct Item, hurtEnemy, const mc_boost::shared_ptr<struct ItemInstance>&, const mc_boost::shared_ptr<struct LivingEntity>&, const mc_boost::shared_ptr<struct LivingEntity>&);
        MC_VFUNC(bool,         struct Item, mineBlock, const mc_boost::shared_ptr<struct ItemInstance>&, struct Level*, const struct BlockState*, const BlockPos&, mc_boost::shared_ptr<struct LivingEntity>&);
        MC_VFUNC(void,         struct Item, getAttackDamage__FQ2_5boost25shared_ptr__tm__8_6Entity);
        MC_VFUNC(void,         struct Item, canDestroySpecial__FPC10BlockState);
        MC_VFUNC(void,         struct Item, interactEnemy__F35not_null_ptr__tm__15_12ItemInstanceQ2_5boost25shared_ptr__tm__8_6PlayerQ2_5boost33shared_ptr__tm__15_12LivingEntityQ2_15InteractionHand16EInteractionHand);
        MC_VFUNC(bool,         struct Item, isHandEquipped__Fv);
        MC_VFUNC(bool,         struct Item, isMirroredArt__Fv);
        MC_VFUNC(void,         struct Item, getDescriptionId__Fi);
        MC_VFUNC(void,         struct Item, getDescriptionId__F35not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(void,         struct Item, getUseDescriptionId__Fv);
        MC_VFUNC(void,         struct Item, shouldOverrideMultiplayerNBT__Fv);
        MC_VFUNC(void,         struct Item, getUseDescriptionId__F35not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(void,         struct Item, inventoryTick, mc_boost::shared_ptr<struct ItemInstance>&, struct Level *, mc_boost::shared_ptr<struct Entity>&, int, bool);
        MC_VFUNC(void,         struct Item, getColor__F35not_null_ptr__tm__15_12ItemInstancei);
        MC_VFUNC(bool,         struct Item, isComplex__Fv);
        MC_VFUNC(void,         struct Item, onCraftedBy__F35not_null_ptr__tm__15_12ItemInstanceP5LevelQ2_5boost25shared_ptr__tm__8_6Player);
        MC_VFUNC(int,          struct Item, getUseDuration, const mc_boost::shared_ptr<struct ItemInstance>&);
        MC_VFUNC(void,         struct Item, getUseAnimation__CF36not_null_ptr__tm__16_C12ItemInstance);
        MC_VFUNC(struct Item*, struct Item, releaseUsing, const mc_boost::shared_ptr<struct ItemInstance>&, struct Level*, const mc_boost::shared_ptr<struct LivingEntity>&, int);
        MC_VFUNC(void,         struct Item, appendHoverText__F35not_null_ptr__tm__15_12ItemInstanceQ2_5boost25shared_ptr__tm__8_6PlayerPQ2_3std66vector__tm__52_10HtmlStringQ2_3std30allocator__tm__13_10HtmlStringb);
        MC_VFUNC(void,         struct Item, getName__F35not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(bool,         struct Item, isFoil__F35not_null_ptr__tm__15_12ItemInstance, mc_boost::shared_ptr<struct ItemInstance>);
        MC_VFUNC(void,         struct Item, getRarity__F35not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(bool,         struct Item, isEnchantable__F35not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(void,         struct Item, getEnchantmentValue__Fv);
        MC_VFUNC(void,         struct Item, mayBePlacedInAdventureMode__Fv);
        MC_VFUNC(bool,         struct Item, isValidRepairItem__F35not_null_ptr__tm__15_12ItemInstanceT1);
        MC_VFUNC(void,         struct Item, getDefaultAttributeModifiers__FPC13EquipmentSlot);
        MC_VFUNC(void,         struct Item, registerIcons__FP12IconRegister);
        MC_VFUNC(void,         struct Item, hasMultipleSpriteLayers__Fv);
        MC_VFUNC(void,         struct Item, getLayerIcon__FiT135not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(void,         struct Item, getIconType__Fv);
        MC_VFUNC(void,         struct Item, getIcon__Fi);
        MC_VFUNC(void,         struct Item, getIcon__F35not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(void,         struct Item, GetArmorType__Fv);
        MC_VFUNC(void,         struct Item, GetOverrideCount__Fv);
        MC_VFUNC(void,         struct Item, GetOverrideCountColour__Fv);
        MC_VFUNC(void,         struct Item, GetOverrideCountIcon__F35not_null_ptr__tm__15_12ItemInstance);
    };
}