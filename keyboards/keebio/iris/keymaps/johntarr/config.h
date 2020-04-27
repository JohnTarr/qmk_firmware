// JNT 2020-04-26
// Processed after keebio/iris/rev4/config.h and /users/john/config.h
// This file is in addition to, not instead of
// Meaning anything they include that you don't want needs to be #undef

#pragma once

// JNT 2020-04-19 - selectively enabling animations to save space
// First need to undefine animations defined in keebio/iris/rev4/config.h
#undef RGBLIGHT_ANIMATIONS
// Now defining the animations I want to keep:
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_CHRISTMAS
// Animations I'm not keeping:
// #define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_EFFECT_SNAKE

// JNT 2020-04-19 - changes to "Knight Rider" effect
// Keeps it from using the back two leds on each half
#define RGBLIGHT_EFFECT_KNIGHT_LED_NUM 8
#define RGBLIGHT_EFFECT_KNIGHT_OFFSET 2

// JNT 2020--4-19 - Grave Escape Overrides for Ctrl+Shift+Esc & Cmd+Opt+Esc
#define GRAVE_ESC_CTRL_OVERRIDE
#define GRAVE_ESC_ALT_OVERRIDE
