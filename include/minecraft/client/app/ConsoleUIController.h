#pragma once

#include <code/code.h>

namespace mc {
    class ConsoleUIController {
    public:
        static ConsoleUIController* getInstance() {
            return (ConsoleUIController*) 0x104F73E0;
        }

        void PlayUISFX(struct SoundEvent* sound) {
            code::Func<void, 0x02DA7918, ConsoleUIController*, struct SoundEvent*>()(this, sound);
        }
    };
}