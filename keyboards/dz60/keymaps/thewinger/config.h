#pragma once

// Turn off RGB/Underglow when computer goes to sleep
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP
#endif // RGBLIGHT_ENABLE

// Set Tap Dance timing
#ifdef TAP_DANCE_ENABLE
#define TAPPING_TERM 200
#endif