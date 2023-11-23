#pragma once

#include <code/code.h>

#include "../client/resource/wstring.h"

namespace mc {
    class SoundEvent {
    public:
        static SoundEvent* random_successful_hit           asm("0x104C3FAC");
        static SoundEvent* random_bow                      asm("0x104C3FB0");
        static SoundEvent* mob_bat_idle                    asm("0x104C3FB4");
        static SoundEvent* mob_bat_death                   asm("0x104C3FB8");
        static SoundEvent* mob_bat_hurt                    asm("0x104C3FBC");
        static SoundEvent* mob_bat_takeoff                 asm("0x104C3FC0");
        static SoundEvent* mob_blaze_breath                asm("0x104C3FC4");
        static SoundEvent* fire_fire                       asm("0x104C3FC8");
        static SoundEvent* mob_blaze_death                 asm("0x104C3FCC");
        static SoundEvent* mob_blaze_hit                   asm("0x104C3FD0");
        static SoundEvent* mob_ghast_fireball              asm("0x104C3FD4");
        static SoundEvent* entity_bobber_throw             asm("0x104C3FD8");
        static SoundEvent* entity_bobber_retrieve          asm("0x104C3FDC");
        static SoundEvent* item_bottle_empty               asm("0x104C3FE0");
        static SoundEvent* item_bottle_fill                asm("0x104C3FE4");
        static SoundEvent* item_bottle_fill_dragonbreath   asm("0x104C3FE8");
        static SoundEvent* block_brewing_stand_brew        asm("0x104C3FEC");
        static SoundEvent* item_bucket_empty               asm("0x104C3FF0");
        static SoundEvent* item_bucket_empty_lava          asm("0x104C3FF4");
        static SoundEvent* item_bucket_fill                asm("0x104C3FF8");
        static SoundEvent* item_bucket_fill_lava           asm("0x104C3FFC");
        static SoundEvent* item_bucket_fill_fish           asm("0x104C4000");
        static SoundEvent* item_bucket_empty_fish          asm("0x104C4004");
        static SoundEvent* mob_cat_meow                    asm("0x104C4008");
        static SoundEvent* mob_cat_hit                     asm("0x104C400C");
        static SoundEvent* mob_cat_hiss                    asm("0x104C4010");
        //static SoundEvent* mob_cat_hit                     asm("0x104C4014");
        static SoundEvent* mob_cat_purr                    asm("0x104C4018");
        static SoundEvent* mob_cat_purreow                 asm("0x104C401C");
        static SoundEvent* block_chest_close               asm("0x104C4020");
        static SoundEvent* random_door_close               asm("0x104C4024");
        static SoundEvent* block_chest_open                asm("0x104C4028");
        static SoundEvent* mob_chicken_idle                asm("0x104C402C");
        static SoundEvent* mob_chicken_hurt                asm("0x104C4030");
        static SoundEvent* mob_chicken_plop                asm("0x104C4034");
        //static SoundEvent* mob_chicken_hurt                asm("0x104C4038");
        static SoundEvent* mob_chicken_step                asm("0x104C403C");
        static SoundEvent* block_chorus_flower_death       asm("0x104C4040");
        static SoundEvent* block_chorus_flower_grow        asm("0x104C4044");
        static SoundEvent* mob_endermen_portal             asm("0x104C4048");
        static SoundEvent* dig_cloth                       asm("0x104C404C");
        static SoundEvent* step_cloth                      asm("0x104C4050");
        //static SoundEvent* step_cloth                      asm("0x104C4054");
        //static SoundEvent* dig_cloth                       asm("0x104C4058");
        //static SoundEvent* step_cloth                      asm("0x104C405C");
        static SoundEvent* random_click                    asm("0x104C4060");
        static SoundEvent* mob_cow_idle                    asm("0x104C4064");
        static SoundEvent* mob_cow_hurt                    asm("0x104C4068");
        //static SoundEvent* mob_cow_hurt                    asm("0x104C406C");
        static SoundEvent* entity_cow_milk                 asm("0x104C4070");
        static SoundEvent* mob_cow_step                    asm("0x104C4074");
        static SoundEvent* mob_creeper_death               asm("0x104C4078");
        static SoundEvent* mob_creeper_hurt                asm("0x104C407C");
        static SoundEvent* random_fuse                     asm("0x104C4080");
        //static SoundEvent* random_click                    asm("0x104C4084");
        //static SoundEvent* random_click                    asm("0x104C4088");
        //static SoundEvent* random_bow                      asm("0x104C408C");
        static SoundEvent* mob_horse_donkey_idle           asm("0x104C4090");
        static SoundEvent* mob_horse_donkey_angry          asm("0x104C4094");
        //static SoundEvent* mob_chicken_plop                asm("0x104C4098");
        static SoundEvent* mob_horse_donkey_death          asm("0x104C409C");
        static SoundEvent* mob_horse_donkey_hit            asm("0x104C40A0");
        //static SoundEvent* random_bow                      asm("0x104C40A4");
        static SoundEvent* mob_guardian_elder_idle         asm("0x104C40A8");
        static SoundEvent* mob_guardian_land_idle          asm("0x104C40AC");
        static SoundEvent* mob_guardian_curse              asm("0x104C40B0");
        static SoundEvent* mob_guardian_elder_death        asm("0x104C40B4");
        static SoundEvent* mob_guardian_land_death         asm("0x104C40B8");
        static SoundEvent* mob_guardian_flop               asm("0x104C40BC");
        static SoundEvent* mob_guardian_elder_hit          asm("0x104C40C0");
        static SoundEvent* mob_guardian_land_hit           asm("0x104C40C4");
        static SoundEvent* item_elytra_flying              asm("0x104C40C8");
        static SoundEvent* block_enchantment_table_enchant asm("0x104C40CC");
        static SoundEvent* block_enderchest_close          asm("0x104C40D0");
        static SoundEvent* block_enderchest_open           asm("0x104C40D4");
        static SoundEvent* mob_enderdragon_growl           asm("0x104C40D8");
        static SoundEvent* mob_enderdragon_end             asm("0x104C40DC");
        static SoundEvent* random_explode                  asm("0x104C40E0");
        static SoundEvent* mob_enderdragon_wings           asm("0x104C40E4"); 
        //static SoundEvent* mob_enderdragon_growl           asm("0x104C40E8");
        static SoundEvent* random_fizz                     asm("0x104C430C");
        static SoundEvent* ambient_weather_thunder         asm("0x104C4324");
        static SoundEvent* note_bd                         asm("0x104C439C");
        static SoundEvent* note_bassattack                 asm("0x104C43A0");
        static SoundEvent* note_harp                       asm("0x104C43A4");
        static SoundEvent* note_hat                        asm("0x104C43A8");
        static SoundEvent* note_pling                      asm("0x104C43AC");
        //static SoundEvent* random_click                    asm("0x104C4370");
        static SoundEvent* note_snare                      asm("0x104C43B0");
        static SoundEvent* random_breath                   asm("0x104C4478");
        static SoundEvent* random_break                    asm("0x104C453C");
        static SoundEvent* mob_wolf_howl                   asm("0x104C4728");
        static SoundEvent* MG01_celebration                asm("0x104C47CC");
        static SoundEvent* MG01_death                      asm("0x104C47D4");
        static SoundEvent* MG01_gracezero                  asm("0x104C47DC");
        static SoundEvent* MG01_lobby                      asm("0x104C47E0");
        static SoundEvent* MG01_lobbyaccent                asm("0x104C47E4");
        static SoundEvent* MG01_lobbyzero                  asm("0x104C47E8");
        static SoundEvent* MG01_gamestart                  asm("0x104C47EC");
        static SoundEvent* MG02_gamestart                  asm("0x104C47F8");
        static SoundEvent* MG03_emeraldPointTick           asm("0x104C4864");
        static SoundEvent* block_note_xylophone            asm("0x104C488C");
        static SoundEvent* block_note_bell                 asm("0x104C4890");
        static SoundEvent* block_note_chime                asm("0x104C4894");
        static SoundEvent* block_note_flute                asm("0x104C4898");
        static SoundEvent* block_note_guitar               asm("0x104C489C");
        static SoundEvent* item_trident_riptide2           asm("0x104C4954");


        void getName(const mstd::wstring& name) {
            code::Func<void, 0x028E11EC, SoundEvent*, const mstd::wstring&>()(this, name);
        }

        static float getNoteBlockPitch(int count) {
            switch (count) {
            case 0:
                return 0.5f;
            case 12:
                return 1.0f;
            default:
                return powf(2, (-12 + mc::toFloat(count)) / 12);
            };
        }
    };
}