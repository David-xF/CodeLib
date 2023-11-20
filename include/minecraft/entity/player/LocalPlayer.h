#pragma once

#include <code/code.h>

#include "Player.h"
#include "../../util/InteractionHand.h"

// 0318ABFC
namespace mc {
    class LocalPlayer : public Player {
    public:
		void playSound(struct SoundEvent* sound, float vol = 1.0f, float pitch = 1.0f) {
			code::Func<void, 0x031EA16C, float, float, LocalPlayer*, struct SoundEvent*>()(vol, pitch, this, sound);
		}

		void setAndBroadcastCustomSkin(uint32_t skinID) {
			code::Func<void, 0x031F3A30, LocalPlayer*, uint32_t>()(this, skinID);
		}

		void setAndBroadcastCustomCape(uint32_t capeID) {
			code::Func<void, 0x031F3A40, LocalPlayer*, uint32_t>()(this, capeID);
		}

        float getDamageTaken() {
            return code::Func<float, 0x031F3A50, LocalPlayer*>()(this);
        }

		struct GameType* GetGameType() {
			return code::Func<struct GameType*, 0x031f4114, LocalPlayer*>()(this);
		}

		void getCarriedItem(mc_boost::shared_ptr<struct ItemInstance>& item) {
            code::Func<void, 0x031F3AC4, LocalPlayer*, mc_boost::shared_ptr<struct ItemInstance>&>()(this, item);
        }

        bool isSneaking() {
            return code::Func<bool, 0x031EC5B4, LocalPlayer*>()(this);
        }

        static code::Func<void, 0x031E7D74, LocalPlayer*, mc::InteractionHand::EInteractionHand> _swing;
        void swing(mc::InteractionHand::EInteractionHand hand) {
            _swing(this, hand);
        }

        void openContainer(const mc_boost::shared_ptr<struct Container>& container) {
            code::Func<void, 0x031EAAC8, LocalPlayer*, const mc_boost::shared_ptr<struct Container>&>()(this, container);
        }

		uint32_t field_0x868;
        uint32_t field_0x86C;
        uint32_t field_0x870;
        uint32_t field_0x874;
        struct ClientPacketListener* listener;
        uint32_t field_0x87C;
        uint32_t field_0x880;
        uint32_t field_0x884;
        uint32_t field_0x888;
        uint32_t field_0x88C;
        uint32_t field_0x890;
        uint32_t field_0x894;
        uint32_t field_0x898;
        uint32_t field_0x89C;
        uint32_t field_0x8A0;
        uint32_t field_0x8A4;
        uint32_t field_0x8A8;
        uint32_t field_0x8AC;
        uint32_t field_0x8B0;
        struct ConsoleUIController* uiController;
        uint32_t field_0x8B8;
        uint32_t field_0x8BC;
        uint32_t field_0x8C0;
        uint32_t field_0x8C4;
        uint32_t field_0x8C8;
        uint32_t field_0x8CC;
        uint32_t field_0x8D0;
        uint32_t field_0x8D4;
        uint32_t field_0x8D8;
        uint32_t field_0x8DC;
        uint32_t field_0x8E0;
        uint32_t field_0x8E4;
        uint32_t field_0x8E8;
        uint32_t field_0x8EC;
        uint32_t field_0x8F0;
        uint32_t field_0x8F4;
        uint32_t field_0x8F8;
        uint32_t field_0x8FC;
        uint32_t field_0x900;
        uint32_t field_0x904;
        uint32_t field_0x908;
        uint32_t field_0x90C;
        uint32_t field_0x910;
        uint32_t field_0x914;
        uint32_t field_0x918;
        uint32_t field_0x91C;
        uint32_t field_0x920;
        uint32_t field_0x924;
        uint32_t field_0x928;
        uint32_t field_0x92C;
        uint32_t field_0x930;
        uint32_t field_0x934;
        uint32_t field_0x938;
        uint32_t field_0x93C;
        uint32_t field_0x940;
        uint32_t field_0x944;
		uint32_t field_0x948;
		uint32_t field_0x94C;
		uint32_t field_0x950;
        uint32_t field_0x954;
        uint32_t field_0x958;
        uint32_t field_0x95C;
		uint32_t field_0x960;
        uint32_t field_0x964;
        uint32_t field_0x968;
        uint32_t field_0x96C;
		uint32_t field_0x970;
        uint32_t field_0x974;
        uint32_t field_0x978;
        uint32_t field_0x97C;
		uint32_t field_0x980;
        uint32_t field_0x984;
        uint32_t field_0x988;
        uint32_t field_0x98C;
		uint32_t field_0x990;
        uint32_t field_0x994;
        uint32_t field_0x998;
        uint32_t field_0x99C;
		uint32_t field_0x9A0;
        uint32_t field_0x9A4;
        uint32_t field_0x9A8;
        uint32_t field_0x9AC;
		uint32_t field_0x9B0;
        uint32_t field_0x9B4;
        uint32_t field_0x9B8;
        uint32_t field_0x9BC;
		uint32_t field_0x9C0;
        uint32_t field_0x9C4;
        uint32_t field_0x9C8;
        uint32_t field_0x9CC;
		uint32_t field_0x9D0;
        uint32_t field_0x9D4;
        uint32_t field_0x9D8;
        uint32_t field_0x9DC;
		uint32_t field_0x9E0;
        uint32_t field_0x9E4;
        uint32_t field_0x9E8;
        uint32_t field_0x9EC;
		uint32_t field_0x9F0;
        uint32_t field_0x9F4;
        uint32_t field_0x9F8;
        uint32_t field_0x9FC;
		uint32_t field_0xA00;
        uint32_t field_0xA04;
        uint32_t field_0xA08;
        uint32_t field_0xA0C;
    };
};