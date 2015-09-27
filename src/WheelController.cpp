#include <avr/io.h>

#include "Atmega168Utils.h"

#include "WheelController.h"

WheelController::WheelController(uint8_t power) : power(power) {
}

WheelController::~WheelController() {
}

void WheelController::move(Movement movement) {
    switch(movement) {
    case FORWARD:
        leftWheelForward();
        rightWheelForward();
        return;
    case BACKWARD:
        leftWheelBackward();
        rightWheelBackward();
        return;
    case ROTATE_CW:
        leftWheelForward();
        //rightWheelBackward();
        return;
    case ROTATE_CCW:
        //leftWheelBackward();
        rightWheelForward();
        return;
    case STOP:
        leftWheelStill();
        rightWheelStill();
        return;
    }
}

void WheelController::leftWheelForward() {
    // Set direction, run motor, set indicator
    PORTB |= BV(PORTB3);
    OCR1A = 0xff - power - 20; // -10 quick fix to get directional movement
    PORTB |= BV(PORTB0);
}

void WheelController::rightWheelForward() {
    // Set direction, run motor, set indicator
    PORTB |= BV(PORTB4);
    OCR1B = 0xff - power;
    PORTB |= BV(PORTB5);
}

void WheelController::leftWheelStill() {
    // Set default directions, top motors, set indicators
    PORTB &= ~BV(PORTB3);
    OCR1A = 0xff;
    PORTB &= ~BV(PORTB0);
}

void WheelController::rightWheelStill() {
    // Set default directions, top motors, set indicators
    PORTB &= ~BV(PORTB4);
    OCR1B = 0xff;
    PORTB &= ~BV(PORTB5);
}

void WheelController::leftWheelBackward() {
    // Set direction, run motor, set indicator
    PORTB &= ~BV(PORTB3);
    OCR1A = 0xff - power;
    PORTB |= BV(PORTB0);
}

void WheelController::rightWheelBackward() {
    // Set direction, run motor, set indicator
    PORTB &= ~BV(PORTB4);
    OCR1B = 0xff - power;
    PORTB |= BV(PORTB5);
}
