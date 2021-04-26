/*
 * @Author: thewinger
 * @Date:   2019-03-08
 * @Last Modified by:   thewinger
 * @Last Modified time: 2020-03-14
 */

#include QMK_KEYBOARD_H
#include "print.h"

enum layers {
  _MAC,
  _WIN,
  _NAVM,
  _LEDS,
  _CONFIG
};

enum keycodes {
    WIN = SAFE_RANGE,
    MAC,
    M_NTILD
};

#define KC_CAD LCTL(LALT(KC_DEL))

static bool control_disabled = false;
static bool delete_pressed = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* MAC
     * ,-----------------------------------------------------------------------------------------.
     * | Grv |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \    |
     * |-----------------------------------------------------------------------------------------+
     * | ESC      |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter   |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |     Shift       |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl | Alt  | Gui  |              Space                   | Gui |  Alt  |  Leds  | Ctrl |
     * `-----------------------------------------------------------------------------------------'
     */

    [_MAC] = LAYOUT_60_ansi(
        KC_GRV,            KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,       KC_9,   KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,
        KC_TAB,             KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,       KC_O,   KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,
        LT(_NAVM, KC_ESC), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,       KC_L,   KC_SCLN,    KC_QUOT,    KC_ENT,
        KC_LSFT,            KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,    KC_DOT, KC_SLSH,        RSFT_T(KC_UP),
        KC_LCTL,  KC_LALT,  KC_LGUI,                     KC_SPC,                    KC_RGUI,    RALT_T(KC_LEFT),     LT(_LEDS, KC_DOWN),  RCTL_T(KC_RIGHT)),


    /* WIN
     * ,-----------------------------------------------------------------------------------------.
     * | Grv |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \    |
     * |-----------------------------------------------------------------------------------------+
     * | ESC      |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter   |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |     Shift       |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl | Gui  | Alt  |              Space                   | Alt |  Gui  |  Leds  | Ctrl |
     * `-----------------------------------------------------------------------------------------'
     */

    [_WIN] = LAYOUT_60_ansi(
        KC_GRV,            KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,       KC_9,   KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,
        KC_TAB,             KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,       KC_O,   KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,
        LT(_NAVM, KC_ESC), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,       KC_L,   KC_SCLN,    KC_QUOT,    KC_ENT,
        KC_LSFT,            KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,    KC_DOT, KC_SLSH,            RSFT_T(KC_UP),
        KC_LCTL,  KC_LGUI,  KC_LALT,                     KC_SPC,                    KC_RALT,    RGUI_T(KC_LEFT),    LT(_LEDS, KC_DOWN),    RCTL_T(KC_RIGHT)),


     /* NAVMEDIA
     * ,-----------------------------------------------------------------------------------------.
     * | Esc | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10  |  F11  | F12  |  Del  |
     * |-----------------------------------------------------------------------------------------+
     * |KC_CAD|     |  Up |     |     |     |     |  7  |  8  |  9  |  PRSR |  T- |  T+ |  Play  |
     * |-----------------------------------------------------------------------------------------+
     * |          |  Lf |  Dw |  Rg |     |     |     |  4  |  5  |  6  |  V- | V+  |    Mute    |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |     |     |     |  ñ  |  1  |  2  |  3  |  0  |                 |
     * |-----------------------------------------------------------------------------------------+
     * |      |      |      |                                      |       |      |       |      |
     * `-----------------------------------------------------------------------------------------'
     */

    [_NAVM] = LAYOUT_60_ansi(
        KC_ESC, KC_F1,   KC_F2,    KC_F3,      KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,     KC_F12,     KC_DEL,
        KC_CAD, _______, KC_UP,    _______,    _______, _______, _______,  KC_7,    KC_8,    KC_9,  KC_PSCR,  KC_MRWD,    KC_MFFD,    KC_MPLY,
        _______, KC_LEFT, KC_DOWN,  KC_RIGHT,   _______, _______, _______,  KC_4,    KC_5,    KC_6,  KC_VOLD,  KC_VOLU,                KC_MUTE,
        _______, _______, _______,  _______,    _______, _______, M_NTILD, KC_1,    KC_2,    KC_3,     KC_0,                          _______,
        _______, _______, _______,                      _______,                    _______, _______,           _______,                _______),

    /* LEDS
     * ,-----------------------------------------------------------------------------------------.
     * | Esc | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10  |  F11  | F12  |  Del  |
     * |-----------------------------------------------------------------------------------------+
     * |        |RGBTo|RGBMo|RGBH+|RGBH-|RGBS+|RGBS-|RGBV+|RGBV-|     |     |     |     |        |
     * |-----------------------------------------------------------------------------------------+
     * |          | BL- | BTo | BL+ |BLStep|    |     |     |     |     |     |     |            |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |     |     |     |     |     |     |     |     |                 |
     * |-----------------------------------------------------------------------------------------+
     * |      |      |      |                                      |       |      |       |      |
     * `-----------------------------------------------------------------------------------------'
     */

    [_LEDS] = LAYOUT_60_ansi(
        KC_ESC, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,     KC_F12,     KC_DEL,
        _______, RGB_TOG, RGB_MOD,  RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,  KC_MRWD,   KC_MFFD,    KC_MPLY,
        _______, BL_DEC,  BL_TOGG,  BL_INC,  BL_STEP, _______, _______, _______, _______, _______, KC_VOLD,  KC_VOLU,    KC_MUTE,
        _______, _______, _______,  _______, _______, _______, M_NTILD, _______, _______, _______, _______,     _______,
        _______, _______, _______,                      _______,                    _______,     _______,       _______,             _______),

        /* CONFIG (NAVMED + LEDS)
     * ,-----------------------------------------------------------------------------------------.
     * |      |    |     |     |     |     |     |     |     |     |      |       |      | Reset |
     * |-----------------------------------------------------------------------------------------+
     * |        |     | Win |     |     |     |     |     |     |     |     |     |     |        |
     * |-----------------------------------------------------------------------------------------+
     * |          | Mac |     |     |     |     |     |     |     |     |     |     |            |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |     |     |     |     |     |     |     |     |                 |
     * |-----------------------------------------------------------------------------------------+
     * |      |      |      |                                      |       |      |       |      |
     * `-----------------------------------------------------------------------------------------'
     */

    [_CONFIG] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, WIN,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, MAC,     _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,
        _______, _______, _______,                      _______,                    _______,      _______,     _______,      _______)

};

void matrix_init_user(void) {

}

void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_matrix = false;
    switch(biton32(default_layer_state)) {
        case _WIN:
            rgblight_sethsv_noeeprom_white(); // sets the color to white without saving
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // sets mode to Fast breathing without saving
            break;

        case _MAC:
            rgblight_sethsv_noeeprom_cyan(); // sets the color to teal/cyan without saving
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // sets mode to Fast breathing without saving
            break;
    }
}

// switch layers depending on keypressed, with persistent layer in the mix
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case WIN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WIN);
            }
            return false;
            break;

        case MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC);
            }
            return false;
            break;
        case M_NTILD:
            if (record->event.pressed) {
                if(keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    register_code (KC_LSFT);
                    register_code (KC_GRV);
                    unregister_code (KC_GRV);
                    tap_code(KC_N);
                    unregister_code (KC_LSFT);
                } else {
                    register_code (KC_LSFT);
                    register_code (KC_GRV);
                    unregister_code (KC_GRV);
                    unregister_code (KC_LSFT);
                    tap_code(KC_N);
                }
            }
            return false;
            break;
        case KC_BSPC:
            if (record->event.pressed) {
                if(keyboard_report->mods & MOD_BIT(KC_LCTL)) {
                    delete_pressed = true;
                    control_disabled = true;
                    unregister_code(KC_LCTL);
                    register_code(KC_DEL);
                    return false;
                }
            } else if(delete_pressed) {
                delete_pressed = false;
                unregister_code(KC_DEL);

                if(control_disabled) {
                    control_disabled = false;
                    register_code(KC_LCTL);
                }
                return false;
            }
            break;
        case KC_LCTL:
            if (!record->event.pressed) {
                if (delete_pressed) {
                    delete_pressed = false;
                    control_disabled = false;
                    unregister_code(KC_DEL);
                    register_code(KC_BSPC);
                    return false;
                }
            }
            break;
        default:
            break;
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    state = update_tri_layer_state(state, _NAVM, _LEDS, _CONFIG);
    #ifdef RGBLIGHT_ENABLE
        switch (biton32(state)) {
            case _NAVM:
                rgblight_sethsv_noeeprom_cyan(); // sets the color to teal/cyan without saving
                rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT + 1); // sets mode to Fast breathing without saving
                state = update_tri_layer_state(state, _NAVM, _LEDS, _CONFIG);
                break;

            case _LEDS:
                rgblight_sethsv_noeeprom_cyan(); // sets the color to teal/cyan without saving
                rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
                state = update_tri_layer_state(state, _NAVM, _LEDS, _CONFIG);
                break;

            case _CONFIG:
                rgblight_mode_noeeprom(RGBLIGHT_MODE_CHRISTMAS);
                break;

            default:
                switch(biton32(default_layer_state)) {
                    case _WIN:
                        rgblight_sethsv_noeeprom_white(); // sets the color to white without saving
                        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // sets mode to Fast breathing without saving
                        break;

                    case _MAC:
                        rgblight_sethsv_noeeprom_cyan(); // sets the color to teal/cyan without saving
                        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // sets mode to Fast breathing without saving
                        break;
                }
                break;
        }
    #endif// RGBLIGHT_ENABLE

    return state;
}
