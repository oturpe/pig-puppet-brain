// Cpu frequency for util/delay.h
#define F_CPU 8000000

// Unit of time for the whole control system. Given in milliseconds.
#define LOOP_DELAY 10

// How long is half period of power indicator led blinking. Given in units of
// LOOP_DELAY
#define INDICATOR_HALF_PERIOD 50

// How long legs stay active when searching. Given in units of LOOP_DELAY.
#define LEG_SEARCH_PERIOD 100
// How long legs stay active when finding line. Given in units of LOOP_DELAY.
#define LEG_FIND_LINE_PERIOD 100
// How long legs stay active when avoiding line. Given in units of LOOP_DELAY.
#define LEG_AVOID_PERIOD 85
// How long legs stay active when retreating. Given in units of LOOP_DELAY.
#define LEG_RETREAT_PERIOD 85
// How long legs stop between changing movement types. Given in unuits of
// LOOP_DELAY-
#define LEG_TRANSITION_PERIOD 80
// Pwm duty cycle for running leg motors. 0 is 0 %, 255 is 100 %.
#define LEG_MOTOR_DUTY_CYCLE 90

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
#define SENSOR_THRESHOLD 100
// Maximum sensor reading to consider as found pen limit lost
#define SENSOR_HYSTERESIS 30

// How many times a reading must be confirmed to make it valid.
#define READING_VALIDITY_MINIMUM 1

//Enables debug messaging
#define DEBUG
