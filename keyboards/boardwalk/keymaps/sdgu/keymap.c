/*
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

#include QMK_KEYBOARD_H
#include "keymap_steno.h"

#define _DEFAULT 0
#define _PLOVER 10
#define _LOWER 11
#define _RAISE 12
#define _ADJUST 20

#define _FN 30

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  PLOVER,
  EXT_PLV,
};

#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* FUNCTION
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


[_DEFAULT] = LAYOUT_ortho_5x14(
   KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,      KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL , \
   KC_TAB,          KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,       KC_EQL,    KC_MINS,    KC_F,     KC_G,    KC_C,    KC_R,    KC_L,      KC_SLSH , \
   KC_LCTL,         KC_A,    KC_O,    KC_E,    KC_U,    KC_I,       KC_EQL,    KC_MINS,    KC_D,     KC_H,    KC_T,    KC_N,    KC_S,      KC_ENT , \
   KC_LSFT,         KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,       KC_SLSH,   KC_BSLS,    KC_B,     KC_M,    KC_W,    KC_V,    KC_Z,      KC_RSFT, \
   _______,         _______, KC_LGUI, KC_LALT, LOWER,   KC_SPC,     _______,   _______,   KC_BSPC,  RAISE,   KC_RALT, KC_RGUI, _______,    _______ 
),

[_LOWER] = LAYOUT_ortho_5x14(
  KC_ESC,  LCTL(KC_C),    LCTL(KC_V),       LCTL(KC_X),      LCTL(KC_S),   LCTL(KC_Z), _______, KC_TRNS,   LCTL(KC_Y),    _______,    _______,    _______, _______, _______, \
  _______, LALT(KC_QUOT), LALT(KC_COMM),    LALT(KC_DOT),    LALT(KC_P),   LALT(KC_Y), _______, KC_TRNS,   _______,    _______,    _______,    _______, KC_0, KC_BSLS, \
  _______, _______,       KC_LBRC,          KC_LCBR,         KC_LPRN,      KC_MINS, _______, KC_TRNS,      _______,    KC_RPRN,    KC_RCBR,    KC_RBRC, _______, XXXXXXX, \
  _______, KC_UP,         KC_RBRC,          KC_RCBR,         KC_RPRN,      KC_ENT, _______, KC_TRNS,    _______,    _______,    _______,    _______, _______, _______, \
  KC_LEFT, KC_DOWN,       KC_RIGHT,          _______,     _______,         KC_BSPC, _______, KC_TRNS,    _______,    _______,    _______,    _______, _______, _______ 
), 

[_RAISE] = LAYOUT_ortho_5x14(
  _______,   KC_F1,      KC_F2,      KC_F3,      KC_F4,   KC_F5,  KC_F11, KC_F12, KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,   _______, \
  _______,  KC_MPRV,    KC_MPLY,    KC_MNXT,    _______, _______, KC_TRNS, KC_TRNS, _______,  _______, KC_UP,    _______,  KC_PSCR,  KC_BSLS, \
  _______,  _______,    KC_VOLD,    KC_VOLU,    KC_MUTE, _______, KC_TRNS, KC_TRNS, _______,  KC_LEFT, KC_DOWN,  KC_RIGHT, KC_INS,   KC_DEL, \
  _______,  _______,    _______,    _______,    _______, _______, KC_TRNS, KC_TRNS, _______,  _______, _______,  _______,  _______,  _______, \
  _______,  _______,    _______,    _______,    _______, _______, KC_TRNS, KC_TRNS, KC_SPC,   _______, _______,  _______,  _______,  _______ 
), 

[_ADJUST] = LAYOUT_ortho_5x14(
  TO(_DEFAULT),   PLOVER, _______, _______,  _______,   _______,  KC_TRNS, _______, _______,    _______,   _______,    ST_GEM,   ST_BOLT,   RESET, \
  _______,  _______,    _______,    _______,    _______, _______, KC_TRNS, _______, _______,  _______, _______,    _______,  _______,  _______, \
  _______,  _______,    _______,    _______,    _______, _______, KC_TRNS, _______, _______,  _______, _______,  _______, _______,   _______, \
  _______,  _______,    _______,    _______,    _______, _______, KC_TRNS, _______, _______,  _______, _______,  _______,  _______,  _______, \
  _______,  _______,    _______,    _______,    _______, _______, KC_TRNS, _______, _______,   _______, _______,  _______,  _______,  _______ 
), 



[_PLOVER] = LAYOUT_ortho_5x14(
  STN_N1,   STN_N2,     STN_N3,     STN_N4,     STN_N5,  STN_N6,   XXXXXXX, XXXXXXX,  STN_N7,  STN_N8,    STN_N9,    STN_NA,    STN_NB,    STN_NC, 
  KC_TAB,   STN_S1,     STN_TL,     STN_PL,     STN_HL,  STN_ST1,  XXXXXXX, XXXXXXX,  STN_ST3, STN_FR,    STN_PR,    STN_LR,    STN_TR,    STN_DR, 
  KC_LCTL,  STN_S2,     STN_KL,     STN_WL,     STN_RL,  STN_ST2,  XXXXXXX, XXXXXXX,  STN_ST4, STN_RR,   STN_BR,     STN_GR,   STN_SR,    STN_ZR, 
  KC_LSFT,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, LOWER,    XXXXXXX, XXXXXXX,    RAISE,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
  XXXXXXX,  XXXXXXX,    KC_LGUI,    KC_LALT,    LOWER,   STN_A,   STN_O, STN_E,    STN_U,   RAISE, KC_BSPC,   STN_PWR,  STN_RE1,  STN_RE2 
), 

/* FUNCTION
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


 [_FN] = LAYOUT_ortho_5x14(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 )
};


const uint16_t PROGMEM fn_actions[] = {

};

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
// {
//   // MACRODOWN only works in this function
//   switch (id) {
//   case 0:
//     if (record->event.pressed) {
//       register_code(KC_RSFT);
//     }
//     else {
//       unregister_code(KC_RSFT);
//     }
//     break;
//   }
//   return MACRO_NONE;
// };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);

      } else {
        layer_off(_ADJUST);

      }
      return false;
      break;
  case PLOVER:
      if (!record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_on(_PLOVER);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;

  }
  return true;
}

