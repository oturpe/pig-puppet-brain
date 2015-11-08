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
    case AVOID_LINE:
        runAvoidLine();
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
        } else if (currentBehavior == RETREAT) {
            setBehavior(SEARCH);
        }

        return;
    }

    // Similar to the previous case
    if(!reading.left && reading.right) {
        if (currentBehavior == SEARCH) {
            setBehavior(FIND_LINE_CW);
        } else if (currentBehavior == RETREAT) {
            setBehavior(SEARCH);
        }

        return;
    }

    // Found pen limit and is aligned. Retreat.
    if(reading.left && reading.right) {
        if(currentBehavior == SEARCH ||
           currentBehavior == FIND_LINE_CW ||
           currentBehavior == FIND_LINE_CCW) {
            setBehavior(AVOID_LINE);
        }

        return;
    }

    if(!reading.left && !reading.right) {
        if(currentBehavior == FIND_LINE_CW ||
           currentBehavior == FIND_LINE_CCW) {
            // Was looking for pen limit, but somehow lost it. Get back to
            // searching again.
            setBehavior(SEARCH);
        } else if (currentBehavior == AVOID_LINE) {
            // Got clear of the line when trying to get out of it. Start
            // the actual retreat.
            setBehavior(RETREAT);
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
        // Sometimes stop. Otherwise, keep rotating to the same direction
        if(rand() % 2) {
            setMovement(WheelController::STOP);
        }
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

void PigMover::runAvoidLine() {
    // TODO: Is there a better way?
    static uint8_t avoidCounter = 0;

    // Still running current behavior
    if(counter % LEG_AVOID_PERIOD)
        return;

    switch(avoidCounter % 2) {
    case 0:
        setMovement(WheelController::STOP);
        break;
    case 1:
        setMovement(WheelController::BACKWARD);
        break;
    }

    // Avoidance goes on until the pig does not see the line.
    // Thus there is no terminating condition here. See notify()
    // function for this action.

    avoidCounter++;
}

void PigMover::runRetreat() {
    // TODO: Is there a better way?
    static uint8_t retreatCounter = 0;

    // Still running current behavior
    if(counter % LEG_RETREAT_PERIOD)
        return;

    switch(retreatCounter % 3) {
    case 0:
        setMovement(WheelController::STOP);
        break;
    case 1:
        setMovement(WheelController::BACKWARD);
        break;
    case 2:
        setMovement(WheelController::BACKWARD);
        break;
    }

    // Retreat only for a set time
    if(retreatCounter % 9 == 0) {
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