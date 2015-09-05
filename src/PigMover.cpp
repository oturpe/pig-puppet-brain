#include "config.h"

#include <util/delay.h>

#include "PigMover.h"

PigMover::PigMover(WheelController & legs)
 : currentMovementType(SEARCH),
   counter(0),
   legs(legs) {
}

PigMover::~PigMover() {
}

void PigMover::setMovementType(MovementType type) {
    currentMovementType = type;
    counter = 0;
    run();
}

void PigMover::run() {
    switch(currentMovementType) {
    case SEARCH:
        runSearch();
        break;
    case FIND_LINE:
        runFindLine();
        break;
    }

    counter++;
}

void PigMover::runSearch() {
    // TODO: Is there a better way?
    static uint8_t searchCounter = 0;

    // Still running current behavior
    if(counter % LEG_ACTIVATION_PERIOD)
        return;

    // Stop and cool down before changing movement.
    // TODO: Get rid of delay here, it stops the main loop
    legs.stop();
    _delay_ms(LOOP_DELAY*20);

    switch(searchCounter % 5) {
    case 0:
        legs.stop();
        break;
    case 1:
        legs.moveForward();
        break;
    case 2:
        // TESTING: Backwards only if sensor says so
        //legController.moveBackward();
        break;
    case 3:
        legs.rotateClockwise();
        break;
    case 4:
        legs.rotateCounterClockwise();
        break;
    }

    searchCounter++;
}

void PigMover::runFindLine() {
    //TODO
}