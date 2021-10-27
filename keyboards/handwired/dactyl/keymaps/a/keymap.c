#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYM  1 // symbols
#define NUM  2 // numbers
#define MOU  3 // mouse

enum combos {
  KL_ENT,
  LS_BASE,
  SD_NUM,
  UR_ENT,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

enum custom_keycodes {
  SLEEP = SAFE_RANGE,
  TAB_CMD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Sleep |CapsLk| Back |Forwrd| WinL | WinR |                    | Prev | Play | Next | Mute |VolDwn|VolUp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Tab/TC|   A  |S/Meh L2 D/Cm| F/Opt|   G  |                    |   H  |J/Opt |K/Cm Ent L/Mh|;/Ctrl|  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Undo |   Z  |   X  |   C  |   V  |   B  |                    |   N  |   M  |   ,  |   .  |  /   | Redo |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |SpaceL|SpaceR| SS D | SS 5 | SS C |                                  |  Cut | Copy |Paste |ScrnL |ScrnR |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      | Back | Max  |  |Spa/Sh|Forwrd|
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |Center|  |Cmd+Sh|      |Back  |
 *                               |Space |Shift |------|  |------|  L1  |space/|
 *                               |      |      | Esc  |  |Delete|      |  L2  |
 *                               `--------------------'  `--------------------'
 */
[BASE] = LAYOUT_dactyl(
       // left hand
       SLEEP,         KC_CAPS,       LCMD(KC_LBRC), LCMD(KC_RBRC), LAG(KC_LEFT),     LAG(KC_RGHT),
       KC_GRV,        KC_Q,          KC_W,          KC_E,          KC_R,             KC_T,
       TAB_CMD,       KC_A,          MEH_T(KC_S),   LCMD_T(KC_D),  LOPT_T(KC_F),     KC_G,
       LCMD(KC_Z),    KC_Z,          KC_X,          KC_C,          KC_V,             KC_B,
       HYPR(KC_LEFT), HYPR(KC_RGHT), SCMD(KC_4),    SCMD(KC_5),    SCMD(LCTL(KC_4)),
                                                                                     SCMD(KC_LBRC), LAG(KC_F),
                                                                                                    LAG(KC_C),
                                                                             KC_SPC, OSM(MOD_LSFT), KC_ESC,
       // right hand
                                 KC_MPRV,       KC_MPLY,      KC_MNXT,      KC_MUTE,     KC_VOLD,         KC_VOLU,
                                 KC_Y,          KC_U,         KC_I,         KC_O,        KC_P,            KC_BSLS,
                                 KC_H,          ROPT_T(KC_J), RCMD_T(KC_K), MEH_T(KC_L), LCTL_T(KC_SCLN), KC_QUOT,
                                 KC_N,          KC_M,         KC_COMM,      KC_DOT,      KC_SLSH,         SCMD(KC_Z),
                                                LCMD(KC_X),   LCMD(KC_C),   LCMD(KC_V),  MEH(KC_LEFT),    MEH(KC_RGHT),
       LSFT_T(KC_SPC),           SCMD(KC_RBRC),
       OSM(MOD_LGUI | MOD_LSFT),
       KC_DEL,                   OSL(SYM), LT(NUM, KC_BSPC)
),
/* Keymap 1: Symbol Layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   (  |   )  |   ~  |                    |   +  |   -  |   =  |   _  |   $  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   |  |   &  |   {  |   }  |   %  |                    |   ^  |   [  |   ]  |   *  |   #  |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |      |      |      |      |      |                                  |      |      |      |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |------|  |------|      |      |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
[SYM] = LAYOUT_dactyl(
      // left hand
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_TILD,
      _______, KC_PIPE, KC_AMPR, KC_LCBR, KC_RCBR, KC_PERC,
      _______, _______, _______, _______, _______,
                                                   _______, _______,
                                                            _______,
                                          _______, _______, _______,
      // right hand
               _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______,
               KC_PLUS, KC_MINS, KC_EQL,  KC_UNDS, KC_DLR,  _______,
               KC_CIRC, KC_LBRC, KC_RBRC, KC_ASTR, KC_HASH, _______,
                        _______, _______, _______, _______, _______,
      _______, _______,
      _______,
      _______, _______, _______
),
/* Keymap 2: Number Layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |LCmdS L0 LOpS|R+Op+S|R+Cm+S|                    | Left | Down |  Up Ent Rght|  L3  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | F14  | F13  |Shift |      |                    |Lt+Cmd|Lt+Opt|Rt+Opt|Rt+Cmd|      |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |      |      |      |      |      |                                  |      |      |      |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |------|  |------|      |      |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
[NUM] = LAYOUT_dactyl(
      // left hand
      _______, _______, _______,       _______,      _______,      _______,
      _______, KC_1,    KC_2,          KC_3,         KC_4,         KC_5,
      _______, _______, SCMD(KC_LEFT), LSA(KC_LEFT), LSA(KC_RGHT), SCMD(KC_RGHT),
      _______, _______, KC_F14,        KC_F13,       KC_LSFT,      _______,
      _______, _______, _______,       _______,      _______,
                                                                   _______, _______,
                                                                            _______,
                                                          _______, _______, _______,
      // right hand
               _______,       _______,       _______,       _______,       _______, _______,
               KC_6,          KC_7,          KC_8,          KC_9,          KC_0,    _______,
               KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       TO(MOU), _______,
               LCMD(KC_LEFT), LOPT(KC_LEFT), LOPT(KC_RGHT), LCMD(KC_RGHT), _______, _______,
                              _______,       _______,       _______,       _______, _______,
      _______, _______,
      _______,
      _______, _______, _______
),
/* Keymap 3: Mouse Layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Reset |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | M Up |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |M Left|M Dwn | M Rt |      |                    |ScrllL|ScrllD|ScrllU|ScrllR|  L0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | Cmd  |Shift |      |                    |      |LClick|RClick|MClick|      |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |      |      |      |      |      |                                  |      |      |      |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |------|  |------|      |      |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
[MOU] = LAYOUT_dactyl(
      // left hand
      RESET,   _______, _______, _______, _______, _______,
      _______, _______, _______, KC_MS_U, _______, _______,
      _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
      _______, _______, _______, KC_LCMD, KC_LSFT, _______,
      _______, _______, _______, _______, _______,
                                                   _______, _______,
                                                            _______,
                                          _______, _______, _______,
      // right hand
               _______, _______, _______, _______, _______,  _______,
               _______, _______, _______, _______, _______,  _______,
               KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, TO(BASE), _______,
               _______, KC_BTN1, KC_BTN2, KC_BTN3, _______,  _______,
                        _______, _______, _______, _______,  _______,
      _______, _______,
      _______,
      _______, _______, _______
),
};

const uint16_t PROGMEM kl_combo[] = {RCMD_T(KC_K), MEH_T(KC_L), COMBO_END};
const uint16_t PROGMEM ls_combo[] = {SCMD(KC_LEFT), LSA(KC_LEFT), COMBO_END};
const uint16_t PROGMEM sd_combo[] = {MEH_T(KC_S), LCMD_T(KC_D), COMBO_END};
const uint16_t PROGMEM ur_combo[] = {KC_UP, KC_RGHT, COMBO_END};

combo_t key_combos[] = {
  [KL_ENT] = COMBO(kl_combo, KC_ENT),
  [LS_BASE] = COMBO_ACTION(ls_combo),
  [SD_NUM] = COMBO_ACTION(sd_combo),
  [UR_ENT] = COMBO(ur_combo, KC_ENT)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case LS_BASE:
      if (pressed) {
        layer_off(NUM);
      }
      break;
    case SD_NUM:
      if (pressed) {
        layer_on(NUM);
      }
      break;
  }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(NUM, KC_BSPC):
      return TAPPING_TERM - 42;
    default:
      return TAPPING_TERM;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t timer;
  switch (keycode) {
    case SLEEP:
      if (record->event.pressed) {
        tap_code16(LCTL(LCMD(KC_Q)));
        wait_ms(400);
        tap_code(KC_ESC);
      }
      break;
    case TAB_CMD:
      if (record->event.pressed) {
        timer = timer_read();
      } else {
        if (timer_elapsed(timer) < 140) {
          tap_code(KC_TAB);
        } else {
          tap_code16(LCMD(KC_TAB));
        }
      }
      return false;
  }
  return true;
}
