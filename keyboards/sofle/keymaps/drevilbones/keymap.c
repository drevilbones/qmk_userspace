
 /* Copyright 2021 Dane Evans & 2024 Nick Scratch
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
  // SOFLE RGB
#include <stdio.h>
#include "keymap_introspection.h"
#include QMK_KEYBOARD_H

enum my_keycodes {
  MB1HLD = SAFE_RANGE
};

// A bunch of aliases for home row mod-taps to keep the layout pretty
// Left-hand home row mods
#define MT_A LSFT_T(KC_A)
#define MT_S LCTL_T(KC_S)
#define MT_D LGUI_T(KC_D)
#define MT_F LALT_T(KC_F)

// Right-hand home row mods
#define MT_J LALT_T(KC_J)
#define MT_K RGUI_T(KC_K)
#define MT_L RCTL_T(KC_L)
#define MT_SCLN RSFT_T(KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT( //base
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS,
  MO(3),    KC_A,   MT_S,    MT_D,    MT_F,    KC_G,                      KC_H,    MT_J,   MT_K,    MT_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  _______,   _______, KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_LCTL, KC_LGUI, KC_LBRC, LT(2,KC_SPC), KC_ENT, KC_ENT, LT(2,KC_SPC), KC_RBRC, KC_MINS, KC_EQL
),

[1] = LAYOUT( //games (basically disabling the tap-hold keys)
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS,
  MO(3),    KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  _______,   _______, KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_LCTL, MO(2), KC_LALT, KC_SPC,  KC_NO,     KC_ENT,  KC_SPC,  KC_RALT, MO(2),   KC_RCTL 
),

[2] = LAYOUT( //navigation
  KC_TILD,  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,  KC_DEL,
  _______, _______, KC_PGUP, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_HOME, KC_PGDN, KC_END,  _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,   MO(5), _______, _______, _______, _______
),

[3] = LAYOUT( //function
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11,  
  _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, KC_F12,
  _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, TO(1),
                    _______, TO(0),   _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_MPLY,_______, _______, TG(6)
),

[4] = LAYOUT( //mouse
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, MB1HLD,  _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, MS_BTN1, MS_BTN3, MS_BTN2, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[5] = LAYOUT(//RGB LED
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, _______,                   _______, _______, _______, _______, _______, _______,
  _______, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[6] = LAYOUT( //Numpad
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_NUM,  XXXXXXX, XXXXXXX,XXXXXXX, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
  TG(6),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, KC_P0,  KC_PDOT, XXXXXXX
)

/*
[8] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
*/

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MB1HLD:
      return false;
    default:
      return true;
  }
}

bool mb1held = false;
bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
      case MB1HLD:
        if (record->event.pressed) {
          if (mb1held) {
            SEND_STRING(SS_UP(X_BTN1));
            auto_mouse_toggle();
            mb1held = false;
          } else {
            SEND_STRING(SS_DOWN(X_BTN1));
            auto_mouse_toggle();
            mb1held = true;
          }
        }
        return true;
      default:
        return false;
    }
    return false;
}


void pointing_device_init_user(void) {
  set_auto_mouse_enable(true);
}


bool encoder_update_user(uint8_t index, bool clockwise) {
  switch(get_highest_layer(layer_state)) {
    case 2:
      if (clockwise) {
        tap_code(MS_WHLR);
      } else {
        tap_code(MS_WHLL);
      }
      break;
    case 1:
    case 3:
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
      break;
    default:
      if (clockwise) {
        tap_code(MS_WHLD);
      } else {
        tap_code(MS_WHLU);
      }
  }
  return false;
}


// index 0 and 36: indicator LEDs
// refactor indicator LED setting into the loop for efficiency
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  hsv_t layer_color_hsv = (hsv_t){HSV_CYAN};
  layer_color_hsv = (hsv_t){layer_color_hsv.h, layer_color_hsv.s, 75};
  uint8_t layer = get_highest_layer(layer_state);
  switch(layer) {
    case 1: //games
      layer_color_hsv =(hsv_t){HSV_RED};
      rgb_matrix_set_color(0, RGB_OFF);
      rgb_matrix_set_color(36, RGB_OFF);
      break;
    case 4: //mouse
      rgb_matrix_set_color(0, RGB_CYAN);
      break;
    case 6: //numpad
      layer_color_hsv = (hsv_t){HSV_PURPLE};
      break;
    default:
      rgb_matrix_set_color(0, RGB_OFF);
      rgb_matrix_set_color(36, RGB_OFF);
      break;      
  }

  rgb_t lrgb = hsv_to_rgb(layer_color_hsv);

  for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        uint8_t index = g_led_config.matrix_co[row][col];

        uint16_t kcatkml = keycode_at_keymap_location(layer, row, col);
        if (index >= led_min && index < led_max && index != NO_LED) {
          if (kcatkml == XXXXXXX) { rgb_matrix_set_color(index, RGB_OFF); } // if it's off, then LED is off
          else { rgb_matrix_set_color(index, lrgb.r, lrgb.g, lrgb.b); } // else make it the right color
        }
    }
  }
  return false;
}

// space saving
#ifndef MAGIC_ENABLE
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
#endif
#ifndef MAGIC_ENABLE
uint8_t mod_config(uint8_t mod) {
    return mod;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void print_status(void) {
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("BASE"), false);
            break;        
        case 1:
            oled_write_ln_P(PSTR("GAMES"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("FUNC"), false);
            break;
        case 4:
            oled_write_ln_P(PSTR("MOUSE"), false);
            break;
        case 5:
            oled_write_ln_P(PSTR("RGB"), false);
            oled_write_ln(get_u8_str(rgb_matrix_config.hsv.h, '0'), false);
            oled_write_ln(get_u8_str(rgb_matrix_config.hsv.s, '0'), false);
            oled_write_ln(get_u8_str(rgb_matrix_config.hsv.v, '0'), false);
            break;
        case 6:
            oled_write_ln_P(PSTR("NUM"), false);
            break;            
        default:
            oled_write_ln_P(PSTR("???"), false);
    }

    oled_write_P(PSTR("\n\n\n"), false);

    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
      oled_write_ln_P(PSTR("CAPS"), false);
    } else {
      oled_write_ln_P(PSTR("    "), false);
    }
}


bool oled_task_user(void) {
    print_status();
    return false;
}
#endif //OLED_ENABLE
