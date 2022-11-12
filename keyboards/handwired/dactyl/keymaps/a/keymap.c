#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYM  1 // symbols
#define NAV  2 // navigation
#define MOU  3 // mouse

enum combos {
  AL_ESC,
  ASDF_CMOPSH,
  BE_ENT,
  BK_ENT,
  DF_CMSH,
  JK_CMSH,
  JKL_CMOP,
  JKLS_CMOPSH,
  SD_ESC,
  SDF_CMOP,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

enum custom_keycodes {
  TAB_CMD = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Sleep |ZmMute| Back |Forwrd| WinL | WinR |                    | Prev | Play | Next | SS 5 | SS C | SS D |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Tab/TC|A/Ctrl|S/Mh Esc D/Cm| F/Opt|   G  |                    |   H  |J/Opt | K/Cm | L/Mh |;/Ctrl|  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Undo |   Z  |   X  |   C  |   V  |   B  |                    |   N  |   M  |   ,  |   .  |  /   | Redo |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |SpaceL|SpaceR| Mute |VolDwn|VolUp |                                  |  Cut | Copy |Paste |ScrnL |ScrnR |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      | Back | Max  |  |Delete|Forwrd|
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |Center|  | Caps |      |Back  |
 *                               |Space |Shift |------|  |------|  L1  |space/|
 *                               |      |      |  L1  |  |Spa/Sh|      |  L2  |
 *                               `--------------------'  `--------------------'
 */
[BASE] = LAYOUT_dactyl(
       // left hand
       LAG(KC_PWR),   SCMD(KC_A),    LCMD(KC_LBRC), LCMD(KC_RBRC), LAG(KC_LEFT), LAG(KC_RGHT),
       KC_GRV,        KC_Q,          KC_W,          KC_E,          KC_R,         KC_T,
       TAB_CMD,       LCTL_T(KC_A),  MEH_T(KC_S),   LCMD_T(KC_D),  LOPT_T(KC_F), KC_G,
       LCMD(KC_Z),    KC_Z,          KC_X,          KC_C,          KC_V,         KC_B,
       HYPR(KC_LEFT), HYPR(KC_RGHT), KC_MUTE,       KC_VOLD,       KC_VOLU,
                                                                                 SCMD(KC_LBRC), LAG(KC_F),
                                                                                                LAG(KC_C),
                                                                         KC_SPC, OSM(MOD_LSFT), TG(SYM),
       // right hand
                       KC_MPRV,       KC_MPLY,      KC_MNXT,      SCMD(KC_5),  SCMD(LCTL(KC_4)), SCMD(KC_4),
                       KC_Y,          KC_U,         KC_I,         KC_O,        KC_P,             KC_BSLS,
                       KC_H,          ROPT_T(KC_J), RCMD_T(KC_K), MEH_T(KC_L), RCTL_T(KC_SCLN),  KC_QUOT,
                       KC_N,          KC_M,         KC_COMM,      KC_DOT,      KC_SLSH,          SCMD(KC_Z),
                                      LCMD(KC_X),   LCMD(KC_C),   LCMD(KC_V),  MEH(KC_LEFT),     MEH(KC_RGHT),
       KC_DEL,         SCMD(KC_RBRC),
       KC_CAPS,
       LSFT_T(KC_SPC), OSL(SYM),      LT(NAV, KC_BSPC)
),
/* Keymap 1: Symbol Layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   '  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   :  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ,  |   !  |   @  |   (  |   )  |   ~  |                    |   +  |   -  |   =  |   _  |   $  |   .  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   |  |   &  |   {  |   }  |   %  |                    |   ^  |   [  |   ]  |   *  |   #  |   /  |
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
      KC_QUOT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
      KC_COMM, KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_TILD,
      _______, KC_PIPE, KC_AMPR, KC_LCBR, KC_RCBR, KC_PERC,
      _______, _______, _______, _______, _______,
                                                   _______, _______,
                                                            _______,
                                          _______, _______, _______,
      // right hand
               _______, _______, _______, _______, _______, _______,
               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COLN,
               KC_PLUS, KC_MINS, KC_EQL,  KC_UNDS, KC_DLR,  KC_DOT,
               KC_CIRC, KC_LBRC, KC_RBRC, KC_ASTR, KC_HASH, KC_SLSH,
                        _______, _______, _______, _______, _______,
      _______, _______,
      _______,
      _______, _______, _______
),
/* Keymap 2: Navigation Layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |L+Cm+S|L+Op+S|R+Op+S|R+Cm+S|                    | Left | Down |  Up  |Right |  L3  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |Lt+Cmd|Lt+Opt|Rt+Opt|Rt+Cmd|      |      |
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
[NAV] = LAYOUT_dactyl(
      // left hand
      _______, _______, _______,       _______,      _______,      _______,
      _______, _______, _______,       _______,      _______,      _______,
      _______, _______, SCMD(KC_LEFT), LSA(KC_LEFT), LSA(KC_RGHT), SCMD(KC_RGHT),
      _______, _______, _______,       _______,      _______,      _______,
      _______, _______, _______,       _______,      _______,
                                                                   _______, _______,
                                                                            _______,
                                                          _______, _______, _______,
      // right hand
               _______,       _______,       _______,       _______,       _______, _______,
               _______,       _______,       _______,       _______,       _______, _______,
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
 * |      |      | Cmd  | M Up |Shift |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |M Left|M Dwn | M Rt |      |                    |      |Accel0|Accel1|Accel2|  L0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |ScrllU|ScrllD|      |                    |      |LClick|RClick|MClick|      |      |
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
      _______, _______, KC_LCMD, KC_MS_U, KC_LSFT, _______,
      _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
      _______, _______, _______, KC_WH_U, KC_WH_D, _______,
      _______, _______, _______, _______, _______,
                                                   _______, _______,
                                                            _______,
                                          _______, _______, _______,
      // right hand
               _______, _______, _______, _______, _______,  _______,
               _______, _______, _______, _______, _______,  _______,
               _______, KC_ACL0, KC_ACL1, KC_ACL2, TO(BASE), _______,
               _______, KC_BTN1, KC_BTN2, KC_BTN3, _______,  _______,
                        _______, _______, _______, _______,  _______,
      _______, _______,
      _______,
      _______, _______, _______
),
};

const uint16_t PROGMEM al_combo[] = {KC_AT, KC_LPRN, COMBO_END};
const uint16_t PROGMEM asdf_combo[] = {LCTL_T(KC_A), MEH_T(KC_S), LCMD_T(KC_D), LOPT_T(KC_F), COMBO_END};
const uint16_t PROGMEM be_combo[] = {LT(NAV, KC_BSPC), KC_EQL, COMBO_END};
const uint16_t PROGMEM bk_combo[] = {LT(NAV, KC_BSPC), RCMD_T(KC_K), COMBO_END};
const uint16_t PROGMEM df_combo[] = {LCMD_T(KC_D), LOPT_T(KC_F), COMBO_END};
const uint16_t PROGMEM jk_combo[] = {ROPT_T(KC_J), RCMD_T(KC_K), COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {ROPT_T(KC_J), RCMD_T(KC_K), MEH_T(KC_L), COMBO_END};
const uint16_t PROGMEM jkls_combo[] = {ROPT_T(KC_J), RCMD_T(KC_K), MEH_T(KC_L), RCTL_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM sd_combo[] = {MEH_T(KC_S), LCMD_T(KC_D), COMBO_END};
const uint16_t PROGMEM sdf_combo[] = {MEH_T(KC_S), LCMD_T(KC_D), LOPT_T(KC_F), COMBO_END};

combo_t key_combos[] = {
  [AL_ESC] = COMBO(al_combo, KC_ESC),
  [ASDF_CMOPSH] = COMBO(asdf_combo, LAG(KC_LSFT)),
  [BE_ENT] = COMBO(be_combo, KC_ENT),
  [BK_ENT] = COMBO(bk_combo, KC_ENT),
  [DF_CMSH] = COMBO(df_combo, LCMD(KC_LSFT)),
  [JK_CMSH] = COMBO(jk_combo, RCMD(KC_RSFT)),
  [JKL_CMOP] = COMBO(jkl_combo, RCMD(KC_ROPT)),
  [JKLS_CMOPSH] = COMBO(jkls_combo, RAG(KC_RSFT)),
  [SD_ESC] = COMBO(sd_combo, KC_ESC),
  [SDF_CMOP] = COMBO(sdf_combo, LCMD(KC_LOPT)),
};

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
  switch (index) {
    case ASDF_CMOPSH:
    case DF_CMSH:
    case JK_CMSH:
    case JKL_CMOP:
    case JKLS_CMOPSH:
    case SDF_CMOP:
      return true;
    default:
      return false;
  }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  switch (index) {
    case AL_ESC:
    case BE_ENT:
    case BK_ENT:
    case SD_ESC:
      return true;
    default:
      return false;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(NAV, KC_BSPC):
      return TAPPING_TERM - 42;
    default:
      return TAPPING_TERM;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t timer;
  switch (keycode) {
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
