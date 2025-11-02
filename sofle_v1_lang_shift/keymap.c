
// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum custom_keycodes {
    KC_PRVWD = SAFE_RANGE, // Previous Word 
    KC_NXTWD,              // Next Word
    KC_LSTRT,              // Line Start
    KC_LEND,               // Line End
    KC_DWDL,               // Delete Word Left (backward)
    KC_DWDR,               // Delete Word Right (forward)
    KC_CH_OS,              // Change OS
    WIN_0_OS,              // клавиша CMD под Mac и CTRL под Windows/Linux
    CTRL_0_OS,             // клавиша CMD под Windows/Linux и CTRL под Mac
    NEW_SAFE_RANGE,
};

#define CUSTOM_SAFE_RANGE NEW_SAFE_RANGE
#include "lib/lang_shift/include.h"


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

// параметр в eeprom для операционной системы
#define OS_MACOS 0
#define OS_WINDOWS 1
#define OS_LINUX 2

typedef union {
    uint32_t raw;
    struct {
        uint8_t os_type : 2;
    };
} user_config_t;
user_config_t user_config;
__attribute__((weak)) void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}
void switch_to_next_os(void) {
    user_config.os_type = (user_config.os_type + 1) % 3;
    eeconfig_update_user(user_config.raw);
}
#define OS_TYPE user_config.os_type
#define IS_MACOS (OS_TYPE == OS_MACOS)
#define IS_WINDOWS (OS_TYPE == OS_WINDOWS)
#define IS_LINUX (OS_TYPE == OS_LINUX)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * EN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   q  |   w  |   e  |   r  |   t  |                    |   y  |   u  |   i  |   o  |   p  |   [  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   a  |   s  |   d  |   f  |   g  |-------.    ,-------|   h  |   j  |   k  |   l  |   ;  |   '  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|   z  |   x  |   c  |   v  |   b  |-------|    |-------|   n  |   m  |   ,  |   .  |   /  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LOWER| CTR  |  Alt |. GUI | /Space  /       \RU/EN \  | RAISE|Enter |  GUI |  CTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_LAYER_EN] = LAYOUT(
  KC_ESC,   AG_1,   AG_2,    AG_3,    AG_4,    AG_5,                      AG_6,    AG_7,    AG_8,    AG_9,    AG_0,  KC_BSPC,
  KC_TAB,   EN_Q,   EN_W,    EN_E,    EN_R,    EN_T,                      EN_Y,    EN_U,    EN_I,    EN_O,    EN_P,  EN_LBRC,
  EN_GRV,   EN_A,   EN_S,    EN_D,    EN_F,    EN_G,                      EN_H,    EN_J,    EN_K,    EN_L, EN_SCLN,  EN_QUOT,
  SFT_STK,  EN_Z,   EN_X,    EN_C,    EN_V,    EN_B, KC_MUTE,  TG(_RAISE),EN_N,    EN_M, EN_COMM,  EN_DOT, AG_SLSH,  SFT_STK,

                 TL_LOWR, CTRL_0_OS, ALT_0, WIN_0_OS, KC_SPC,    LA_CHNG, TL_UPPR, KC_ENT, WIN_0_OS, CTRL_0_OS
),
/*
 * EN_SHIFT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   !  |   @  |   #  |   $  |   %  |                    |   ˆ  |   &  |   *  |   (  |   )  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   {  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ~  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   :  |   "  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   <  |   >  |   ?  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *           | LOWER| CTR  |  Alt |  GUI |  /Space  /       \RU/EN \  | RAISE|Enter |  GUI |  CTR |
 *           |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_LAYER_EN_SHIFT] = LAYOUT(
  KC_ESC,AG_EXCL,  EN_AT, EN_HASH,  EN_DLR, AG_PERC,                     EN_CIRC, EN_AMPR, AG_ASTR, AG_LPRN, AG_RPRN,  KC_BSPC,
  KC_TAB, EN_S_Q, EN_S_W,  EN_S_E,  EN_S_R,  EN_S_T,                      EN_S_Y,  EN_S_U,  EN_S_I,  EN_S_O,  EN_S_P,  EN_LCBR,
 EN_TILD, EN_S_A, EN_S_S,  EN_S_D,  EN_S_F,  EN_S_G,                      EN_S_H,  EN_S_J,  EN_S_K,  EN_S_L, EN_COLN,  EN_DQUO,
 SFT_STK, EN_S_Z, EN_S_X,  EN_S_C,  EN_S_V,  EN_S_B, KC_MUTE,  TG(_RAISE),EN_S_N,  EN_S_M,   EN_LT,   EN_GT, AG_QUES,  SFT_STK,

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
 *            | LOWER| CTR  |  Alt |  GUI | /Space  /       \RU/EN \  | RAISE|Enter |  GUI |  CTR |
 *            |      |      |      |      |/       /         \      \ | RAISE|      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_LAYER_RU] = LAYOUT(
  KC_ESC,   AG_1,   AG_2,    AG_3,    AG_4,    AG_5,                        AG_6,    AG_7,    AG_8,    AG_9,    AG_0,  KC_BSPC,
  KC_TAB,   RU_J,  RU_TS,    RU_U,    RU_K,   RU_JE,                        RU_N,    RU_G,   RU_SH,   RU_SC,    RU_Z,  RU_H,
   RU_JO,   RU_F,   RU_Y,    RU_V,    RU_A,    RU_P,                        RU_R,    RU_O,    RU_L,    RU_D,   RU_ZH,  RU_E,
 SFT_STK,  RU_JA,  RU_CH,    RU_S,    RU_M,    RU_I, KC_MUTE,    TG(_RAISE),RU_T,   RU_SF,    RU_B,   RU_JU, AG_SLSH,  SFT_STK,

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
 *            | LOWER| CTR  |  Alt |  GUI | /Space  /       \RU/EN \  | RAISE|Enter |  GUI |  CTR |
 *            |      |      |      |      |/       /         \      \ | RAISE|      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_LAYER_RU_SHIFT] = LAYOUT(
  KC_ESC, AG_EXCL,   EN_AT, EN_HASH,  EN_DLR, AG_PERC,                     EN_CIRC, EN_AMPR, AG_ASTR, AG_LPRN, AG_RPRN, KC_BSPC,
  KC_TAB,  RU_S_J, RU_S_TS,  RU_S_U,  RU_S_K, RU_S_JE,                      RU_S_N,  RU_S_G, RU_S_SH, RU_S_SC,  RU_S_Z,  RU_S_H,
 RU_S_JO,  RU_S_F,  RU_S_Y,  RU_S_V,  RU_S_A,  RU_S_P,                      RU_S_R,  RU_S_O,  RU_S_L,  RU_S_D, RU_S_ZH,  RU_S_E,
 SFT_STK, RU_S_JA, RU_S_CH,  RU_S_S,  RU_S_M,  RU_S_I, KC_MUTE,  TG(_RAISE),RU_S_T, RU_S_SF,  RU_S_B, RU_S_JU, AG_QUES,  SFT_STK,

                    _______, _______, _______, _______, KC_SPC,     _______, _______, _______, _______, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   !  |   @  |   #  |   $  |   %  |                    |   ˆ  |   &  |   *  |   (  |   )  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   ?  |      |   №  |   '  |   (  |                    |   )  |   .  |   +  |   -  |   |  |   "  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   ~  |      |   :  |   "  |   {  |-------.    ,-------|   }  |   ,  |   =  |   _  |   \  |   '  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|      |      |   ;  |   <  |   [  |-------|    |-------|   ]  |   >  |   ,  |   .  |   /  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LOWER| CTR  |  Alt |  GUI | / Bspc  /       \RU/EN \  | RAISE|Enter |  GUI |  CTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______, AG_EXCL,   EN_AT, EN_HASH,  EN_DLR, AG_PERC,                    EN_CIRC, EN_AMPR, AG_ASTR, AG_LPRN, AG_RPRN, KC_BSPC,
  _______, AG_QUES, XXXXXXX, RU_NUME, EN_QUOT, AG_LPRN,                    AG_RPRN,  AG_DOT, AG_PLUS, AG_MINS, EN_PIPE, AG_DQUO,
   EN_GRV, EN_TILD, XXXXXXX, AG_COLN, AG_DQUO, EN_LCBR,                    EN_RCBR, AG_COMM,  AG_EQL, AG_UNDS, AG_BSLS, EN_QUOT,
  _______, XXXXXXX, XXXXXXX, AG_SCLN,   EN_LT, EN_LBRC, _______,   XXXXXXX,EN_RBRC,   EN_GT, AG_COMM,  AG_DOT, EN_SLSH, _______,

                       _______, _______, _______, _______, KC_BSPC,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | Home |  Up  | End  | PgUp |<-WDel|                    |WDel->| Home |  Up  | End  | PgUp |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  | Right| Down | Left | PgDn | <-Wrd|-------.    ,-------| Wrd->| Right| Down | Left | PgDn |   '  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  Ins |      |  Del |      |<-Line|-------|    |-------|Line->|  Ins |      |  Del |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LOWER| CTR  |  Alt |  GUI | / Bspc  /       \RU/EN \  | RAISE|Enter |  GUI |  CTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F11,
  _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP, KC_DWDL,                        KC_DWDR,  KC_HOME,   KC_UP,   KC_END,  KC_PGUP,   KC_F12,
   EN_GRV, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,KC_PRVWD,                       KC_NXTWD,  KC_LEFT, KC_DOWN,  KC_RGHT,  KC_PGDN,  EN_QUOT,
  _______,  KC_INS, XXXXXXX,  KC_DEL, XXXXXXX,KC_LSTRT,  _______,    _______,  KC_LEND,   KC_INS, XXXXXXX,   KC_DEL,  XXXXXXX,  _______,

                     _______, _______, _______, _______, KC_BSPC,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |On/Off| Next | Prew | Hue+ | Hue- |                    |  Sat+| Sat- | Val+ | Val- |Speed+|Speed-| RGB row
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |      |MACWIN|      |      |      |-------.    ,-------|      |  Ъ   |      |      |      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |-------|    |-------|      |  ъ   |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LOWER| CTR  |  Alt |  GUI | / Bspc  /       \RU/EN \  | RAISE|Enter |  GUI |  CTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
  _______,  RM_TOGG,  RM_NEXT,  RM_PREV , RM_HUEU, RM_HUED,                     RM_SATU, RM_SATD, RM_VALU, RM_VALD, RM_SPDU, RM_SPDD,
  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   EN_GRV,  XXXXXXX, KC_CH_OS,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, RU_S_HD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,   RU_HD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                    _______, _______, _______, _______, KC_BSPC,     _______, _______, _______, _______, _______
   )
};

/* COMBOS HORISONTAL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |     [!]    [@]    [#]    [$]    [%]     |                    |     [ˆ]    [&]    [*]    [(]    [)]     |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |     [?]    [ ]    [№]    [']    [(]     |                    |     [)]    [.]    [+]    [-]    [|]     |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |     [˜]    [ ]    [:]    ["]    [{]     |-------.    ,-------|     [}]    [,]    [=]    [_]    [\]     |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |     [ ]    [ ]    [;]    [<]    [[]     |-------|    |-------|     []]    [>]    [,]    [.]    [/]     |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |.     | /       /       \.     \  |      |.     |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
const uint16_t PROGMEM combos_horizontal[] = {
  AG_EXCL,    EN_AT,  EN_HASH,   EN_DLR, AG_PERC,                      EN_CIRC, EN_AMPR, AG_ASTR, AG_LPRN, AG_RPRN,
  AG_QUES,  XXXXXXX,  RU_NUME,  EN_QUOT, AG_LPRN,                      AG_RPRN,  AG_DOT, AG_PLUS, AG_MINS, EN_PIPE,
  EN_TILD,  XXXXXXX,  AG_COLN,  AG_DQUO, EN_LCBR,                      EN_RCBR, AG_COMM,  AG_EQL, AG_UNDS, AG_BSLS,
  XXXXXXX,  XXXXXXX,  AG_SCLN,    EN_LT, EN_LBRC,                      EN_RBRC,   EN_GT, AG_COMM,  AG_DOT, EN_SLSH,
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // меняем CMD и CTRL местами под Win и Linux
    uint16_t langshft_keycode = keycode;
    switch (keycode) {
        case WIN_0_OS:
            if (!IS_MACOS) {
                langshft_keycode = CTRL_0;
            } else {
                langshft_keycode = WIN_0;
            }
            break;
        case CTRL_0_OS:
            if (IS_MACOS) {
                langshft_keycode = CTRL_0;
            } else {
                langshft_keycode = WIN_0;
            }
            break;
        }

    if (!lang_shift_process_record(langshft_keycode, record))
        return false;

    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (IS_MACOS) {
                    register_code(KC_RIGHT_ALT);
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_RIGHT_CTRL);
                    register_code(KC_LEFT);
                }
            } else {
                if (IS_MACOS) {
                    unregister_code(KC_LEFT);
                    unregister_code(KC_RIGHT_ALT);
                } else {
                    unregister_code(KC_LEFT);
                    unregister_code(KC_RIGHT_CTRL);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (IS_MACOS) {
                    register_code(KC_RIGHT_ALT);
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_RIGHT_CTRL);
                    register_code(KC_RIGHT);
                }
            } else {
                if (IS_MACOS) {
                    unregister_code(KC_RIGHT);
                    unregister_code(KC_RIGHT_ALT);
                } else {
                    unregister_code(KC_RIGHT);
                    unregister_code(KC_RIGHT_CTRL);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (IS_MACOS) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_code(KC_RIGHT_GUI);
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (IS_MACOS) {
                    unregister_code(KC_LEFT);
                    unregister_code(KC_RIGHT_GUI);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (IS_MACOS) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_code(KC_RIGHT_GUI);
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (IS_MACOS) {
                    unregister_code(KC_RIGHT);
                    unregister_code(KC_RIGHT_GUI);
                    
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DWDL:
            if (record->event.pressed) {
                // Delete word backward = Alt + Backspace on Mac
                register_code(KC_RIGHT_ALT);
                register_code(KC_BSPC);
            } else {
                unregister_code(KC_BSPC);
                unregister_code(KC_RIGHT_ALT);
            }
            break;
        case KC_DWDR:
            if (record->event.pressed) {
                // Delete word forward = Ctrl + Delete on Mac
                register_code(KC_RIGHT_ALT);
                register_code(KC_DEL);
            } else {
                unregister_code(KC_DEL);
                unregister_code(KC_RIGHT_ALT);
            }
            break;
        // переключение операционной системы
        case KC_CH_OS:
            if (record->event.pressed) {
                switch_to_next_os();
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

#include "lib/encoders.c"
#include "lib/rgb_matrix.c"
#include "lib/oled.c"
#include "lib/combos.c"
