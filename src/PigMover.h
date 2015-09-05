#ifndef PIG_MOVER_H_
#define PIG_MOVER_H_

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
    enum MovementType {
        SEARCH,
        FIND_LINE
    };

public:
    /// \brief
    ///    Initializes a new pig mover instance.
    ///
    /// \param legs
    ///    Leg controller to call
    PigMover(WheelController & legs);

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
    ///    Sets the current movement type. The new movement is initiated
    ///    instantly by calling run().
    void setMovementType(MovementType type);

private:
    // TODO: Document
    void runSearch();

    // TODO: Document
    void runFindLine();

private:
    /// Current movement type
    MovementType currentMovementType;

    /// How long the current movement has been going on.
    uint16_t counter;

    /// Leg controller to delegate the actual movements
    WheelController & legs;
};

#endif