#pragma once

namespace mc {
    class Direction {
    public:
        static Direction* down  asm("0x104C24A0");
        static Direction* up    asm("0x104C24A4");
        static Direction* north asm("0x104C24A8");
        static Direction* south asm("0x104C24AC");
        static Direction* west  asm("0x104C24B0");
        static Direction* east  asm("0x104C24B4");
    };
}