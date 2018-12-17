# Keymap & EN/RU layouts for Levinson 40% split keyboard

<img src="./cheatsheet.png">

## Building keymap

- Clone `https://github.com/qmk/qmk_toolbox`
- Follow [docs.qmk.fm/#/newbs_getting_started](https://docs.qmk.fm/#/newbs_getting_started)
- `ln -s keymap qmk_toolbox/keyboards/levinson/keymaps/tonsky`
- In `qmk_toolbox` rum `make levinson/rev2:tonsky`
- Flash with `QMK Toolbox.app`

## Layout

Layout and keymap work together to put keys where I want them, when possible. This is EN/RU layout, which led to some compromises.

- `EN` sends F17, `RU` sends F18.
- Alt layout mostly compatible with [Ilya Birman Typography Layout](https://ilyabirman.ru/projects/typography-layout/).
- Some of the principles from [github.com/tonsky/Universal-Layout](https://github.com/tonsky/Universal-Layout) apply.
- Navigation arrows do not require Karabiner.

## The physical device

<img src="./photo.jpg">

NOTE: Not all caps match their actual function :) Consult cheatsheet above for the truth.

## Where to buy

[keeb.io/products/levinson-lets-split-w-led-backlight](https://keeb.io/products/levinson-lets-split-w-led-backlight)