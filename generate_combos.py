def gen_enum():
    lines = ["enum combo_events {"]
    for lang in ("E", "R"):
        for i in range(40):
            lines.append(f"  CMB_H{lang}_{i:02d},")
    for lang in ("E", "R"):
        for shift in ("", "S"):
            for i in range(1, 13):
                s = f"_{shift}" if shift else ""
                lines.append(f"  CMB_V{lang}{s}_{i:02d},")
    lines.append("  COMBO_COUNT")
    lines.append("};")
    return lines

def gen_arrays():
    lines = []

    # Horizontal
    for lang, layer in (("E", "_LAYER_EN"), ("R", "_LAYER_RU")):
        for i in range(40):
            row = i // 5  # 0–3 → top rows
            if row < 4:
                r = row
                c1, c2 = i % 5, i % 5 + 1
                k1 = f"keymaps[{layer}][{r}][{c1}]"
                k2 = f"keymaps[{layer}][{r}][{c2}]"
            else:
                r = 5 + (i - 20) // 5  # 5–8 → bottom rows
                c2 = 5 - (i - 20) % 5
                c1 = c2 + 1
                k1 = f"keymaps[{layer}][{r}][{c1}]"
                k2 = f"keymaps[{layer}][{r}][{c2}]"
            lines.append(f"const uint16_t PROGMEM cmb_h{lang.lower()}_{i:02d}[] = {{{k1}, {k2}, COMBO_END}};")

    # Vertical
    top_row_pairs = [(0,1), (0,2), (0,3), (0,4), (5,5)]
    bot_row_pairs = [(1,1), (1,2), (1,3), (1,4), (1,5)]
    extra_top = [(5,5), (5,4), (5,3), (5,2), (5,1), (5,0), (6,0)]
    extra_bot = [(6,5), (6,4), (6,3), (6,2), (6,1), (6,0), (7,0)]
    v_coords = list(zip(top_row_pairs + extra_top, bot_row_pairs + extra_bot))

    for lang, layer_base in (("E", "_LAYER_EN"), ("R", "_LAYER_RU")):
        for shift in ("", "_SHIFT"):
            layer = layer_base + shift
            suffix = "_s" if shift else "_"
            for i, ((r1, c1), (r2, c2)) in enumerate(v_coords, 1):
                k1 = f"keymaps[{layer}][{r1}][{c1}]"
                k2 = f"keymaps[{layer}][{r2}][{c2}]"
                name = f"cmb_v{lang.lower()}{suffix}{i:02d}"
                lines.append(f"const uint16_t PROGMEM {name}[] = {{{k1}, {k2}, COMBO_END}};")

    return lines

def gen_combo_table():
    lines = ["combo_t key_combos[] = {"]
    # Horizontal
    for lang in ("E", "R"):
        for i in range(40):
            lines.append(f"    [CMB_H{lang}_{i:02d}] = COMBO(cmb_h{lang.lower()}_{i:02d}, combos_horizontal[{i}]),")
    # Vertical
    for lang in ("E", "R"):
        for shift in ("", "S"):
            for i in range(1, 13):
                enum_s = f"_{shift}" if shift else ""
                var_s = "_s" if shift else "_"
                var = f"cmb_v{lang.lower()}{var_s}{i:02d}"
                kc = f"KC_F{i}"
                lines.append(f"    [CMB_V{lang}{enum_s}_{i:02d}] = COMBO({var}, {kc}),")
    lines.append("};")
    return lines


out = []
out.extend(gen_enum())
out.append("")
out.extend(gen_arrays())
out.append("")
out.extend(gen_combo_table())
print("\n".join(out))
