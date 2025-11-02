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
