#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define WRD_BCK LALT(KC_LEFT)
#define WRD_FWD LALT(KC_RGHT)
#define LN_BACK LGUI(KC_LEFT)
#define LN_FWD  LGUI(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SLSH, \
  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_LBRC, KC_RBRC, \
  KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_NUBS, KC_NUHS, \
  KC_F17,  KC_LALT, KC_LCTL, KC_ENT,  KC_LGUI, KC_SPC,     RAISE,   LOWER,   KC_MINS, KC_QUOT, KC_DQUO, KC_F18   \
),

[_LOWER] = LAYOUT_ortho_4x12( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TILD, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PLUS, KC_EQL,  KC_SCLN, KC_COLN, KC_GRV,  XXXXXXX, \
  _______, _______, _______, _______, _______, _______,    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______  \
),

[_RAISE] = LAYOUT_ortho_4x12( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,    LN_BACK, KC_PGUP, KC_UP,   KC_PGDN, LN_FWD,  XXXXXXX, \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,      WRD_BCK, KC_LEFT, KC_DOWN, KC_RGHT, WRD_FWD, XXXXXXX, \
  _______, XXXXXXX, KC_F10,  KC_F11,  KC_F12,  XXXXXXX,    XXXXXXX, KC_BSPC, XXXXXXX, KC_DEL,  XXXXXXX, XXXXXXX, \
  _______, _______, _______, _______, _______, _______,    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______  \
),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
  }
  return true;
}
