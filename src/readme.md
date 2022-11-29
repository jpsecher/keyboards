# Firmware for mechanical keyboards

## First-time install

### MacOs

I mostly use the Olimex AVR-ISP-Mk2 programmer:

    $ system_profiler SPUSBDataType
    AVRISP mkII:
      Product ID: 0x2104
      Vendor ID: 0x03eb  (Atmel Corporation)
      Version: 2.00
      Serial Number: 764215213308
      Speed: Up to 12 Mb/s
      Manufacturer: ATMEL
      Location ID: 0x14100000 / 6
      Current Available (mA): 500
      Extra Operating Current (mA): 0

Install avrdude:

    $ brew install avrdude

Install QMK Tools / Device Firmware Update:

    $ brew install qmk-toolbox dfu-programmer 


### MacOS/Linux

The microcontroller needs a crystal with capacitors for avrdude detection to work:

    $ avrdude -c avrispmkii -p m32u2
    avrdude: Device signature = 0x1e958a (probably m32u2)
    avrdude: safemode: Fuses OK (E:F4, H:D9, L:5E)

But according to [helentronica](https://helentronica.com/2015/07/23/getting-started-with-atmega8u2-and-other-avr-usb-microcontrollers/), ATmega32U2 always have a bootloader built in, so an application can be flashed over USB.
