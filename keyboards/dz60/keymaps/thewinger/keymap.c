/*
 * @Author: thewinger
 * @Date:   2019-03-08
 * @Last Modified by:   thewinger
 * @Last Modified time: 2019-03-08
 */

#include QMK_KEYBOARD_H

enum layers {
  _WIN,
  _MAC,
  _NAVM,
  _LEDS,
  _CONFIG
};

enum keycodes {
    WIN = SAFE_RANGE,
    MAC,
    NAVM,
    LEDS,
    EEPROM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* WIN
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \    |
     * |-----------------------------------------------------------------------------------------+
     * | Caps     |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter   |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |     Shift       |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl | Gui  | Alt  |              Space                   | Alt |  Gui  |  Leds  | Ctrl |
     * `-----------------------------------------------------------------------------------------'
     */

    [_WIN] = LAYOUT_60_ansi(
        KC_GESC,            KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,       KC_9,   KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,
        KC_TAB,             KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,       KC_O,   KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,
        LT(_NAVM, KC_CAPS), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,       KC_L,   KC_SCLN,    KC_QUOT,    KC_ENT,
        KC_LSFT,            KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,    KC_DOT, KC_SLSH,            RSFT_T(KC_UP),
        KC_LCTL,  KC_LGUI,  KC_LALT,                     KC_SPC,                    KC_RALT,    RGUI_T(KC_LEFT),    LT(_LEDS, KC_DOWN),    RCTL_T(KC_RIGHT)),

    /* MAC
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \    |
     * |-----------------------------------------------------------------------------------------+
     * | Caps     |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter   |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |     Shift       |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl | Alt  | Gui  |              Space                   | Gui |  Alt  |  Leds  | Ctrl |
     * `-----------------------------------------------------------------------------------------'
     */

    [_MAC] = LAYOUT_60_ansi(
        KC_GESC,            KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,       KC_9,   KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,
        KC_TAB,             KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,       KC_O,   KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,
        LT(_NAVM, KC_CAPS), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,       KC_L,   KC_SCLN,    KC_QUOT,    KC_ENT,
        KC_LSFT,            KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,    KC_DOT, KC_SLSH,        RSFT_T(KC_UP),
        KC_LCTL,  KC_LALT,  KC_LGUI,                     KC_SPC,                    KC_RGUI,    RALT_T(KC_LEFT),     LT(_LEDS, KC_DOWN),  RCTL_T(KC_RIGHT)),


     /* NAVMEDIA
     * ,-----------------------------------------------------------------------------------------.
     * | Wake| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10  |  F11  | F12  |  Del  |
     * |-----------------------------------------------------------------------------------------+
     * |        |     |  Up |     |     |     |     |     |     |     |     |  T- |  T+ |  Play  |
     * |-----------------------------------------------------------------------------------------+
     * |          |  Lf |  Dw |  Rg |     |     |     |     |     |     |  V- | V+  |    Mute    |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |     |     |     |     |     |     |     |     |                 |
     * |-----------------------------------------------------------------------------------------+
     * |      |      |      |                                      |       |      |       |      |
     * `-----------------------------------------------------------------------------------------'
     */

    [_NAVM] = LAYOUT_60_ansi(
        KC_WAKE, KC_F1,   KC_F2,    KC_F3,      KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,     KC_F12,     KC_DEL,
        _______, _______, KC_UP,    _______,    _______, _______, _______, _______, _______, _______, _______,  KC_MRWD,    KC_MFFD,    KC_MPLY,
        _______, KC_LEFT, KC_DOWN,  KC_RIGHT,   _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_VOLD,  KC_VOLU,    KC_MUTE,
        _______, _______, _______,  _______,    _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, _______, _______,                      _______,                    _______, _______,           _______,                _______),

    /* LEDS
     * ,-----------------------------------------------------------------------------------------.
     * | Wake| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10  |  F11  | F12  |  Del  |
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
        RESET, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,     KC_F12,     KC_DEL,
        _______, RGB_TOG, RGB_MOD,  RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,  _______,    _______,    _______,
        _______, BL_DEC,  BL_TOGG,  BL_INC,  BL_STEP, _______, _______, _______, _______, _______, _______,  _______,    _______,
        _______, WIN, MAC,  _______, _______, _______, _______, _______, _______, _______, _______,     _______,
        _______, _______, _______,                      _______,                    _______,     _______,       _______,             _______),

        /* CONFIG (NAVMED + LEDS)
     * ,-----------------------------------------------------------------------------------------.
     * |EEPROM|    |     |     |     |     |     |     |     |     |      |       |      | Reset |
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

void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_matrix = false;

    #ifdef RBGLIGHT_ENABLE
        // Read the user config from EEPROM
/*         user_config.raw = eeconfig_read_user();

        // Set default layer, if enabled
        if (user_config.rgb_layer_change) {
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom_cyan();
            rgblight_mode_noeeprom(1);
        } */
    #endif
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

/*         case NAVM:
            if (record->event.pressed) {
                layer_on(_NAVM);
                update_tri_layer(_NAVM, _LEDS, _CONFIG);
            } else  {
                layer_off(_NAVM);
                update_tri_layer(_NAVM, _LEDS, _CONFIG);
            }
            return false;
            break;

        case LEDS:
            if (record->event.pressed) {
                layer_on(_LEDS);
                update_tri_layer(_NAVM, _LEDS, _CONFIG);
            } else  {
                layer_off(_LEDS);
                update_tri_layer(_NAVM, _LEDS, _CONFIG);
            }
            return false;
            break; */

       default:
            break;
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    #ifdef RGBLIGHT_ENABLE
        switch (biton32(state)) {
            case _NAVM:
                rgblight_sethsv_noeeprom_cyan(); // sets the color to teal/cyan without saving
                rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE); // sets mode to Fast breathing without saving
                break;

            case _LEDS:
                rgblight_sethsv_noeeprom_cyan(); // sets the color to teal/cyan without saving
                rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
                break;

            case _CONFIG:
                rgblight_mode_noeeprom(RGBLIGHT_MODE_CHRISTMAS);
                break;

            default:
                switch(biton32(default_layer_state)) {
                    case _WIN:
                        rgblight_sethsv_noeeprom_white(); // sets the color to yellow without saving
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
    state = update_tri_layer_state(state, _NAVM, _LEDS, _CONFIG);
    return state;
}