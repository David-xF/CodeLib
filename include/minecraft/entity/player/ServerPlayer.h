#pragma once

#include <code/code.h>

#include "Player.h"

#include "../../client/resource/shared_ptr.h"

namespace mc {
    // 03299F8C
    class ServerPlayer : public Player {
    public:
        void teleportTo(double _x, double _y, double _z) {
            code::Func<void, 0x032d6b74, ServerPlayer*, double, double, double>()(this, _x, _y, _z);
        }

        void disconnect() {
            code::Func<void, 0x03286798, ServerPlayer*>()(this); 
        }

        static code::Func<void, 0x032c3114, ServerPlayer*> _tick;
        void tick() {
            _tick(this);
        }

        static code::Func<void, 0x032d8b5c, ServerPlayer*, InteractionHand::EInteractionHand> _swing;
        void swing(InteractionHand::EInteractionHand hand) {
            _swing(this, hand);
        }

        static code::Func<void, 0x032d8a3c, ServerPlayer*, const mc_boost::shared_ptr<Entity>&> _attack;
        void attack(const mc_boost::shared_ptr<Entity>& entity) {
            _attack(this, entity);
        }

        bool isSpectator() {
            return code::Func<bool, 0x032d8000, ServerPlayer*>()(this);   
        }

        bool isCreative()  {
            return code::Func<bool, 0x032d8060, ServerPlayer*>()(this);   
        }

        void openContainer(const mc_boost::shared_ptr<struct Container>& cont) {
            code::Func<void, 0x032cc440, ServerPlayer*, const mc_boost::shared_ptr<struct Container>&>()(this, cont);
        }

        void closeContainer() {
            code::Func<void, 0x032D0800, ServerPlayer*>()(this);
        }

        void openTextEdit(const mc_boost::shared_ptr<struct SignBlockEntity>& entity) {
            code::Func<void, 0x032CACD0, ServerPlayer*, const mc_boost::shared_ptr<struct SignBlockEntity>&>()(this, entity);
        }

        void giveExperienceLevels(int _level) {
            code::Func<void, 0x032C2730, ServerPlayer*, int>()(this, _level);
        }

        void setGameMode(const struct GameType* _type) {
            code::Func<void, 0x032d7f3c, ServerPlayer*, const struct GameType*>()(this, _type);
        }

        void refreshContainer(struct AbstractContainerMenu* _container) {
            code::Func<void, 0x032a2264, ServerPlayer*, struct AbstractContainerMenu*>()(this, _container);
        }

        void addEffect(struct MobEffectInstance* effect, const mc_boost::shared_ptr<Entity>& entity) {
            code::Func<void, 0x032c6fd8, ServerPlayer*, struct MobEffectInstance*, const mc_boost::shared_ptr<Entity>&>()(this, effect, entity);
        }

        static uint64_t GetType() {
            return code::Func<uint64_t, 0x0332fc30>()();
        }

        void startRiding(const mc_boost::shared_ptr<Entity>& ent) {
            code::Func<void, 0x032ca21c, ServerPlayer*, const mc_boost::shared_ptr<Entity>&>()(this, ent);
        }

        struct ServerPlayerGameMode* gamemode;
        struct ServerGamePacketListenerImpl* listener;
        uint32_t field_0x874;
        uint32_t field_0x878;
        uint32_t field_0x87C;
        uint32_t field_0x890;
        uint32_t field_0x894;
        uint32_t field_0x898;
        uint32_t field_0x89C;
        uint32_t field_0x8A0;
        uint32_t field_0x8A4;
        uint32_t field_0x8A8;
        uint32_t field_0x8AC;
        uint32_t field_0x8B0;
        uint32_t field_0x8B4;
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
        uint32_t field_0x900; // Send Update Packet???
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
    };
}