# Acacia keyboard

A custom built mechanical keyboard with just 38 keys plus two extra media keys.

![Top side](acacia-top.jpg)

![PCB side](acacia-bottom.jpg)

The [layout](acacia.pdf) uses three layers.  One for alphas, one for navigation/function keys, and one for symbols/numpad.

The thumb home keys double as layer switches and tab/space.  The lower thumb keys are one-shot shift keys.

The Escape key is a [Layer Lock](https://getreuer.info/posts/keyboards/layer-lock) on both upper layers, which eliminates the strain of holding down the thumb for prolonged navigation and number punching.  And it makes it possible to move one hand to a trackball while using the other hand for mouse buttons.

The lower home row (Z, X, C, V) doubles as modifiers (AltGr, GUI, Alt, Control), and these functions are mirrored on the other hand (M, comma, period, quote).  This mirroring of modifiers is carried through on both other layers.

If used on macOS, then the Control and GUI (Command) keys should be swapped at the OS level.

As seen on the picture, the current layout for the alphas is [Minimak-6](http://www.minimak.org/), and it works very well with the already relocated T and Y keys on Acacia.  It is pretty close to standard QWERTY, so changing between the two should not be a problem.

## Improvements

- Remove the now unused lower thumb keys.
- Adjust the thumb keys slightly to make sure that key caps of any reasonable size do not collide.  Also, the thumb home key could be a little less tilted, and the whole bock moved a little further towards the middle.
- Align Q and P keys with ring finger use (instead of pinky use), or simply tilt the pinky columns the same as the ring finger column.
- Include a trackball (as alluded to in the pictures).  Unfortunately the ATmega32U2 used in the build does not have built-in I2C communication, so unless the controller is upgraded to eg. ATmega32U4, the communication has to be done brute-force through some of the five unused GPIO pins.
- Make a proper (wooden?) case.
- Shielding for the PCB.
- Layer status output, eg. through LEDs.

## Alternatives

- After finishing the prototypes, I discovered this repo: https://github.com/AlaaSaadAbdo/battoota/

