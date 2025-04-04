//
// Created by leximon on 03.04.2025.
//

#include "led_control.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "avr/delay.h"

#define T0H 2 // FCPU = 20MHz, T0H = 3us
#define T0L 6 // FCPU = 20MHz, T0L = 9us

#define T1H 4 // FCPU = 20MHz, T1H = 6us
#define T1L 4 // FCPU = 20MHz, T1L = 6us

#define LED_DAT_PORT PORTA
#define LED_DAT_PIN PIN2_bm

#define LED_COUNT 11
#define LED_BYTE_COUNT (LED_COUNT * 3)

static uint8_t leds[LED_BYTE_COUNT];

void LEDControl::init() {
    LED_DAT_PORT.DIRSET = LED_DAT_PIN;
    for (uint8_t i = 0; i < LED_BYTE_COUNT; i++) {
        leds[i] = 0x00;
    }
}

void LEDControl::ledGreen() {
    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T1H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T1L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);


    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);


    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);
}

void LEDControl::ledRed() {
    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);


    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T1H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T1L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);


    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);
}

void LEDControl::ledOff() {
    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);


    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);


    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);

    LED_DAT_PORT.OUTSET = LED_DAT_PIN;
    _delay_loop_1(T0H);
    LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
    _delay_loop_1(T0L);
}


void LEDControl::show() {

//    for (uint8_t byte : leds) {
//        for (int8_t bitIndex = 7; bitIndex >= 0; bitIndex--) {
//            if ((byte >> bitIndex) & 1) {
//                LED_DAT_PORT.OUTSET = LED_DAT_PIN;
//                _delay_loop_1(T1H);
//                LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
//                _delay_loop_1(T1L - 2);
//            } else {
//                LED_DAT_PORT.OUTSET = LED_DAT_PIN;
//                _delay_loop_1(T0H);
//                LED_DAT_PORT.OUTCLR = LED_DAT_PIN;
//                _delay_loop_1(T0L - 2);
//            }
//        }
//    }
}