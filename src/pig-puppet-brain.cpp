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

/// Initializes analog to digital conversion by setting the reference and
/// prescaler.
void initializePwm() {

}

int main() {

    #ifdef DEBUG
        // Some debug stuff?
    #endif

    //initializeAdc();

    // Set output pins:
    //    PB1 (indicator)
    //    PC0..PC3 (left leg stepper)
    DDRB |= BV(DDB1);
    DDRC |= BV(DDC0) | BV(DDC1) | BV(DDC2) | BV(DDC3);
    DDRD |= BV(DDD6);

    // Non-inverting fast pwm mode of timer for outputs OC0A, OC0B
    // (the eyes)
    TCCR0A |= BV(WGM01) | BV(WGM00);
    TCCR0A |= BV(COM0A1);
    TCCR0A |= BV(COM0B1);
    Atmega168::setTimer0Prescaler(Atmega168::PSV_64);

    // Non-inverting fast pwm mode of timer for outputs OC1A, OC1B
    // (the leg motors)
    TCCR1A |= BV(WGM10);
    TCCR1B |= BV(WGM12);
    TCCR1A |= BV(COM1A1);
    TCCR1A |= BV(COM1B1);
    Atmega168::setTimer1Prescaler(Atmega168::PSV_256);

    // Set leg direction pins as output: PB3 (left), PB4 (right)
    DDRB |= BV(DDB3) | BV(DDB4);

    // Nose control pin PD 4as output
    DDRD |= BV(DDD4);

    uint16_t counter = 0;
    bool legsRunning = false;
    bool legsForward = false;
    bool noseActive = false;
    bool nosePulling = false;
    UnipolarStepperDriver tailDriver;
    bool tailClockwise = true;
    while(true) {

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
            if(legsRunning) {
                OCR0A = 0xff;
                OCR1A = 0xff;
            } else {
                OCR0A = 0xff - LEG_MOTOR_DUTY_CYCLE;
                OCR1A = 0xff - LEG_MOTOR_DUTY_CYCLE;
            }

            legsRunning = !legsRunning;
        }

        if(counter % LEG_DIRECTION_PERIOD == 0) {
            if(legsForward) {
                PORTB |= BV(PORTB3) | BV(PORTB4);
            } else {
                PORTB &= ~BV(PORTB3) & ~BV(PORTB4);
            }

            legsForward = !legsForward;
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
        }
        /* Stepper stuff
        PORTB |= BV(PORTB1);
        _delay_ms(MOTOR_DELAY);
        stepMotor(true);
        _delay_ms(MOTOR_DELAY);
        stepMotor(true);
        _delay_ms(MOTOR_DELAY);
        stepMotor(true);
        _delay_ms(MOTOR_DELAY);
        stepMotor(true);

        PORTB &= ~BV(PORTB1);
        _delay_ms(MOTOR_DELAY);
        stepMotor(true);
        _delay_ms(MOTOR_DELAY);
        stepMotor(true);
        _delay_ms(MOTOR_DELAY);
        stepMotor(true);
        _delay_ms(MOTOR_DELAY);
        stepMotor(true);
        */
    }
}
