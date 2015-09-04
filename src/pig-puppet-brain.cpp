// Controller for pig puppet/robot. The puppet walks around on wheels and
// makes various body movements.
//
// Author: Otto Urpelainen
// Email: oturpe@iki.fi
// Created on: 2015-08-26

#include "config.h"

#include "Atmega168Utils.h"
#include <avr/io.h>
#include <util/delay.h>

#include "UnipolarStepperDriver.h"
#include "WheelController.h"

/// Initializes analog to digital conversion by setting the reference and
/// prescaler.
void initializePwm() {

}

/// \brief
///    Changes the power indicator led state between on and off.
inline void flipPowerIndicator() {
    static bool lit;

    if(lit) {
        PORTB |= BV(PB6);
    } else {
        PORTB &= ~BV(PB6);
    }

    lit = !lit;
}

/// \brief
///    Changes the tail movement direction indicator led state between on and
///    off.
inline void flipTailIndicator() {
    static bool lit;

    if(lit) {
        PORTC |= BV(PC4);
    } else {
        PORTC &= ~BV(PC4);
    }

    lit = !lit;
}

int main() {

    #ifdef DEBUG
        // Some debug stuff?
    #endif

    //initializeAdc();

    // Set power indicator output pin PB6
    DDRB |= BV(DDB6);

    // Set tail output pins: motor PC0..PC3 and direction indicator PC4
    DDRC |= BV(DDC0) | BV(DDC1) | BV(DDC2) | BV(DDC3) | BV(DDC4);

    // Eye output pins PD5 (left) and  PD6 (right)
    DDRD |= BV(DDD5) | BV(DDD6);

    // Non-inverting fast pwm mode of timer for outputs OC0A, OC0B
    // (the eyes)
    TCCR0A |= BV(WGM01) | BV(WGM00);
    TCCR0A |= BV(COM0A1);
    TCCR0A |= BV(COM0B1);
    Atmega168::setTimer0Prescaler(Atmega168::PSV_64);

    // Non-inverting fast pwm mode of timer for outputs OC1A, OC1B
    // (the leg motors). Start with no movement.
    OCR1A = 0xff;
    OCR1B = 0xff;
    TCCR1A |= BV(WGM10);
    TCCR1B |= BV(WGM12);
    TCCR1A |= BV(COM1A1);
    TCCR1A |= BV(COM1B1);
    Atmega168::setTimer1Prescaler(Atmega168::PSV_256);

    // Set leg direction pins as output:
    // PB1, PB2 (left and right leg motors)
    // PB3, PB4 (left and right leg direction)
    // PB0, PB5 (left and right leg indicators)
    DDRB |= BV(DDB0) | BV(DDB1) | BV(DDB2) | BV(DDB3) | BV(DDB4) | BV(DDB5);

    WheelController legController(LEG_MOTOR_DUTY_CYCLE);

    // Nose control pin PD4 as output
    DDRD |= BV(DDD4);

    uint16_t counter = 0;
    bool legsRunning = false;
    bool legsForward = false;
    uint8_t legCounter = 0;
    bool noseActive = false;
    bool nosePulling = false;
    UnipolarStepperDriver tailDriver;
    bool tailClockwise = true;
    while(true) {

        if(counter % INDICATOR_HALF_PERIOD == 0) {
            // Indicator flashes when the power is on
            flipPowerIndicator();
        }

        if(counter % NOSE_ACTIVATION_PERIOD == 0) {
            noseActive = !noseActive;
        }

        if(noseActive && (counter % NOSE_HALF_PERIOD == 0)) {
            if (nosePulling) {
                PORTD &= ~BV(PORTD4);
            } else {
                PORTD |= BV(PORTD4);
            }

            nosePulling = !nosePulling;
        }

        if(counter % LEG_ACTIVATION_PERIOD == 0) {
            // Stop and cool down before changing movement.
            legController.stop();
            _delay_ms(LOOP_DELAY*20);
            switch(legCounter % 5) {
            case 0:
                legController.stop();
                break;
            case 1:
                legController.moveForward();
                break;
            case 2:
                legController.moveBackward();
                break;
            case 3:
                legController.rotateClockwise();
                break;
            case 4:
                legController.rotateCounterClockwise();
                break;
            }

            legCounter++;
        }

        counter++;
        _delay_ms(LOOP_DELAY);

        // Run tail stepper ¼ of time.
        if(counter % 4 == 0) {
            tailDriver.run();
        } else {
            tailDriver.rest();
        }

        if(counter % TAIL_STEP_PERIOD == 0) {
            tailDriver.step(tailClockwise);
        }

        if(counter % (TAIL_CHANGE_PERIOD*TAIL_STEP_PERIOD) == 0) {
            tailClockwise = !tailClockwise;
            flipTailIndicator();
        }
    }
}
