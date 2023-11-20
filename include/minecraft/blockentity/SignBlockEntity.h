#pragma once

#include <code/code.h>

#include "BlockEntity.h"

#include "../client/resource/shared_ptr.h"
#include "../client/resource/wstring.h"

namespace mc {
    class SignBlockEntity : public BlockEntity {
    public:
		void SetMessage(int index, const mstd::wstring& message) {
			code::Func<void, 0x02913680, SignBlockEntity*, int, const mstd::wstring&>()(this, index, message);
		}

		const mc_boost::shared_ptr<struct Packet>& getUpdatePacket() {
			return code::Func<const mc_boost::shared_ptr<struct Packet>&, 0x029144b8, SignBlockEntity*>()(this);
		}

		static uint64_t getType() {
			return code::Func<uint64_t, 0x0297BF48>()();
		}

		static code::Func<bool, 0x02915610, SignBlockEntity*, mc_boost::shared_ptr<struct Player>> _executeClickCommands;
		bool executeClickCommands(mc_boost::shared_ptr<struct Player> player) {
			return _executeClickCommands(this, player);
		}

		uint32_t field_0x28;
		uint32_t field_0x2C;
		uint32_t field_0x30;
		uint32_t field_0x34;
		uint32_t field_0x38;
		uint32_t field_0x3C;
		uint32_t field_0x40;
		uint32_t field_0x44;
		uint32_t field_0x48;
        uint32_t field_0x4C;
        uint32_t field_0x50;
        mstd::wstring line1; 
		mstd::wstring line2;
		mstd::wstring line3;
		mstd::wstring line4;
		uint32_t field_0xC8;
		uint32_t field_0xCC; 
    };
}