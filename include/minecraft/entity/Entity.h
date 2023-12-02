#pragma once

#include <code/code.h>

#include "../client/resource/wstring.h"
#include "../client/resource/shared_ptr.h"

#include "../util/EntityTickCache.h"
#include "../util/Vec3.h"

namespace mc {
    class Entity {
    public:
        Entity() {

        }

		void setupForSpawn(const mstd::wstring& name, Entity* namer) {
			mstd::wstring playerUUID;
    		namer->getStringUUID(playerUUID);
    		this->setCustomName(name, playerUUID, true);

			// I don't know (Don't ask me)
    		uint32_t* data = new uint32_t[4];
    		data[0] = 1;
    		data[1] = 1;
    		data[2] = (uint32_t) mc::Entity::spawn_entity_vtbl;
    		data[3] = (uint32_t) this;
    		this->this_shared = mc_boost::shared_ptr<mc::Entity>(this, (uint32_t) data);
		}

		void setPos(double _x, double _y, double _z) {
			code::Func<void, 0x023298e0, Entity*, double, double, double>()(this, _x, _y, _z);
		}

		void setPos(const Vec3& pos) {
			code::Func<void, 0x023298e0, Entity*, double, double, double>()(this, pos.x, pos.y, pos.z);
		}

		void moveTo(double _x, double _y, double _z, float _yaw = 1.0f, float _pitch = 1.0f) {
			code::Func<void, 0x0233474c, Entity*, double, double, double, float, float>()(this, _x, _y, _z, _yaw, _pitch);
		}

		void moveTo(const Vec3& pos, float _yaw = 1.0f, float _pitch = 1.0f) {
			code::Func<void, 0x0233474c, Entity*, double, double, double, float, float>()(this, pos.x, pos.y, pos.z, _yaw, _pitch);
		}

		float getEyeHeight() {
			return code::Func<float, 0x02347618, Entity*>()(this);
		}

		uint64_t type() {
    	    uint32_t typeAddr = ((uint32_t*) vtable)[3];

			// template from code::Func
			// Can't be used, typeAddr is not Constant
    	    // ((ret(*)(Args...))(addr))(args...)
			return ((uint64_t(*)())(typeAddr))();
    	}

		void getStringUUID(const mstd::wstring& str) {
			code::Func<void, 0x0234651C, Entity*, const mstd::wstring&>()(this, str);
		}

		void setCustomName(const mstd::wstring& str1, const mstd::wstring& str2, bool unk) {
			code::Func<void, 0x023467E4, Entity*, const mstd::wstring&, const mstd::wstring&, bool>()(this, str1, str2, unk);
		}

		void push(double _x, double _y, double _z) {
			code::Func<void, 0x02334EF4, Entity*, double, double, double>()(this, _x, _y, _z);
		}

		void push(const Vec3& pos) {
			code::Func<void, 0x02334EF4, Entity*, double, double, double>()(this, pos.x, pos.y, pos.z);
		}

		void startRiding(const mc_boost::shared_ptr<Entity>& entity, bool unk) {
			code::Func<void, 0x0233BEA0, Entity*, const mc_boost::shared_ptr<Entity>&, bool>()(this, entity, unk);
		}

		const Vec3& calculateViewVector() {
			return code::Func<const Vec3&, 0x02334FB8, Entity*>()(this);
		}

		void setSilent(bool state) {
			code::Func<void, 0x02331394, Entity*, bool>()(this, state);
		}

		void setNoGravity(bool state) {
			code::Func<void, 0x023314a4, Entity*, bool>()(this, state);
		}

		void remove() {
			code::Func<void, 0x0232b538, Entity*>()(this);
		}

		bool isSneaking() {
			return code::Func<bool, 0x02340568, Entity*>()(this);
		}

		bool getSharedFlag(int index) {
			return code::Func<bool, 0x023369b8, Entity*, int>()(this, index);
		}

		void setSharedFlag(int index, bool state) {
			code::Func<void, 0x0232bb18, Entity*, int, bool>()(this, index, state);
		}

		void setCustomNameVisible(bool state) {
			code::Func<void, 0x02347228, Entity*, bool>()(this, state);
		}

		void setInvulnerable(bool state) {
			code::Func<void, 0x023418dc, Entity*, bool>()(this, state);
		}

		DEFINE_STATIC_VAR(struct VTable*, spawn_entity_vtbl, 0x100CA7B4);
        
        mc_boost::shared_ptr<Entity> this_shared;
		void* anotherVtbl; // Will look at later
		uint32_t entityId;
		uint32_t field_0x10;
		mstd::vector<void*> weak_ptr_Entity;
		EntityTickCache tickCache;        
		mstd::vector<struct AABB> vec_aabb;
		struct AABB* _aabb; 
		uint32_t field_0x88;
		uint32_t field_0x8C;  
		uint32_t field_0x90; 
		uint32_t field_0x94; 
		uint32_t field_0x98; 
		uint32_t field_0x9C; 
		uint32_t field_0xA0; 
		uint32_t field_0xA4; 
		uint32_t field_0xA8; 
		uint32_t field_0xAC; 
		uint32_t field_0xB0;
		uint32_t field_0xB4; 
		uint32_t field_0xB8;
		uint32_t field_0xBC; 
		uint32_t field_0xC0; 
		uint32_t field_0xC4; 
		Vec3 field_0xC8;
		float field_0xE0; 
		float field_0xE4; 
		uint32_t field_0xE8;
		mc_boost::shared_ptr<Entity> vehicle;
		uint32_t field_0xF4;
		struct Level* lvl;  
		uint32_t field_0xFC; 
		uint32_t field_0x100;
		uint32_t field_0x104;
		uint32_t field_0x108;
		uint32_t field_0x10C;
		uint32_t field_0x110;
		Vec3 position;       
		Vec3 motion;  
		float yaw;         
		float pitch;       
		float oldYaw;  
		float oldPitch;  
		struct AABB* boundingBox; 
		uint32_t field_0x15C;
		uint32_t field_0x160;
		uint32_t field_0x164;
		uint32_t field_0x168;
		uint32_t field_0x16C;
		uint32_t field_0x170;
		uint32_t field_0x174;
		uint32_t field_0x178;
		uint32_t field_0x17C;
		uint32_t field_0x180;
		uint32_t field_0x184;
		uint32_t field_0x188;
		uint32_t field_0x18C;
		uint32_t field_0x190;
		uint32_t field_0x194;
		float field_0x198;
		float eyeHeight;
		uint32_t field_0x1A0;
		uint32_t field_0x1A4;
		uint32_t field_0x1A8;
		uint32_t field_0x1AC;
		uint32_t field_0x1B0;
		uint32_t field_0x1B4;
		uint32_t field_0x1B8;
		uint32_t field_0x1BC;
		uint32_t field_0x1C0;
		uint32_t field_0x1C4;
		uint32_t field_0x1C8;
		uint32_t field_0x1CC;
		uint32_t field_0x1D0;
		uint32_t field_0x1D4;
		float step;
		uint32_t blockAABB;
		uint32_t field_0x1E0;
		struct Random* random; // Random
		int totalTickCount;
		uint32_t field_0x1EC;
		uint32_t field_0x1F0;
		uint32_t field_0x1F4;
		uint32_t field_0x1F8;
		uint32_t field_0x1FC;
		uint32_t field_0x200;
		uint32_t field_0x204;
		uint32_t field_0x208;
		uint32_t field_0x20C;
		uint32_t field_0x210;
		uint32_t field_0x214;
		uint32_t field_0x218;
		uint32_t field_0x21C;
		uint32_t field_0x220;
		uint32_t field_0x224;
		uint32_t field_0x228;
		uint32_t field_0x22C;
		uint32_t field_0x230;
		uint32_t field_0x234;
		uint32_t field_0x238;
		uint32_t field_0x23C;
		uint32_t field_0x240;
		uint32_t field_0x244;
		uint32_t field_0x248;
		uint32_t field_0x24C;
		uint32_t field_0x250;
		uint32_t field_0x254;
		uint32_t field_0x258;
		uint32_t field_0x25C;
		uint32_t field_0x260;
		uint32_t field_0x264;
		uint32_t field_0x268;
		uint32_t field_0x26C;
		uint32_t field_0x270;
		uint32_t field_0x274;
		uint32_t field_0x278;
		uint32_t field_0x27C;
		uint32_t field_0x280;
		uint32_t field_0x284;
		uint32_t field_0x288;
		uint32_t field_0x28C;
		uint32_t field_0x290;
		uint32_t field_0x294;
		uint32_t field_0x298;
		uint32_t field_0x29C;
		uint32_t field_0x2A0;
		uint32_t field_0x2A4;
		uint32_t field_0x2A8;
		uint32_t field_0x2AC;
		uint32_t field_0x2B0;
		uint32_t field_0x2B4;
		uint32_t field_0x2B8;
		uint32_t field_0x2BC;
		uint32_t field_0x2C0;
		uint32_t field_0x2C4;
		uint32_t field_0x2C8;
		uint32_t field_0x2CC;
		uint32_t field_0x2D0;
		uint32_t field_0x2D4;
		uint32_t field_0x2D8;
		uint32_t field_0x2DC;
		uint32_t field_0x2E0;
		uint32_t field_0x2E4;
		uint32_t field_0x2E8;
		uint32_t field_0x2EC;
		uint32_t field_0x2F0;
		uint32_t field_0x2F4;
		uint32_t field_0x2F8;
		uint32_t field_0x2FC;
		uint32_t field_0x300;
		uint32_t field_0x304;
		uint32_t field_0x308;
		uint32_t field_0x30C;
		uint32_t field_0x310;
		uint32_t field_0x314;
		uint32_t field_0x318;
		uint32_t field_0x31C;
		uint32_t field_0x320;
		uint32_t field_0x324;
		uint32_t field_0x328;
		uint32_t field_0x32C;
		uint32_t field_0x330;
		uint32_t field_0x334;
		uint32_t skinAnim;
		uint32_t field_0x33C;
		uint32_t field_0x340;
		int field_0x344; // bge 0x14 | field_0x344 = 0 
		struct VTable_Entity* vtable;
		uint32_t field_0x34C;
    };
}