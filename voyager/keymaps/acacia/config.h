/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#undef TAPPING_TERM
#define TAPPING_TERM 225

// Cancel one-shot after one and a half second
#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1500

#define PERMISSIVE_HOLD

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

// Smart caps lock cancels after 10 seconds.
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 10000

// Navigation layer lock cancels after 10 seconds.
#define LAYER_LOCK_IDLE_TIMEOUT 10000

#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 300000

#define USB_SUSPEND_WAKEUP_DELAY 0
#define LAYER_STATE_8BIT

#define RGB_MATRIX_STARTUP_SPD 60
