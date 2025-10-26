# copy all files & directories to ˜/qmk_firmware/keyboards/sofle/keymaps/default
cp -r sofle_v1_lang_shift/* ~/qmk_firmware/keyboards/sofle/keymaps/default
# compile for rp2040
qmk flash -kb sofle/rev1 -km default -e CONVERT_TO=rp2040_ce
