#pragma once

#include "Entity.h"

namespace mc {
    class LivingEntity : public Entity {
    public:
        void setHealth(float amount) {
            code::Func<void, 0x02579530, LivingEntity*, float>()(this, amount);
        }

		float getMaxHealth() {
			return code::Func<float, 0x0257f6a8, LivingEntity*>()(this);
		}

		int getArrowCount() {
			return code::Func<int, 0x0257F6F0, LivingEntity*>()(this);
		}

		void hurt(struct DamageSource* source, float dmg) {
			code::Func<void, 0x025796cc, LivingEntity*, struct DamageSource*, float>()(this, source, dmg);
		}

		float getHealth() {
			return code::Func<float, 0x025793f8, LivingEntity*>()(this);
		}

		static uint64_t GetType() {
			return code::Func<uint64_t, 0x026027a4>()();
		}

		bool hasEffect(struct MobEffect* effect) {
			return code::Func<bool, 0x025781EC, LivingEntity*, struct MobEffect*>()(this, effect);
		}

		struct MobEffectInstance* getEffect(struct MobEffect* effect) {
			return code::Func<struct MobEffectInstance*, 0x0257822c, LivingEntity*, struct MobEffect*>()(this, effect);
		}

		int getFallFlyingTicks() {
			return code::Func<int, 0x0258dae0, LivingEntity*>()(this);
		}

		void addEffect(struct MobEffectInstance* effect) {
			code::Func<void, 0x0257840C, LivingEntity*, struct MobEffectInstance*>()(this, effect);
		}

        uint32_t field_0x350;
		struct CombatTracker* field_0x354;
		uint32_t field_0x358;
		uint32_t field_0x35C;
		double field_0x360;
		double field_0x368;
		double field_0x370;
		uint32_t field_0x378;
		uint32_t field_0x37C;
		uint32_t field_0x380;
		uint32_t field_0x384;
		uint32_t field_0x388;
		uint32_t field_0x38C;
		uint32_t field_0x390;
		uint32_t field_0x394;
		uint32_t field_0x398;
		uint32_t field_0x39C;
		uint32_t field_0x3A0;
		uint32_t field_0x3A4;
		uint32_t field_0x3A8;
		uint32_t field_0x3AC;
		uint32_t field_0x3B0;
		uint32_t field_0x3B4;
		uint32_t field_0x3B8;
		uint32_t field_0x3BC;
		uint32_t field_0x3C0;
		uint32_t field_0x3C4;
		uint32_t field_0x3C8;
		uint32_t field_0x3CC;
		uint32_t field_0x3D0;
		uint32_t field_0x3D4;
		uint32_t field_0x3D8;
		float field_0x3DC;
		uint32_t field_0x3E0;
		uint32_t field_0x3E4;
		float field_0x3E8;
		uint32_t field_0x3EC;
		uint32_t field_0x3F0;
		uint32_t field_0x3F4;
		uint32_t field_0x3F8;
		uint32_t field_0x3FC;
		uint32_t field_0x400;
		uint32_t field_0x404;
		uint32_t field_0x408;
		uint32_t field_0x40C;
		uint32_t field_0x410;
		uint32_t field_0x414;
		uint32_t field_0x418;
		uint32_t field_0x41C;
		uint32_t field_0x420;
		uint32_t field_0x424;
		uint32_t field_0x428;
		uint32_t field_0x42C;
		uint32_t field_0x430;
		uint32_t field_0x434;
		uint32_t field_0x438;
		uint32_t field_0x43C;
		uint32_t field_0x440;
		uint32_t field_0x444;
		uint32_t field_0x448;
		uint32_t field_0x44C;
		mstd::wstring field_0x450;
		uint32_t field_0x470;
		uint32_t field_0x474;
		uint32_t field_0x478;
		uint32_t field_0x47C;
		uint32_t field_0x480;
		uint32_t field_0x484;
		uint32_t field_0x488;
		uint32_t field_0x48C;
		uint32_t field_0x490;
		uint32_t field_0x494;
		uint32_t field_0x498;
		uint32_t field_0x49C;
		uint32_t field_0x4A0;
		uint32_t jumping;
		uint32_t field_0x4A8;
		uint32_t field_0x4AC;
		uint32_t field_0x4B0;
		uint32_t field_0x4B4;
		uint32_t field_0x4B8;
		uint32_t field_0x4BC;
		uint32_t field_0x4C0;
		uint32_t field_0x4C4;
		uint32_t field_0x4C8;
		uint32_t field_0x4CC;
		uint32_t field_0x4D0;
		uint32_t field_0x4D4;
		uint32_t field_0x4D8;
		uint32_t field_0x4DC;
		uint32_t field_0x4E0;
		uint32_t field_0x4E4;
		uint32_t field_0x4E8;
		uint32_t field_0x4EC;
		uint32_t field_0x4F0;
		uint32_t field_0x4F4;
		uint32_t field_0x4F8;
		uint32_t field_0x4FC;
		uint32_t field_0x500;
		uint32_t field_0x504;
		uint32_t field_0x508;
		uint32_t field_0x50C;
		uint32_t field_0x510;
		uint32_t field_0x514;
		uint32_t field_0x518;
		uint32_t field_0x51C;
		uint32_t bowPower; // IDK has something to do with Bows i guess
		uint32_t field_0x524; // idk
		BlockPos field_0x528;
		uint32_t field_0x534;
		uint32_t field_0x538;
		uint32_t field_0x53C;
		uint32_t field_0x540;
		uint32_t field_0x544;
		uint32_t field_0x548;
		uint32_t field_0x54C;
		uint32_t field_0x550;
		uint32_t field_0x554;
		uint32_t field_0x558;
		uint32_t field_0x55C;
		uint32_t field_0x560;
		uint32_t field_0x564;
		uint32_t field_0x568;
		uint32_t field_0x56C;
		uint32_t field_0x570;
		uint32_t field_0x574;
		uint32_t field_0x578;
		uint32_t field_0x57C;
		uint32_t field_0x580;
		uint32_t field_0x584;
		uint32_t field_0x588;
		uint32_t field_0x58C;
		uint32_t field_0x590;
		uint32_t field_0x594;
		uint32_t field_0x598;
		uint32_t field_0x59C;
		uint32_t field_0x5A0;
		uint32_t field_0x5A4;
		uint32_t field_0x5A8;
		uint32_t field_0x5AC;
		uint32_t field_0x5B0;
		uint32_t field_0x5B4;
		uint32_t field_0x5B8;
		uint32_t field_0x5BC;
		uint32_t field_0x5C0;
		uint32_t field_0x5C4;
		uint32_t field_0x5C8;
		uint32_t field_0x5CC;
		uint32_t field_0x5D0;
		uint32_t field_0x5D4;
		uint32_t field_0x5D8;
		uint32_t field_0x5DC;
		uint32_t field_0x5E0;
		uint32_t field_0x5E4;
		uint32_t field_0x5E8;
		uint32_t field_0x5EC;
    };
}