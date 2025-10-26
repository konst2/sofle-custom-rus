
// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum custom_keycodes {
    KC_PRVWD = SAFE_RANGE, // Previous Word 
    KC_NXTWD,              // Next Word
    KC_LSTRT,              // Line Start
    KC_LEND,               // Line End
    NEW_SAFE_RANGE,
};

#define CUSTOM_SAFE_RANGE NEW_SAFE_RANGE
#include "lang_shift/include.h"


enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _LAYER_EN,
    _LAYER_EN_SHIFT,
    _LAYER_RU,
    _LAYER_RU_SHIFT,
    _LOWER,
    _RAISE,
    _ADJUST,
};


//#define KC_QWERTY PDF(_QWERTY)
//#define KC_COLEMAK PDF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * EN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   q  |   w  |   e  |   r  |   t  |                    |   y  |   u  |   i  |   o  |   p  |   {  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   a  |   s  |   d  |   f  |   g  |-------.    ,-------|   h  |   j  |   k  |   l  |   ;  |   '  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|   z  |   x  |   c  |   v  |   b  |-------|    |-------|   n  |   m  |   ,  |   .  |   /  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Space  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_LAYER_EN] = LAYOUT(
  KC_ESC,   AG_1,   AG_2,    AG_3,    AG_4,    AG_5,                     AG_6,    AG_7,    AG_8,    AG_9,    AG_0,  KC_BSPC,
  KC_TAB,   EN_Q,   EN_W,    EN_E,    EN_R,    EN_T,                     EN_Y,    EN_U,    EN_I,    EN_O,    EN_P,  EN_LBRC,
  EN_GRV,   EN_A,   EN_S,    EN_D,    EN_F,    EN_G,                     EN_H,    EN_J,    EN_K,    EN_L, EN_SCLN,  EN_QUOT,
  SFT_N,    EN_Z,   EN_X,    EN_C,    EN_V,    EN_B, KC_MUTE,    XXXXXXX,EN_N,    EN_M, EN_COMM,  EN_DOT, AG_SLSH,  SFT_N,

                       CTRL_0, ALT_0, WIN_0, TL_LOWR, KC_SPC,    LA_CHNG, TL_UPPR, KC_ENT, WIN_0, CTRL_0
),
/*
 * EN_SHIFT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   !  |   @  |   #  |   $  |   %  |                    |   ˆ  |   &  |   *  |   (  |   )  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   [  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ~  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   :  |   "  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   <  |   >  |   ?  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Space  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ | RAISE|      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_LAYER_EN_SHIFT] = LAYOUT(
  KC_ESC,AG_EXCL,  EN_AT, EN_HASH,  EN_DLR, AG_PERC,                  EN_CIRC, EN_AMPR, AG_ASTR, AG_LPRN, AG_RPRN,  KC_BSPC,
  KC_TAB, EN_S_Q, EN_S_W,  EN_S_E,  EN_S_R,  EN_S_T,                   EN_S_Y,  EN_S_U,  EN_S_I,  EN_S_O,  EN_S_P,  EN_LBRC,
  EN_TILD,EN_S_A, EN_S_S,  EN_S_D,  EN_S_F,  EN_S_G,                   EN_S_H,  EN_S_J,  EN_S_K,  EN_S_L, EN_COLN,  EN_DQUO,
  SFT_N,  EN_S_Z, EN_S_X,  EN_S_C,  EN_S_V,  EN_S_B, KC_MUTE,  XXXXXXX,EN_S_N,  EN_S_M,   EN_LT,   EN_GT, AG_QUES,  SFT_N,

                    _______, _______, _______, _______, KC_SPC,     _______, _______, _______, _______, _______
),
/*
 * RU
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   й  |   ц  |   у  |   к  |   е  |                    |   н  |   г  |   ш  |   щ  |   з  |   х  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ё  |   ф  |   ы  |   в  |   а  |   п  |-------.    ,-------|   р  |   о  |   л  |   д  |   ж  |   э  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|   я  |   ч  |   с  |   м  |   и  |-------|    |-------|   т  |   ь  |   б  |   ю  |   /  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Space  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ | RAISE|      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_LAYER_RU] = LAYOUT(
  KC_ESC,   AG_1,   AG_2,    AG_3,    AG_4,    AG_5,                     AG_6,    AG_7,    AG_8,    AG_9,    AG_0,  KC_BSPC,
  KC_TAB,   RU_J,  RU_TS,    RU_U,    RU_K,   RU_JE,                     RU_N,    RU_G,   RU_SH,   RU_SC,    RU_Z,  RU_H,
   RU_JO,   RU_F,   RU_Y,    RU_V,    RU_A,    RU_P,                     RU_R,    RU_O,    RU_L,    RU_D,   RU_ZH,  RU_E,
   SFT_N,  RU_JA,  RU_CH,    RU_S,    RU_M,    RU_I, KC_MUTE,    XXXXXXX,RU_T,   RU_SF,    RU_B,   RU_JU, AG_SLSH,  SFT_N,

                    _______, _______, _______, _______, KC_SPC,     _______, _______, _______, _______, _______
),
/*
 * RU_SHIFT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   !  |   @  |   #  |   $  |   %  |                    |   ˆ  |   &  |   *  |   (  |   )  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Й  |   Ц  |   У  |   К  |   Е  |                    |   Н  |   Г  |   Ш  |   Щ  |   З  |   Х  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   Ë  |   Ф  |   Ы  |   В  |   А  |   П  |-------.    ,-------|   Р  |   О  |   Л  |   Д  |   Ж  |    Э |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|   Я  |   Ч  |   С  |   М  |   И  |-------|    |-------|   Т  |   Ь  |   Б  |   Ю  |   ?  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Space  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ | RAISE|      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_LAYER_RU_SHIFT] = LAYOUT(
  KC_ESC, AG_EXCL,   EN_AT, EN_HASH,  EN_DLR, AG_PERC,                  EN_CIRC, EN_AMPR, AG_ASTR, AG_LPRN, AG_RPRN, KC_BSPC,
  KC_TAB,  RU_S_J, RU_S_TS,  RU_S_U,  RU_S_K, RU_S_JE,                   RU_S_N,  RU_S_G, RU_S_SH, RU_S_SC,  RU_S_Z,  RU_S_H,
 RU_S_JO,  RU_S_F,  RU_S_Y,  RU_S_V,  RU_S_A,  RU_S_P,                   RU_S_R,  RU_S_O,  RU_S_L,  RU_S_D, RU_S_ZH,  RU_S_E,
   SFT_N, RU_S_JA, RU_S_CH,  RU_S_S,  RU_S_M,  RU_S_I, KC_MUTE,  XXXXXXX,RU_S_T, RU_S_SF,  RU_S_B, RU_S_JU, AG_QUES,  SFT_N,

                    _______, _______, _______, _______, KC_SPC,     _______, _______, _______, _______, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ,  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | / Bspc  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,

                       _______, _______, _______, _______, KC_BSPC,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | Home |  Up  | End  | PgUp |  (   |                    |  )   |      |      |      |      |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ru/En| Right| Down | Left | PgDn |  {   |-------.    ,-------|  }   |      |      |      |      |   .  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|      |      |      |  <   |  [   |-------|    |-------|  ]   |  >   |      |      |      |   ,  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | / Bspc  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
 *            |      |      |      |      |/       /         \ SYNC \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,    KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,
  _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP, AG_LPRN,                       AG_RPRN,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   KC_F12,
  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, EN_LCBR,                       EN_RCBR,  XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX,  AG_DOT,
  _______, XXXXXXX, XXXXXXX, XXXXXXX,   EN_LT, EN_LBRC,  _______,    _______, EN_RBRC,    EN_GT,  XXXXXXX, KC_LEND,   XXXXXXX, AG_COMM,

                         _______, _______, _______, _______, KC_BSPC,       LA_SYNC, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | / Bspc  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
  AG_8,     XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT , XXXXXXX,  XXXXXXX ,  XXXXXXX , CG_TOGG, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,  CG_TOGG ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,

                    _______, _______, _______, _______, KC_BSPC,     _______, _______, _______, _______, _______
   )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!lang_shift_process_record(keycode, record))
        return false;

    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}

// lang_shift
void user_timer(void) {
  lang_shift_user_timer();
}

void matrix_scan_user(void) {
  user_timer();
}
