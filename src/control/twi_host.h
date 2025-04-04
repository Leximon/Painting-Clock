#pragma once

#include <util/twi.h>

namespace TWIHost {
    
    void init(uint32_t sclClockFreq);

    void stop();

    uint8_t start(uint8_t address, uint8_t transferDirection);

    uint8_t repeatedStart(uint8_t address, uint8_t transferDirection);

    uint8_t write(uint8_t data);

    uint8_t readAck();

    uint8_t readNack();
    
}