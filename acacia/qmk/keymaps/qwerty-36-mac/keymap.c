/* Copyright 2024 Jens Peter Secher <jpsecher@gmail.com>
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
#include QMK_KEYBOARD_H

enum layer_names {
  _ALP_MAC,
  _NAV_MAC,
  _NUM_MAC,
  _SYMBOLS,
  _ALP_OVL
};

#define LCK_ALPM TO(_ALP_MAC)
#define OSL_ALPM OSL(_ALP_OVL)
#define LCK_NAVM TO(_NAV_MAC)
#define TT_NAVM TT(_NAV_MAC)
#define MO_SYM MO(_SYMBOLS)
#define MO_ALPM MO(_ALP_MAC)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)
#define OSL_FUNM OSL(_NUM_MAC)
#define SPC_FUNM LT(_NUM_MAC, KC_SPC)
#define ESC_FUNM LT(_NUM_MAC, KC_ESC)
#define BCK_NUM LT(_NUM_MAC, KC_BSPC)
#define ESC_NAV LT(_NAV_MAC, KC_ESC)
#define OSM_AGR OSM(MOD_RALT)
#define Z_GUI LGUI_T(KC_Z)
#define B_GUI RGUI_T(KC_B)
#define X_ALT LALT_T(KC_X)

#define V_SYM LT(_SYMBOLS, KC_V)
#define N_SYM LT(_SYMBOLS, KC_N)
#define C_NUM LT(_NUM_MAC, KC_C)
#define M_NUM LT(_NUM_MAC, KC_M)
#define X_NAV LT(_NAV_MAC, KC_X)
#define COMM_NAV LT(_NAV_MAC, KC_COMM)
#define G_SFT LSFT_T(KC_G)
#define H_SFT RSFT_T(KC_H)


#define LBRC_ALT LALT_T(KC_LBRC)
#define C_SYM LT(_SYMBOLS, KC_C)
#define V_CTL LCTL_T(KC_V)
#define RBRC_CTL RCTL_T(KC_RBRC)
#define N_CTL RCTL_T(KC_N)
#define M_SYM LT(_SYMBOLS, KC_M)
#define SCLN_SYM LT(_SYMBOLS, KC_SCLN)
#define COMM_ALT LALT_T(KC_COMM)
#define DOT_GUI RGUI_T(KC_DOT)
#define BSLS_GUI RGUI_T(KC_BSLS)
#define GUIZ LGUI(KC_Z)
#define GUIX LGUI(KC_X)
#define GUIC LGUI(KC_C)
#define GUIV LGUI(KC_V)
#define GUIQ LGUI(KC_Q)
#define GUIW LGUI(KC_W)
#define GUIF LGUI(KC_F)
#define GUIA LGUI(KC_A)
#define GUIS LGUI(KC_S)
#define GUID LGUI(KC_D)
#define GUIK LGUI(KC_K)
#define GUIR LGUI(KC_R)
#define GUIL LGUI(KC_L)
#define GUIE LGUI(KC_E)
#define GUIY LGUI(KC_Y)
#define GUIO LGUI(KC_O)
#define GUII LGUI(KC_I)
#define GUIT LGUI(KC_T)
#define GUIG LGUI(KC_G)
#define GUIH LGUI(KC_H)
#define GUIB LGUI(KC_B)
#define GUIU LGUI(KC_U)
#define PGDN_CTL RCTL_T(KC_PGDN)
#define PGUP_SYM LT(_SYMBOLS, KC_PGUP)
#define ONE_CTL RCTL_T(KC_1)
#define TWO_SYM LT(_SYMBOLS, KC_2)
#define THRE_ALT LALT_T(KC_3)
#define F1_CTL RCTL_T(KC_F1)
#define F3_ALT LALT_T(KC_F3)
#define F11_GUI RGUI_T(KC_F11)
#define MINS_AGR RALT_T(KC_MINS)
#define SIX_ALT LALT_T(KC_6)
#define FIVE_GUI RGUI_T(KC_5)
#define FOUR_CTL RCTL_T(KC_4)
#define QUOT_GUI RGUI_T(KC_QUOT)
#define GRV_AGR RALT_T(KC_GRV)
#define AGRO RALT(KC_O)
#define AGRQUOT RALT(KC_QUOT)
#define AGRA RALT(KC_A)
#define CTLE RCTL(KC_E)
#define CTLA RCTL(KC_A)
#define TAB_FUNM LT(_NUM_MAC, KC_TAB)
#define SPC_SYM LT(_SYMBOLS, KC_SPC)
#define B_FUNM LT(_NUM_MAC, KC_B)
#define P_AGR RALT_T(KC_P)
#define L_ALT LALT_T(KC_L)
#define J_CTL RCTL_T(KC_J)
#define K_GUI RGUI_T(KC_K)
#define F_CTL LCTL_T(KC_F)
#define D_GUI LGUI_T(KC_D)
#define S_ALT LALT_T(KC_S)
#define A_AGR RALT_T(KC_A)
#define B_SHFT LSFT_T(KC_B)
#define F5_AGR RALT_T(KC_F5)
#define F6_ALT LALT_T(KC_F6)
#define F7_GUI LGUI_T(KC_F7)
#define F8_CTL LCTL_T(KC_F8)

enum {
  // Save buffer in editor
  SAVE = SAFE_RANGE,
  // Quit editor
  QUIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALP_MAC] = LAYOUT(
    XXXXXXX,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_B,     XXXXXXX,
    KC_TAB,   A_AGR,    S_ALT,    D_GUI,    F_CTL,    G_SFT,     H_SFT,    J_CTL,    K_GUI,    L_ALT,    P_AGR,    KC_ENT,
              KC_Z,     KC_X,     C_NUM,    V_SYM,                         N_SYM,    M_NUM,    KC_COMM,  KC_DOT,
              KC_MNXT,  XXXXXXX,  OSM_LSFT, ESC_NAV,  XXXXXXX,   XXXXXXX,  BCK_NUM,  SPC_SYM,  XXXXXXX,  KC_MPLY,  DB_TOGG
  ),
  [_NAV_MAC] = LAYOUT(
    _______,  GUIY,     KC_BTN3,  KC_BTN2,  KC_BTN1,  KC_WH_D,   CTLA,     KC_PGDN,  KC_PGUP,  CTLE,     QK_LLCK,  _______,
    _______,  GUIZ,     GUIX,     GUIC,     GUIV,     KC_WH_U,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  SAVE,     _______,
              _______,  KC_LALT,  KC_LGUI,  KC_LCTL,                       AGRQUOT,  AGRO,     AGRA,     QUIT,
              KC_MPRV,  _______,  _______,  LCK_ALPM, _______,   _______,  _______,  _______,  _______,  _______,  DB_TOGG
  ),
  [_ALP_OVL] = LAYOUT(
    _______,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_B,     _______,
    _______,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_P,     _______,
              KC_Z,     KC_X,     KC_C,     KC_V,                          KC_N,     KC_M,     KC_COMM,  KC_DOT,
              _______,  _______,  _______,  LCK_ALPM, _______,   _______,  KC_BSPC,  KC_SPC,   _______,  _______,  DB_TOGG
  ),
  [_NUM_MAC] = LAYOUT(
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_QUES,   KC_MINS,  KC_7,     KC_8,     KC_9,     QK_LLCK,  _______,
    _______,  F5_AGR,   F6_ALT,   F7_GUI,   F8_CTL,   KC_SCLN,   KC_COLN,  FOUR_CTL, FIVE_GUI, SIX_ALT,  KC_PLUS,  KC_EQL,
              KC_F9,    KC_F10,   KC_F11,   KC_F12,                        KC_1,     KC_2,     KC_3,     KC_DOT,
              QK_BOOT,  _______,  KC_0,     LCK_ALPM, _______,   _______,  _______,  KC_0,     _______,  KC_PWR,   DB_TOGG
  ),
  [_SYMBOLS] = LAYOUT(
    _______,  XXXXXXX,  KC_GRV,   KC_LCBR,  KC_RCBR,  KC_QUES,   KC_MINS,  KC_AMPR,  KC_ASTR,  KC_UNDS,  XXXXXXX,  _______,
    KC_GT,    KC_LT,    KC_DQUO,  KC_LPRN,  KC_RPRN,  KC_SCLN,   KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_PLUS,  KC_EQL,
              KC_BSLS,  KC_QUOT,  KC_LBRC,  KC_RBRC,                       KC_EXLM,  KC_AT,    KC_HASH,  KC_PIPE,
              KC_VOLD,  _______,  KC_SLSH,  KC_TILD,  _______,   _______,  _______,  _______,  _______,  KC_VOLU,  DB_TOGG
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Store the current modifier state in the variable for later reference.
  static uint8_t mod_state;
  mod_state = get_mods();
  switch (keycode) {
    case SAVE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC) ":w" SS_TAP(X_ENT));
        return false;
      }
      break;
    case QUIT:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC) ":q" SS_TAP(X_ENT));
        return false;
      }
      break;
  }
  return true;
}
