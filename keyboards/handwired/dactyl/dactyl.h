#ifndef DACTYL_H
#define DACTYL_H

#include "quantum.h"
#include <stdint.h>
#include <stdbool.h>
#include "i2cmaster.h"
#include <util/delay.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00

#define I2C_ADDR        0b0100000
#define I2C_ADDR_WRITE  ( (I2C_ADDR<<1) | I2C_WRITE )
#define I2C_ADDR_READ   ( (I2C_ADDR<<1) | I2C_READ  )
#define IODIRA          0x00            // i/o direction register
#define IODIRB          0x01
#define GPPUA           0x0C            // GPIO pull-up resistor register
#define GPPUB           0x0D
#define GPIOA           0x12            // general purpose i/o port register (write modifies OLAT)
#define GPIOB           0x13
#define OLATA           0x14            // output latch register
#define OLATB           0x15

extern uint8_t expander_status;
extern uint8_t expander_input_pin_mask;
extern bool i2c_initialized;

void init_dactyl(void);
void init_expander(void);

/*
 *   LEFT HAND: LINES 38-45
 *  RIGHT HAND: LINES 47-54
 */
#define LAYOUT_dactyl(                                                  \
                                                                        \
    k00,k01,k02,k03,k04,k05,                                            \
    k10,k11,k12,k13,k14,k15,                                            \
    k20,k21,k22,k23,k24,k25,                                            \
    k30,k31,k32,k33,k34,k35,                                            \
    k40,k41,k42,k43,k44,                                                \
                            k55,k54,                                    \
                                k53,                                    \
                        k52,k51,k50,                                    \
                                                                        \
            k06,k07,k08,k09,k0A,k0B,                                    \
            k16,k17,k18,k19,k1A,k1B,                                    \
            k26,k27,k28,k29,k2A,k2B,                                    \
            k36,k37,k38,k39,k3A,k3B,                                    \
                k47,k48,k49,k4A,k4B,                                    \
    k57,k56,                                                            \
    k58,                                                                \
    k5B,k5A,k59 )                                                       \
                                                                        \
   /* matrix positions */                                               \
   {                                                                    \
    { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
    { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
    { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
    { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
    { k40, k41, k42, k43, k44, KC_NO, KC_NO, k47, k48, k49, k4A, k4B }, \
    { k50, k51, k52, k53, k54, k55,     k56, k57, k58, k59, k5A, k5B }, \
   }


#endif
