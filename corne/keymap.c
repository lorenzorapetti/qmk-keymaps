#include QMK_KEYBOARD_H

#include "features/achordion.h"

// TODO:
// - Add media keys
// - Add unicode layer
// - Add leader key
// - Add mouse keys
// - Add repeat key
// - Add caps word

#define LAYOUT LAYOUT_split_3x6_3

#define LCTL_KA LCTL_T(KC_A)
#define LALT_KS LALT_T(KC_S)
#define LGUI_KD LGUI_T(KC_D)
#define LSFT_KF LSFT_T(KC_F)

#define LCTL_SCLN LCTL_T(KC_SCLN)
#define LALT_KL LALT_T(KC_L)
#define LGUI_KK LGUI_T(KC_K)
#define LSFT_KJ LSFT_T(KC_J)

#define LALT_KR LALT_T(KC_R)
#define LGUI_KS LGUI_T(KC_S)
#define LSFT_KT LSFT_T(KC_T)

#define LCTL_KO LCTL_T(KC_O)
#define LALT_KI LALT_T(KC_I)
#define LGUI_KE LGUI_T(KC_E)
#define LSFT_KN LSFT_T(KC_N)

// Yabai shortcuts
#define SPC_1 LCTL(LALT(KC_1))
#define SPC_2 LCTL(LALT(KC_2))
#define SPC_3 LCTL(LALT(KC_3))
#define SPC_4 LCTL(LALT(KC_4))
#define SPC_5 LCTL(LALT(KC_5))
#define SPC_6 LCTL(LALT(KC_6))
#define SPC_7 LCTL(LALT(KC_7))
#define SPC_8 LCTL(LALT(KC_8))
#define SPC_9 LCTL(LALT(KC_9))
#define SPC_0 LCTL(LALT(KC_0))

// Focus windows
#define FC_LEFT  LCTL(LALT(KC_H))
#define FC_DOWN  LCTL(LALT(KC_J))
#define FC_UP    LCTL(LALT(KC_K))
#define FC_RIGHT LCTL(LALT(KC_L))
#define FSP_LEFT  LCTL(LALT(KC_S))
#define FSP_RIGHT LCTL(LALT(KC_G))

// Swap windows
#define SW_LEFT  LSFT(FC_LEFT)
#define SW_DOWN  LSFT(FC_DOWN)
#define SW_UP    LSFT(FC_UP)
#define SW_RIGHT LSFT(FC_RIGHT)

// Move windows
#define MV_LEFT   HYPR(KC_H)
#define MV_DOWN   HYPR(KC_J)
#define MV_UP     HYPR(KC_K)
#define MV_RIGHT  HYPR(KC_L)
#define DSP_LEFT  LCTL(LSFT(LALT(KC_S)))
#define DSP_RIGHT LCTL(LSFT(LALT(KC_G)))

// Maximize window
#define MAX_WIN LCTL(LALT(LSFT(KC_M)))

// Layers
#define MO_SYM MO(_SYM)
#define MO_NUM MO(_NUM)
#define SPC_NAV LT(_NAV, KC_SPC)
#define ENT_YAB LT(_YABAI, KC_ENT)
#define ESC_MEDIA LT(_MEDIA, KC_ESC)

enum layers {
	_COLEMAK = 0,
	_QWERTY,
	_NUM,
	_SYM,
	_NAV,
	_YABAI,
	_MEDIA,
	_UNICODE,
	_KB_FN
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTY_NOHOMEROW,
  COLEMAK,
  COLEMAK_NOHOMEROW,
  LOWER,
  RAISE,
  ADJUST,
  ONESHOT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COLEMAK] = LAYOUT(
		KC_TAB,    KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,                    KC_J,      KC_L,    	 KC_U,      KC_Y,   	 KC_SCLN,   KC_BSLS,
		KC_BSPC,   LCTL_KA,   LALT_KR,   LGUI_KS,   LSFT_KT,   KC_G,             			  KC_M,      LSFT_KN,    LGUI_KE,   LALT_KI,   LCTL_KO,   KC_QUOT,
		KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,                    KC_K,      KC_H,       KC_COMM,   KC_DOT,    KC_SLSH,   ESC_MEDIA,
																	   KC_LGUI,   MO_SYM,    SPC_NAV,     					  ENT_YAB,   MO_NUM,     KC_RGUI
  ),

	[_QWERTY] = LAYOUT(
		KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                    KC_Y,      KC_U,    	KC_I,      KC_O,   	 KC_P,        KC_BSLS,
		KC_BSPC,   LCTL_KA,   LALT_KS,   LGUI_KD,   LSFT_KF,   KC_G,             		    KC_M,      LSFT_KJ,   LGUI_KK,   LALT_KL,  LCTL_SCLN,   KC_QUOT,
		KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,                    KC_K,      KC_H, 		  KC_COMM,   KC_DOT, 	 KC_SLSH,     ESC_MEDIA,
																	   KC_LGUI,   MO_SYM,    SPC_NAV,     					  ENT_YAB,   MO_NUM,    KC_RGUI
	),

	[_NUM] = LAYOUT(
		_______,   _______,   KC_7,      KC_8,      KC_9,      _______,                 _______,   _______,   _______,   _______,   _______,   _______,
		_______,   _______,   KC_4,      KC_5,      KC_6,      _______,             		KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,
		_______,   _______,   KC_1,      KC_2,      KC_3,      KC_EQL,                  KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,
																	   KC_0,      KC_DOT,    _______,     					  _______,   _______, 	_______
	),

	[_SYM] = LAYOUT(
		KC_GRV,    KC_EXLM,   KC_AT,     KC_LCBR,   KC_RCBR,   _______,                 _______,   KC_PLUS,   KC_ASTR,   KC_SLSH,   _______,   _______,
		KC_TILD,   KC_PERC,   KC_HASH,   KC_LPRN,   KC_RPRN,   _______,             		_______,   KC_COLN,   KC_SCLN,   KC_PIPE,   _______,   _______,
		_______,   KC_CIRC,   KC_DLR,    KC_LBRC,   KC_RBRC,   _______,                 _______,   KC_EQL,    KC_MINS,   KC_UNDS, 	KC_BSLS,   _______,
																	   _______,   _______,   _______,     					  _______,   _______, 	_______
	),

	[_NAV] = LAYOUT(
		_______,   _______,   _______,   _______,   _______,   _______,                 KC_HOME,   KC_PGDN,   KC_PGUP,   KC_END,     _______,   _______,
		_______,   _______,   _______,   _______,   _______,   _______,             		KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,   _______,   _______,
		_______,   _______,   _______,   _______,   _______,   _______,                 _______,   _______,   _______,   _______,    _______,   KC_LSFT,
																	   _______,   _______,   _______,     					  _______,   _______, 	_______
	),

	[_YABAI] = LAYOUT(
		XXXXXXX,   DSP_LEFT,    SPC_7,     SPC_8,     SPC_9,    DSP_RIGHT,              MV_LEFT,   MV_DOWN,   MV_UP,    MV_RIGHT,   XXXXXXX,   XXXXXXX,
		XXXXXXX,   FSP_LEFT,    SPC_4,     SPC_5,     SPC_6,    FSP_RIGHT,           		FC_LEFT,   FC_DOWN,   FC_UP,    FC_RIGHT,   XXXXXXX,   XXXXXXX,
		XXXXXXX,   SPC_0,       SPC_1,     SPC_2,     SPC_3,    MAX_WIN,                SW_LEFT,   SW_DOWN,   SW_UP,    SW_RIGHT,   XXXXXXX,   KC_LSFT,
																	    XXXXXXX,   XXXXXXX,   XXXXXXX,     					  _______,   XXXXXXX, 	XXXXXXX
	),

	[_MEDIA] = LAYOUT(
		_______,   _______,   _______,   _______,   _______,   _______,                 _______,   _______,   _______,   _______,   _______,   _______,
		_______,   _______,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_BRIU,             		_______,   _______,   _______,   _______,   _______,   _______,
		_______,   _______,   KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_BRID,                 _______,   _______,   _______,   _______, 	_______,   _______,
																	   _______,   _______,   _______,     					  _______,   _______, 	_______
	)

	// Template for adding new layers
	// [_QWERTY] = LAYOUT(
	// 	_______,   _______,   _______,   _______,   _______,   _______,                 _______,   _______,   _______,   _______,   _______,   _______,
	// 	_______,   _______,   _______,   _______,   _______,   _______,             		_______,   _______,   _______,   _______,   _______,   _______,
	// 	_______,   _______,   _______,   _______,   _______,   _______,                 _______,   _______,   _______,   _______, 	_______,   _______,
	// 																   _______,   _______,   _______,     					  _______,   _______, 	_______
	// )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
	}
	return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPC_NAV:
        case ENT_YAB:
				case ESC_MEDIA:
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // This enables same-hand combinations
  switch (tap_hold_keycode) {
    case SPC_NAV:
		case ENT_YAB:
		case ESC_MEDIA:
			return true;
  }

  return achordion_opposite_hands(tap_hold_record, other_record);
}
