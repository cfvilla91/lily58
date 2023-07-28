#include "features/oled/numlock/numlock.h"

static const char numLockOn[] PROGMEM = {
    // 'numlock ON', 32x32px
    0x00, 0x00, 0x00, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8,
    0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xcf, 0xcf, 0xcf, 0x00, 0x00, 0xcf, 0xcf,
    0xcf, 0xcf, 0x00, 0x00, 0xcf, 0xcf, 0xcf, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xf3, 0xf3, 0xf3, 0x00, 0x00, 0xf3, 0xf3,
    0xf3, 0xf3, 0x00, 0x00, 0xf3, 0xf3, 0xf3, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00,
};



static const char numLockOff[] PROGMEM = {
    // 'numlock off', 32x32px
    0x00, 0x00, 0x00, 0xf8, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xf8, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0xff, 0xff, 0x30, 0x30,
    0x30, 0x30, 0xff, 0xff, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0xff, 0xff, 0x0c, 0x0c,
    0x0c, 0x0c, 0xff, 0xff, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00
};


void process_numLock() {
    led_t led_usb_state = host_keyboard_led_state();

    oled_set_cursor(0, 4);
    if(led_usb_state.num_lock){
        oled_write_raw_P(numLockOn, sizeof(numLockOn));
    } else {
        oled_write_raw_P(numLockOff, sizeof(numLockOff));
    }
}
