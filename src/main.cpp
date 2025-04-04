

#include <control/twi_host.h>

#include "control/led_control.h"
#include "control/display_control.h"
#include "avr/delay.h"
#include "avr/io.h"

#define SEG_DRIVER_ADDRESS 0x10 << 2

[[noreturn]] int main() {
    CCP = CCP_IOREG_gc; // enable protected register write
    CLKCTRL.MCLKCTRLB = 0; // disable main clock prescaler -> 20MHz
    CLKCTRL.MCLKLOCK = CLKCTRL_LOCKEN_bm; // lock oscillator registers


    TWIHost::init(100000);
    LEDControl::init();

    PORTA.DIRSET = PIN4_bm | PIN1_bm;
    PORTA.OUTSET = PIN4_bm; // set pin 4 high
    PORTA.OUTCLR = PIN1_bm; // set pin 1 low

    _delay_ms(1000);

    while (true) {
        Display::init();
        _delay_ms(1000);
    }
}