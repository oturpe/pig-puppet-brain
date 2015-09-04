#include <avr/io.h>

#include "Atmega168Utils.h"

#include "WheelController.h"

WheelController::WheelController(uint8_t power) : power(power) {
}

WheelController::~WheelController() {
}

void WheelController::moveForward() {
    leftWheelForward();
    rightWheelForward();
}

void WheelController::moveBackward() {
    leftWheelBackward();
    rightWheelBackward();
}

void WheelController::rotateClockwise() {
    leftWheelForward();
    rightWheelBackward();
}

void WheelController::rotateCounterClockwise() {
    leftWheelBackward();
    rightWheelForward();
}

void WheelController::stop() {
    // Set default directions, top motors, set indicators
    PORTB &= ~BV(PORTB3) & ~BV(PORTB4);
    OCR1A = 0xff;
    OCR1B = 0xff;
    PORTB &= ~BV(PORTB5) & ~BV(PORTB0);
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

void WheelController::leftWheelForward() {
    // Set direction, run motor, set indicator
    PORTB |= BV(PORTB3);
    OCR1A = 0xff - power;
    PORTB |= BV(PORTB0);
}

void WheelController::rightWheelForward() {
    // Set direction, run motor, set indicator
    PORTB |= BV(PORTB4);
    OCR1B = 0xff - power;
    PORTB |= BV(PORTB5);
}
