#pragma once

namespace mc {
    class Direction {
    public:
        #ifdef CEMU
            static Direction* down  asm("0x104C24A0");
            static Direction* up    asm("0x104C24A4");
            static Direction* north asm("0x104C24A8");
            static Direction* south asm("0x104C24AC");
            static Direction* west  asm("0x104C24B0");
            static Direction* east  asm("0x104C24B4");
        #else
            static Direction* down  asm("0x109C46A0");
            static Direction* up    asm("0x109C46A4");
            static Direction* north asm("0x109C46A8");
            static Direction* south asm("0x109C46AC");
            static Direction* west  asm("0x109C46B0");
            static Direction* east  asm("0x109C46B4");
        #endif
    };
}