//
// Created by USER on 04.04.2025.
//

#include "display_control.h"

#include <util/delay.h>

#include "twi_host.h"
#include "led_control.h"

#define DRIVER_ADDRESS 0x10

#define MAX_LINES_bm 0x5 << 3 // 5 Scan Lines
#define DATA_REFRESH_MODE_bm 0x0 << 1 // Mode 1
#define PWM_FREQ_bm 0x0 << 0 // 125kHz

uint8_t start(const uint16_t registerAddress, const uint8_t transferDirection) {
    const uint8_t registerAddressH = registerAddress >> 8 & 0b11;
    const uint8_t registerAddressL = registerAddress & 0xFF;

    if (!TWIHost::startWrite((DRIVER_ADDRESS << 2) | registerAddressH))
        return 0;
    if (!TWIHost::write(registerAddressL))
        return 0;

    return 1;
}

void Display::init() {
     bool success = start(0x001, TW_WRITE);
    // TWIHost::write(0x01);
    TWIHost::write(MAX_LINES_bm | DATA_REFRESH_MODE_bm | PWM_FREQ_bm);
    // TWIHost::stop();
    //
    // _delay_ms(1);

    start(0x103, TW_WRITE);
    TWIHost::write(0x80);

    start(0x103, TW_WRITE);
    // TWIHost::stop();
    //
    // _delay_ms(1);

    // start(0x000, TW_WRITE);
    // bool success = TWIHost::write(0x1);
    // TWIHost::stop();
    //
    // _delay_ms(1);

    // start(0x104, TW_WRITE);
    TWIHost::startRead(DRIVER_ADDRESS << 2 | 0x00);
    TWIHost::readNack() == 0x80;
    TWIHost::stop();

    // TWIHost::stop();
    //
    // _delay_ms(1);

    // start(0x200, TW_WRITE);
    // TWIHost::write(0xFF);
    // TWIHost::write(0xFF);
    // TWIHost::write(0xFF);
    // TWIHost::stop();


    if (success) {
        LEDControl::ledGreen();
        LEDControl::ledGreen();
        _delay_ms(500);
        LEDControl::ledOff();
        LEDControl::ledOff();
    } else {
        LEDControl::ledRed();
        LEDControl::ledRed();
        _delay_ms(500);
        LEDControl::ledOff();
        LEDControl::ledOff();
    }
}