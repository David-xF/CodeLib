#include <code/code.h>

#include <minecraft/mc.h>

mc::Vec3 getLookAt(float yaw, float pitch) {
    return mc::Vec3(
        fabs(sinf(degToRad(pitch - 90.0f))) * sinf(degToRad(yaw   - 180.0f)),
                                              sinf(degToRad(pitch - 180.0f)),
        fabs(sinf(degToRad(pitch - 90.0f))) * cosf(degToRad(yaw))
    );
}

namespace mc {
    VTable_Item* TestItem_default_vtbl = nullptr;
    class TestItem : public BowItem {
    public:
        TestItem() : BowItem() {
            if (!TestItem_default_vtbl) {
                TestItem_default_vtbl = (VTable_Item*) new uint8_t[sizeof(VTable_Item)];
                memcpy(TestItem_default_vtbl, BowItem::default_vtbl, sizeof(VTable_Item));
                TestItem_default_vtbl->releaseUsing = &TestItem::releaseUsing;
                TestItem_default_vtbl->hurtEnemy = &TestItem::hurtEnemy;
                TestItem_default_vtbl->mineBlock = &TestItem::mineBlock;
            }

            vtbl = TestItem_default_vtbl;
            iconName = Item::byId(BowItem::default_itemId)->iconName.c_str();
        }

        static Item* releaseUsing(Item* _this, const mc_boost::shared_ptr<struct ItemInstance>& instance, struct Level* level, const mc_boost::shared_ptr<struct LivingEntity>& entity, int duration) {
            Vec3 lookAt = getLookAt(entity->yaw, entity->pitch);
            lookAt *= 3.0f;
            entity->push(lookAt.x, lookAt.y, lookAt.z);
            return _this;
        }

        static bool hurtEnemy(Item* _this, const mc_boost::shared_ptr<struct ItemInstance>& item, const mc_boost::shared_ptr<struct LivingEntity>& attacked, const mc_boost::shared_ptr<struct LivingEntity>& attacker) {
            Vec3 lookAt = getLookAt(attacker->yaw, attacker->pitch);
            lookAt *= 3.0f;
            attacker->push(lookAt.x, lookAt.y, lookAt.z);
            return false;
        }

        static bool mineBlock(Item* _this, const mc_boost::shared_ptr<struct ItemInstance>& item, struct Level* lvl, const struct BlockState* state, const BlockPos& pos, mc_boost::shared_ptr<struct LivingEntity>& entity) {
            mc_printf(L"Broke Block At (%d %d %d)", pos.x, pos.y, pos.z);
            return false;   
        }
    };
}

DECL_FUNCTION(void, MinecraftWorld_RunStaticCtors__Fv, void) {
    real_MinecraftWorld_RunStaticCtors__Fv();
    
    // Something like minecraft:bow would be modded:custom_item 
    mc::ResourceLocation loc(L"modded", L"custom_item");
    mc::TestItem* testItem = new mc::TestItem();
    
    // Set Item Id to 1, so we can get it from the Creative Inventory
    mc::Item::registerItem(1, loc, testItem);
}

int c_main(void*) {
    code::init();

    REPLACE(0x026112C0, MinecraftWorld_RunStaticCtors__Fv);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}