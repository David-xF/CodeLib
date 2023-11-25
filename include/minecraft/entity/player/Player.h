#pragma once

#include <code/code.h>

#include "../LivingEntity.h"
#include "PlayerUID.h"

#include "../../client/resource/shared_ptr.h"

#include "../../util/Abilities.h"
#include "../../util/FoodData.h"

namespace mc {
    // 0x0270E1A8
    class Player : public LivingEntity {
    public:
		Player(struct Level* _level, const mstd::wstring& _name) {
			code::Func<void, 0x0270E1A8, Player*, struct Level*, const mstd::wstring&>()(this, _level, _name);
		}

        void getDisplayName(mstd::wstring& ret) {
			code::Func<void, 0x026D2EDC, Player*, mstd::wstring&>()(this, ret);
		}
		
		bool isAllowedToFly() {
			return code::Func<bool, 0x0271AA10, Player*>()(this);
		}

        float getEyeHeight() {
			return code::Func<float, 0x027272C8, Player*>()(this);
		}
		
		// 0272A178 # Player::setXuid((PlayerUID))  sizeof (PlayerUID = )
		void setXuid(const PlayerUID& uid) {
			code::Func<void, 0x0272A178, Player*, const PlayerUID&>()(this, uid);
		}

		void hurt(DamageSource* source, float dmg) {
			code::Func<void, 0x0271aa90, Player*, DamageSource*, float>()(this, source, dmg);
		}

		bool isAllowedToMine() {
			return code::Func<bool, 0x0272B284, Player*>()(this);
		}

		bool isAllowedToAttackAnimals() {
			return code::Func<bool, 0x0272B304, Player*>()(this);
		}

		bool isAllowedToUse(struct Block* block) {
			return code::Func<bool, 0x0272a584, Player*, struct Block*>()(this, block);
		}

		bool isModerator() {
			return code::Func<bool, 0x0272B714, Player*>()(this);
		}

		float getUnderwaterLightLevel() {
			return code::Func<float, 0x0272CEE0, Player*>()(this);
		}

		void setUnderwaterLightLevel(float underwaterLightLevel) {
			code::Func<void, 0x0272CEE8, Player*, float>()(this, underwaterLightLevel);
		}

		void addItem(const mc_boost::shared_ptr<struct ItemInstance>& item) {
			code::Func<void, 0x027265c4, Player*, const mc_boost::shared_ptr<struct ItemInstance>&>()(this, item);
		}

		void setRespawnPosition(BlockPos* pos, bool isForced) {
			code::Func<void, 0x02721D64, Player*, BlockPos*, bool>()(this, pos, isForced);
		}

		float getAbsorptionAmount() {
			return code::Func<float, 0x02727718, Player*>()(this);
		}

		float getArmorCoverPercentage() {
			return code::Func<float, 0x0271b884, Player*>()(this);
		}

		float getCurrentItemAttackStrengthDelay() {
			return code::Func<float, 0x02728794, Player*>()(this);
		}

		void jumpFromGround() {
			code::Func<void, 0x02721E08, Player*>()(this);
		}

		static uint64_t GetType() {
			return code::Func<uint64_t, 0x027CD2F4>()();
		}

		// void setItemSlot(EquipmentSlot const * slot, ItemInstance* item) {
		// 	code::Func<void, 0x02725F70, Player*, EquipmentSlot const *, ItemInstance*>()(this, slot, item);
		// }

		
		struct Inventory* inventory;
		uint32_t field_0x5F4;
		uint32_t field_0x5F8;
		uint32_t field_0x5FC;
		struct AbstractContainerMenu* notInUseContainer;
		struct AbstractContainerMenu* currentContainer;
		FoodData foodData;
		uint32_t field_0x61C;
		uint32_t field_0x620;
		uint32_t field_0x624;
		uint32_t field_0x628;
		mstd::wstring customSkinPath;
		mstd::wstring customCapePath;
		uint32_t field_0x66C;
		uint32_t field_0x670;
		uint32_t field_0x674;
		uint32_t field_0x678;
		uint32_t field_0x67C;
		uint32_t field_0x680;
		uint32_t field_0x684;
		uint32_t field_0x688;
		uint32_t field_0x68C;
		uint32_t field_0x690;
		uint32_t field_0x694;
		uint32_t field_0x698;
		uint32_t field_0x69C;
		mstd::wstring _name;
		bool isSleeping;
		bool field_0x6C1;
		bool field_0x6C2;
		bool field_0x6C3;
		uint32_t field_0x6C4;
		int sleeptimer; // max 0x64
		uint32_t field_0x6CC;
		uint32_t field_0x6D0;
		uint32_t field_0x6D4;
		uint32_t field_0x6D8;
		uint32_t field_0x6DC;
		uint32_t field_0x6E0;
		uint32_t field_0x6E4;
		uint32_t field_0x6E8;
		uint32_t field_0x6EC;
		uint32_t field_0x6F0;
		uint32_t field_0x6F4;
		uint32_t field_0x6F8;
		uint32_t field_0x6FC;
		uint32_t field_0x700;
		uint32_t field_0x704;
		uint32_t field_0x708;
		Abilities abilities;
		uint32_t xpLevel;
		uint32_t rawXp;
		float xpProgress;
		mc_boost::shared_ptr<Entity> thrownItem;
		uint32_t field_0x730;
		float redirection; // default = 0.02f
		uint32_t field_0x738;
		uint32_t field_0x73C;
		mstd::wstring name;
		uint32_t field_0x760;
		uint32_t field_0x764;
		uint32_t field_0x768;
		uint32_t field_0x76C;
		uint32_t field_0x770;
		uint32_t field_0x774;
		uint32_t field_0x778;
		struct CameraController* field_0x77C; // Is nullptr?
		uint32_t field_0x780;
		PlayerUID uuid;
		PlayerUID uuid2;
		PlayerUID uuid3;
		uint32_t field_0x7C0;
		uint32_t field_0x7C4;
		uint32_t field_0x7C8;
		uint32_t field_0x7CC;
		uint32_t field_0x7D0;
		uint32_t field_0x7D4;
		uint32_t field_0x7D8;
		uint32_t customSkinId;
		uint32_t customCapeId;
		uint32_t colourIndex;
		uint32_t field_0x7E8;
		uint32_t field_0x7EC;
		uint32_t field_0x7F0;
		uint32_t field_0x7F4;
		uint32_t field_0x7F8;
		uint32_t field_0x7FC;
		uint32_t field_0x800;
		uint32_t field_0x804;
		uint32_t field_0x808;
		Entity* entitySpectating;
		uint32_t field_0x810;
		uint32_t field_0x814;
		uint32_t field_0x818;
		uint32_t field_0x81C;
		uint32_t field_0x820;
		uint32_t field_0x824;
		uint32_t field_0x828;
		uint32_t field_0x82C;
		uint32_t field_0x830;
		uint32_t field_0x834;
		uint32_t field_0x838;
		uint32_t field_0x83C;
		float field_0x840;
    	float field_0x844;
    	float field_0x848;
    	float field_0x84C;
		uint32_t field_0x850;
		float field_0x854; // Underwater Light Level
		float field_0x858; // Underwater Vision Scale
		uint32_t field_0x85C;
		uint32_t field_0x860;
		uint32_t field_0x864;
    };
}