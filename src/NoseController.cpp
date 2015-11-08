#include <avr/io.h>

#include "Atmega168Utils.h"

#include "NoseController.h"

NoseController::NoseController(uint16_t halfPeriod, uint8_t halfUpperPeriod)
  : sniffing(false),
    noseBack(false),
    upperCycleSleep(false),
    halfPeriod(halfPeriod),
    halfUpperPeriod(halfUpperPeriod) {
}

NoseController::~NoseController() {
}

void NoseController::start() {
    if(!sniffing) {
        counter = 0;
    }

    sniffing = true;
}

void NoseController::stop() {
    sniffing = false;
    PORTD &= ~BV(PORTD4);
}

void NoseController::run() {
    if(!sniffing) {
        return;
    }

    counter += 1;

    // Not all the time moving
    uint8_t superCounter = counter / (halfPeriod);
    if(superCounter % halfUpperPeriod == 0) {
        upperCycleSleep = !upperCycleSleep;
    }

    if (upperCycleSleep) {
        // Nose magnet off during upper cycle sleep
        PORTD &= ~BV(PORTD4);
    } else if(counter % halfPeriod == 0) {
        if (noseBack) {
            PORTD &= ~BV(PORTD4);
        } else {
            PORTD |= BV(PORTD4);
        }

        noseBack = !noseBack;
    }
}
