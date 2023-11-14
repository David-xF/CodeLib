#pragma once

#include <code/code.h>

#include "../util/BlockPos.h"
#include "../client/resource/shared_ptr.h"
#include "../client/resource/vector.h"

namespace mc {
    class Level {
	public:
		uint32_t getBlockId(int x, int y, int z) {
			return code::Func<uint32_t, 0x0254CCAC, Level*, int, int, int>()(this, x, y, z);
		}

		uint32_t getBlockData(int x, int y, int z) {
			return code::Func<uint32_t, 0x0254D800, Level*, int, int, int>()(this, x, y, z);
		}

        uint32_t getBlockState(const BlockPos& pos) {
            return code::Func<uint32_t, 0x0254ca88, Level*, const BlockPos&>()(this, pos);
        }

        void setData(const BlockPos& pos, int unk, int unk2, bool unk3) {
            code::Func<void, 0x0254A7E4, Level*, const BlockPos&, int, int, bool>()(this, pos, unk, unk2, unk3);
        }

		int isInWorldBounds(int x, int y, int z) {
			return code::Func<int, 0x02546BB4, Level*, int, int, int>()(this, x, y, z);
		}

        const mc_boost::shared_ptr<struct BlockEntity>& getBlockEntity(const BlockPos& pos) {
            return code::Func<const mc_boost::shared_ptr<struct BlockEntity>&, 0x025612CC, Level*, int, const BlockPos&>()(this, 0, pos);
        }

        void setBlock(const BlockPos& pos, uint32_t state, int id, bool unk) {
            code::Func<void, 0x02547678, Level*, const BlockPos&, uint32_t, int, bool>()(this, pos, state, id, unk);
        }

        bool hasSignal(const BlockPos& pos, struct Direction* dir) {
            return code::Func<bool, 0x0256767C, Level*, const BlockPos&, struct Direction*>()(this, pos, dir);
        }

        void getPlayerByName(const mc_boost::shared_ptr<struct Player>& player, const mstd::wstring& name) {
            code::Func<void, 0x02569ae4, Level*, const mc_boost::shared_ptr<struct Player>&, const mstd::wstring&>()(this, player, name);
        }

        void getAllEntities(mstd::vector<struct Entity>& ent) {
            code::Func<void, 0x02565ED8, Level*, mstd::vector<struct Entity>&>()(this, ent);
        }

		uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xC;
        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
        uint32_t field_0x20;
        uint32_t field_0x24;
        uint32_t field_0x28;
        uint32_t field_0x2C;
        uint32_t field_0x30;
        mstd::vector<mc_boost::shared_ptr<struct Entity>> entities;
        uint32_t field_0x44;
        uint32_t field_0x48;
        uint32_t field_0x4C;
        uint32_t field_0x50;
        uint32_t field_0x54;
        uint32_t field_0x58;
        uint32_t field_0x5C;
        uint32_t field_0x60;
        uint32_t field_0x64;
        uint32_t field_0x68;
        uint32_t field_0x6C;
        uint32_t field_0x70;
        uint32_t field_0x74;
        uint32_t field_0x78;
        uint32_t field_0x7C;
        uint32_t field_0x80;
        uint32_t field_0x84;
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
        mstd::vector<mc_boost::shared_ptr<struct Player>> players;
        uint32_t field_0xD4;
        uint32_t field_0xD8;
        uint32_t field_0xDC;
        uint32_t field_0xE0;
        uint32_t field_0xE4;
        uint32_t field_0xE8;
        uint32_t field_0xEC;
        uint32_t field_0xF0;
        uint32_t field_0xF4;
        uint32_t field_0xF8;
        uint32_t field_0xFC;
        uint32_t field_0x100;
        uint32_t field_0x104;
        uint32_t field_0x108;
        uint32_t field_0x10C;
        uint32_t field_0x110;
        uint32_t field_0x114;
        uint32_t field_0x118;
        uint32_t field_0x11C;
        uint32_t field_0x120;
        uint32_t field_0x124;
        uint32_t field_0x128;
        uint32_t field_0x12C;
        uint32_t field_0x130;
        uint32_t field_0x134;
        uint32_t field_0x138;
        uint32_t field_0x13C;
        uint32_t field_0x140;
        uint32_t field_0x144;
        uint32_t field_0x148;
        uint32_t field_0x14C;
        uint32_t field_0x150;
        uint32_t field_0x154;
        uint32_t field_0x158;
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
        uint32_t field_0x198;
        uint32_t field_0x19C;
        uint32_t field_0x1A0;
        uint32_t field_0x1A4;
        uint32_t field_0x1A8;
        uint32_t field_0x1AC;
        uint32_t field_0x1B0;
        uint32_t field_0x1B4;
        mstd::vector<mc_boost::shared_ptr<struct LivingEntity>> livingEntities;
        uint32_t field_0x1C8;
        uint32_t field_0x1CC;
        uint32_t field_0x1D0;
        uint32_t field_0x1D4;
        uint32_t field_0x1D8;
        uint32_t field_0x1DC;
        uint32_t field_0x1E0;
        uint32_t field_0x1E4;
        uint32_t field_0x1E8;
        uint32_t field_0x1EC;
        uint32_t field_0x1F0;
        uint32_t field_0x1F4;
        uint32_t field_0x1F8;
        uint32_t field_0x1FC;
        uint32_t field_0x200;
	};
}