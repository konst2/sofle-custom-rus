// комбо
enum combo_events {
  // Слой En
  CMB_HE_00, CMB_HE_01, CMB_HE_02, CMB_HE_03, CMB_HE_04,
    CMB_HE_05, CMB_HE_06, CMB_HE_07, CMB_HE_08, CMB_HE_09,
  CMB_HE_10, CMB_HE_11, CMB_HE_12, CMB_HE_13, CMB_HE_14,
    CMB_HE_15, CMB_HE_16, CMB_HE_17, CMB_HE_18, CMB_HE_19,
  CMB_HE_20, CMB_HE_21, CMB_HE_22, CMB_HE_23, CMB_HE_24,
    CMB_HE_25, CMB_HE_26, CMB_HE_27, CMB_HE_28, CMB_HE_29,
  CMB_HE_30, CMB_HE_31, CMB_HE_32, CMB_HE_33, CMB_HE_34,
    CMB_HE_35, CMB_HE_36, CMB_HE_37, CMB_HE_38, CMB_HE_39,
  
  // Слой Ru
  CMB_HR_00, CMB_HR_01, CMB_HR_02, CMB_HR_03, CMB_HR_04,
    CMB_HR_05, CMB_HR_06, CMB_HR_07, CMB_HR_08, CMB_HR_09,
  CMB_HR_10, CMB_HR_11, CMB_HR_12, CMB_HR_13, CMB_HR_14,
    CMB_HR_15, CMB_HR_16, CMB_HR_17, CMB_HR_18, CMB_HR_19,
  CMB_HR_20, CMB_HR_21, CMB_HR_22, CMB_HR_23, CMB_HR_24,
    CMB_HR_25, CMB_HR_26, CMB_HR_27, CMB_HR_28, CMB_HR_29,
  CMB_HR_30, CMB_HR_31, CMB_HR_32, CMB_HR_33, CMB_HR_34,
    CMB_HR_35, CMB_HR_36, CMB_HR_37, CMB_HR_38, CMB_HR_39,

  // Fx combos
  CMB_VE_01, CMB_VE_02, CMB_VE_03, CMB_VE_04,
    CMB_VE_05, CMB_VE_06, CMB_VE_07, CMB_VE_08, CMB_VE_09,
  CMB_VE_10, CMB_VE_11, CMB_VE_12, 

  CMB_VE_S01, CMB_VE_S02, CMB_VE_S03, CMB_VE_S04,
    CMB_VE_S05, CMB_VE_S06, CMB_VE_S07, CMB_VE_S08, CMB_VE_S09,
  CMB_VE_S10, CMB_VE_S11, CMB_VE_S12, 

  CMB_VR_01, CMB_VR_02, CMB_VR_03, CMB_VR_04,
    CMB_VR_05, CMB_VR_06, CMB_VR_07, CMB_VR_08, CMB_VR_09,
  CMB_VR_10, CMB_VR_11, CMB_VR_12, 

  CMB_VR_S01, CMB_VR_S02, CMB_VR_S03, CMB_VR_S04,
    CMB_VR_S05, CMB_VR_S06, CMB_VR_S07, CMB_VR_S08, CMB_VR_S09,
  CMB_VR_S10, CMB_VR_S11, CMB_VR_S12, 

  COMBO_COUNT
};
    // Слой En
    const uint16_t PROGMEM cmb_he_00[] = {keymaps[_LAYER_EN][0][0], keymaps[_LAYER_EN][0][1], COMBO_END};
    const uint16_t PROGMEM cmb_he_01[] = {keymaps[_LAYER_EN][0][1], keymaps[_LAYER_EN][0][2], COMBO_END};
    const uint16_t PROGMEM cmb_he_02[] = {keymaps[_LAYER_EN][0][2], keymaps[_LAYER_EN][0][3], COMBO_END};
    const uint16_t PROGMEM cmb_he_03[] = {keymaps[_LAYER_EN][0][3], keymaps[_LAYER_EN][0][4], COMBO_END};
    const uint16_t PROGMEM cmb_he_04[] = {keymaps[_LAYER_EN][0][4], keymaps[_LAYER_EN][0][5], COMBO_END};

        const uint16_t PROGMEM cmb_he_05[] = {keymaps[_LAYER_EN][5][5], keymaps[_LAYER_EN][5][4], COMBO_END};
        const uint16_t PROGMEM cmb_he_06[] = {keymaps[_LAYER_EN][5][4], keymaps[_LAYER_EN][5][3], COMBO_END};
        const uint16_t PROGMEM cmb_he_07[] = {keymaps[_LAYER_EN][5][3], keymaps[_LAYER_EN][5][2], COMBO_END};
        const uint16_t PROGMEM cmb_he_08[] = {keymaps[_LAYER_EN][5][2], keymaps[_LAYER_EN][5][1], COMBO_END};
        const uint16_t PROGMEM cmb_he_09[] = {keymaps[_LAYER_EN][5][1], keymaps[_LAYER_EN][5][0], COMBO_END};

    const uint16_t PROGMEM cmb_he_10[] = {keymaps[_LAYER_EN][1][0], keymaps[_LAYER_EN][1][1], COMBO_END};
    const uint16_t PROGMEM cmb_he_11[] = {keymaps[_LAYER_EN][1][1], keymaps[_LAYER_EN][1][2], COMBO_END};
    const uint16_t PROGMEM cmb_he_12[] = {keymaps[_LAYER_EN][1][2], keymaps[_LAYER_EN][1][3], COMBO_END};
    const uint16_t PROGMEM cmb_he_13[] = {keymaps[_LAYER_EN][1][3], keymaps[_LAYER_EN][1][4], COMBO_END};
    const uint16_t PROGMEM cmb_he_14[] = {keymaps[_LAYER_EN][1][4], keymaps[_LAYER_EN][1][5], COMBO_END};

        const uint16_t PROGMEM cmb_he_15[] = {keymaps[_LAYER_EN][6][5], keymaps[_LAYER_EN][6][4], COMBO_END};
        const uint16_t PROGMEM cmb_he_16[] = {keymaps[_LAYER_EN][6][4], keymaps[_LAYER_EN][6][3], COMBO_END};
        const uint16_t PROGMEM cmb_he_17[] = {keymaps[_LAYER_EN][6][3], keymaps[_LAYER_EN][6][2], COMBO_END};
        const uint16_t PROGMEM cmb_he_18[] = {keymaps[_LAYER_EN][6][2], keymaps[_LAYER_EN][6][1], COMBO_END};
        const uint16_t PROGMEM cmb_he_19[] = {keymaps[_LAYER_EN][6][1], keymaps[_LAYER_EN][6][0], COMBO_END};

    const uint16_t PROGMEM cmb_he_20[] = {keymaps[_LAYER_EN][2][0], keymaps[_LAYER_EN][2][1], COMBO_END};
    const uint16_t PROGMEM cmb_he_21[] = {keymaps[_LAYER_EN][2][1], keymaps[_LAYER_EN][2][2], COMBO_END};
    const uint16_t PROGMEM cmb_he_22[] = {keymaps[_LAYER_EN][2][2], keymaps[_LAYER_EN][2][3], COMBO_END};
    const uint16_t PROGMEM cmb_he_23[] = {keymaps[_LAYER_EN][2][3], keymaps[_LAYER_EN][2][4], COMBO_END};
    const uint16_t PROGMEM cmb_he_24[] = {keymaps[_LAYER_EN][2][4], keymaps[_LAYER_EN][2][5], COMBO_END};

        const uint16_t PROGMEM cmb_he_25[] = {keymaps[_LAYER_EN][7][5], keymaps[_LAYER_EN][7][4], COMBO_END};
        const uint16_t PROGMEM cmb_he_26[] = {keymaps[_LAYER_EN][7][4], keymaps[_LAYER_EN][7][3], COMBO_END};
        const uint16_t PROGMEM cmb_he_27[] = {keymaps[_LAYER_EN][7][3], keymaps[_LAYER_EN][7][2], COMBO_END};
        const uint16_t PROGMEM cmb_he_28[] = {keymaps[_LAYER_EN][7][2], keymaps[_LAYER_EN][7][1], COMBO_END};
        const uint16_t PROGMEM cmb_he_29[] = {keymaps[_LAYER_EN][7][1], keymaps[_LAYER_EN][7][0], COMBO_END};

    const uint16_t PROGMEM cmb_he_30[] = {keymaps[_LAYER_EN][3][0], keymaps[_LAYER_EN][3][1], COMBO_END};
    const uint16_t PROGMEM cmb_he_31[] = {keymaps[_LAYER_EN][3][1], keymaps[_LAYER_EN][3][2], COMBO_END};
    const uint16_t PROGMEM cmb_he_32[] = {keymaps[_LAYER_EN][3][2], keymaps[_LAYER_EN][3][3], COMBO_END};
    const uint16_t PROGMEM cmb_he_33[] = {keymaps[_LAYER_EN][3][3], keymaps[_LAYER_EN][3][4], COMBO_END};
    const uint16_t PROGMEM cmb_he_34[] = {keymaps[_LAYER_EN][3][4], keymaps[_LAYER_EN][3][5], COMBO_END};

        const uint16_t PROGMEM cmb_he_35[] = {keymaps[_LAYER_EN][8][5], keymaps[_LAYER_EN][8][4], COMBO_END};
        const uint16_t PROGMEM cmb_he_36[] = {keymaps[_LAYER_EN][8][4], keymaps[_LAYER_EN][8][3], COMBO_END};
        const uint16_t PROGMEM cmb_he_37[] = {keymaps[_LAYER_EN][8][3], keymaps[_LAYER_EN][8][2], COMBO_END};
        const uint16_t PROGMEM cmb_he_38[] = {keymaps[_LAYER_EN][8][2], keymaps[_LAYER_EN][8][1], COMBO_END};
        const uint16_t PROGMEM cmb_he_39[] = {keymaps[_LAYER_EN][8][1], keymaps[_LAYER_EN][8][0], COMBO_END};

// Слой Ru
const uint16_t PROGMEM cmb_hr_00[] = {keymaps[_LAYER_RU][0][0], keymaps[_LAYER_RU][0][1], COMBO_END};
const uint16_t PROGMEM cmb_hr_01[] = {keymaps[_LAYER_RU][0][1], keymaps[_LAYER_RU][0][2], COMBO_END};
const uint16_t PROGMEM cmb_hr_02[] = {keymaps[_LAYER_RU][0][2], keymaps[_LAYER_RU][0][3], COMBO_END};
const uint16_t PROGMEM cmb_hr_03[] = {keymaps[_LAYER_RU][0][3], keymaps[_LAYER_RU][0][4], COMBO_END};
const uint16_t PROGMEM cmb_hr_04[] = {keymaps[_LAYER_RU][0][4], keymaps[_LAYER_RU][0][5], COMBO_END};

    const uint16_t PROGMEM cmb_hr_05[] = {keymaps[_LAYER_RU][5][5], keymaps[_LAYER_RU][5][4], COMBO_END};
    const uint16_t PROGMEM cmb_hr_06[] = {keymaps[_LAYER_RU][5][4], keymaps[_LAYER_RU][5][3], COMBO_END};
    const uint16_t PROGMEM cmb_hr_07[] = {keymaps[_LAYER_RU][5][3], keymaps[_LAYER_RU][5][2], COMBO_END};
    const uint16_t PROGMEM cmb_hr_08[] = {keymaps[_LAYER_RU][5][2], keymaps[_LAYER_RU][5][1], COMBO_END};
    const uint16_t PROGMEM cmb_hr_09[] = {keymaps[_LAYER_RU][5][1], keymaps[_LAYER_RU][5][0], COMBO_END};

const uint16_t PROGMEM cmb_hr_10[] = {keymaps[_LAYER_RU][1][0], keymaps[_LAYER_RU][1][1], COMBO_END};
const uint16_t PROGMEM cmb_hr_11[] = {keymaps[_LAYER_RU][1][1], keymaps[_LAYER_RU][1][2], COMBO_END};
const uint16_t PROGMEM cmb_hr_12[] = {keymaps[_LAYER_RU][1][2], keymaps[_LAYER_RU][1][3], COMBO_END};
const uint16_t PROGMEM cmb_hr_13[] = {keymaps[_LAYER_RU][1][3], keymaps[_LAYER_RU][1][4], COMBO_END};
const uint16_t PROGMEM cmb_hr_14[] = {keymaps[_LAYER_RU][1][4], keymaps[_LAYER_RU][1][5], COMBO_END};

    const uint16_t PROGMEM cmb_hr_15[] = {keymaps[_LAYER_RU][6][5], keymaps[_LAYER_RU][6][4], COMBO_END};
    const uint16_t PROGMEM cmb_hr_16[] = {keymaps[_LAYER_RU][6][4], keymaps[_LAYER_RU][6][3], COMBO_END};
    const uint16_t PROGMEM cmb_hr_17[] = {keymaps[_LAYER_RU][6][3], keymaps[_LAYER_RU][6][2], COMBO_END};
    const uint16_t PROGMEM cmb_hr_18[] = {keymaps[_LAYER_RU][6][2], keymaps[_LAYER_RU][6][1], COMBO_END};
    const uint16_t PROGMEM cmb_hr_19[] = {keymaps[_LAYER_RU][6][1], keymaps[_LAYER_RU][6][0], COMBO_END};

const uint16_t PROGMEM cmb_hr_20[] = {keymaps[_LAYER_RU][2][0], keymaps[_LAYER_RU][2][1], COMBO_END};
const uint16_t PROGMEM cmb_hr_21[] = {keymaps[_LAYER_RU][2][1], keymaps[_LAYER_RU][2][2], COMBO_END};
const uint16_t PROGMEM cmb_hr_22[] = {keymaps[_LAYER_RU][2][2], keymaps[_LAYER_RU][2][3], COMBO_END};
const uint16_t PROGMEM cmb_hr_23[] = {keymaps[_LAYER_RU][2][3], keymaps[_LAYER_RU][2][4], COMBO_END};
const uint16_t PROGMEM cmb_hr_24[] = {keymaps[_LAYER_RU][2][4], keymaps[_LAYER_RU][2][5], COMBO_END};

    const uint16_t PROGMEM cmb_hr_25[] = {keymaps[_LAYER_RU][7][5], keymaps[_LAYER_RU][7][4], COMBO_END};
    const uint16_t PROGMEM cmb_hr_26[] = {keymaps[_LAYER_RU][7][4], keymaps[_LAYER_RU][7][3], COMBO_END};
    const uint16_t PROGMEM cmb_hr_27[] = {keymaps[_LAYER_RU][7][3], keymaps[_LAYER_RU][7][2], COMBO_END};
    const uint16_t PROGMEM cmb_hr_28[] = {keymaps[_LAYER_RU][7][2], keymaps[_LAYER_RU][7][1], COMBO_END};
    const uint16_t PROGMEM cmb_hr_29[] = {keymaps[_LAYER_RU][7][1], keymaps[_LAYER_RU][7][0], COMBO_END};

const uint16_t PROGMEM cmb_hr_30[] = {keymaps[_LAYER_RU][3][0], keymaps[_LAYER_RU][3][1], COMBO_END};
const uint16_t PROGMEM cmb_hr_31[] = {keymaps[_LAYER_RU][3][1], keymaps[_LAYER_RU][3][2], COMBO_END};
const uint16_t PROGMEM cmb_hr_32[] = {keymaps[_LAYER_RU][3][2], keymaps[_LAYER_RU][3][3], COMBO_END};
const uint16_t PROGMEM cmb_hr_33[] = {keymaps[_LAYER_RU][3][3], keymaps[_LAYER_RU][3][4], COMBO_END};
const uint16_t PROGMEM cmb_hr_34[] = {keymaps[_LAYER_RU][3][4], keymaps[_LAYER_RU][3][5], COMBO_END};

    const uint16_t PROGMEM cmb_hr_35[] = {keymaps[_LAYER_RU][8][5], keymaps[_LAYER_RU][8][4], COMBO_END};
    const uint16_t PROGMEM cmb_hr_36[] = {keymaps[_LAYER_RU][8][4], keymaps[_LAYER_RU][8][3], COMBO_END};
    const uint16_t PROGMEM cmb_hr_37[] = {keymaps[_LAYER_RU][8][3], keymaps[_LAYER_RU][8][2], COMBO_END};
    const uint16_t PROGMEM cmb_hr_38[] = {keymaps[_LAYER_RU][8][2], keymaps[_LAYER_RU][8][1], COMBO_END};
    const uint16_t PROGMEM cmb_hr_39[] = {keymaps[_LAYER_RU][8][1], keymaps[_LAYER_RU][8][0], COMBO_END};

// Fx combos
    const uint16_t PROGMEM cmb_ve_01[] = {keymaps[_LAYER_EN][0][1], keymaps[_LAYER_EN][1][1], COMBO_END};
    const uint16_t PROGMEM cmb_ve_02[] = {keymaps[_LAYER_EN][0][2], keymaps[_LAYER_EN][1][2], COMBO_END};
    const uint16_t PROGMEM cmb_ve_03[] = {keymaps[_LAYER_EN][0][3], keymaps[_LAYER_EN][1][3], COMBO_END};
    const uint16_t PROGMEM cmb_ve_04[] = {keymaps[_LAYER_EN][0][4], keymaps[_LAYER_EN][1][4], COMBO_END};
    const uint16_t PROGMEM cmb_ve_05[] = {keymaps[_LAYER_EN][5][5], keymaps[_LAYER_EN][1][5], COMBO_END};

        const uint16_t PROGMEM cmb_ve_06[] = {keymaps[_LAYER_EN][5][5], keymaps[_LAYER_EN][6][5], COMBO_END};
        const uint16_t PROGMEM cmb_ve_07[] = {keymaps[_LAYER_EN][5][4], keymaps[_LAYER_EN][6][4], COMBO_END};
        const uint16_t PROGMEM cmb_ve_08[] = {keymaps[_LAYER_EN][5][3], keymaps[_LAYER_EN][6][3], COMBO_END};
        const uint16_t PROGMEM cmb_ve_09[] = {keymaps[_LAYER_EN][5][2], keymaps[_LAYER_EN][6][2], COMBO_END};
        const uint16_t PROGMEM cmb_ve_10[] = {keymaps[_LAYER_EN][5][1], keymaps[_LAYER_EN][6][1], COMBO_END};
        const uint16_t PROGMEM cmb_ve_11[] = {keymaps[_LAYER_EN][5][0], keymaps[_LAYER_EN][6][0], COMBO_END};
        const uint16_t PROGMEM cmb_ve_12[] = {keymaps[_LAYER_EN][6][0], keymaps[_LAYER_EN][7][0], COMBO_END};

    const uint16_t PROGMEM cmb_ve_s01[] = {keymaps[_LAYER_EN_SHIFT][0][1], keymaps[_LAYER_EN_SHIFT][1][1], COMBO_END};
    const uint16_t PROGMEM cmb_ve_s02[] = {keymaps[_LAYER_EN_SHIFT][0][2], keymaps[_LAYER_EN_SHIFT][1][2], COMBO_END};
    const uint16_t PROGMEM cmb_ve_s03[] = {keymaps[_LAYER_EN_SHIFT][0][3], keymaps[_LAYER_EN_SHIFT][1][3], COMBO_END};
    const uint16_t PROGMEM cmb_ve_s04[] = {keymaps[_LAYER_EN_SHIFT][0][4], keymaps[_LAYER_EN_SHIFT][1][4], COMBO_END};
    const uint16_t PROGMEM cmb_ve_s05[] = {keymaps[_LAYER_EN_SHIFT][5][5], keymaps[_LAYER_EN_SHIFT][1][5], COMBO_END};

        const uint16_t PROGMEM cmb_ve_s06[] = {keymaps[_LAYER_EN_SHIFT][5][5], keymaps[_LAYER_EN_SHIFT][6][5], COMBO_END};
        const uint16_t PROGMEM cmb_ve_s07[] = {keymaps[_LAYER_EN_SHIFT][5][4], keymaps[_LAYER_EN_SHIFT][6][4], COMBO_END};
        const uint16_t PROGMEM cmb_ve_s08[] = {keymaps[_LAYER_EN_SHIFT][5][3], keymaps[_LAYER_EN_SHIFT][6][3], COMBO_END};
        const uint16_t PROGMEM cmb_ve_s09[] = {keymaps[_LAYER_EN_SHIFT][5][2], keymaps[_LAYER_EN_SHIFT][6][2], COMBO_END};
        const uint16_t PROGMEM cmb_ve_s10[] = {keymaps[_LAYER_EN_SHIFT][5][1], keymaps[_LAYER_EN_SHIFT][6][1], COMBO_END};
        const uint16_t PROGMEM cmb_ve_s11[] = {keymaps[_LAYER_EN_SHIFT][5][0], keymaps[_LAYER_EN_SHIFT][6][0], COMBO_END};
        const uint16_t PROGMEM cmb_ve_s12[] = {keymaps[_LAYER_EN_SHIFT][6][0], keymaps[_LAYER_EN_SHIFT][7][0], COMBO_END};

// Fx RUS combos
    const uint16_t PROGMEM cmb_vr_01[] = {keymaps[_LAYER_RU][0][1], keymaps[_LAYER_RU][1][1], COMBO_END};
    const uint16_t PROGMEM cmb_vr_02[] = {keymaps[_LAYER_RU][0][2], keymaps[_LAYER_RU][1][2], COMBO_END};
    const uint16_t PROGMEM cmb_vr_03[] = {keymaps[_LAYER_RU][0][3], keymaps[_LAYER_RU][1][3], COMBO_END};
    const uint16_t PROGMEM cmb_vr_04[] = {keymaps[_LAYER_RU][0][4], keymaps[_LAYER_RU][1][4], COMBO_END};
    const uint16_t PROGMEM cmb_vr_05[] = {keymaps[_LAYER_RU][5][5], keymaps[_LAYER_RU][1][5], COMBO_END};

        const uint16_t PROGMEM cmb_vr_06[] = {keymaps[_LAYER_RU][5][5], keymaps[_LAYER_RU][6][5], COMBO_END};
        const uint16_t PROGMEM cmb_vr_07[] = {keymaps[_LAYER_RU][5][4], keymaps[_LAYER_RU][6][4], COMBO_END};
        const uint16_t PROGMEM cmb_vr_08[] = {keymaps[_LAYER_RU][5][3], keymaps[_LAYER_RU][6][3], COMBO_END};
        const uint16_t PROGMEM cmb_vr_09[] = {keymaps[_LAYER_RU][5][2], keymaps[_LAYER_RU][6][2], COMBO_END};
        const uint16_t PROGMEM cmb_vr_10[] = {keymaps[_LAYER_RU][5][1], keymaps[_LAYER_RU][6][1], COMBO_END};
        const uint16_t PROGMEM cmb_vr_11[] = {keymaps[_LAYER_RU][5][0], keymaps[_LAYER_RU][6][0], COMBO_END};
        const uint16_t PROGMEM cmb_vr_12[] = {keymaps[_LAYER_RU][6][0], keymaps[_LAYER_RU][7][0], COMBO_END};

    const uint16_t PROGMEM cmb_vr_s01[] = {keymaps[_LAYER_RU_SHIFT][0][1], keymaps[_LAYER_RU_SHIFT][1][1], COMBO_END};
    const uint16_t PROGMEM cmb_vr_s02[] = {keymaps[_LAYER_RU_SHIFT][0][2], keymaps[_LAYER_RU_SHIFT][1][2], COMBO_END};
    const uint16_t PROGMEM cmb_vr_s03[] = {keymaps[_LAYER_RU_SHIFT][0][3], keymaps[_LAYER_RU_SHIFT][1][3], COMBO_END};
    const uint16_t PROGMEM cmb_vr_s04[] = {keymaps[_LAYER_RU_SHIFT][0][4], keymaps[_LAYER_RU_SHIFT][1][4], COMBO_END};
    const uint16_t PROGMEM cmb_vr_s05[] = {keymaps[_LAYER_RU_SHIFT][5][5], keymaps[_LAYER_RU_SHIFT][1][5], COMBO_END};

        const uint16_t PROGMEM cmb_vr_s06[] = {keymaps[_LAYER_RU_SHIFT][5][5], keymaps[_LAYER_RU_SHIFT][6][5], COMBO_END};
        const uint16_t PROGMEM cmb_vr_s07[] = {keymaps[_LAYER_RU_SHIFT][5][4], keymaps[_LAYER_RU_SHIFT][6][4], COMBO_END};
        const uint16_t PROGMEM cmb_vr_s08[] = {keymaps[_LAYER_RU_SHIFT][5][3], keymaps[_LAYER_RU_SHIFT][6][3], COMBO_END};
        const uint16_t PROGMEM cmb_vr_s09[] = {keymaps[_LAYER_RU_SHIFT][5][2], keymaps[_LAYER_RU_SHIFT][6][2], COMBO_END};
        const uint16_t PROGMEM cmb_vr_s10[] = {keymaps[_LAYER_RU_SHIFT][5][1], keymaps[_LAYER_RU_SHIFT][6][1], COMBO_END};
        const uint16_t PROGMEM cmb_vr_s11[] = {keymaps[_LAYER_RU_SHIFT][5][0], keymaps[_LAYER_RU_SHIFT][6][0], COMBO_END};
        const uint16_t PROGMEM cmb_vr_s12[] = {keymaps[_LAYER_RU_SHIFT][6][0], keymaps[_LAYER_RU_SHIFT][7][0], COMBO_END};
// Fx rus combos

combo_t key_combos[] = {
    // Слой En - горизонтальные комбо
    [CMB_HE_00] = COMBO(cmb_he_00, combos_horizontal[0]),
    [CMB_HE_01] = COMBO(cmb_he_01, combos_horizontal[1]),
    [CMB_HE_02] = COMBO(cmb_he_02, combos_horizontal[2]),
    [CMB_HE_03] = COMBO(cmb_he_03, combos_horizontal[3]),
    [CMB_HE_04] = COMBO(cmb_he_04, combos_horizontal[4]),
    [CMB_HE_05] = COMBO(cmb_he_05, combos_horizontal[5]),
    [CMB_HE_06] = COMBO(cmb_he_06, combos_horizontal[6]),
    [CMB_HE_07] = COMBO(cmb_he_07, combos_horizontal[7]),
    [CMB_HE_08] = COMBO(cmb_he_08, combos_horizontal[8]),
    [CMB_HE_09] = COMBO(cmb_he_09, combos_horizontal[9]),
    [CMB_HE_10] = COMBO(cmb_he_10, combos_horizontal[10]),
    [CMB_HE_11] = COMBO(cmb_he_11, combos_horizontal[11]),
    [CMB_HE_12] = COMBO(cmb_he_12, combos_horizontal[12]),
    [CMB_HE_13] = COMBO(cmb_he_13, combos_horizontal[13]),
    [CMB_HE_14] = COMBO(cmb_he_14, combos_horizontal[14]),
    [CMB_HE_15] = COMBO(cmb_he_15, combos_horizontal[15]),
    [CMB_HE_16] = COMBO(cmb_he_16, combos_horizontal[16]),
    [CMB_HE_17] = COMBO(cmb_he_17, combos_horizontal[17]),
    [CMB_HE_18] = COMBO(cmb_he_18, combos_horizontal[18]),
    [CMB_HE_19] = COMBO(cmb_he_19, combos_horizontal[19]),
    [CMB_HE_20] = COMBO(cmb_he_20, combos_horizontal[20]),
    [CMB_HE_21] = COMBO(cmb_he_21, combos_horizontal[21]),
    [CMB_HE_22] = COMBO(cmb_he_22, combos_horizontal[22]),
    [CMB_HE_23] = COMBO(cmb_he_23, combos_horizontal[23]),
    [CMB_HE_24] = COMBO(cmb_he_24, combos_horizontal[24]),
    [CMB_HE_25] = COMBO(cmb_he_25, combos_horizontal[25]),
    [CMB_HE_26] = COMBO(cmb_he_26, combos_horizontal[26]),
    [CMB_HE_27] = COMBO(cmb_he_27, combos_horizontal[27]),
    [CMB_HE_28] = COMBO(cmb_he_28, combos_horizontal[28]),
    [CMB_HE_29] = COMBO(cmb_he_29, combos_horizontal[29]),
    [CMB_HE_30] = COMBO(cmb_he_30, combos_horizontal[30]),
    [CMB_HE_31] = COMBO(cmb_he_31, combos_horizontal[31]),
    [CMB_HE_32] = COMBO(cmb_he_32, combos_horizontal[32]),
    [CMB_HE_33] = COMBO(cmb_he_33, combos_horizontal[33]),
    [CMB_HE_34] = COMBO(cmb_he_34, combos_horizontal[34]),
    [CMB_HE_35] = COMBO(cmb_he_35, combos_horizontal[35]),
    [CMB_HE_36] = COMBO(cmb_he_36, combos_horizontal[36]),
    [CMB_HE_37] = COMBO(cmb_he_37, combos_horizontal[37]),
    [CMB_HE_38] = COMBO(cmb_he_38, combos_horizontal[38]),
    [CMB_HE_39] = COMBO(cmb_he_39, combos_horizontal[39]),

    // Слой Ru - горизонтальные комбо
    [CMB_HR_00] = COMBO(cmb_hr_00, combos_horizontal[0]),
    [CMB_HR_01] = COMBO(cmb_hr_01, combos_horizontal[1]),
    [CMB_HR_02] = COMBO(cmb_hr_02, combos_horizontal[2]),
    [CMB_HR_03] = COMBO(cmb_hr_03, combos_horizontal[3]),
    [CMB_HR_04] = COMBO(cmb_hr_04, combos_horizontal[4]),
    [CMB_HR_05] = COMBO(cmb_hr_05, combos_horizontal[5]),
    [CMB_HR_06] = COMBO(cmb_hr_06, combos_horizontal[6]),
    [CMB_HR_07] = COMBO(cmb_hr_07, combos_horizontal[7]),
    [CMB_HR_08] = COMBO(cmb_hr_08, combos_horizontal[8]),
    [CMB_HR_09] = COMBO(cmb_hr_09, combos_horizontal[9]),
    [CMB_HR_10] = COMBO(cmb_hr_10, combos_horizontal[10]),
    [CMB_HR_11] = COMBO(cmb_hr_11, combos_horizontal[11]),
    [CMB_HR_12] = COMBO(cmb_hr_12, combos_horizontal[12]),
    [CMB_HR_13] = COMBO(cmb_hr_13, combos_horizontal[13]),
    [CMB_HR_14] = COMBO(cmb_hr_14, combos_horizontal[14]),
    [CMB_HR_15] = COMBO(cmb_hr_15, combos_horizontal[15]),
    [CMB_HR_16] = COMBO(cmb_hr_16, combos_horizontal[16]),
    [CMB_HR_17] = COMBO(cmb_hr_17, combos_horizontal[17]),
    [CMB_HR_18] = COMBO(cmb_hr_18, combos_horizontal[18]),
    [CMB_HR_19] = COMBO(cmb_hr_19, combos_horizontal[19]),
    [CMB_HR_20] = COMBO(cmb_hr_20, combos_horizontal[20]),
    [CMB_HR_21] = COMBO(cmb_hr_21, combos_horizontal[21]),
    [CMB_HR_22] = COMBO(cmb_hr_22, combos_horizontal[22]),
    [CMB_HR_23] = COMBO(cmb_hr_23, combos_horizontal[23]),
    [CMB_HR_24] = COMBO(cmb_hr_24, combos_horizontal[24]),
    [CMB_HR_25] = COMBO(cmb_hr_25, combos_horizontal[25]),
    [CMB_HR_26] = COMBO(cmb_hr_26, combos_horizontal[26]),
    [CMB_HR_27] = COMBO(cmb_hr_27, combos_horizontal[27]),
    [CMB_HR_28] = COMBO(cmb_hr_28, combos_horizontal[28]),
    [CMB_HR_29] = COMBO(cmb_hr_29, combos_horizontal[29]),
    [CMB_HR_30] = COMBO(cmb_hr_30, combos_horizontal[30]),
    [CMB_HR_31] = COMBO(cmb_hr_31, combos_horizontal[31]),
    [CMB_HR_32] = COMBO(cmb_hr_32, combos_horizontal[32]),
    [CMB_HR_33] = COMBO(cmb_hr_33, combos_horizontal[33]),
    [CMB_HR_34] = COMBO(cmb_hr_34, combos_horizontal[34]),
    [CMB_HR_35] = COMBO(cmb_hr_35, combos_horizontal[35]),
    [CMB_HR_36] = COMBO(cmb_hr_36, combos_horizontal[36]),
    [CMB_HR_37] = COMBO(cmb_hr_37, combos_horizontal[37]),
    [CMB_HR_38] = COMBO(cmb_hr_38, combos_horizontal[38]),
    [CMB_HR_39] = COMBO(cmb_hr_39, combos_horizontal[39]),

    // Fx EN combos
    [CMB_VE_01] = COMBO(cmb_ve_01, KC_F1),
    [CMB_VE_02] = COMBO(cmb_ve_02, KC_F2),
    [CMB_VE_03] = COMBO(cmb_ve_03, KC_F3),
    [CMB_VE_04] = COMBO(cmb_ve_04, KC_F4),
    [CMB_VE_05] = COMBO(cmb_ve_05, KC_F5),
    [CMB_VE_06] = COMBO(cmb_ve_06, KC_F6),
    [CMB_VE_07] = COMBO(cmb_ve_07, KC_F7),
    [CMB_VE_08] = COMBO(cmb_ve_08, KC_F8),
    [CMB_VE_09] = COMBO(cmb_ve_09, KC_F9),
    [CMB_VE_10] = COMBO(cmb_ve_10, KC_F10),
    [CMB_VE_11] = COMBO(cmb_ve_11, KC_F11),
    [CMB_VE_12] = COMBO(cmb_ve_12, KC_F12),

    [CMB_VE_S01] = COMBO(cmb_ve_s01, KC_F1),
    [CMB_VE_S02] = COMBO(cmb_ve_s02, KC_F2),
    [CMB_VE_S03] = COMBO(cmb_ve_s03, KC_F3),
    [CMB_VE_S04] = COMBO(cmb_ve_s04, KC_F4),
    [CMB_VE_S05] = COMBO(cmb_ve_s05, KC_F5),
    [CMB_VE_S06] = COMBO(cmb_ve_s06, KC_F6),
    [CMB_VE_S07] = COMBO(cmb_ve_s07, KC_F7),
    [CMB_VE_S08] = COMBO(cmb_ve_s08, KC_F8),
    [CMB_VE_S09] = COMBO(cmb_ve_s09, KC_F9),
    [CMB_VE_S10] = COMBO(cmb_ve_s10, KC_F10),
    [CMB_VE_S11] = COMBO(cmb_ve_s11, KC_F11),
    [CMB_VE_S12] = COMBO(cmb_ve_s12, KC_F12),

    // Fx RU combos
    [CMB_VR_01] = COMBO(cmb_vr_01, KC_F1),
    [CMB_VR_02] = COMBO(cmb_vr_02, KC_F2),
    [CMB_VR_03] = COMBO(cmb_vr_03, KC_F3),
    [CMB_VR_04] = COMBO(cmb_vr_04, KC_F4),
    [CMB_VR_05] = COMBO(cmb_vr_05, KC_F5),
    [CMB_VR_06] = COMBO(cmb_vr_06, KC_F6),
    [CMB_VR_07] = COMBO(cmb_vr_07, KC_F7),
    [CMB_VR_08] = COMBO(cmb_vr_08, KC_F8),
    [CMB_VR_09] = COMBO(cmb_vr_09, KC_F9),
    [CMB_VR_10] = COMBO(cmb_vr_10, KC_F10),
    [CMB_VR_11] = COMBO(cmb_vr_11, KC_F11),
    [CMB_VR_12] = COMBO(cmb_vr_12, KC_F12),

    [CMB_VR_S01] = COMBO(cmb_vr_s01, KC_F1),
    [CMB_VR_S02] = COMBO(cmb_vr_s02, KC_F2),
    [CMB_VR_S03] = COMBO(cmb_vr_s03, KC_F3),
    [CMB_VR_S04] = COMBO(cmb_vr_s04, KC_F4),
    [CMB_VR_S05] = COMBO(cmb_vr_s05, KC_F5),
    [CMB_VR_S06] = COMBO(cmb_vr_s06, KC_F6),
    [CMB_VR_S07] = COMBO(cmb_vr_s07, KC_F7),
    [CMB_VR_S08] = COMBO(cmb_vr_s08, KC_F8),
    [CMB_VR_S09] = COMBO(cmb_vr_s09, KC_F9),
    [CMB_VR_S10] = COMBO(cmb_vr_s10, KC_F10),
    [CMB_VR_S11] = COMBO(cmb_vr_s11, KC_F11),
    [CMB_VR_S12] = COMBO(cmb_vr_s12, KC_F12),
};
