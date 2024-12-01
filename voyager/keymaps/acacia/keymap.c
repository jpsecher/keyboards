#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_74_255_255,
  HSV_169_255_255,
  M_SAVE,
  M_QUIT,
};

enum layer_names {
  _ALP_MAC,
  _NAV_MAC,
  _NUM_MAC,
  _SYMBOLS,
  _ALP_OVL
};

#define AGRO RALT(KC_O)
#define AGRQUOT RALT(KC_QUOT)
#define AGRA RALT(KC_A)

#define CTLE RCTL(KC_E)
#define CTLA RCTL(KC_A)

#define GUIZ LGUI(KC_Z)
#define GUIY LGUI(KC_Y)
#define GUIX LGUI(KC_X)
#define GUIC LGUI(KC_C)
#define GUIV LGUI(KC_V)

#define BCK_NUM LT(_NUM_MAC, KC_BSPC)
#define LCK_NAV TO(_NAV_MAC)
#define ESC_NAV LT(_NAV_MAC, KC_ESC)
#define SPC_SYM LT(_SYMBOLS, KC_SPC)
#define OSM_LSFT OSM(MOD_LSFT)
#define LCK_ALP TO(_ALP_MAC)
#define OSL_ALP OSL(_ALP_OVL)
#define OSL_NUM OSL(_NUM_MAC)

#define P_AGR RALT_T(KC_P)
#define L_ALT LALT_T(KC_L)
#define J_CTL RCTL_T(KC_J)
#define K_GUI RGUI_T(KC_K)
#define F_CTL LCTL_T(KC_F)
#define D_GUI LGUI_T(KC_D)
#define S_ALT LALT_T(KC_S)
#define A_AGR RALT_T(KC_A)

#define V_SYM LT(_SYMBOLS, KC_V)
#define N_SYM LT(_SYMBOLS, KC_N)
#define C_NUM LT(_NUM_MAC, KC_C)
#define M_NUM LT(_NUM_MAC, KC_M)

#define F6_ALT LALT_T(KC_F6)
#define F7_GUI LGUI_T(KC_F7)
#define F8_CTL LCTL_T(KC_F8)
#define SIX_ALT LALT_T(KC_6)
#define FIVE_GUI RGUI_T(KC_5)
#define FOUR_CTL RCTL_T(KC_4)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALP_MAC] = LAYOUT_voyager(
    KC_MNXT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MPLY,
    XXXXXXX,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                            KC_Y,     KC_U,     KC_I,     KC_O,     KC_B,     XXXXXXX, 
    KC_TAB,   A_AGR,    S_ALT,    D_GUI,    F_CTL,    KC_G,                            KC_H,     J_CTL,    K_GUI,    L_ALT,    P_AGR,    KC_ENT,
    XXXXXXX,  KC_Z,     KC_X,     C_NUM,    V_SYM,    XXXXXXX,                         XXXXXXX,  N_SYM,    M_NUM,    KC_COMMA, KC_DOT,   XXXXXXX, 
                                                      OSM_LSFT, ESC_NAV,     BCK_NUM,  SPC_SYM
  ),
  [_NAV_MAC] = LAYOUT_voyager(
    KC_MPRV,  _______,  _______,  _______,  _______,  _______,                         _______,  _______,  _______,  _______,  _______,  _______, 
    _______,  GUIY,     KC_BTN3,  KC_BTN2,  KC_BTN1,  KC_WH_D,                         CTLA,     KC_PGDN,  KC_PGUP,  CTLE,     QK_LLCK,  _______, 
    _______,  GUIZ,     GUIX,     GUIC,     GUIV,     KC_WH_U,                         KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, M_SAVE,   _______, 
    _______,  _______,  KC_LALT,  KC_LGUI,  KC_LCTL,  _______,                         _______,  AGRQUOT,  AGRO,     AGRA,     M_QUIT,   _______, 
                                                      _______,  LCK_ALP,     _______,  _______
  ),
  [_ALP_OVL] = LAYOUT_voyager(
    _______,  _______,  _______,  _______,  _______,  _______,                         _______,  _______,  _______,  _______,  _______,  _______, 
    _______,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                            KC_Y,     KC_U,     KC_I,     KC_O,     KC_B,     _______, 
    _______,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                            KC_H,     KC_J,     KC_K,     KC_L,     KC_P,     _______,
    _______,  KC_Z,     KC_X,     KC_C,     KC_V,     _______,                         _______,  KC_N,     KC_M,     KC_COMMA, KC_DOT,   _______, 
                                                      _______,  LCK_ALP,     KC_BSPC,  KC_SPC
  ),
  [_NUM_MAC] = LAYOUT_voyager(
    RGB_TOG,  _______,  _______,  _______,  _______,  _______,                         _______,  _______,  _______,  _______,  _______,  QK_BOOT,        
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_QUES,                         KC_MINUS, KC_7,     KC_8,     KC_9,     QK_LLCK,  _______, 
    _______,  KC_F5,    F6_ALT,   F7_GUI,   F8_CTL,   KC_SCLN,                         KC_COLN,  FOUR_CTL, FIVE_GUI, SIX_ALT,  KC_PLUS,  KC_EQUAL,       
    _______,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,                         _______,  KC_1,     KC_2,     KC_3,     KC_DOT,   _______, 
                                                      KC_0,     LCK_ALP,     _______,  KC_0
  ),
  [_SYMBOLS] = LAYOUT_voyager(
    KC_VOLD,  _______,  _______,  _______,  _______,  _______,                         _______,  _______,  _______,  _______,  _______,  KC_VOLU,
    _______,  XXXXXXX,  KC_QUOTE, KC_LCBR,  KC_RCBR,  KC_QUES,                         KC_MINUS, KC_AMPR,  KC_ASTR,  KC_UNDS,  XXXXXXX,  _______, 
    KC_RABK,  KC_LABK,  KC_DQUO,  KC_LPRN,  KC_RPRN,  KC_SCLN,                         KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_PLUS,  KC_EQUAL,       
    _______,  KC_BSLS,  KC_GRAVE, KC_LBRC,  KC_RBRC,  _______,                         _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_PIPE,  _______, 
                                                      KC_SLASH, KC_TILD,     _______,  _______
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_SAVE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC) ":w" SS_TAP(X_ENT));
      }
      break;
    case M_QUIT:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC) ":q" SS_TAP(X_ENT));
      }
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
  }
  return true;
}



