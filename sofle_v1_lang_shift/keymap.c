
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
 *            | LCTR | LAlt | LGUI |LOWER | /Space  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_LAYER_EN] = LAYOUT(
  KC_ESC,   AG_1,   AG_2,    AG_3,    AG_4,    AG_5,                     AG_6,    AG_7,    AG_8,    AG_9,    AG_0,  KC_BSPC,
  KC_TAB,   EN_Q,   EN_W,    EN_E,    EN_R,    EN_T,                     EN_Y,    EN_U,    EN_I,    EN_O,    EN_P,  EN_LBRC,
  EN_GRV,   EN_A,   EN_S,    EN_D,    EN_F,    EN_G,                     EN_H,    EN_J,    EN_K,    EN_L, EN_SCLN,  EN_QUOT,
  SFT_STK,  EN_Z,   EN_X,    EN_C,    EN_V,    EN_B, KC_MUTE,    XXXXXXX,EN_N,    EN_M, EN_COMM,  EN_DOT, AG_SLSH,  SFT_STK,

                       CTRL_0, ALT_0, WIN_0, TL_LOWR, KC_SPC,    LA_CHNG, TL_UPPR, KC_ENT, WIN_0, CTRL_0
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
 *            | LCTR | LAlt | LGUI |LOWER | /Space  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ | RAISE|      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_LAYER_EN_SHIFT] = LAYOUT(
  KC_ESC,AG_EXCL,  EN_AT, EN_HASH,  EN_DLR, AG_PERC,                  EN_CIRC, EN_AMPR, AG_ASTR, AG_LPRN, AG_RPRN,  KC_BSPC,
  KC_TAB, EN_S_Q, EN_S_W,  EN_S_E,  EN_S_R,  EN_S_T,                   EN_S_Y,  EN_S_U,  EN_S_I,  EN_S_O,  EN_S_P,  EN_LCBR,
 EN_TILD, EN_S_A, EN_S_S,  EN_S_D,  EN_S_F,  EN_S_G,                   EN_S_H,  EN_S_J,  EN_S_K,  EN_S_L, EN_COLN,  EN_DQUO,
 SFT_STK, EN_S_Z, EN_S_X,  EN_S_C,  EN_S_V,  EN_S_B, KC_MUTE,  XXXXXXX,EN_S_N,  EN_S_M,   EN_LT,   EN_GT, AG_QUES,  SFT_STK,

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
 SFT_STK,  RU_JA,  RU_CH,    RU_S,    RU_M,    RU_I, KC_MUTE,    XXXXXXX,RU_T,   RU_SF,    RU_B,   RU_JU, AG_SLSH,  SFT_STK,

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
 SFT_STK, RU_S_JA, RU_S_CH,  RU_S_S,  RU_S_M,  RU_S_I, KC_MUTE,  XXXXXXX,RU_S_T, RU_S_SF,  RU_S_B, RU_S_JU, AG_QUES,  SFT_STK,

                    _______, _______, _______, _______, KC_SPC,     _______, _______, _______, _______, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   !  |   @  |   #  |   $  |   %  |                    |   ˆ  |   &  |   *  |   (  |   )  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   ?  |      |   №  |   '  |   (  |                    |   )  |   '  |   +  |   -  |   |  |   "  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   ~  |      |   :  |   "  |   {  |-------.    ,-------|   }  |   "  |   =  |   _  |   \  |   '  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|      |      |   ;  |   <  |   [  |-------|    |-------|   ]  |   >  |   ,  |   .  |   /  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | / Bspc  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______, AG_EXCL,   EN_AT, EN_HASH,  EN_DLR, AG_PERC,                    EN_CIRC, EN_AMPR, AG_ASTR, AG_LPRN, AG_RPRN, KC_BSPC,
  _______, AG_QUES, XXXXXXX, RU_NUME, EN_QUOT, AG_LPRN,                    AG_RPRN, EN_QUOT, AG_PLUS, AG_MINS, EN_PIPE, AG_DQUO,
   EN_GRV, EN_TILD, XXXXXXX, AG_COLN, AG_DQUO, EN_LCBR,                    EN_RCBR, AG_DQUO,  AG_EQL, AG_UNDS, AG_BSLS, EN_QUOT,
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
 *            | LCTR | LAlt | LGUI |LOWER | / Bspc  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
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
 *            | LCTR | LAlt | LGUI |LOWER | / Bspc  /       \RU/EN \  | RAISE|Enter | LGUI | RCTR |
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

// комбо скобки
enum combo_events {
    COMBO_AG_LPRN,  // (
    COMBO_AG_RPRN,  // )
    COMBO_EN_LCBR,  // {
    COMBO_EN_RCBR,  // }
    COMBO_EN_LBRC,  // [
    COMBO_EN_RBRC,  // ]
    COMBO_EN_LT,    // <
    COMBO_EN_GT,    // >
    COMBO_AG_LPRN_R,  // (
    COMBO_AG_RPRN_R,  // )
    COMBO_EN_LCBR_R,  // {
    COMBO_EN_RCBR_R,  // }
    COMBO_EN_LBRC_R,  // [
    COMBO_EN_RBRC_R,  // ]
    COMBO_EN_LT_R,    // <
    COMBO_EN_GT_R,    // >
    COMBO_COUNT
};
// комбо скобки
const uint16_t PROGMEM rt_combo[] = {EN_R, EN_T, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {EN_F, EN_G, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {EN_V, EN_B, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {EN_C, EN_V, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {EN_Y, EN_U, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {EN_H, EN_J, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {EN_N, EN_M, COMBO_END};
const uint16_t PROGMEM mcom_combo[] = {EN_M, EN_COMM, COMBO_END};

const uint16_t PROGMEM rt_combo_r[] = {RU_K, RU_JE, COMBO_END};
const uint16_t PROGMEM fg_combo_r[] = {RU_A, RU_P, COMBO_END};
const uint16_t PROGMEM vb_combo_r[] = {RU_M, RU_I, COMBO_END};
const uint16_t PROGMEM cv_combo_r[] = {RU_S, RU_M, COMBO_END};
const uint16_t PROGMEM yu_combo_r[] = {RU_N, RU_G, COMBO_END};
const uint16_t PROGMEM hj_combo_r[] = {RU_R, RU_O, COMBO_END};
const uint16_t PROGMEM nm_combo_r[] = {RU_T, RU_SF, COMBO_END};
const uint16_t PROGMEM mcom_combo_r[] = {RU_SF, RU_B, COMBO_END};

combo_t key_combos[] = {
    // комбо скобки
    [COMBO_AG_LPRN] = COMBO(rt_combo, AG_LPRN),
    [COMBO_EN_LCBR] = COMBO(fg_combo, EN_LCBR),
    [COMBO_EN_LBRC] = COMBO(vb_combo, EN_LBRC),
    [COMBO_EN_LT] = COMBO(cv_combo, EN_LT),
    [COMBO_AG_RPRN] = COMBO(yu_combo, AG_RPRN),
    [COMBO_EN_RCBR] = COMBO(hj_combo, EN_RCBR),
    [COMBO_EN_RBRC] = COMBO(nm_combo, EN_RBRC),
    [COMBO_EN_GT] = COMBO(mcom_combo, EN_GT),

    [COMBO_AG_LPRN_R] = COMBO(rt_combo_r, AG_LPRN),
    [COMBO_EN_LCBR_R] = COMBO(fg_combo_r, EN_LCBR),
    [COMBO_EN_LBRC_R] = COMBO(vb_combo_r, EN_LBRC),
    [COMBO_EN_LT_R] = COMBO(cv_combo_r, EN_LT),
    [COMBO_AG_RPRN_R] = COMBO(yu_combo_r, AG_RPRN),
    [COMBO_EN_RCBR_R] = COMBO(hj_combo_r, EN_RCBR),
    [COMBO_EN_RBRC_R] = COMBO(nm_combo_r, EN_RBRC),
    [COMBO_EN_GT_R] = COMBO(mcom_combo_r, EN_GT),
};


// RGB эффекты
#ifdef RGB_MATRIX_ENABLE
// Сокращённые названия эффектов для OLED (макс. 8 символов!)
static const char *const rgb_effect_names[] = {
    [RGB_MATRIX_NONE] = "None ",
    [RGB_MATRIX_SOLID_COLOR] = "Solid",
    [RGB_MATRIX_ALPHAS_MODS] = "AlpMd",
    [RGB_MATRIX_GRADIENT_UP_DOWN] = "GrUpD",
    [RGB_MATRIX_GRADIENT_LEFT_RIGHT] = "GrLfR",
    [RGB_MATRIX_BREATHING] = "Breat",
    [RGB_MATRIX_BAND_SAT] = "BdSat",
    [RGB_MATRIX_BAND_VAL] = "BdVal",
    [RGB_MATRIX_BAND_PINWHEEL_SAT] = "PwSat",
    [RGB_MATRIX_BAND_PINWHEEL_VAL] = "PwVal",
    [RGB_MATRIX_BAND_SPIRAL_SAT] = "SpSat",
    [RGB_MATRIX_BAND_SPIRAL_VAL] = "SpVal",
    [RGB_MATRIX_CYCLE_ALL] = "CyAll",
    [RGB_MATRIX_CYCLE_LEFT_RIGHT] = "CyLfR",
    [RGB_MATRIX_CYCLE_UP_DOWN] = "CyUpD",
    [RGB_MATRIX_CYCLE_OUT_IN] = "CyOuI",
    [RGB_MATRIX_CYCLE_OUT_IN_DUAL] = "CyOID",
    [RGB_MATRIX_RAINBOW_MOVING_CHEVRON] = "RbChv",
    [RGB_MATRIX_CYCLE_PINWHEEL] = "CyPyW",
    [RGB_MATRIX_CYCLE_SPIRAL] = "CySpi",
    [RGB_MATRIX_DUAL_BEACON] = "DuBcn",
    [RGB_MATRIX_RAINBOW_BEACON] = "RbBcn",
    [RGB_MATRIX_RAINBOW_PINWHEELS] = "RbPyW",
    [RGB_MATRIX_FLOWER_BLOOMING] = "FlBlm",
    [RGB_MATRIX_RAINDROPS] = "RainD",
    [RGB_MATRIX_JELLYBEAN_RAINDROPS] = "Jelly",
    [RGB_MATRIX_HUE_BREATHING] = "HueBr",
    [RGB_MATRIX_HUE_PENDULUM] = "HuePd",
    [RGB_MATRIX_HUE_WAVE] = "HueWv",
    [RGB_MATRIX_PIXEL_FRACTAL] = "PxFrc",
    [RGB_MATRIX_PIXEL_FLOW] = "PxFlw",
    [RGB_MATRIX_PIXEL_RAIN] = "PxRai",
    [RGB_MATRIX_TYPING_HEATMAP] = "TpHtm",
    [RGB_MATRIX_DIGITAL_RAIN] = "DgRai",
    [RGB_MATRIX_SOLID_REACTIVE_SIMPLE] = "RcSim",
    [RGB_MATRIX_SOLID_REACTIVE] = "React",
    [RGB_MATRIX_SOLID_REACTIVE_WIDE] = "RcWid",
    [RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE] = "RcMWd",
    [RGB_MATRIX_SOLID_REACTIVE_CROSS] = "RcCrs",
    [RGB_MATRIX_SOLID_REACTIVE_MULTICROSS] = "RcMCr",
    [RGB_MATRIX_SOLID_REACTIVE_NEXUS] = "RcNex",
    [RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS] = "ReMNx",
    [RGB_MATRIX_SPLASH] = "Splsh",
    [RGB_MATRIX_MULTISPLASH] = "MlSpl",
    [RGB_MATRIX_SOLID_SPLASH] = "SlSpl",
    [RGB_MATRIX_SOLID_MULTISPLASH] = "SlMSp",
    [RGB_MATRIX_STARLIGHT] = "StarL",
    [RGB_MATRIX_STARLIGHT_SMOOTH] = "StLSm",
    [RGB_MATRIX_STARLIGHT_DUAL_HUE] = "DuHue",
    [RGB_MATRIX_STARLIGHT_DUAL_SAT] = "DuSat",
    [RGB_MATRIX_RIVERFLOW] = "RvFlw",
    [RGB_MATRIX_EFFECT_MAX] = "EffMa",
};
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!lang_shift_process_record(keycode, record))
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
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 64, 64,192, 64, 64,192,  0,  0,  0,240,  8,104,232,168,136,112,  0,  0,  0,  0,  0,  0,  0,128,128,128,128,128,128,128,  0,  0,  0,112,136,128,112,  8,136,112,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48,240,240,224,192,128,128,128,192,224,240,240, 48,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 35, 36,228, 35, 36, 68,131,  0,  0,  0,176,200,136,200,176,128,128,  0,  0,  0,  0,  0,  0,  0,200, 36, 34, 39, 40, 40,199,  0,  0,  0, 28, 34, 34,162, 28,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  4,  4,  6, 14, 14, 30, 63,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,254,252,252,248,253,255,255,255,255,255,255,255,249,248,252,252,254,254,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127, 63, 30, 14, 14,  6,  4,  4,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 66, 66, 67, 66, 66, 81,240,  0,  0,  0,  2,  2,  2, 38, 26,  0,  0,  0,  0,  0,  0,  0,  0,  0,123,138,139,120,136,138,123,  0,  0,  0,113, 33, 33, 35, 33, 37, 50,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  1,  3,  7, 63, 63, 63, 63, 31, 31, 63, 63, 63,127,255,255,255,255,255,255,255,127, 63, 63, 63, 31, 31, 31, 31, 31, 63, 63, 31,  3,  1,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 14,  1, 31, 17, 14,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3, 15,  7,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void print_status_narrow(void) { 
    // раскладка
    switch (get_highest_layer(layer_state)) {
        case _LAYER_EN:
        case _LAYER_EN_SHIFT:
            oled_write_ln_P(PSTR("  e  "), false);
            break;
        case _LAYER_RU:
        case _LAYER_RU_SHIFT:
            oled_write_ln_P(PSTR("RU-RU"), false);
            break;
        case _RAISE:
        case _LOWER:
        case _ADJUST:
            oled_write_ln_P(PSTR("....."), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n\n\n"), false);

    // OS логотип из стандартного знакогенератора QMK
    // https://joric.github.io/qle/
    switch (OS_TYPE) {
        case OS_MACOS:
            oled_write_P(PSTR("  "), false);
            oled_write_char((char)0x95, false);
            oled_write_char((char)0x96, false);
            oled_write_P(PSTR("\n  "), false);
            oled_write_char((char)0xB5, false);
            oled_write_char((char)0xB6, false);
            break;
        case OS_WINDOWS:
            oled_write_P(PSTR("  "), false);
            oled_write_char((char)0x97, false);
            oled_write_char((char)0x98, false);
            oled_write_P(PSTR("\n  "), false);
            oled_write_char((char)0xB7, false);
            oled_write_char((char)0xB8, false);
            break;
        default:
            oled_write_P(PSTR("  "), false);
            oled_write_char((char)0x99, false);
            oled_write_char((char)0x9A, false);
            oled_write_P(PSTR("\n  "), false);
            oled_write_char((char)0xB9, false);
            oled_write_char((char)0xBA, false);
    }
    oled_write_ln_P(PSTR("\n"), false);


    // === RGB состояние ===
#ifdef RGB_MATRIX_ENABLE
    if (rgb_matrix_is_enabled()) {
        oled_write_P(PSTR(" RGB\n"), false);
        uint8_t mode = rgb_matrix_get_mode();
        if (mode < sizeof(rgb_effect_names) / sizeof(rgb_effect_names[0]) && rgb_effect_names[mode]) {
            oled_write(rgb_effect_names[mode], false);
        } else {
            oled_write_P(PSTR("?????"), false);
        }
    } else {
        oled_write_P(PSTR("\n"), false);
        oled_write_P(PSTR("_   _"), false);
    }
#endif

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)

    // Print current layer
    oled_write_P(PSTR("\n\n\n\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _LAYER_EN:
        case _LAYER_EN_SHIFT:
        case _LAYER_RU:
        case _LAYER_RU_SHIFT:
            oled_write_P(PSTR("  .  "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("   <R"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("l>   "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("l> <R"), false);
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
