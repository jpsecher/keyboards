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
  _ALPHA_MAC,
  _NAVI_MAC,
  _FUNC_MAC,
  _SYM_NUM,
  _ALPHA_OL
};

#define LCK_ALPM TO(_ALPHA_MAC)
#define OSL_ALPM OSL(_ALPHA_OL)
#define LCK_NAVM TO(_NAVI_MAC)
#define TT_NAVM TT(_NAVI_MAC)
#define MO_SYM MO(_SYM_NUM)
#define MO_ALPM MO(_ALPHA_MAC)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)
#define SPC_FUNM LT(_FUNC_MAC, KC_SPC)
#define OSM_AGR OSM(MOD_RALT)
#define Z_GUI LGUI_T(KC_Z)
#define B_GUI RGUI_T(KC_B)
#define X_ALT LALT_T(KC_X)
#define LBRC_ALT LALT_T(KC_LBRC)
#define C_SYM LT(_SYM_NUM, KC_C)
#define V_CTL LCTL_T(KC_V)
#define RBRC_CTL LCTL_T(KC_RBRC)
#define N_CTL RCTL_T(KC_N)
#define M_SYM LT(_SYM_NUM, KC_M)
#define SCLN_SYM LT(_SYM_NUM, KC_SCLN)
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
#define PGUP_SYM LT(_SYM_NUM, KC_PGUP)
#define ONE_CTL RCTL_T(KC_1)
#define TWO_SYM LT(_SYM_NUM, KC_2)
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
#define TAB_FUNM LT(_FUNC_MAC, KC_TAB)
#define SPC_SYM LT(_SYM_NUM, KC_SPC)
#define B_FUNM LT(_FUNC_MAC, KC_B)
#define P_AGR RALT_T(KC_P)
#define L_ALT LALT_T(KC_L)
#define J_CTL RCTL_T(KC_J)
#define K_GUI RGUI_T(KC_K)
#define F_CTL RCTL_T(KC_F)
#define D_GUI RGUI_T(KC_D)
#define S_ALT LALT_T(KC_S)
#define A_AGR RALT_T(KC_A)
#define B_SHFT LSFT_T(KC_B)
#define F11_AGR RALT_T(KC_F11)
#define F6_ALT LALT_T(KC_F6)
#define F5_GUI RGUI_T(KC_F5)
#define F4_CTL RCTL_T(KC_F4)


enum {
  // Save buffer in editor
  SAVE = SAFE_RANGE,
  // Quit editor
  QUIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA_MAC] = LAYOUT(
              KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_BSPC,
    KC_ESC,   A_AGR,    S_ALT,    D_GUI,    F_CTL,    KC_G,      KC_H,     J_CTL,    K_GUI,    L_ALT,    P_AGR,    KC_ENT,
              KC_Z,     KC_X,     KC_C,     KC_V,                          KC_N,     KC_M,     KC_COMM,  KC_DOT,
                        KC_MNXT,  OSM_LSFT, TT_NAVM,  B_FUNM,    TAB_FUNM, SPC_SYM,  OSM_RSFT, KC_MPLY
  ),
  [_NAVI_MAC] = LAYOUT(
              XXXXXXX,  KC_BTN3,  KC_BTN2,  KC_BTN1,  KC_WH_D,   CTLA,     KC_PGDN,  KC_PGUP,  CTLE,     _______,
    GUIY,     KC_LSFT,  KC_LALT,  KC_LGUI,  KC_LCTL,  KC_WH_U,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  SAVE,     _______,
              GUIZ,     GUIX,     GUIC,     GUIV,                          AGRQUOT,  AGRO,     AGRA,     QUIT,
                        KC_MPRV,  _______,  OSL_ALPM, LCK_ALPM,  _______,  _______,  _______,  KC_MNXT
  ),
  [_ALPHA_OL] = LAYOUT(
              KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     _______,
    _______,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_P,     _______,
              KC_Z,     KC_X,     KC_C,     KC_V,                          KC_N,     KC_M,     KC_COMM,  KC_DOT,
                        _______,  _______,  _______,  KC_B,      KC_TAB,   KC_SPC,   _______,  _______
  ),
  [_FUNC_MAC] = LAYOUT(
              KC_F12,   KC_F9,    KC_F8,    KC_F7,    KC_SCLN,   KC_SLSH,  KC_7,     KC_8,     KC_9,     _______,
    _______,  F11_AGR,  F6_ALT,   F5_GUI,   F4_CTL,   KC_COLN,   KC_QUES,  FOUR_CTL, FIVE_GUI, SIX_ALT,  KC_MINS,  KC_EQL,
              KC_F10,   KC_F3,    KC_F2,    KC_F1,                         KC_1,     KC_2,     KC_3,     KC_PLUS,
                        QK_BOOT,  XXXXXXX,  XXXXXXX,  _______,   KC_COMM,  KC_DOT,   KC_0,     KC_PWR
  ),
  [_SYM_NUM] = LAYOUT(
              KC_LCTL,  KC_GRV,   KC_LCBR,  KC_RCBR,  KC_SCLN,   KC_PIPE,  KC_AMPR,  KC_ASTR,  KC_UNDS,  _______,
    KC_LT,    KC_GT,    KC_DQUO,  KC_LPRN,  KC_RPRN,  KC_COLN,   KC_QUES,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_MINS,  KC_EQL,
              KC_LGUI,  KC_QUOT,  KC_LBRC,  KC_RBRC,                       KC_EXLM,  KC_AT,    KC_HASH,  KC_PLUS,
                        KC_VOLD,  KC_BSLS,  KC_SLSH,  KC_TILD,   XXXXXXX,  _______,  KC_LALT,  KC_VOLU
  )
};


const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 6, HSV_OFF});
const rgblight_segment_t PROGMEM navi_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 6, HSV_BLUE});
const rgblight_segment_t PROGMEM symb_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 6, HSV_OFF});
const rgblight_segment_t PROGMEM func_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 6, HSV_OFF});
const rgblight_segment_t PROGMEM caps_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 6, HSV_CYAN});
const rgblight_segment_t * const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  base_layer, navi_layer, symb_layer, func_layer, caps_layer
);

void keyboard_post_init_user(void) {
  rgblight_layers = rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _ALPHA_MAC));
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(1, layer_state_cmp(state, _NAVI_MAC));
  rgblight_set_layer_state(2, layer_state_cmp(state, _SYM_NUM));
  rgblight_set_layer_state(3, layer_state_cmp(state, _FUNC_MAC));
  return state;
}

void caps_word_set_user(bool active) {
  rgblight_set_layer_state(4, active);
}

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
    case QUIT:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC) ":q" SS_TAP(X_ENT));
        return false;
      }
    case KC_BSPC:
      {
      // Keep track of whether the delete key status is registered.
      static bool delkey_registered;
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
          // Make sure that Shift is not applied to the KC_DEL keycode.
          del_mods(MOD_MASK_SHIFT);
          register_code(KC_DEL);
          // Update the boolean variable to reflect the status of KC_DEL
          delkey_registered = true;
          // Reapplying modifier state so that the held shift key(s)
          // still work even after having tapped the Backspace/Delete key.
          set_mods(mod_state);
          return false;
        }
      } else { // on release of KC_BSPC
        // In case KC_DEL is still being sent even after the release of KC_BSPC
        if (delkey_registered) {
          unregister_code(KC_DEL);
          delkey_registered = false;
          return false;
        }
      }
    }
  }
  return true;
}
