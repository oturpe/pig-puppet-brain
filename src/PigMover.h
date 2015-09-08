#ifndef PIG_MOVER_H_
#define PIG_MOVER_H_

#include "Reading.h"
#include "WheelController.h"

/// \class PigMover
///
/// Controls the movement of the pig by issuing commands to leg controller.
/// While the leg controller takes care of controlling actuatorsa and setting
/// indicators, this class contains the behavior of the pig.
///
/// This class expects to have the run() method called on regular intervals.
/// These calls provide the clock for the movements.
class PigMover {
public:
    /// \enum MovementType
    ///
    /// Different movement types the pig can have.
    enum Behavior {
        SEARCH,
        FIND_LINE_CW,
        FIND_LINE_CCW,
        RETREAT
    };

public:
    /// \brief
    ///    Initializes a new pig mover instance.
    ///
    /// \param legs
    ///    Leg controller to call
    PigMover(WheelController & legs, uint16_t transitionPeriod);

    /// \brief
    ///    Destoys this pig mover instance.
    ~PigMover();

public:
    /// \brief
    ///    Runs the pig using current movement type and increments the counter.
    ///
    /// Exact behavior of this call depends on current movement type as set by
    /// calling setMovementType(MovementType.
    void run();

    /// \brief
    ///    Notifies this pig mover about sensor readings. The mover
    ///    reacts by setting itself ready for approriate kind of action. The
    ///    change takes effect starting from next call to run() method.
    ///
    /// \param event
    ///    The event to notify
    void notify(Reading reading);

private:
    /// \brief
    ///    Proceeds one step in the search routine
    void runSearch();

    /// \brief
    ///    Proceeds one step in the line finding routine
    ///
    /// \param rotation
    ///    Which way to rotate to find the line
    void runFindLine(WheelController::Movement rotation);

    /// \brief
    ///    Proceeds one step in the retreat routine
    void runRetreat();

    /// \brief
    ///    Sets a new movement as current and resets transition counter. The new
    ///    movement starts when sufficient amount of call to run() have been
    ///    made to deplete the transition counter. If the new movement is the
    ///    same as the current one, this method does nothing.
    void setMovement(WheelController::Movement movement);

    /// \brief
    ///    Sets a new behavior and resets behavior and transition counters. The
    /// new behavior starts when run() is next called, the first action being
    /// waiting for transition.
    void setBehavior(Behavior behavior);

private:
    /// Transition period
    const uint16_t transitionPeriod;

    /// Leg controller to delegate the actual movements
    WheelController & legs;

    /// Current behavior
    Behavior currentBehavior;

    /// Current movement type
    WheelController::Movement currentMovement;

    /// Current sensor reading
    Reading currentReading;

    /// Remaining wait time between changing movement types
    uint16_t transitionCounter;

    /// How long the current movement has been going on.
    uint16_t counter;
};

#endif