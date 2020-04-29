#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _KEYPAD
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  KEYPAD
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define WRD_BCK LALT(KC_LEFT)
#define WRD_FWD LALT(KC_RGHT)
#define LN_BACK LGUI(KC_LEFT)
#define LN_FWD  LGUI(KC_RGHT)
#define TB_LEFT LGUI(LSFT(KC_LBRC))
#define TB_RGHT LGUI(LSFT(KC_RBRC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SLSH, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_LBRC, KC_RBRC, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, KC_GRV,  \
  KC_F17,  KC_LCTL, KC_LALT, KC_LGUI, KC_ENT,  KC_SPC,     RAISE,   LOWER,   _______, _______, KEYPAD,  KC_F18   \
),

[_LOWER] = LAYOUT_ortho_4x12( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_LPRN, KC_RPRN, \
  _______, KC_PLUS, KC_EQL,  KC_MINS, KC_SCLN, KC_COLN,    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______  \
),

[_RAISE] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______,    XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, _______, _______, _______, _______, _______,    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, TB_LEFT, TB_RGHT, \
  _______, _______, _______, _______, _______, _______,    XXXXXXX, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, _______, _______, _______, _______, _______,    _______, _______, XXXXXXX, XXXXXXX, _______, _______  \
),

[_ADJUST] = LAYOUT_ortho_4x12( \
  _______, KC_F1,   KC_F2,   KC_F3,    KC_F4,       KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
  _______, RESET,   XXXXXXX, KC_MRWD,  KC_MPLY,     KC_MFFD,      BL_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   \
  _______, BL_TOGG, XXXXXXX, KC__MUTE, KC__VOLDOWN, KC__VOLUP,    BL_DEC,  BL_INC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, _______, _______, _______,  _______,     _______,      _______, _______, XXXXXXX, XXXXXXX, _______, _______  \
),

[_KEYPAD] = LAYOUT_ortho_4x12( \
  _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_PDOT,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, _______, _______, _______, _______, _______,    _______, _______, XXXXXXX, XXXXXXX, _______, _______  \
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
    case KEYPAD:
      if (record->event.pressed)
        layer_on(_KEYPAD);
      else
        layer_off(_KEYPAD);
      return false;
      break;
  }
  return true;
}
