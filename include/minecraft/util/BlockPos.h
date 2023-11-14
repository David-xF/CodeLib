#pragma once

#include <code/code.h>

namespace mc {
    class BlockPos {
	public:
		BlockPos(int _x, int _y, int _z) { 
			code::Func<BlockPos*, 0x020c3ad4, BlockPos*, int, int, int>()(this, _x, _y, _z); 
	  	}

		BlockPos() = default;

		BlockPos operator+(mc::BlockPos pos) {
			return BlockPos(x + pos.x, y + pos.y, z + pos.z);
		}

		bool operator==(const BlockPos& pos) {
			return code::Func<bool, 0x020c4bf4, BlockPos*, const BlockPos&>()(this, pos);
		}

		bool operator!=(const BlockPos& pos) {
			return code::Func<bool, 0x020c4c04, BlockPos*, const BlockPos&>()(this, pos);
		}
	  	
        int x;
        int y;
        int z;
	};
}