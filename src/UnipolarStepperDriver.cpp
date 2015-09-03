#include "config.h"

#include <avr/io.h>

#include "Atmega168Utils.h"
#include "UnipolarStepperDriver.h"

UnipolarStepperDriver::UnipolarStepperDriver()
  : currentStep(0),
    running(false) {
}

UnipolarStepperDriver::~UnipolarStepperDriver() {
}

void UnipolarStepperDriver::step(bool clockwise) {
    if(clockwise) {
        currentStep++;
    } else {
        currentStep--;
    }

    // In case motor is already running, it has to move to new step immediately.
    if(running) {
        run();
    }
}

void UnipolarStepperDriver::run() {
    switch(currentStep % 4) {
    case 0:
        PORTC |= BV(PORTC0);
        return;
    case 1:
        PORTC |= BV(PORTC2);
        return;
    case 2:
        PORTC |= BV(PORTC1);
        return;
    case 3:
        PORTC |= BV(PORTC3);
        return;
    }
}

void UnipolarStepperDriver::rest() {
    PORTC &= ~BV(PORTC0) & ~BV(PORTC1) & ~BV(PORTC2) & ~BV(PORTC3);
}
