#include QMK_KEYBOARD_H

// *** Comments ***
// 2020-04-19
//  - Layer changes
//    - Added COLEMAK layer
//    - LOWER -> NUMNAV - numpad & navigation
//    - RAISE -> SPCLS - FN keys & special chrs
//    - ADJUST -> SYSTM - computer controls (vol, prv, etc) & keyboard config
//    - Added MSE layer for mouse controls
//  - Keycode changes
//    - Holding enter registers shift
//    - Shift + Space = Underscore
//    - Shift + Backspace = Delete
//  - Other changes
//    - enumerated layers instead of defines (easier maintenance)

// *** To Do ***
// Change colors on layer changes - especially COlEMAK
// Set up specials layer better
// Turn off number row?

enum custom_layers {
  _QWERTY,
  _COLEMAK,
  _NUMNAV,
  _SPCLS,
  _SYSTM,
  _MSE,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  NUMNAV,
  SPCLS,
  SYSTM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,           KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, NUMNAV,  MT(MOD_LSFT,KC_ENT),       KC_SPC,  SPCLS,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,           KC_SPC,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, NUMNAV,  MT(MOD_LSFT,KC_ENT),       KC_SPC,  SPCLS,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMNAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, KC_P0,   _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_BSPC,                            KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_P4,   KC_P5,   KC_P6,   _______,                            KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,          _______, _______, TG(_MSE),_______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, KC_P0,   _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_BSPC,                            KC_PGUP, KC_HOME, KC_MS_U, KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_BTN1,                            KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_BTN2, _______,          _______, _______, _______,_______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_SPCLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRAVE, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                           KC_CIRC, KC_AMPR, _______, _______, KC_EQL,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS,                            KC_PLUS,  KC_RPRN, KC_RBRC, KC_RCBR, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, KC_SLSH, _______,          KC_UNDS, KC_ASTR, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_UNDS, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYSTM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     DF(_QWERTY),DF(_COLEMAK), _______, _______, _______, _______,                   DM_REC1, DM_REC2, DM_RSTP, DM_PLY1, DM_PLY2, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_MPLY, KC_MUTE, _______, _______,                            RGB_M_P, RGB_M_B, RGB_M_K, RGB_M_X, RGB_M_G, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPRV, KC_MNXT, KC_VOLU, KC_BRIU, _______,                            RGB_TOG, RGB_VAI, RGB_HUI, RGB_SAI, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_VOLD, KC_BRID, _______, _______,          _______, _______, RGB_VAD, RGB_HUD, RGB_SAD, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, RESET
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case NUMNAV:
      if (record->event.pressed) {
        layer_on(_NUMNAV);
        update_tri_layer(_NUMNAV, _SPCLS, _SYSTM);
      } else {
        layer_off(_NUMNAV);
        update_tri_layer(_NUMNAV, _SPCLS, _SYSTM);
      }
      return false;
      break;
    case SPCLS:
      if (record->event.pressed) {
        layer_on(_SPCLS);
        update_tri_layer(_NUMNAV, _SPCLS, _SYSTM);
      } else {
        layer_off(_SPCLS);
        update_tri_layer(_NUMNAV, _SPCLS, _SYSTM);
      }
      return false;
      break;
    case SYSTM:
      if (record->event.pressed) {
        layer_on(_SYSTM);
      } else {
        layer_off(_SYSTM);
      }
      return false;
      break;

      // 2020-04-19 - adding code to convert Shift + Space to Underscore
      case KC_SPC:
        if (record->event.pressed) {
          if (get_mods() & MOD_MASK_SHIFT) {
            register_code(KC_MINS);
            return false;
          }
        } else {
          if (get_mods() & MOD_MASK_SHIFT) {
            unregister_code(KC_MINS);
            return false;
          }
        }
        return true;
        break;

    // 2020-04-19 - adding code to convert Shift + Backspace to Delete
    case KC_BSPC:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          register_code(KC_DEL);
          return false;
        }
      } else {
        if (get_mods() & MOD_MASK_SHIFT) {
          unregister_code(KC_DEL);
          return false;
        }
      }
      return true;
      break;

  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
