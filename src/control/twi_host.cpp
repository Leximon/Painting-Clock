#include "twi_host.h"

#include <avr/io.h>

void TWIHost::init(uint32_t sclClockFreq) {
    TWI0.CTRLA = TWI_SDAHOLD_enum::TWI_SDAHOLD_300NS_gc; // set SDA hold time
    TWI0.MBAUD = (F_CPU / sclClockFreq - 16) / 2; // set baud rate
//    TWI0.MBAUD = (F_CPU / (2*sclClockFreq)) - (5 + (F_CPU * t_r)/2)
    TWI0.MCTRLA |= TWI_ENABLE_bm; // enable TWI Host
    TWI0.MSTATUS |= TWI_BUSSTATE_IDLE_gc; // set bus state to idle
}

uint8_t TWIHost::start(uint8_t address, uint8_t transferDirection) {
    TWI0.MADDR = (address << 1) + transferDirection; // send address
    while (!(TWI0.MSTATUS & TWI_WIF_bm)); // wait until the write interrupt flag is set

    if (TWI0.MSTATUS & TWI_RXACK_bm) {
        return 0; // fail
    }
    return 1;

//    // send start condition
//    TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN);
//    while  (!(TWCR & _BV(TWINT))); // wait until the interrupt flag has been set
//
//    if ((TWSR & 0xF8) != TW_START) {
//        TWCR = _BV(TWINT); // clear TWIMaster Interrupt Flag
//        return 0;
//    }
//
//    // send address
//    TWDR = (address << 1) + transferDirection;
//    TWCR = _BV(TWINT) | _BV(TWEN);
//    while (!(TWCR & _BV(TWINT))); // wait until the interrupt flag has been set
//
//    if (TW_STATUS != TW_MT_SLA_ACK && TW_STATUS != TW_MR_SLA_ACK) {
//        TWCR = _BV(TWINT); // clear TWIMaster Interrupt Flag
//        return 0;
//    }
//    return 1;
}

uint8_t TWIHost::repeatedStart(uint8_t address, uint8_t transferDirection) {
    return TWIHost::start(address, transferDirection);
}

void TWIHost::stop() {
    TWI0.MCTRLB = TWI_MCMD_STOP_gc; // send stop condition
}

uint8_t TWIHost::write(uint8_t data) {
    // send data
    TWDR = data;
    TWCR = _BV(TWINT) | _BV(TWEN);
    while(!(TWCR & _BV(TWINT))); // wait until the interrupt flag has been set

    if((TW_STATUS & 0xF8) != TW_MT_DATA_ACK) {
        TWCR = _BV(TWINT); // clear TWIMaster Interrupt Flag
        return 0;
    }
    return 1;
}

uint8_t TWIHost::readAck() {

}

uint8_t TWIHost::readNack() {
    
}