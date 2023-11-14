#pragma once

#include <inttypes.h>

#include "Packet.h"

namespace mc {
    class DisconnectPacket : public Packet {
    public:
        enum eDisconnectReason : int {
            CONNECTION_LOST = 0,
            HOST_LEFT = 1,
            KICKED_FOR_FLYING = 7,
            KICKED_FROM_THE_GAME = 8,
            SERVER_IS_FULL = 13,
            OLDER_VERSION = 14,
            NEWER_VERSION = 15,
            CONTENT_PRIVILEGE_TOO_LOW = 20,
            TOO_RESTRICTIVE = 21,
            NOT_FRIENDS_WITH_ANYONE = 25,
            PREVIOUSLY_KICKED = 26,
            FRIENDS_OF_FRIENDS = 27,
            MII_ALREADY_SELECTED = 30,
            NO_GAME_FOUND = 32,
        };

        uint32_t field_0x10;
        uint32_t field_0x14;
        eDisconnectReason reason;
    };
}