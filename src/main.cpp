

#include "control/led_control.h"
#include "avr/delay.h"
#include "avr/io.h"

int main() {
    CCP = CCP_IOREG_gc; // enable protected register write
    CLKCTRL.MCLKCTRLB = 0; // disable main clock prescaler -> 20MHz
    CLKCTRL.MCLKLOCK = CLKCTRL_LOCKEN_bm; // lock oscillator registers


    LEDControl::init();


//    PORTA.DIRSET = PIN2_bm;



    while (true) {
        _delay_ms(1);
        LEDControl::show();
//        PORTA.OUTTGL = PIN2_bm;
    }
}