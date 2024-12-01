# Acacia

A pseudo-split keyboard with 2+4x3+2 vertically staggered keys and 4+1 thumb keys for each hand.

* Keyboard Maintainer: [jpsecher](https://github.com/jpsecher)
* Hardware Supported: https://github.com/jpsecher/keyboards/acacia

Make example for this keyboard (after setting up your build environment):

    make handwired/acacia:default

Flashing example for this keyboard:

    make handwired/acacia:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.  If the chip is completely blank, then you might have to forcefully erase it like

    dfu-programmer atmega32u2 erase --force

## Acacia-2

    make handwired/acacia_2:qwerty-36-pc
    make handwired/acacia_2:qwerty-36-pc:flash

## Bootloader

Enter the bootloader by using the small buttons on the PCB: press the RESET button while connected to QMK Toolbox.

Then you can flash the HEX file you built above.
