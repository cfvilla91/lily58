#include QMK_KEYBOARD_H
#include "./my_keymap.h"
#include "features/oled/luna-keyboard-dog/luna.h"
#include "features/oled/caps/caps.h"
#include "features/oled/numlock/numlock.h"
#include "features/oled/print-layer/print-layer.h"
#include "features/oled/print-wpm/print-wpm.h"
#include "features/rgb/underlight/set-color-per-layer.h"

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void matrix_scan_user(void) {
    process_set_color_per_layer();
}


//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {

    process_print_layer();
    process_print_wpm();
    process_numLock();
    process_caps();

    render_luna(0, 13);
    return false;
}
#endif // OLED_ENABLE

bool should_process_keypress(void) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_HYPHEN_ARROW:
            if (record->event.pressed) {
                tap_code(KC_SLSH);
                register_code(KC_LSFT);
                tap_code(KC_NUBS);
                unregister_code(KC_LSFT);
            }
            break;
        case CK_ARROW_FUNCTION:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                tap_code(KC_0);
                tap_code(KC_NUBS);
                unregister_code(KC_LSFT);
            }
            break;
    }
    process_luna(keycode, record);
    return true;
}
