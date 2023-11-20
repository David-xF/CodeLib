#pragma once

#include <code/code.h>

#include "../../client/resource/shared_ptr.h"

#include "../packet/DisconnectPacket.h"

namespace mc {
    class ServerGamePacketListenerImpl {
    public:
        void send(mc_boost::shared_ptr<Packet> packet) {
            code::Func<void, 0x03249FB4, ServerGamePacketListenerImpl*, mc_boost::shared_ptr<Packet>>()(this, packet);
        }

        void disconnect(DisconnectPacket::eDisconnectReason reason) {
            code::Func<void, 0x03288878, ServerGamePacketListenerImpl*, DisconnectPacket::eDisconnectReason>()(this, reason);
        }

        void teleport(double x, double y, double z, float yaw, float pitch, bool unk1, bool unk2) {
            code::Func<void, 0x03293e88, ServerGamePacketListenerImpl*, double, double, double, float, float, bool, bool>()(this, x, y, z, yaw, pitch, unk1, unk2);
        }

		static code::Func<void, 0x032dc90c, ServerGamePacketListenerImpl*, const mc_boost::shared_ptr<struct ServerboundMovePlayerPacket>&> _handleMovePlayer;
		void handleMovePlayer(const mc_boost::shared_ptr<struct ServerboundMovePlayerPacket>& packet) {
			_handleMovePlayer(this, packet);
		}

		static code::Func<void, 0x032dff9c, ServerGamePacketListenerImpl*, const mc_boost::shared_ptr<struct ServerboundPlayerActionPacket>&> _handlePlayerAction;
		void handlePlayerAction(const mc_boost::shared_ptr<struct ServerboundPlayerActionPacket>& packet) {
			_handlePlayerAction(this, packet);
		}

		static code::Func<void, 0x032e2c64, ServerGamePacketListenerImpl*, const mc_boost::shared_ptr<struct ServerboundUseItemOnPacket>&> _handleUseItemOn;
		void handleUseItemOn(const mc_boost::shared_ptr<struct ServerboundUseItemOnPacket>& packet) {
			_handleUseItemOn(this, packet);
		}

		static code::Func<void, 0x032e9b10, ServerGamePacketListenerImpl*, const mc_boost::shared_ptr<struct ServerboundContainerClickPacket>&> _handleContainerClick;
		void handleContainerClick(const mc_boost::shared_ptr<struct ServerboundContainerClickPacket>& packet) {
			_handleContainerClick(this, packet);
		}

		static code::Func<void, 0x032f9d3c, ServerGamePacketListenerImpl*, const mc_boost::shared_ptr<struct ClientboundSoundPacket>&> _handleSoundEvent;
		void handleSoundEvent(const mc_boost::shared_ptr<struct ClientboundSoundPacket>& packet) {
			_handleSoundEvent(this, packet);
		}

		static code::Func<void, 0x032e68a4, ServerGamePacketListenerImpl*, const mc_boost::shared_ptr<struct ClientboundChatPacket>&> _handleChat;
		void handleChat(const mc_boost::shared_ptr<struct ClientboundChatPacket>& packet) {
			_handleChat(this, packet);
		}
		
        uint32_t unk_0x0;
        uint32_t unk_0x4;
	    struct Connection* connection;
        uint32_t unk_0xC;
	    uint32_t unk_0x10;
	    uint32_t unk_0x14;
	    uint32_t unk_0x18;
	    uint32_t unk_0x1C;
	    uint32_t unk_0x20;
	    uint32_t unk_0x24;
	    uint32_t unk_0x28;
	    uint32_t unk_0x2C;
	    uint32_t unk_0x30;
	    uint32_t unk_0x34;
	    uint32_t unk_0x38;
	    uint32_t unk_0x3C;
	    uint32_t unk_0x40;
	    uint32_t unk_0x44;
	    uint32_t unk_0x48;
	    uint32_t unk_0x4C;
	    uint32_t unk_0x50;
	    uint32_t unk_0x54;
	    uint32_t unk_0x58;
	    uint32_t unk_0x5C;
	    uint32_t unk_0x60;
	    uint32_t unk_0x64;
	    struct MinecraftServer* server;
	    mc_boost::shared_ptr<struct ServerPlayer> player;
	    uint32_t unk_0x74;
	    uint32_t unk_0x78;
	    uint32_t unk_0x7C;
	    uint32_t unk_0x80;
	    uint32_t unk_0x84;
	    uint32_t unk_0x88;
	    uint32_t unk_0x8C;
	    uint32_t unk_0x90;
	    uint32_t unk_0x94;
	    uint32_t unk_0x98;
	    uint32_t unk_0x9C;
	    uint32_t unk_0xA0;
	    uint32_t unk_0xA4;
	    uint32_t unk_0xA8;
	    uint32_t unk_0xAC;
	    uint32_t unk_0xB0;
	    uint32_t unk_0xB4;
	    uint32_t unk_0xB8;
	    uint32_t unk_0xBC;
	    uint32_t unk_0xC0;
	    uint32_t unk_0xC4;
	    uint32_t unk_0xC8;
	    uint32_t unk_0xCC;
	    uint32_t unk_0xD0;
	    uint32_t unk_0xD4;
	    uint32_t unk_0xD8;
	    uint32_t unk_0xDC;
	    uint32_t unk_0xE0;
	    uint32_t unk_0xE4;
	    uint32_t unk_0xE8;
	    uint32_t unk_0xEC;
	    uint32_t unk_0xF0;
	    uint32_t unk_0xF4;
	    uint32_t unk_0xF8;
	    uint32_t unk_0xFC;
	    uint32_t unk_0x100;
	    uint32_t unk_0x104;
	    uint32_t unk_0x108;
	    uint32_t unk_0x10C;
	    uint32_t unk_0x110;
	    uint32_t unk_0x114;
	    uint32_t unk_0x118;
	    uint32_t unk_0x11C;
	    uint32_t unk_0x120;
	    uint32_t unk_0x124;
	    uint32_t unk_0x128;
	    uint32_t unk_0x12C;
	    uint32_t unk_0x130;
	    uint32_t unk_0x134;
	    uint32_t unk_0x138;
	    uint32_t unk_0x13C;
	    uint32_t unk_0x140;
	    uint32_t unk_0x144;
	    uint32_t unk_0x148;
	    uint32_t unk_0x14C;
	    uint32_t unk_0x150;
	    uint32_t unk_0x154;
    };
}