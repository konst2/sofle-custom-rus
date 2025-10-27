
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
 * | ESC  |   !  |   @  |   #  |   $  |   %  |                    |   ˆ  |   &  |   *  |   (  |   )  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   ?  |      |   №  |      |   (  |                    |   )  |   "  |   +  |   -  |   |  |   "  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   ~  |      |   :  |   '  |   {  |-------.    ,-------|   }  |   '  |   =  |   _  |   \  |   '  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|      |      |   ;  |   <  |   [  |-------|    |-------|   ]  |   >  |   ,  |   .  |   /  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | / Bspc  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______, AG_EXCL,   EN_AT, EN_HASH,  EN_DLR, AG_PERC,                    EN_CIRC, EN_AMPR, AG_ASTR, AG_LPRN, AG_RPRN, KC_BSPC,
  _______, AG_QUES, XXXXXXX, RU_NUME, XXXXXXX, AG_LPRN,                    AG_RPRN, AG_DQUO, AG_PLUS, AG_MINS, EN_PIPE, AG_DQUO,
   EN_GRV, EN_TILD, XXXXXXX, AG_COLN, EN_QUOT, EN_LCBR,                    EN_RCBR, EN_QUOT,  AG_EQL, AG_UNDS, AG_BSLS, EN_QUOT,
  _______, XXXXXXX, XXXXXXX, AG_SCLN,   EN_LT, EN_LBRC, _______,   XXXXXXX,EN_RBRC,   EN_GT, AG_COMM,  AG_DOT, EN_SLSH, _______,

                       _______, _______, _______, _______, KC_BSPC,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | Home |  Up  | End  | PgUp |  (   |                    |  )   |      |      |      |      |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  | Right| Down | Left | PgDn |  {   |-------.    ,-------|  }   |      |      |      |      |   '  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  Ins |      |  Del |  <   |  [   |-------|    |-------|  ]   |  >   |      |      |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | / Bspc  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
 *            |      |      |      |      |/       /         \ SYNC \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F11,
  _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP, AG_LPRN,                       AG_RPRN,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   KC_F12,
   EN_GRV, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, EN_LCBR,                       EN_RCBR,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  EN_QUOT,
  _______,  KC_INS, XXXXXXX,  KC_DEL,   EN_LT, EN_LBRC,  _______,    _______, EN_RBRC,    EN_GT,  XXXXXXX, KC_LEND,  XXXXXXX,  _______,

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
 *            |      |      |      |      |/       /         \ SYNC \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
  AG_8,     RM_TOGG,  RM_NEXT ,  RM_PREV , RM_HUEU, RM_HUED,                     RM_SATU, RM_SATD, RM_VALU, RM_VALD, RM_SPDU, RM_SPDD,
  QK_BOOT , XXXXXXX,  XXXXXXX ,  XXXXXXX , CG_TOGG, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,  CG_TOGG ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,

                    _______, _______, _______, _______, KC_BSPC,     LA_SYNC, _______, _______, _______, _______
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

// Encoders
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
    return false;
}
#endif

// подсветка
#ifdef RGB_MATRIX_ENABLE
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
  //                                           ROWS
  // 12 13 22 23 32 33       33 32 23 22 13 12  0
  //    02    03    04       04    03    02
  // 11 14 21 24 31 34       34 31 24 21 14 11  1
  //                01       01
  // 10 15 20 25 30 35       35 30 25 20 15 10  2
  //
  // 09 16 19 26 29 36       36 29 26 19 16 09  3
  //
  //     08 17 18 27 28     28 27 18 17 08      4
  //    07    06    05       05    06    07

led_config_t g_led_config = {
    {
        {  11,  12,  21,  22,  31,  32 },
        {  10,  13,  20,  23,  30,  33 },
        {  9,   14,  19,  24,  29,  34},
        {  8,   15,  18,  25,  28,  35},
        {  7,   16,  17,  26,  27,  NO_LED },
        {  47,  48,  57,  58,  67,  68},
        {  46,  49,  56,  59,  66,  69},
        {  45,  50,  55,  60,  65,  70},
        {  44,  51,  54,  61,  64,  71},
        {  43,  52,  53,  62,  63,  NO_LED }
    },
    {
       // Left side underglow
        {96, 40}, {16, 20}, {48, 10}, {80, 18}, {88, 60}, {56, 57}, {24,60},
        // Left side Matrix
        {32, 57}, { 0, 48}, { 0, 36}, { 0, 24}, { 0, 12},
        {16, 12}, {16, 24}, {16, 36}, {16, 48}, {48, 55},
        {64, 57}, {32, 45}, {32, 33}, {32, 21}, {32,  9},
        {48,  7}, {48, 19}, {48, 31}, {48, 43}, {80, 59},
        {96, 64}, {64, 45}, {64, 33}, {64, 21}, {64,  9},
        {80, 10}, {80, 22}, {80, 34}, {80, 47},


        // Right side underglow
        {128, 40}, {208, 20}, {176, 10}, {144, 18}, {136, 60}, {168, 57}, {200,60},
        // Right side Matrix
        {192, 57}, {224, 48}, {224, 36}, {224, 24}, {224, 12},
        {208, 12}, {208, 24}, {208, 36}, {208, 48}, {176, 55},
        {160, 57}, {192, 45}, {192, 33}, {192, 21}, {192,  9},
        {176,  7}, {176, 19}, {176, 31}, {176, 43}, {144, 59},
        {128, 64}, {160, 45}, {160, 33}, {160, 21}, {160,  9},
        {144, 10}, {144, 22}, {144, 34}, {144, 47},
    },
    {
        LED_FLAG_NONE, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_NONE, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
    }
};
#endif


// OLED display
#ifdef OLED_ENABLE

// https://joric.github.io/qle/
// Logo rendered in 128x32px
static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,  0,  0,  0,192,224,240,240,240,240,240,240,240,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48,240,240,224,192,128,128,128,192,224,240,240, 48,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,224,240,  0,  0,240,252,254,255,255,255,  1,240,252,255,255,255,255,255,255,255,255,127, 31,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  4,  4,  6, 14, 14, 30, 63,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,254,252,252,248,253,255,255,255,255,255,255,255,249,248,252,252,254,254,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127, 63, 30, 14, 14,  6,  4,  4,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 63,255,255,255,254,240,255,255,255,255,255,255,248,255,255,255,255,255,255,255,255,255,193,128,128,128,192,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  1,  3,  7, 63, 63, 63, 63, 31, 31, 63, 63, 63,127,255,255,255,255,255,255,255,127, 63, 63, 63, 31, 31, 31, 31, 31, 63, 63, 31,  3,  1,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  3,  3,  1,  1,  3,  3,  7,  7,  7,  3,  3,  1,  3,  7,  7,  7,  7,  7,  7,  7,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3, 15,  7,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void print_status_narrow(void) {
    switch (get_highest_layer(layer_state)) {
        case _LAYER_EN:
        case _LAYER_EN_SHIFT:
            oled_write_ln_P(PSTR("  e"), false);
            break;
        case _LAYER_RU:
        case _LAYER_RU_SHIFT:
            oled_write_ln_P(PSTR("RURU"), false);
            break;
        case _RAISE:
        case _LOWER:
        case _ADJUST:
            oled_write_ln_P(PSTR("...."), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);


    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR(" @dr\nKard"), false);

    oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)

    // Print current layer
    oled_write_P(PSTR("\n\n\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _LAYER_EN:
        case _LAYER_EN_SHIFT:
        case _LAYER_RU:
        case _LAYER_RU_SHIFT:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}
#endif
