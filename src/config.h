// Cpu frequency for util/delay.h
#define F_CPU 8000000

// Unit of time for the whole control system. Given in milliseconds.
#define LOOP_DELAY 10

// How long is half period of power indicator led blinking. Given in units of
// LOOP_DELAY
#define INDICATOR_HALF_PERIOD 50

// How long legs stay active when activated. Given in units of LOOP_DELAY.
#define LEG_ACTIVATION_PERIOD 120
// How long legs retain one direction of movement. Given in units of LOOP_DELAY.
#define LEG_DIRECTION_PERIOD 1000
// Pwm duty cycle for running leg motors. 0 is 0 %, 255 is 100 %.
#define LEG_MOTOR_DUTY_CYCLE 70

// How long nose stays active until activated
#define NOSE_ACTIVATION_PERIOD 100
// Half duration of one nose pull. Given in units of LOOP_DELAY.
#define NOSE_HALF_PERIOD 5

// Duration of one step of tail movement. Given in units of LOOP_DELAY.
#define TAIL_STEP_PERIOD 4
// Duration of one direction of tail movement. Given in units of
// TAIL_STEP_PERIOD.
#define TAIL_CHANGE_PERIOD 70

// How often pen perimeter sensors are read. Given in units of LOOP_DELAY.
#define SENSOR_INTERVAL 10

// Minimum sensor reading to consider as pen limit found
#define SENSOR_THRESHOLD 600

//Enables debug messaging
#define DEBUG
