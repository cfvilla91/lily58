
enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BakSPC|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  ´¨  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ñ  |  ?   |
 * |------+------+------+------+------+------|   {[  |    |  }]   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | WIND |LOWER | /Space  /       \Enter \  |RAISE |  /   |  @   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC         ,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB         ,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  LSFT_T(KC_CAPS),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS,
  KC_LCTL        ,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_QUOT,  KC_NUHS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
                                KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_PSLS, KC_ALGR
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  |°  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  C   |   /  |   *  |  -   | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |MOUSE1|MOUSE2|MOUSE3|      |      |                    |      |  7   |  8   |  9   |  +   |  ``  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |  4   |  5   |  6   |  %   |  ¿¡  |
 * |------+------+------+------+------+------|  <>   |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  1   |  2   |  3   |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |  0   |  .   |
 *                   |      |      |      |/       /         SS\      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
   KC_GRV ,  KC_F1,     KC_F2,      KC_F3,      KC_F4  ,      KC_F5,                            KC_F6  ,    S(KC_C),    KC_PSLS,    KC_PAST,    KC_PMNS,  KC_DEL, \
   _______,  KC_BTN1,   KC_BTN2,    KC_BTN3,    _______,    _______,                          KC_NUM ,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_PPLS,  RALT(KC_BSLS), \
   _______,  _______,   _______,    _______,    _______,    _______,                          XXXXXXX,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_PERC,  KC_EQL, \
   _______,  _______,   _______,    _______,    _______,    _______, KC_NUBS,        S(KC_NUBS), XXXXXXX,    KC_KP_1,    KC_KP_2,    KC_KP_3,    XXXXXXX,  _______, \
                                   _______, _______, _______, _______,                      _______, _______, KC_KP_0, KC_DOT \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |PrntSc|      |      | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      | Back |  Up  |Forwrd|      | Home |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  | F10  |-------.    ,-------|      | Left | Down |Right |      | End  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      | F11  | F12  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
   _______        ,  _______,   _______,    _______,    _______,    _______,                          _______,    _______,    KC_PRINT_SCREEN,    _______,    _______,  KC_DEL, \
   KC_C           ,  KC_F1,     KC_F2,      KC_F3,      KC_F4,      KC_F5,                            _______,    KC_WBAK,      KC_UP,    KC_WFWD,    _______,  KC_HOME, \
   _______        ,  KC_F6,     KC_F7,      KC_F8,      KC_F9,      KC_F10,                           _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,  KC_END, \
   _______        ,  KC_F11,    KC_F12,     _______,     _______,     _______, _______,         _______, _______,    _______,    _______,    _______,    _______,  _______, \
                                   _______, _______, _______, _______,                      _______, _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |RGB ON|                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | HUE+ | SAT+ | VAL+ |SPEED+| MODE |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | HUE- | SAT- | VAL- |SPEED-|      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RA|ISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                                   _______, _______, _______, _______, _______,  _______, _______, _______ \
    )
};