# copy all files & directories to qmk_firmware
mkdir -p ~/qmk_firmware/keyboards/sofle/keymaps/sofle_custom_rus
cp -r sofle_v1_lang_shift/* ~/qmk_firmware/keyboards/sofle/keymaps/sofle_custom_rus
# compile for rp2040
qmk compile -kb sofle/rev1 -km sofle_custom_rus -e CONVERT_TO=rp2040_ce
# copy firmware here
cp ~/qmk_firmware/sofle_rev1_sofle_custom_rus_rp2040_ce.uf2 ./sofle_rev1_sofle_custom_rus_rp2040_ce.uf2

