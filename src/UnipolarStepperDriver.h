#ifndef UNIPOLAR_STEPPER_DRIVER_H
#define UNIPOLAR_STEPPER_DRIVER_H

/// \class UnipolarStepperDriver
///
/// Driver unipolar stepper motor in two directions. This controller does assume
/// any responsibility on timing. All instructions to step at certain moment and
/// to run or rest the motor have to be given from outside.
class UnipolarStepperDriver {

public:
    /// \brief
    ///    Creates and initializes a new unipolar stepper driver instance.
    ///
    /// The motor is initialized not running. Pins used are PC0 ... PC3.
    UnipolarStepperDriver();

    /// \brief
    ///    Destroys this unipolar stepper instance.
    ~UnipolarStepperDriver();
public:
    /// \brief
    ///    Àdvances the motor position by one step. Direction of the step is given
    ///    as input.
    ///
    /// If the motor is already running, the change takes effect immediately.
    /// Otherwise, it takes effect the next time motor is run.
    ///
    /// \param clockwise
    ///    If motor steps clockwise
    void step(bool clockwise);

    /// \brief
    ///    Run stepper motor using the current step.
    void run();

    /// \brief
    ///    Rests the stepper motor. All outputs are disabled.
    void rest();

private:
    /// Current position of the motor
    uint8_t currentStep;
    /// If the motor is currently running
    bool running;
};

#endif