#pragma once

#include <code/tcpgecko.h>

#define VPAD_BUTTON_A        0x8000
#define VPAD_BUTTON_B        0x4000
#define VPAD_BUTTON_X        0x2000
#define VPAD_BUTTON_Y        0x1000
#define VPAD_BUTTON_LEFT     0x0800
#define VPAD_BUTTON_RIGHT    0x0400
#define VPAD_BUTTON_UP       0x0200
#define VPAD_BUTTON_DOWN     0x0100
#define VPAD_BUTTON_ZL       0x0080
#define VPAD_BUTTON_ZR       0x0040
#define VPAD_BUTTON_L        0x0020
#define VPAD_BUTTON_R        0x0010
#define VPAD_BUTTON_PLUS     0x0008
#define VPAD_BUTTON_MINUS    0x0004
#define VPAD_BUTTON_HOME     0x0002
#define VPAD_BUTTON_SYNC     0x0001
#define VPAD_BUTTON_STICK_R  0x00020000
#define VPAD_BUTTON_STICK_L  0x00040000
#define VPAD_BUTTON_TV       0x00010000

#define VPAD_STICK_R_EMULATION_LEFT    0x04000000
#define VPAD_STICK_R_EMULATION_RIGHT   0x02000000
#define VPAD_STICK_R_EMULATION_UP      0x01000000
#define VPAD_STICK_R_EMULATION_DOWN    0x00800000

#define VPAD_STICK_L_EMULATION_LEFT    0x40000000
#define VPAD_STICK_L_EMULATION_RIGHT   0x20000000
#define VPAD_STICK_L_EMULATION_UP      0x10000000
#define VPAD_STICK_L_EMULATION_DOWN    0x08000000

struct Vec2D {
    float x;
    float y;
};

struct VPADTPData {
    uint16_t x, y;               /* Touch coordinates */
    uint16_t touched;            /* 1 = Touched, 0 = Not touched */
    uint16_t invalid;            /* 0 = All valid, 1 = X invalid, 2 = Y invalid, 3 = Both invalid? */
};

struct VPADData{
    uint32_t btns_h;             /* Held buttons */
    uint32_t btns_d;             /* Buttons that are pressed at that instant */
    uint32_t btns_r;             /* Released buttons */
    Vec2D lstick, rstick;        /* Each contains 4-byte X and Y components */
    char unknown1c[0x52 - 0x1c]; /* Contains accelerometer and gyroscope data somewhere */
    VPADTPData tpdata;           /* Normal touchscreen data */
    VPADTPData tpdata1;          /* Modified touchscreen data 1 */
    VPADTPData tpdata2;          /* Modified touchscreen data 2 */
    char unknown6a[0xa0 - 0x6a];
    uint8_t volume;
    uint8_t battery;             /* 0 to 6 */
    uint8_t unk_volume;          /* One less than volume */
    char unknowna4[0xac - 0xa4];
};

EXPORT_DECL(void, VPADInit, void);
EXPORT_DECL(void, VPADRead, int chan, VPADData *buffer, uint32_t buffer_size, int *error);

#define START_BUTTONCHECK(x, y, z)                  \
    VPADData vpadData;                              \
    int vpadError;                                  \
    VPADRead(0, &vpadData, 1, &vpadError);          \
    uint32_t z = vpadData.btns_d | vpadData.btns_h; \
    static bool isActive = false;                   \
    if (x) {                                        \
        if (!isActive) {                            \
            y;                                      \
            isActive = true;                        \
        }                                           \
    }

#define ADD_BUTTONCHECK(x, y) \
    else if (x) {             \
        if (!isActive) {      \
            y;                \
            isActive = true;  \
        }                     \
    }

#define END_BUTTONCHECK() \
    else {                \
        isActive = false; \
    }

#define START_TIMED_BUTTONCHECK(ifCheck, action, btnName, minTime, cps)          \
    VPADData vpadData;                                                           \
    int vpadError;                                                               \
    VPADRead(0, &vpadData, 1, &vpadError);                                       \
    uint32_t btnName = vpadData.btns_d | vpadData.btns_h;                        \
    static uint64_t lastClickTime = 0;                                           \
    static uint64_t lastTime = 0;                                                \
    uint64_t mTime = minTime;                                                    \
    uint64_t clickTime = 1000 / cps;                                             \
    uint64_t currentTime = mc::System::processTimeInMilliSecs();                 \
    static bool wasBtnPressed = false;                                           \
    if (ifCheck) {                                                               \
        if     (!(mTime     > (currentTime -      lastTime) && wasBtnPressed)) { \
            if (!(clickTime > (currentTime - lastClickTime) && wasBtnPressed)) { \
                action;                                                          \
                wasBtnPressed = true;                                            \
                lastClickTime = currentTime;                                     \
            }                                                                    \
        }                                                                        \
    }

#define ADD_TIMED_BUTTONCHECK(ifCheck, action)                                   \
    else if (ifCheck) {                                                          \
        if     (!(mTime     > (currentTime -      lastTime) && wasBtnPressed)) { \
            if (!(clickTime > (currentTime - lastClickTime) && wasBtnPressed)) { \
                action;                                                          \
                wasBtnPressed = true;                                            \
                lastClickTime = currentTime;                                     \
            }                                                                    \
        }                                                                        \
    }

#define END_TIMED_BUTTONCHECK(action) \
    else {                            \
        wasBtnPressed = false;        \
        action;                       \
        lastTime = currentTime;       \
    }

void InitVPadFunctionPointers(void) {
    unsigned int *funcPointer = 0;
    uint32_t vpad_handle;
    OSDynLoad_Acquire("vpad.rpl", &vpad_handle);

    OS_FIND_EXPORT(vpad_handle, VPADInit);
    OS_FIND_EXPORT(vpad_handle, VPADRead);
}