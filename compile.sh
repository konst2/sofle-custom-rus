# copy all files & directories to ˜/qmk_firmware/keyboards/sofle/keymaps/default
cp -r sofle_v1_lang_shift/* ~/qmk_firmware/keyboards/sofle/keymaps/default
# compile for rp2040
qmk compile -kb sofle/rev1 -km default -e CONVERT_TO=rp2040_ce
# copy firmware here
cp ~/qmk_firmware/sofle_rev1_default_rp2040_ce.uf2 ./sofle_rev1_default_rp2040_ce.uf2

