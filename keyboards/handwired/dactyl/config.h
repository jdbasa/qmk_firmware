#ifndef DACTYL_CONFIG_H
#define DACTYL_CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x1308
#define DEVICE_VER      0x0001
#define MANUFACTURER    Adereth
#define PRODUCT         Dactyl

#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROWS 6
#define MATRIX_COLS 12
#define COL_EXPANDED { true, true, true, true, true, true, false, false, false, false, false, false}
#define MATRIX_ONBOARD_ROW_PINS { F1, F0, F4, F5, F7, F6 }
#define MATRIX_ONBOARD_COL_PINS { 0, 0, 0, 0, 0, 0, B2, B1, B3, D2, D3, C6 }
#define EXPANDER_COL_REGISTER GPIOA
#define EXPANDER_ROW_REGISTER GPIOB
#define MATRIX_EXPANDER_COL_PINS {0, 1, 2, 3, 4, 5}
#define MATRIX_EXPANDER_ROW_PINS {0, 1, 2, 3, 4, 5}

#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_WHEEL_DELAY 0

#define COMBO_TERM 35
#define COMBO_MUST_TAP_PER_COMBO
#define DEBOUNCE 10
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY
#define USB_MAX_POWER_CONSUMPTION 500

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#endif
