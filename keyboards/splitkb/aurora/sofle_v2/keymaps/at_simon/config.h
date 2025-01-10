/* Copyright 2024 at-simon
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// not needed rgb effects
// #define RGB_DISABLE_WHEN_USB_SUSPENDED
// #define RGB_MATRIX_KEYPRESSES
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #define ENABLE_RGB_MATRIX_SOLID_SPLASH
// #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT

// disabling oled display
// #undef OLED_ENABLE
// #define OLED_ENABLE = no

// disabling encoder
#undef ENCODER_ENABLE
#define ENCODER_ENABLE = no

// Liatris onboard rgb
// https://docs.splitkb.com/product-guides/liatris/onboard-rgb
#undef WS2812_DI_PIN
#define WS2812_DI_PIN 25
// #undef RGBLED_NUM
// #define RGBLED_NUM 2
#undef RGBLED_SPLIT
#define RGBLED_SPLIT {1, 1}
