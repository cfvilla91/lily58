#include QMK_KEYBOARD_H
#include "./keymap.h"
#include "features/oled/luna-keyboard-dog/luna.h"
#include "features/oled/caps/caps.h"
#include "features/oled/numlock/numlock.h"
#include "features/oled/print-layer/print-layer.h"

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// When you add source files to SRC in rules.mk, you can use functions.

bool oled_task_user(void) {

    process_print_layer();
    process_numLock();
    process_caps();

    render_luna(0, 13);
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  process_luna(keycode, record);
  return true;
}
