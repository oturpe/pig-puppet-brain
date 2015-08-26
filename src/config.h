// Cpu frequency for util/delay.h
#define F_CPU 8000000

#define AVG_WINDOW 100

#define ADC_PRESCALER Atmega328p::ADC_PSV_32

#define PWM_PRESCALER Atmega328p::PSV_128
#define PWM_PORT PORTB
#define PWM_PIN PORTB1

//Enables debug messaging
#define DEBUG
