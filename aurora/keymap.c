#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum layers {
    _DEFAULT = 0,
    _NAV = 1,
    _NUM = 2,
    _SYM = 3,
    _SYM_2 = 4,
    _MOV = 5
};

enum custom_keycodes {
    QUOTE = SAFE_RANGE,
    TILDE,
    CURLY_OPEN,
    CURLY_CLOSED,
    ROUND_OPEN,
    ROUND_CLOSED,
    SQUARE_OPEN,
    SQUARE_CLOSED,
    AT,
    DOLLAR,
    AMPERSAND,
    POUND,
    ANGLE_OPEN,
    ANGLE_CLOSED,
    PERCENT,
    UNDERSCORE,
    PIPE,
    COLON,
    BCKSLSH,
    PLUS,
    ASTRSK,
    EXCLAMATION,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
        KC_Q,         KC_W,         KC_F,         KC_P,              KC_B,                     KC_J,             KC_L,             KC_U,             KC_Y,           KC_QUOTE,
        KC_A,         KC_R,         KC_S,         KC_T,              KC_G,                     KC_M,             KC_N,             KC_E,             KC_I,           KC_O,
        LCTL_T(KC_Z), LALT_T(KC_X), LGUI_T(KC_C), LSFT_T(KC_D),      KC_V,                     KC_K,             RSFT_T(KC_H),     LGUI_T(KC_COMMA), RALT_T(KC_DOT), RCTL_T(KC_SLSH),
                                                  LT(_NAV, KC_BSPC), LT(_MOV, KC_SPACE),       LT(_SYM, KC_ENT), LT(_NUM, KC_ESC)
    ),
    [_NAV] = LAYOUT(
        KC_TAB,     KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,             LGUI(LSFT(KC_Z)),   LGUI(KC_V),   LGUI(KC_C),    LGUI(KC_X),     LGUI(KC_Z),
        KC_TRNS,    KC_TRNS,      KC_TRNS,      KC_LGUI,      KC_TRNS,             KC_LEFT,            KC_DOWN,      KC_UP,      KC_RIGHT,   KC_CAPS,
        KC_LCTL,    KC_LALT,      KC_LGUI,      KC_LSFT,      KC_TRNS,             KC_TRNS,            KC_HOME,      KC_PGDN,    KC_PGUP,    KC_END,
                                                KC_TRNS,      KC_TRNS,             KC_ENT,             KC_DEL
    ),
    [_NUM] = LAYOUT(
        KC_PSLS, KC_7, KC_8, KC_9, KC_PAST,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_4, KC_5, KC_6, KC_PMNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_1, KC_2, KC_3, KC_PPLS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             KC_0, KC_EQUAL,        KC_TRNS, KC_TRNS
    ),
    [_SYM] = LAYOUT(
        QUOTE,      TILDE,        CURLY_OPEN,  CURLY_CLOSED,  AT,               KC_TRNS, KC_MINUS, UNDERSCORE, PIPE,    KC_TRNS,
        DOLLAR,     AMPERSAND,    ROUND_OPEN,  ROUND_CLOSED,  POUND,            KC_TRNS, KC_SCLN,  COLON,      BCKSLSH, KC_TRNS,
        ANGLE_OPEN, ANGLE_CLOSED, SQUARE_OPEN, SQUARE_CLOSED, PERCENT,          KC_TRNS, KC_EQL,   PLUS,       ASTRSK,  EXCLAMATION,
                                               KC_TRNS,       KC_TRNS,          KC_TRNS, KC_TRNS
    ),
    [_SYM_2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, LALT(KC_RBRC), LALT(LSFT(KC_RBRC)), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, LALT(KC_LBRC), LALT(LSFT(KC_LBRC)), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS
    ),
    [_MOV] = LAYOUT(
        LGUI(KC_GRV), KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,         LCTL(LALT(LSFT(KC_H))), KC_TRNS,                KC_TRNS,                LCTL(LALT(LSFT(KC_L))), KC_TRNS,
        KC_TRNS,      KC_TRNS, KC_TRNS, LCTL(KC_J), KC_TRNS,         LCTL(LALT(KC_H)),       LCTL(LALT(KC_J)),       LCTL(LALT(KC_K)),       LCTL(LALT(KC_L)),       KC_TRNS,
        KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,         KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,                KC_TRNS,
                                        KC_TRNS,    KC_TRNS,         LCTL(LALT(KC_ENT)),     KC_TRNS
    )
};

const uint16_t PROGMEM sym2_combo[] = {KC_Q, KC_QUOTE, COMBO_END};

combo_t key_combos[] = {
    COMBO(sym2_combo, OSL(_SYM_2)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }

    if (record->event.pressed) {
        switch (keycode) {
        case QUOTE:
            SEND_STRING("`");
            break;
        case TILDE:
            SEND_STRING("~");
            break;
        case CURLY_OPEN:
            SEND_STRING("{");
            break;
        case CURLY_CLOSED:
            SEND_STRING("}");
            break;
        case ROUND_OPEN:
            SEND_STRING("(");
            break;
        case ROUND_CLOSED:
            SEND_STRING(")");
            break;
        case SQUARE_OPEN:
            SEND_STRING("[");
            break;
        case SQUARE_CLOSED:
            SEND_STRING("]");
            break;
        case AT:
            SEND_STRING("@");
            break;
        case DOLLAR:
            SEND_STRING("$");
            break;
        case AMPERSAND:
            SEND_STRING("&");
            break;
        case POUND:
            SEND_STRING("#");
            break;
        case ANGLE_OPEN:
            SEND_STRING("<");
            break;
        case ANGLE_CLOSED:
            SEND_STRING(">");
            break;
        case PERCENT:
            SEND_STRING("%");
            break;
        case UNDERSCORE:
            SEND_STRING("_");
            break;
        case PIPE:
            SEND_STRING("|");
            break;
        case COLON:
            SEND_STRING(":");
            break;
        case BCKSLSH:
            SEND_STRING("\\");
            break;
        case PLUS:
            SEND_STRING("+");
            break;
        case ASTRSK:
            SEND_STRING("*");
            break;
        case EXCLAMATION:
            SEND_STRING("!");
            break;
        }
    }
    return true;
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NAV, KC_BSPC):
        case LT(_MOV, KC_SPACE):
        case LT(_SYM, KC_ENT):
        case LT(_NUM, KC_ESC):
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
    case LT(_SYM, KC_ENT):
    case LT(_NAV, KC_BSPC):
    case LT(_NUM, KC_ESC):
    case LT(_MOV, KC_SPACE):
        return true;
  }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

// bool achordion_eager_mod(uint8_t mod) {
//   switch (mod) {
//     case MOD_LSFT:
//     case MOD_RSFT:
//     case MOD_LCTL:
//     case MOD_RCTL:
//       return true;  // Eagerly apply Shift and Ctrl mods.

//     default:
//       return false;
//   }
// }
