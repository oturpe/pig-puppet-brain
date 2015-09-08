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
    /// \enum Movement
    ///
    /// Different wheel movement types
    enum Movement {
        FORWARD,
        BACKWARD,
        ROTATE_CW,
        ROTATE_CCW,
        STOP
    };

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
    ///    Terminates current movement and starts given movement. The movement
    ///    continues until another command is given.
    void move(Movement movement);

private:
    /// \brief
    ///    Moves left leg forward.
    void leftWheelForward();

    /// \brief
    ///    Moves right leg forward.
    void rightWheelForward();

    /// \brief
    ///    Stops left leg.
    void leftWheelStill();

    /// \brief
    ///    Stops right leg.
    void rightWheelStill();

    /// \brief
    ///    Moves left leg backward.
    void leftWheelBackward();

    /// \brief
    ///    Moves right leg backward.
    void rightWheelBackward();

private:
    /// Power to feed to motor
    uint8_t power;
};

#endif