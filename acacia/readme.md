# Acacia keyboard

A custom built mechanical keyboard with just 40 keys plus two extra media keys.

![Top side](acacia-top.jpg)

![PCB side](acacia-bottom.jpg)

The [layout](acacia.pdf) uses three layers.  One for alphas, one for navigation/function-keys, and one for symbols/numpad.

The outer thumb keys are one-shot modifiers (alt, shift, altgr, alt) but can also be held.  The two inner thumb keys are regular keys when tapped (backspace, escape, delete, space) but modifiers when held (symbol layer, control, gui, navigation layer).  When one layer key is held, then the opposite layer key becomes a modifier (control or gui).

If used on macOS, then the Control and GUI (Command) keys should be swapped at the OS level.

## Improvements

- Include a trackball (as alluded to in the pictures).  Unfortunately the ATmega32U2 used in the build does not have built-in I2C communication, so unless the controller is upgraded to eg. ATmega32U4, the communication has to be done brute-force through some of the five unused GPIO pins.
