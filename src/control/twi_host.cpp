#include "twi_host.h"

#include <avr/io.h>

void TWIHost::init(uint32_t sclClockFreq) {
    TWI0.CTRLA = TWI_SDAHOLD_300NS_gc; // set SDA hold time
    TWI0.MBAUD = (F_CPU / sclClockFreq - 16) / 2; // set baud rate
//    TWI0.MBAUD = (F_CPU / (2*sclClockFreq)) - (5 + (F_CPU * t_r)/2)
    TWI0.MCTRLA |= TWI_ENABLE_bm | TWI_SMEN_bm; // enable TWI Host and Smart Mode
    TWI0.MSTATUS |= TWI_BUSSTATE_IDLE_gc; // set bus state to idle
}

uint8_t TWIHost::startWrite(uint8_t address) {
    TWI0.MADDR = (address << 1) | TW_WRITE; // send address
    while (!(TWI0.MSTATUS & TWI_WIF_bm)) {}// wait until the write interrupt flag is set

    if (TWI0.MSTATUS & TWI_RXACK_bm) {
        return 0; // fail
    }
    return 1;
}

uint8_t TWIHost::startRead(uint8_t address) {
    TWI0.MADDR = (address << 1) | TW_READ; // send address

    if (TWI0.MSTATUS & TWI_RXACK_bm) {
        return 0; // fail
    }
    return 1;
}

void TWIHost::stop() {
    TWI0.MCTRLB = TWI_MCMD_STOP_gc; // send stop condition
}

uint8_t TWIHost::write(uint8_t data) {
    TWI0.MDATA = data; // send data
    while (!(TWI0.MSTATUS & TWI_WIF_bm)) {}// wait until the write interrupt flag is set

    if (TWI0.MSTATUS & TWI_RXACK_bm) {
        return 0; // fail
    }
    return 1;
}

uint8_t TWIHost::readAck() {
    TWI0.MCTRLB = TWI_ACKACT_ACK_gc;
    while (!(TWI0.MSTATUS & TWI_RIF_bm)) {} // wait until the read interrupt flag is set

    return TWI0.MDATA; // read data and send ACK
}

uint8_t TWIHost::readNack() {
    TWI0.MCTRLB = TWI_ACKACT_NACK_gc;
    while (!(TWI0.MSTATUS & TWI_RIF_bm)) {} // wait until the read interrupt flag is set

    return TWI0.MDATA; // read data and send NACK
}