/* Copyright 2024 at-simon
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Useful stuff at: /users/drashna/callbacks.md

#include QMK_KEYBOARD_H
#include "customizations.h"
#include "sendstring_us_international.h"
#include "secret_definitions.h"

// Custom Keycodes
enum custom_user_keycodes {
    RGB_M_0 = SAFE_RANGE,
    RGB_M_1,
    RGB_M_2,
    BRGHT_I,
    BRGHT_D,
    SPEED_I,
    SPEED_D,
    RAINBOW,
    LOCK_SCR,
    A_GREET,
    A_MAIL,
    K_GREET,
    DESK_ML,
    DESK_MR,
    MAC_ON,
    WIN_ON,
};

// LAYERS
enum custom_user_layers {
    _B_MAC,
    _B_WIN,
    _SETTINGS,
    _RESET,
};
    // _NUMPAD,

// Interact with layers
#define MO_SET MO(_SETTINGS)
#define TG_RST TG(_RESET)

// Default values
uint8_t lighting_mode = 2; // default: Dark, FN -> '/'
uint8_t hsv_val = 170;
bool mac_enabled = true;

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* MacBase
     * ,--------------------------------------------------------------------------------------------------.
     * | Ec~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  Backspace  | Home |
     * |-------------------------------------------------------------------------------------------+------|
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \     | PgUp |
     * |-------------------------------------------------------------------------------------------+------|
     * |          |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |     Enter    | PgDn |
     * |-------------------------------------------------------------------------------------------+------|
     * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift    | Up  | End  |
     * |-------------------------------------------------------------------------┬---┬-------------+------|
     * | Lctrl | Lopt | Lcmd |               Space                 | Ropt | Set  |   | Left  | Dwn | Rght |   | Apple
     * | Lopt | Lctrl | Lcmd |               Space                 | Ropt | Set  |   | Left  | Dwn | Rght |   | at-simon
     * `-------------------------------------------------------------------------´   `--------------------´
     */
    [_B_MAC] = LAYOUT_65_ansi_blocker(
        QK_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS   ,KC_PGUP,
        XXXXXXX,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGDN,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
        KC_LOPT,  KC_LCTL,  KC_LCMD,                                KC_SPC,                       KC_ROPT,  MO_SET,             KC_LEFT,  KC_DOWN,  KC_RIGHT
    ),


    /* Base Windows
     * ,--------------------------------------------------------------------------------------------------.
     * | Ec~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  Backspace  | Home |
     * |-------------------------------------------------------------------------------------------+------|
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \     | PgUp |
     * |-------------------------------------------------------------------------------------------+------|
     * |          |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |     Enter    | PgDn |
     * |-------------------------------------------------------------------------------------------+------|
     * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift    | Up  | End  |
     * |-------------------------------------------------------------------------┬---┬-------------+------|
     * | Lctrl | Lwin | Lalt |               Space                 | Ralt | Set  |   | Left  | Dwn | Rght |
     * `-------------------------------------------------------------------------´   `--------------------´
     */
    [_B_WIN] = LAYOUT_65_ansi_blocker(
        QK_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS   ,KC_PGUP,
        XXXXXXX,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGDN,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                       KC_RALT,  MO_SET,             KC_LEFT,  KC_DOWN,  KC_RIGHT
    ),


    /* Settings layer
     * ,--------------------------------------------------------------------------------------------------.
     * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |     Del     |      |
     * |-------------------------------------------------------------------------------------------+------|
     * |        |     |     |     |     |     |     |     |     | Set |     | DM< | DM> |          |      |  // <TODO> Move Desktop auf Mac anpassen
     * |-------------------------------------------------------------------------------------------+------|
     * | Caps     |     | A_M |     |     |     |     |     |     | W L | Br- | Br+ |              | Play |  // <TODO> Win Lock auf Mac anpassen
     * |-------------------------------------------------------------------------------------------+------|
     * |            |     |     |     | A_G | K_G |     | RBW | RM0 | RM1 | RM2 |            | V + | Mute |
     * |-------------------------------------------------------------------------┬---┬-------------+------|
     * |       |      |      |                                     |      |  VV  |   | Prev  | V - | Next |
     * `-------------------------------------------------------------------------´   `--------------------´
     */
    [_SETTINGS] = LAYOUT_65_ansi_blocker(
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TG_RST,   XXXXXXX,  DESK_ML,  DESK_MR,  XXXXXXX,  XXXXXXX,
        KC_CAPS,  XXXXXXX,  A_MAIL,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  LOCK_SCR, BRGHT_D,  BRGHT_I,            XXXXXXX,  KC_MPLY,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  A_GREET,  K_GREET,  XXXXXXX,  RAINBOW,  RGB_M_0,  RGB_M_1,  RGB_M_2,  XXXXXXX,            KC_VOLU,  KC_MUTE,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                      XXXXXXX,  _______,            KC_MPRV,  KC_VOLD,  KC_MNXT
    ),


    /* Numpad layer
     * ,--------------------------------------------------------------------------------------------------.
     * | TO0 |     |     |     |     |     |     |  7  |  8  |  9  |     |  -  |  +  |  Backspace  | Home |
     * |-------------------------------------------------------------------------------------------+------|
     * | Tab    |     |     |     |     |     |     |  4  |  5  |  6  |     |  *  |  /  |          |      |
     * |-------------------------------------------------------------------------------------------+------|
     * |          |     |     |     | NmL |     |     |  1  |  2  |  3  |     |     |    Enter     |      |
     * |-------------------------------------------------------------------------------------------+------|
     * | Shift      |     |  X  |  C  |  V  |     |     |  0  |  ,  |  .  |  /  |            | Up  | End  |
     * |-------------------------------------------------------------------------┬---┬-------------+------|
     * | LCtrl |      | LAlt |                                     |      |      |   | Left  | Dwn | Rght |
     * `-------------------------------------------------------------------------´   `--------------------´
     */
    // [_NUMPAD] = LAYOUT_65_ansi_blocker(
    //     TO(0),    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_P7,    KC_P8,    KC_P9,    XXXXXXX,  KC_PMNS,  KC_PPLS,  KC_BSPC,  KC_HOME,
    //     KC_TAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_P4,    KC_P5,    KC_P6,    XXXXXXX,  KC_PAST,  KC_PSLS,  XXXXXXX,  KC_PGUP,
    //     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NUM,   XXXXXXX,  XXXXXXX,  KC_P1,    KC_P2,    KC_P3,    XXXXXXX,  XXXXXXX,            KC_ENT,   KC_PGDN,
    //     KC_LSFT,  XXXXXXX,  KC_X,     KC_C,     KC_V,     XXXXXXX,  XXXXXXX,  KC_P0,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    //     KC_LCTL,  XXXXXXX,  KC_LALT,                                XXXXXXX,                      XXXXXXX,  XXXXXXX,            KC_LEFT,  KC_DOWN,  KC_RIGHT
    // ),


    /* Reset and EEPROM clear layer
     * ,--------------------------------------------------------------------------------------------------.
     * | Rtn | Win | Mac |     |     |     |     |     |     |     |     |     |     |             |  RST |
     * |-------------------------------------------------------------------------------------------+------|
     * |        |     |     |     |     |     |     |     |     |     |     |     |     |          |  EEP |
     * |-------------------------------------------------------------------------------------------+------|
     * |          |     |     |     |     |     |     |     |     |     |     |     |              |      |
     * |-------------------------------------------------------------------------------------------+------|
     * |            |     |     |     |     |     |     |     |     |     |     |            |     |      |
     * |-------------------------------------------------------------------------┬---┬-------------+------|
     * |       |      |      |                                     |      |      |   |       |     |      |
     * `-------------------------------------------------------------------------´   `--------------------´
     */
    [_RESET] = LAYOUT_65_ansi_blocker(
        TG_RST,   WIN_ON,   MAC_ON,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_BOOT,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  EE_CLR,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                      XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
};

/* Empty keymap
 * ,--------------------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |             |      |
 * |-------------------------------------------------------------------------------------------+------|
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |          |      |
 * |-------------------------------------------------------------------------------------------+------|
 * |          |     |     |     |     |     |     |     |     |     |     |     |              |      |
 * |-------------------------------------------------------------------------------------------+------|
 * |            |     |     |     |     |     |     |     |     |     |     |            |     |      |
 * |-------------------------------------------------------------------------┬---┬-------------+------|
 * |       |      |      |                                     |      |      |   |       |     |      |
 * `-------------------------------------------------------------------------´   `--------------------´
 */



// ----------------------------- Lighting stuff ----------------------------.
// #ifdef ENABLE_MILKSHAKE

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR); // default for rainbow
    // rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR); // default for milkshake
    // rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_cool_effect);
}

uint8_t get_lighting_mode(void) {
    return lighting_mode;
}


void rgb_matrix_set_color_hsv(int index, uint8_t hue, uint8_t sat, uint8_t val) {
    HSV hsv = {hue, sat, hsv_val};
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_driver.set_color(index, rgb.r, rgb.g, rgb.b);
}

void rgb_matrix_set_color_all_hsv(uint8_t hue, uint8_t sat, uint8_t val) {
    HSV hsv = {hue, sat, hsv_val};
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_driver.set_color_all(rgb.r, rgb.g, rgb.b);
}


// -------------------------------- Milkshake --------------------------------.
void colorize_keycaps(void) {
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_YELLOW); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_MILKSHAKE_YELLOW[i], HSV_MILKSHAKE_YELLOW);
    }
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_RED); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_MILKSHAKE_RED[i], HSV_MILKSHAKE_RED);
    }
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_GREEN); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_MILKSHAKE_GREEN[i], HSV_MILKSHAKE_GREEN);
    }
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_BLUE); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_MILKSHAKE_BLUE[i], HSV_MILKSHAKE_BLUE);
    }
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_PURPLE); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_MILKSHAKE_PURPLE[i], HSV_MILKSHAKE_PURPLE);
    }
}

void colorize_settings(void) {
    rgb_matrix_set_color_hsv(LED_P, HSV_MILKSHAKE_PURPLE); // numpad

    rgb_matrix_set_color_hsv(LED_LBRC, HSV_MILKSHAKE_YELLOW); // Windows move left
    rgb_matrix_set_color_hsv(LED_RBRC, HSV_MILKSHAKE_YELLOW); // Windows move right

    rgb_matrix_set_color_hsv(LED_QUOT, HSV_MILKSHAKE_GREEN);
    rgb_matrix_set_color_hsv(LED_SCLN, HSV_MILKSHAKE_RED);

    rgb_matrix_set_color_hsv(LED_L, HSV_MILKSHAKE_GREEN);
    rgb_matrix_set_color_hsv(LED_K, HSV_MILKSHAKE_RED);

    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_LIGHTNIG_MODE); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_LIGHTNIG_MODE[i], HSV_MILKSHAKE_YELLOW);
    }
    rgb_matrix_set_color_hsv(LED_LIST_LIGHTNIG_MODE[get_lighting_mode()], HSV_MILKSHAKE_RED);
}

void colorize_numpad(void) {
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_NUMPAD); i++) {
        if (host_keyboard_led_state().num_lock) {
            rgb_matrix_set_color_hsv(LED_LIST_NUMPAD[i], HSV_MILKSHAKE_BLUE);
        } else {
            rgb_matrix_set_color_hsv(LED_LIST_NUMPAD[i], HSV_MILKSHAKE_RED);
        }
    }
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_NUMPAD_EXTRA); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_NUMPAD_EXTRA[i], HSV_MILKSHAKE_PURPLE);
    }
    rgb_matrix_set_color_hsv(LED_ESC, HSV_MILKSHAKE_RED);
}

void colorize_os_indicators(void) {
    if (mac_enabled) {
        for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_LOGO_APPLE); i++) {
            rgb_matrix_set_color_hsv(LED_LIST_LOGO_APPLE[i], HSV_WHITE);
        }
    } else {
        for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_LOGO_WINDOWS_RED); i++) {
            rgb_matrix_set_color_hsv(LED_LIST_LOGO_WINDOWS_RED[i], HSV_MILKSHAKE_RED);
        }
        for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_LOGO_WINDOWS_GREEN); i++) {
            rgb_matrix_set_color_hsv(LED_LIST_LOGO_WINDOWS_GREEN[i], HSV_MILKSHAKE_GREEN);
        }
        for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_LOGO_WINDOWS_BLUE); i++) {
            rgb_matrix_set_color_hsv(LED_LIST_LOGO_WINDOWS_BLUE[i], HSV_MILKSHAKE_BLUE);
        }
        for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_LOGO_WINDOWS_YELLOW); i++) {
            rgb_matrix_set_color_hsv(LED_LIST_LOGO_WINDOWS_YELLOW[i], HSV_MILKSHAKE_YELLOW);
        }
    }
}
// ----------------------------------------------------------------------------

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state)){
    case _B_MAC:
    case _B_WIN:
        switch(get_lighting_mode()) {
        case 0:
            rgb_matrix_set_color_all_hsv(HSV_WHITE);
            colorize_keycaps();
            break;
        case 1:
            rgb_matrix_set_color_all(HSV_OFF);
            colorize_keycaps();
            break;
        case 2:
            rgb_matrix_set_color_all(HSV_OFF);
            break;
        default:
            break;
        }
        break;
    case _SETTINGS:
        switch(get_lighting_mode()) {
        case 0:
            rgb_matrix_set_color_all_hsv(HSV_WHITE);
            colorize_keycaps();
            colorize_settings();
            break;
        case 1:
            rgb_matrix_set_color_all(HSV_OFF);
            colorize_keycaps();
            colorize_settings();
            break;
        case 2:
            rgb_matrix_set_color_all(HSV_OFF);
            break;
        default:
            break;
        }
        break;
    // case _NUMPAD:
    //     switch(get_lighting_mode()) {
    //     case 0:
    //         rgb_matrix_set_color_all_hsv(HSV_WHITE);
    //         colorize_keycaps();
    //         colorize_numpad();
    //         break;
    //     case 1:
    //         rgb_matrix_set_color_all(HSV_OFF);
    //         colorize_keycaps();
    //         colorize_numpad();
    //         break;
    //     case 2:
    //         rgb_matrix_set_color_all(HSV_OFF);
    //         break;
    //     default:
    //         break;
    //     }
    //     break;
    case _RESET:
        // Special lighting for reset layer
        rgb_matrix_set_color_all(HSV_OFF);
        rgb_matrix_set_color_hsv(LED_ESC, HSV_MILKSHAKE_GREEN);
        rgb_matrix_set_color_hsv(LED_DEL, HSV_MILKSHAKE_RED);
        rgb_matrix_set_color_hsv(LED_PGUP, HSV_MILKSHAKE_GREEN);
        rgb_matrix_set_color_hsv(LED_1, HSV_MILKSHAKE_BLUE);
        rgb_matrix_set_color_hsv(LED_2, HSV_WHITE);

        colorize_os_indicators();
        break;
    default:
        break;
    }
    return false;
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_M_0:
            if (record->event.pressed) {
                lighting_mode = 0;
                rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
            break;
        case RGB_M_1:
            if (record->event.pressed) {
                lighting_mode = 1;
                rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
            break;
        case RGB_M_2:
            if (record->event.pressed) {
                lighting_mode = 2;
                rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
            break;
        case RAINBOW:
            if (record->event.pressed) {
                lighting_mode = 3;
                rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
            }
            return false;
            break;
        case BRGHT_I:
            if (record->event.pressed) {
                hsv_val = (hsv_val >= 238) ? 255 : hsv_val + 17;
            }
            return false;
            break;
        case BRGHT_D:
            if (record->event.pressed) {
                hsv_val = (hsv_val <= 34) ? 17 : hsv_val - 17;
            }
            return false;
            break;
        case SPEED_I:
            if (record->event.pressed) {
                rgb_matrix_increase_speed_noeeprom();
            }
            return false;
            break;
        case SPEED_D:
            if (record->event.pressed) {
                rgb_matrix_decrease_speed_noeeprom();
            }
            return false;
            break;
        case LOCK_SCR:
            if (record->event.pressed) {
                if (mac_enabled) {
                    SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LCMD) SS_TAP(X_Q) SS_UP(X_LCMD) SS_UP(X_LCTL));
                } else {
                    SEND_STRING(SS_LGUI("l"));
                }
            }
            return false;
            break;
        case A_GREET:
            if (record->event.pressed) {
                if(mac_enabled) {
                    SEND_STRING("Viele Gr" SS_DOWN(X_LALT) SS_TAP(X_U) SS_UP(X_LALT) SS_TAP(X_U) SS_RALT("s") "e\nSimon");
                } else {
                    SEND_STRING("Viele Gr" SS_RALT("y") SS_RALT("s") "e\nSimon");
                }
            }
            return false;
            break;
        case K_GREET:
            if (record->event.pressed) {
                if (mac_enabled) {
                    SEND_STRING("Mit freundlichen Gr" SS_DOWN(X_LALT) SS_TAP(X_U) SS_UP(X_LALT) SS_TAP(X_U) SS_RALT("s") "en\nSimon ");
                } else {
                    SEND_STRING("Mit freundlichen Gr" SS_RALT("y") SS_RALT("s") "en\nSimon ");
                }
                SEND_STRING(LAST_NAME);
            }
            return false;
            break;
        case A_MAIL:
            if (record->event.pressed) {
                send_string(MAIL);
            }
            return false;
            break;
        case DESK_ML:
            if (record->event.pressed) {
                if (mac_enabled) {
                    SEND_STRING(SS_DOWN(X_LEFT_CTRL) SS_TAP(X_LEFT) SS_UP(X_LEFT_CTRL)); // Ctrl + Left
                } else {
                    SEND_STRING(SS_DOWN(X_LEFT_CTRL) SS_DOWN(X_LEFT_GUI) SS_TAP(X_LEFT) SS_UP(X_LEFT_GUI) SS_UP(X_LEFT_CTRL)); // Win + Ctrl + Left
                }
            }
            return false;
            break;
        case DESK_MR:
            if (record->event.pressed) {
                if (mac_enabled) {
                    SEND_STRING(SS_DOWN(X_LEFT_CTRL) SS_TAP(X_RIGHT) SS_UP(X_LEFT_CTRL)); // Ctrl + Right
                } else {
                    SEND_STRING(SS_DOWN(X_LEFT_CTRL) SS_DOWN(X_LEFT_GUI) SS_TAP(X_RIGHT) SS_UP(X_LEFT_GUI) SS_UP(X_LEFT_CTRL)); // Win + Ctrl + Right
                }
            }
            return false;
            break;
        case MAC_ON:
            if (record->event.pressed) {
                layer_on(_B_MAC);
                layer_off(_B_WIN);
                mac_enabled = true;
            }
            return false;
            break;
        case WIN_ON:
            if (record->event.pressed) {
                layer_on(_B_WIN);
                layer_off(_B_MAC);
                mac_enabled = false;
            }
            return false;
            break;
        default:
            break;
    }
    return true;
}
// #endif
// ---------------------------------------------------------------------------´

