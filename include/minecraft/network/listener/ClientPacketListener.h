#pragma once 

#include <code/code.h>

#include "../../client/resource/shared_ptr.h"

namespace mc {
    class ClientPacketListener {
	public:
		void send(mc_boost::shared_ptr<struct Packet> packet) {
	    	code::Func<void, 0x0304A5D8, ClientPacketListener*, mc_boost::shared_ptr<struct Packet>>()(this, packet);
		}

		void sendCommand(uint32_t commandAddr = 0x10303000) {
	    	code::Func<void, 0x0304A5D8, ClientPacketListener*, uint32_t>()(this, commandAddr);
		}

		void handleSoundEvent(const mc_boost::shared_ptr<struct ClientboundSoundPacket>& packet) {
			code::Func<void, 0x0306EB2C, ClientPacketListener*, const mc_boost::shared_ptr<struct ClientboundSoundPacket>&>()(this, packet);
    	}
	};
}