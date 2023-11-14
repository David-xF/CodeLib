#pragma once

#include <code/code.h>

#include "../Packet.h"

namespace mc {
    class ServerboundMovePlayerPacket : public Packet {
    public:
        ServerboundMovePlayerPacket(double x, double y, double z, bool isOnGround, bool isFlying) {
            code::Func<void, 0x028AD6C4, ServerboundMovePlayerPacket*, bool, bool, double, double, double, double>()(this, isOnGround, isFlying, x, y, y, z);
        }

        ServerboundMovePlayerPacket(double x, double y, double z, float yaw, float pitch, bool isOnGround, bool isFlying) {
            code::Func<void, 0x028ad398, ServerboundMovePlayerPacket*, bool, bool, double, double, double, float, float>()(this, isOnGround, isFlying, x, y, z, yaw, pitch);
        }

        ServerboundMovePlayerPacket(float yaw, float pitch, bool isOnGround, bool isFlying) {
            code::Func<void, 0x028ad954, ServerboundMovePlayerPacket*, bool, bool, float, float>()(this, isOnGround, isFlying, yaw, pitch);
        }

        uint32_t field_0x10;
        uint32_t field_0x14;
        double x;
        double y;
        double Z;
        float yaw;
        float pitch;
        uint32_t field_0x38;
        uint32_t field_0x3C;
    };
}