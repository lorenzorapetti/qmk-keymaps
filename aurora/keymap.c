#include QMK_KEYBOARD_H
#include "features/achordion.h"

// TODO: add repeat key somewhere

enum layers {
    _DEFAULT = 0,
    _QUERTY = 1,
    _NAV = 2,
    _NUM = 3,
    _SYM = 4,
    _SYM_2 = 5,
    _MOV = 6
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
    A_GRAVE,
    A_GRAVE_UP,
    E_GRAVE,
    E_GRAVE_UP,
    E_ACUTE,
    E_ACUTE_UP,
    I_GRAVE,
    I_GRAVE_UP,
    O_GRAVE,
    O_GRAVE_UP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
        KC_Q,         KC_W,         KC_F,         KC_P,              KC_B,                     KC_J,             KC_L,         KC_U,         KC_Y,         KC_QUOTE,
        LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T),      KC_G,                     KC_M,             RSFT_T(KC_N), LGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_O),
        KC_Z,         KC_X,         KC_C,         KC_D,              KC_V,                     KC_K,             KC_H,         KC_COMMA,     KC_DOT,       KC_SLSH,
                                                  LT(_NAV, KC_BSPC), LT(_MOV, KC_SPACE),       LT(_SYM, KC_ENT), LT(_NUM, KC_ESC)
    ),
    [_QUERTY] = LAYOUT(
        KC_Q,         KC_W,         KC_E,         KC_R,              KC_T,                     KC_Y,             KC_U,         KC_I,         KC_O,         KC_P,
        LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F),      KC_G,                     KC_H,             RSFT_T(KC_J), LGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN),
        KC_Z,         KC_X,         KC_C,         KC_V,              KC_B,                     KC_N,             KC_M,         KC_COMMA,     KC_DOT,       KC_SLSH,
                                                  LT(_NAV, KC_BSPC), LT(_MOV, KC_SPACE),       LT(_SYM, KC_ENT), LT(_NUM, KC_ESC)
    ),
    [_NAV] = LAYOUT(
        KC_TAB,     KC_TRNS,      KC_TRNS,         KC_TRNS,      KC_TRNS,             LGUI(LSFT(KC_Z)),   LGUI(KC_V),   LGUI(KC_C),    LGUI(KC_X),     LGUI(KC_Z),
        KC_LCTL,    KC_LALT,      KC_LGUI,         KC_LSFT,      KC_TRNS,             KC_LEFT,            KC_DOWN,      KC_UP,      KC_RIGHT,   KC_CAPS,
        KC_TRNS,    KC_TRNS,      LGUI(KC_C),      KC_TRNS,      LGUI(KC_V),          KC_TRNS,            KC_HOME,      KC_PGDN,    KC_PGUP,    KC_END,
                                                   KC_TRNS,      KC_TRNS,             KC_ENT,             KC_TAB
    ),
    [_NUM] = LAYOUT(
        KC_PSLS, KC_7, KC_8, KC_9, KC_PAST,         KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
        KC_TRNS, KC_4, KC_5, KC_6, KC_PMNS,         KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_TRNS, KC_1, KC_2, KC_3, KC_PPLS,         KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,
                             KC_0, KC_EQUAL,        KC_TRNS, KC_TRNS
    ),
    [_SYM] = LAYOUT(
        KC_GRV,     TILDE,        CURLY_OPEN,  CURLY_CLOSED,  AT,               KC_TRNS,    KC_TRNS,  KC_TRNS, PIPE,    KC_TRNS,
        DOLLAR,     AMPERSAND,    ROUND_OPEN,  ROUND_CLOSED,  POUND,            KC_MINUS,   KC_SCLN,  COLON,   BCKSLSH, KC_TRNS,
        ANGLE_OPEN, ANGLE_CLOSED, KC_LBRC,     KC_RBRC,       PERCENT,          UNDERSCORE, KC_EQL,   PLUS,    ASTRSK,  EXCLAMATION,
                                               KC_TRNS,       KC_TRNS,          KC_TRNS, KC_TRNS
    ),
    [_SYM_2] = LAYOUT(
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        A_GRAVE,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, E_ACUTE,    E_GRAVE,    I_GRAVE,    O_GRAVE,
        A_GRAVE_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, E_ACUTE_UP, E_GRAVE_UP, I_GRAVE_UP, O_GRAVE_UP,
                                      KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS
    ),
    [_MOV] = LAYOUT(
        LGUI(KC_GRV), KC_NO, KC_NO, KC_NO,      KC_NO,         LCTL(LALT(LSFT(KC_S))), LCTL(LALT(KC_S)),       LCTL(LALT(KC_G)),       LCTL(LALT(LSFT(KC_G))), KC_NO,
        KC_TAB,      KC_LALT, KC_NO, LCTL(KC_J), KC_NO,         LCTL(LALT(KC_H)),       LCTL(LALT(KC_J)),       LCTL(LALT(KC_K)),       LCTL(LALT(KC_L)),       KC_NO,
        KC_NO,      KC_NO,   LCTL(LALT(KC_DOWN)), LCTL(LALT(KC_UP)),      KC_NO,         LCTL(LSFT(LALT(KC_H))), LCTL(LSFT(LALT(KC_J))), LCTL(LSFT(LALT(KC_K))), LCTL(LSFT(LALT(KC_L))), KC_NO,
                                    KC_NO,      KC_NO,         LCTL(LSFT(LALT(KC_M))), KC_NO
    )
};

const uint16_t PROGMEM sym2_combo[]    = {KC_Q, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM qwerty_combo[]  = {KC_W, KC_Y, COMBO_END};
const uint16_t PROGMEM colemak_combo[] = {KC_W, KC_O, COMBO_END};

combo_t key_combos[] = {
    COMBO(sym2_combo, OSL(_SYM_2)),
    COMBO(qwerty_combo, DF(_QUERTY)),
    COMBO(colemak_combo, DF(_DEFAULT))
};

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

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
        case A_GRAVE:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRV) SS_UP(X_LALT) SS_TAP(X_A));
            break;
        case A_GRAVE_UP:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRV) SS_UP(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_A) SS_UP(X_LSFT));
            break;
        case E_GRAVE:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRV) SS_UP(X_LALT) SS_TAP(X_E));
            break;
        case E_GRAVE_UP:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRV) SS_UP(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_E) SS_UP(X_LSFT));
            break;
        case E_ACUTE:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_E) SS_UP(X_LALT) SS_TAP(X_E));
            break;
        case E_ACUTE_UP:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_E) SS_UP(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_E) SS_UP(X_LSFT));
            break;
        case I_GRAVE:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRV) SS_UP(X_LALT) SS_TAP(X_I));
            break;
        case I_GRAVE_UP:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRV) SS_UP(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_I) SS_UP(X_LSFT));
            break;
        case O_GRAVE:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRV) SS_UP(X_LALT) SS_TAP(X_O));
            break;
        case O_GRAVE_UP:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_GRV) SS_UP(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_O) SS_UP(X_LSFT));
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
