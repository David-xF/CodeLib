#pragma once

#include <code/code.h>

namespace mc {
    class ConsoleUIController {
    public:
        static ConsoleUIController* getInstance() {
            #ifdef CEMU
                return (ConsoleUIController*) 0x104F73E0;
            #else
                return (ConsoleUIController*) 0x109F95E0;
            #endif
        }

        void PlayUISFX(struct SoundEvent* sound) {
            code::Func<void, 0x02DA7918, ConsoleUIController*, struct SoundEvent*>()(this, sound);
        }
    };
}