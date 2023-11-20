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

		template<typename T>
		void forBox(int radius, void(*func)(mc::BlockPos pos, T& context), T context) {
			for (int _x = -radius; _x <= radius; _x++) {
				for (int _y = -radius; _y <= radius; _y++) {
					for (int _z = -radius; _z <= radius; _z++) {
						func({_x + x, _y + y, _z + z}, context);
					}
				}
			}
		}
	  	
        int x;
        int y;
        int z;
	};
}