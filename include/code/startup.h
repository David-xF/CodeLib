#pragma once

void _main();

extern "C" __attribute__((section(".entry"))) void entry() {
    asm volatile("_entry_main:");
    _main();
    asm volatile("_entry_main_end:");
}