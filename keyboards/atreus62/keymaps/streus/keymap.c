// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus62.h"
#include "action_layer.h"
#include "keymap_steno.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0


#define _PLOVERQW 9
#define _PLOVER 10
#define _LOWER 11
#define _RAISE 12


#define _ADJUST 20

#define _NAV 25
#define _RESET 26

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  DVORAK_OH,
  DVORAK_OHM, //M for mirror
  DVORAK_OHR, //R for raise
  DVORAK_OHL, //L for lower
  LOWER,
  RAISE,
  ADJUST,
  FUSION,
  PLOVER,
  EXT_PLV,
  PLOVERQW,
  EXT_PQW
};

#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// [_DEFAULT] = { /* qwerty */
// 		{ KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS },
// 		{ KC_BSLS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC },
// 		{ KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TRNS,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
// 		{ KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DELT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LBRC },
// 		{ KC_LCTL,  KC_LGUI, KC_LALT, KC_GRV,  MO(_NAV),KC_BSPC, KC_ENT,   KC_SPC,  KC_EQL,  KC_MINS, KC_QUOT, KC_ENT,  KC_RGUI }
// },

[_DEFAULT] = {
  { KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5, 		   KC_TRNS,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL },
  { KC_TAB,          KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y, 		   KC_TRNS,    KC_F,     KC_G,    KC_C,    KC_R,    KC_L,      KC_SLSH }, 
  { KC_LCTL,         KC_A,    KC_O,    KC_E,    KC_U,    KC_I, 		   KC_TRNS,    KC_D,     KC_H,    KC_T,    KC_N,    KC_S,      KC_ENT }, 
  { KC_LSFT,         KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, 		   KC_BSPC,    KC_B,     KC_M,    KC_W,    KC_V,    KC_Z,      KC_RSFT}, 
  { _______,         _______,  KC_LGUI, KC_LGUI, KC_LALT,   LOWER,    KC_SPC,  	RAISE,  KC_RALT,   KC_RGUI, KC_RGUI, _______,    _______} 
},

[_LOWER] = {
  {KC_ESC,  LCTL(KC_C),    LCTL(KC_V),       LCTL(KC_X),      LCTL(KC_S),   LCTL(KC_Z), KC_TRNS,   LCTL(KC_Y),    _______,    _______,    _______, _______, _______}, 
  {_______, LALT(KC_QUOT), LALT(KC_COMM),    LALT(KC_DOT),    LALT(KC_P),   LALT(KC_Y), KC_TRNS,   _______,    _______,    _______,    _______, KC_0, KC_BSLS}, 
  {_______, _______,       KC_LBRC,          KC_LCBR,         KC_LPRN,      KC_MINS, KC_TRNS,      _______,    KC_RPRN,    KC_RCBR,    KC_RBRC, _______, XXXXXXX}, 
  {_______, KC_UP,         KC_RBRC,          KC_RCBR,         KC_RPRN,      KC_ENT, KC_TRNS,    _______,    _______,    _______,    _______, _______, _______}, 
  {KC_LEFT, KC_DOWN,       KC_RIGHT,          _______,     _______,         KC_BSPC, KC_TRNS,    _______,    _______,    _______,    _______, _______, _______} 
}, 

[_RAISE] = {
  {KC_F11,   KC_F1,      KC_F2,      KC_F3,      KC_F4,   KC_F5,  KC_TRNS, KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F12}, 
  {_______,  KC_MPRV,    KC_MPLY,    KC_MNXT,    _______, _______, KC_TRNS, _______,  _______, KC_UP,    _______,  KC_PSCR,  KC_BSLS}, 
  {_______,  _______,    KC_VOLD,    KC_VOLU,    KC_MUTE, _______, KC_TRNS, _______,  KC_LEFT, KC_DOWN,  KC_RIGHT, KC_INS,   KC_DEL}, 
  {_______,  _______,    _______,    _______,    _______, _______, KC_TRNS, _______,  _______, _______,  _______,  _______,  _______}, 
  {_______,  _______,    _______,    _______,    _______, _______, KC_TRNS, KC_SPC,   _______, _______,  _______,  _______,  _______} 
}, 



[_PLOVER] = {
  {STN_N1,   STN_N2,     STN_N3,     STN_N4,     STN_N5,  STN_N6,   XXXXXXX,  STN_N7,  STN_N8,    STN_N9,    STN_NA,    STN_NB,    STN_NC}, 
  {KC_TAB,   STN_S1,     STN_TL,     STN_PL,     STN_HL,  STN_ST1,  XXXXXXX,  STN_ST3, STN_FR,    STN_PR,    STN_LR,    STN_TR,    STN_DR}, 
  {KC_LCTL,  STN_S2,     STN_KL,     STN_WL,     STN_RL,  STN_ST2,  XXXXXXX,  STN_ST4, STN_RR,   STN_BR,     STN_GR,   STN_SR,    STN_ZR}, 
  {KC_LSFT,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, LOWER,    STN_E,    RAISE,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX}, 
  {ADJUST,  XXXXXXX,    XXXXXXX,    KC_LGUI,    KC_LALT,   STN_A,   STN_O,    STN_U,   KC_BSPC, XXXXXXX,   STN_PWR,  STN_RE1,  STN_RE2} 
}, 

[_ADJUST] = {
  {TO(_DEFAULT),   PLOVER,      PLOVERQW,      _______,      _______,   _______,  KC_TRNS, _______,    _______,   _______,    _______,   _______,   RESET}, 
  {_______,  ST_GEM,    _______,    _______,    _______, _______, KC_TRNS, _______,  _______, _______,    _______,  _______,  _______}, 
  {_______,  ST_BOLT,    _______,    _______,    _______, _______, KC_TRNS, _______,  _______, _______,  _______, _______,   _______}, 
  {_______,  _______,    _______,    _______,    _______, _______, KC_TRNS, _______,  _______, _______,  _______,  _______,  _______}, 
  {_______,  _______,    _______,    _______,    _______, _______, KC_TRNS, _______,   _______, _______,  _______,  _______,  _______} 
}, 


// [_PLOVERQW] = {
//   {KC_1,     KC_1,       KC_1,       KC_1,       KC_1,    KC_1,    KC_TRNS, KC_1,    KC_1,      KC_1,      KC_1,      KC_1,      KC_1}, 
//   {XXXXXXX,  KC_Q,       KC_W,       KC_E,       KC_R,    KC_T,    KC_TRNS, KC_Y,    KC_U,    KC_I,      KC_O,      KC_P,      KC_LBRC}, 
//   {XXXXXXX,  KC_A,       KC_S,       KC_D,       KC_F,    KC_G,    KC_TRNS,  KC_H,      KC_J,       KC_K,      KC_L,      KC_SCLN,   KC_QUOT}, 
//   {XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, KC_BSPC,    XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX}, 
//   {EXT_PQW,  XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_C, KC_V,       XXXXXXX,    KC_N,     KC_M, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX} 
// }, 
// [_NAV] = { 
// 		{ TO(_DEFAULT),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  },
// 		{ KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_F12,  KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS },
// 		{ KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS },
// 		{ TO(_RESET),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
// 		{ KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
// },

// [_RESET] = {
// 		{ TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
// 		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
// 		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
// 		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
// 		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET }
// }


/*
[_TRNS] = {
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},
*/
};



const uint16_t PROGMEM fn_actions[] = {

};

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
	switch (id) {
	case 0:
		if (record->event.pressed) {
			register_code(KC_RSFT);
		}
		else {
			unregister_code(KC_RSFT);
		}
		break;
	}
	return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	// case DVORAK:
 //      if (record->event.pressed) {
 //        set_single_persistent_default_layer(_DEFAULT);
 //      }
 //      return false;
 //      break;
    // case DVORAK:
    //   if (record->event.pressed) {
    //     layer_on(_DEFAULT);

    //   } else {
    //     layer_off(_DEFAULT);

    //   }
    //   return false;
    //   break;
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
	case PLOVERQW:
      if (!record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_on(_PLOVERQW);
      }
      return false;
      break;
    case EXT_PQW:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVERQW);
      }
      return false;
      break;
  }
  return true;
}

