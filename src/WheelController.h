#ifndef WHEELCONTROLLER_H_
#define WHEELCONTROLLER_H_

/// \class WheelController
///
/// Controls two parallel motors connected to wheels for forward, backward and
/// rotational movement. Control is done by two pwm outputs for running the
/// motors, two digital outputs for selecting direction via form 2C relays, and
/// two indicator pins for running of motors.
///
/// Motors are connected so that zero duty cycle is full speed, but this class
/// hides this detail.
class WheelController {
public:
    /// \brief
    ///    Initializes a new wheel controller instance with specfied power to
    ///    feed to motors.
    ///
    /// \param power
    ///    Power to feed to motors, minimum is 0 and maximum is 255
    WheelController(uint8_t power);

    /// \brief
    ///    Destroys this wheel controller instance
    ~WheelController();

public:
    /// \brief
    ///    Terminates current movement and starts forward movement. The movement
    ///    continues until another command is given.
    void moveForward();

    /// \brief
    ///    Terminates current movement and starts backward movement. The
    ///    movement continues until another command is given.
    void moveBackward();

    /// \brief
    ///    Terminates current movement and starts clockwise rotation. The
    ///    rotation continues until another command is given.
    void rotateClockwise();

    /// \brief
    ///    Terminates current movement and starts counter clockwise rotation.
    ///    The rotation continues until another command is given.
    void rotateCounterClockwise();

    /// \brief
    ///    Terminates current movement. If wheels are not moving when this
    ///    function is called, does nothing.
    void stop();

private:
    /// \brief Moves left leg forward.
    void leftWheelForward();

    /// \brief Moves right leg forward.
    void rightWheelForward();

    /// \brief Moves left leg backward.
    void leftWheelBackward();

    /// \brief Moves right leg backward.
    void rightWheelBackward();

private:
    /// Power to feed to motor
    uint8_t power;
};

#endif