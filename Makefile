USER = lorenzorapetti

KEYBOARDS = aurora kyria corne
PATH_aurora = splitkb/aurora/sweep
PATH_kyria = splitkb/kyria
PATH_corne = splitkb/aurora/corne

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# init submodule
	git submodule update --init --recursive

	# cleanup old symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)

	# add new symlinks
	ln -s $(shell pwd)/user qmk_firmware/users/$(USER)
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)

	# run build
	make BUILD_DIR=$(shell pwd) -j1 -C qmk_firmware $(PATH_$@):$(USER)

	# cleanup symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)

	# generate keymap svg
	test -e $@/keymap-config.yaml && test -e $@/keymap.yaml && which keymap > /dev/null && keymap -c $@/keymap-config.yaml draw $@/keymap.yaml > $@/keymap.svg || true

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
	rm -f *.tmp
	rm -f *.uf2
