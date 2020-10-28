#include "dm.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_steno.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0


#define _OSRS 3


#define _PLOVER 10
#define _LOWER  11
#define _RAISE 12
#define _ADJUST 15
// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  OSRS,
  ADJUST,
  PLOVER,
  EXT_PLV,

};

#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = KEYMAP_5x6(
  // left hand
   KC_GRV,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5, 
   KC_TAB,    KC_QUOT,    KC_COMM,    KC_DOT,   KC_P,   KC_Y,
   KC_LCTL,    KC_A,    KC_O,    KC_E,   KC_U,   KC_I,
   KC_LSHIFT, KC_SCLN,    KC_Q,    KC_J,   KC_K,   KC_X,
                       KC_CAPS,  KC_BSLS,
                               LOWER, KC_SPC, 
                               OSRS,   KC_LALT,
                               RAISE, KC_LGUI, 
        // right hand
                     KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_EQL,
                     KC_F,    KC_G,   KC_C,    KC_R,    KC_L,    KC_SLSH,
                     KC_D,    KC_H,   KC_T,    KC_N,    KC_S,    KC_ENT, 
                     KC_B,    KC_M,   KC_W,    KC_V,    KC_Z,    KC_RSHIFT,
                                      KC_LBRC, KC_RBRC,
        KC_BSPC, RAISE, 
        KC_RALT, LOWER,
        KC_RGUI, LOWER),
[_LOWER] = KEYMAP_5x6(
  // left hand
   KC_ESC,  LCTL(KC_C),    LCTL(KC_V),    LCTL(KC_X),    LCTL(KC_S),    LCTL(KC_Z), 
   _______,  LALT(KC_QUOT),  LALT(KC_COMM),   LALT(KC_DOT),     LALT(KC_DOT),   LALT(KC_Y),
   _______,  _______,  KC_LBRC,  KC_LCBR,  KC_LPRN, KC_MINS,
   _______,    _______,  _______,  _______,  _______,  _______,
                       _______,  _______, 
                               LOWER, _______, 
                               _______,   _______,
                               _______, _______,
        // right hand
                     LCTL(KC_Y),    _______,    _______,    _______,     _______,  _______,
                     _______,  _______,  _______,    _______,   _______,  KC_BSLS,
                     KC_EQL,  KC_RPRN,  KC_RCBR,  KC_RBRC, _______, _______,
                     _______,  _______,  _______,  _______,  _______,   _______,
                                         _______,  _______,
        _______, RAISE, 
        _______, _______,
        _______, _______),


[_RAISE] = KEYMAP_5x6(
  // left hand
   KC_F11,   KC_F1,      KC_F2,      KC_F3,      KC_F4,   KC_F5,
   _______,  KC_MPRV,    KC_MPLY,    KC_MNXT,    _______, _______,
   _______,  _______,    KC_VOLD,    KC_VOLU,    KC_MUTE, KC_MINS,
   _______,    _______,  _______,  _______,  _______,  _______,
                       _______,  _______, 
                               LOWER, _______, 
                               _______,   _______,
                               _______, _______,
        // right hand
                     KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F12,
                      _______,  _______, KC_UP,    _______,  KC_PSCR,  KC_BSLS,
                      KC_EQL,  KC_LEFT, KC_DOWN,  KC_RIGHT, KC_INS,   KC_DEL,
                     _______,  _______,  _______,  _______,  _______,   _______,
                                         _______,  _______,
        _______, RAISE, 
       _______, _______,
        _______, _______),

[_OSRS] = KEYMAP_5x6(
  // left hand
   KC_F11,   KC_F1,      KC_F2,      KC_F3,      KC_F4,   KC_F5,
   _______,  KC_MPRV,    KC_MPLY,    KC_MNXT,    _______, _______,
   KC_ESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4, KC_F5,
   _______,    _______,  _______,  _______,  _______,  _______,
                       _______,  _______, 
                               _______, _______, 
                               _______,   _______,
                               _______, _______,
        // right hand
                     KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F12,
                      _______,  _______, KC_UP,    _______,  KC_PSCR,  KC_BSLS,
                      _______,  KC_LEFT, KC_DOWN,  KC_RIGHT, KC_INS,   KC_DEL,
                     _______,  _______,  _______,  _______,  _______,   _______,
                                         _______,  _______,
        _______, _______, 
       _______, _______,
        _______, _______),

[_ADJUST] = KEYMAP_5x6(
  // left hand
   TO(_DEFAULT),   PLOVER,      _______,      _______,      _______,   _______,
   _______,  ST_GEM,    _______,    _______,    _______, _______,
   _______,  ST_BOLT,    _______,    _______,    _______, _______,
   _______,    _______,  _______,  _______,  _______,  _______,
                       _______,  _______, 
                               LOWER, _______, 
                               _______,   _______,
                               _______, _______,
        // right hand
                     _______,    _______,   _______,    _______,   _______,   RESET,
                      _______,  _______, _______,    _______,  _______,  _______,
                      _______,  _______, _______,  _______, _______,   _______,
                     _______,  _______,  _______,  _______,  _______,   _______,
                                         _______,  _______,
        _______, RAISE, 
       _______, _______,
        _______, _______),

[_PLOVER] = KEYMAP_5x6(
  // left hand
   STN_N1,   STN_N2,     STN_N3,     STN_N4,     STN_N5,  STN_N6,
   KC_TAB,   STN_S1,     STN_TL,     STN_PL,     STN_HL,  STN_ST1,
   KC_LCTL,  STN_S2,     STN_KL,     STN_WL,     STN_RL,  STN_ST2,
   KC_LSHIFT,  KC_1,    KC_2,    KC_3,    KC_4, LOWER,
                       LOWER,  RAISE, 
                               STN_A, STN_O, 
                               KC_SPC,   KC_LALT,
                               _______, KC_LGUI,
        // right hand
                     STN_N7,  STN_N8,    STN_N9,    STN_NA,    STN_NB,    STN_NC,
                     STN_ST3, STN_FR,    STN_PR,    STN_LR,    STN_TR,    STN_DR,
                     STN_ST4, STN_RR,   STN_BR,     STN_GR,   STN_SR,    STN_ZR,
                     RAISE,  KC_7, KC_8,  KC_9,  KC_0,  XXXXXXX,
                                         STN_RE1,  STN_RE2,
        STN_E, STN_U, 
       RAISE, KC_BSPC,
        _______, STN_PWR),


};



void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  // case DVORAK:
 //      if (record->event.pressed) {
 //        set_single_persistent_default_layer(_DEFAULT);
 //      }
 //      return false;
 //      break;
    case DVORAK:
      if (record->event.pressed) {
        layer_on(_DEFAULT);

      } else {
        layer_off(_DEFAULT);

      }
      return false;
      break;
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
    case OSRS:
      if (record->event.pressed) {
        layer_on(_OSRS);
        // update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_OSRS);
        // update_tri_layer(_LOWER, _RAISE, _ADJUST);
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


