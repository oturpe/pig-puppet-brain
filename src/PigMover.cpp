#include "config.h"

#include <stdlib.h>
#include <util/delay.h>

#include "PigMover.h"

PigMover::PigMover(WheelController & legs, uint16_t transitionPeriod)
  : currentBehavior(SEARCH),
    currentMovement(WheelController::STOP),
    transitionPeriod(transitionPeriod),
    transitionCounter(0),
    counter(0),
    legs(legs) {
}

PigMover::~PigMover() {
}

void PigMover::run() {
    // Stop if still waiting in transition
    if(transitionCounter > 0) {
        legs.move(WheelController::STOP);
        transitionCounter--;
        return;
    }

    // Not in transition, use current movement
    legs.move(currentMovement);

    switch(currentBehavior) {
    case SEARCH:
        runSearch();
        break;
    case FIND_LINE_CW:
        runFindLine(WheelController::ROTATE_CW);
        break;
    case FIND_LINE_CCW:
        runFindLine(WheelController::ROTATE_CCW);
        break;
    case RETREAT:
        runRetreat();
        break;
    }

    counter++;
}

void PigMover::notify(Reading reading) {
    if(!reading.isValid())
        return;

    currentReading = reading;

    // Ran into pen limit while searching, but not aligned. Find line to get
    // ready for retreat.
    if(reading.left && !reading.right) {
        if (currentBehavior == SEARCH) {
            setBehavior(FIND_LINE_CCW);
        }

        return;
    }

    if(!reading.left && reading.right) {
        if (currentBehavior == SEARCH) {
            setBehavior(FIND_LINE_CW);
        }

        return;
    }

    // Found pen limit and is aligned. Retreat.
    if(reading.left && reading.right) {
        if(currentBehavior == SEARCH ||
           currentBehavior == FIND_LINE_CW ||
           currentBehavior == FIND_LINE_CCW) {
            setBehavior(RETREAT);
        }

        return;
    }

    // Was looking for pen limit, but somehow lost it. Get back to searching
    // again.
    if(!reading.left && !reading.right) {
        if(currentBehavior == FIND_LINE_CW ||
           currentBehavior == FIND_LINE_CCW) {
            setBehavior(SEARCH);
        }

        return;
    }
}

void PigMover::runSearch() {
    // TODO: Is there a better way?
    static uint8_t searchCounter = 0;

    // Still running current behavior
    if(counter % LEG_SEARCH_PERIOD)
        return;

    switch(searchCounter % 6) {
    case 0:
        if(rand() % 2) {
            setMovement(WheelController::ROTATE_CW);
        } else {
            setMovement(WheelController::ROTATE_CCW);
        }
        break;
    case 1:
        // Keep rotating to the same direction
        break;
    case 2:
        setMovement(WheelController::FORWARD);
        break;
    case 3:
        setMovement(WheelController::STOP);
        break;
    case 4:
        setMovement(WheelController::FORWARD);
        break;
    case 5:
        setMovement(WheelController::STOP);
        break;
    }

    searchCounter++;
}

void PigMover::runFindLine(WheelController::Movement rotation) {
    static uint8_t findLineCounter = 0;

    if(counter % LEG_FIND_LINE_PERIOD)
        return;

    switch(findLineCounter % 3) {
    case 0:
        setMovement(rotation);
        break;
    case 1:
    case 2:
        setMovement(WheelController::STOP);
        break;
    }

    findLineCounter++;
}

void PigMover::runRetreat() {
    // TODO: Is there a better way?
    static uint8_t retreatCounter = 0;

    // Still running current behavior
    if(counter % LEG_RETREAT_PERIOD)
        return;

    switch(retreatCounter % 2) {
    case 0:
        setMovement(WheelController::STOP);
        break;
    case 1:
        setMovement(WheelController::BACKWARD);
        break;
    }

    // Retreat only for a set time
    if(retreatCounter % 6 == 0) {
        setBehavior(SEARCH);
    }

    retreatCounter++;
}

void PigMover::setMovement(WheelController::Movement movement) {
    if(currentMovement == movement)
        return;

    transitionCounter = transitionPeriod;
    currentMovement = movement;
}

void PigMover::setBehavior(Behavior behavior) {
    if(currentBehavior == behavior)
        return;

    counter = 0;
    transitionCounter = transitionPeriod;
    currentBehavior = behavior;
}