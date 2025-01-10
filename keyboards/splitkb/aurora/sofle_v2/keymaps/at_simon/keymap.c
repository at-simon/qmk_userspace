#include QMK_KEYBOARD_H

// LAYERS
enum custom_user_layers {
    _BASE,
    _ONE,
    _TWO,
    _THREE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* Base layer
 * ,-----------------------------------.                 ,-----------------------------------.
 * | Ec~ |  1  |  2  |  3  |  4  |  5  |                 |  6  |  7  |  8  |  9  |  0  | BSP |
 * |-----------------------------------|                 |-----------------------------------|
 * | Tab |  Q  |  W  |  E  |  R  |  T  |                 |  Y  |  U  |  I  |  O  |  P  |  \  |
 * |-----------------------------------|                 |-----------------------------------|
 * |     |  A  |  S  |  D  |  F  |  G  |                 |  H  |  J  |  K  |  L  |  ;  |  '  |
 * |-----------------------------------:-----.     .-----:-----------------------------------|
 * |  ^  |  Z  |  X  |  C  |  V  |  B  | (X) |     | (X) |  N  |  M  |  ,  |  .  |  /  |  ^  |
 * `-----------:-----------------------:-----|     .-----:-----;-----;-----;-----;-----------´
 *             |     |     |     | MO1 | ENT |     | SPC | MO2 |     |     |     |
 *             `-----------------------|     |     |     |-----------------------´
 *                                     `-----´     `-----´
 */
    [_BASE] = LAYOUT(
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                           KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
        XXXXXXX,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                           KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,    XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                            KC_LGUI,  KC_LALT,  KC_LCTL,  MO(1),    KC_ENT,     KC_SPC,   MO(2),    KC_RCTL,  KC_RALT,  KC_RGUI
    ),


 /* Layer one
 * ,-----------------------------------.                 ,-----------------------------------.
 * |     | F 1 | F 2 | F 3 | F 4 | F 5 |                 | F 6 | F 7 | F 8 | F 9 | F10 | F11 |
 * |-----------------------------------|                 |-----------------------------------|
 * |     |     |     |     |     |     |                 |     |     |     |     |     | F12 |
 * |-----------------------------------|                 |-----------------------------------|
 * |     |     |     |     |     |     |                 |     |     |     |     |     |     |
 * |-----------------------------------:-----.     .-----:-----------------------------------|
 * |     |     |     |     |     |     | (X) |     | (X) |     |     |     |     |     |     |
 * `-----------:-----------------------:-----|     .-----:-----;-----;-----;-----;-----------´
 *             | !RS |     |     | V V |     |     |     | MO3 |     |     |     |
 *             `-----------------------|     |     |     |-----------------------´
 *                                     `-----´     `-----´
 */
    [_ONE] = LAYOUT(
        XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                          KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                            QK_BOOT,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,    XXXXXXX,  MO(3),    XXXXXXX,  XXXXXXX,  XXXXXXX
    ),


 /* Layer two
 * ,-----------------------------------.                 ,-----------------------------------.
 * |     |     |     |     |     |     |                 |     |     |     |     |     |     |
 * |-----------------------------------|                 |-----------------------------------|
 * |     |     |     |     |     |     |                 |     |     |     |     |     |     |
 * |-----------------------------------|                 |-----------------------------------|
 * |     |     |     |     |     |     |                 |     |     |     |     |     |     |
 * |-----------------------------------:-----.     .-----:-----------------------------------|
 * |     |     |     |     |     |     | (X) |     | (X) |     |     |     |     |     |     |
 * `-----------:-----------------------:-----|     .-----:-----;-----;-----;-----;-----------´
 *             |     |     |     | MO3 |     |     |     | V V |     |     | !RS |
 *             `-----------------------|     |     |     |-----------------------´
 *                                     `-----´     `-----´
 */
    [_TWO] = LAYOUT(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                            XXXXXXX,  XXXXXXX,  XXXXXXX,  MO(3),    XXXXXXX,    XXXXXXX, _______,  XXXXXXX,  XXXXXXX,  QK_BOOT
    ),


 /* Layer three
 * ,-----------------------------------.                 ,-----------------------------------.
 * |     |     |     |     |     |     |                 |     |     |     |     |     |     |
 * |-----------------------------------|                 |-----------------------------------|
 * |     |     |     |     |     |     |                 |     |     |     |     |     |     |
 * |-----------------------------------|                 |-----------------------------------|
 * |     |     |     |     |     |     |                 |     |     |     |     |     |     |
 * |-----------------------------------:-----.     .-----:-----------------------------------|
 * |     |     |     |     |     |     | (X) |     | (X) |     |     |     |     |     |     |
 * `-----------:-----------------------:-----|     .-----:-----;-----;-----;-----;-----------´
 *             |     |     |     | V V |     |     |     | V V |     |     |     |
 *             `-----------------------|     |     |     |-----------------------´
 *                                     `-----´     `-----´
 */
    [_THREE] = LAYOUT(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                            XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,    XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
};

// // Empty keymap
// [_EMPTY] = LAYOUT(
//        _______,  _______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,  _______,
//        _______,  _______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,  _______,
//        _______,  _______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,  _______,
//        _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
//                            _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______
// ),

 /* Empty keymap
 * ,-----------------------------------.                 ,-----------------------------------.
 * |     |     |     |     |     |     |                 |     |     |     |     |     |     |
 * |-----------------------------------|                 |-----------------------------------|
 * |     |     |     |     |     |     |                 |     |     |     |     |     |     |
 * |-----------------------------------|                 |-----------------------------------|
 * |     |     |     |     |     |     |                 |     |     |     |     |     |     |
 * |-----------------------------------:-----.     .-----:-----------------------------------|
 * |     |     |     |     |     |     | (X) |     | (X) |     |     |     |     |     |     |
 * `-----------:-----------------------:-----|     .-----:-----;-----;-----;-----;-----------´
 *             |     |     |     |     |     |     |     |     |     |     |     |
 *             `-----------------------|     |     |     |-----------------------´
 *                                     `-----´     `-----´
 */
