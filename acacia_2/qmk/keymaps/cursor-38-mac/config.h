/*
Copyright 2024 Jens Peter Secher <jpsecher@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define TAPPING_TERM 225
#define PERMISSIVE_HOLD
#define TAPPING_TOGGLE 2

// Cancel one-shot after one second
#define ONESHOT_TIMEOUT 1000

// Smart caps lock cancels after 10 seconds.
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 10000

#define WS2812_DI_PIN B5
#define RGBLED_NUM 6
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK

#define POINTING_DEVICE_ROTATION_90
