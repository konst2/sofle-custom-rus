# sofle-custom-rus

Данная прошивка ориентирована на MacOS.  
Для этого сделаны несколько модификаций в плагин lang_shift.  
Добавлен метод переключения раскладки через ПО Karabier Elements.  
Он должен быть установлен в системе и добавлены 2 правила:  

1.  
```json
{
    "description": "F19 -> переключить на английский (даже с Shift/Ctrl и др.)",
    "manipulators": [
        {
            "from": {
                "key_code": "f19",
                "modifiers": { "optional": ["any"] }
            },
            "to": [{ "select_input_source": { "language": "en" } }],
            "type": "basic"
        }
    ]
}
```

2.  
```json
{
    "description": "F18 -> переключить на русский (даже с Shift/Ctrl и др.)",
    "manipulators": [
        {
            "from": {
                "key_code": "f18",
                "modifiers": { "optional": ["any"] }
            },
            "to": [{ "select_input_source": { "language": "ru" } }],
            "type": "basic"
        }
    ]
}
```

Всё остальное модифицируется согласно описанию плагина lang_shift.  

Раскладка прошивки: [Keyboard Layout Editor](hhttps://www.keyboard-layout-editor.com/#/gists/26ca3f92825312924ce738406f96e0a4)
![Раскладка](soflekeyboard.png)


sofle_v1_lang_shift - Sofle с вкомпилированным lang_shift
https://github.com/ilabutin/lang_shift


Panda layouts:
https://github.com/PandaKBLab/QMK-firmware-for-keyboards/tree/main/sofle/sofle
