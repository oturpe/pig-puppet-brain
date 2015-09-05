#include "config.h"

#include <avr/io.h>

#include "Atmega168Utils.h"
#include "AnalogThresholdComparator.h"

AnalogThresholdComparator::AnalogThresholdComparator(uint16_t threshold)
 : threshold(threshold) {
 }

 AnalogThresholdComparator::~AnalogThresholdComparator() {
 }

AnalogThresholdComparator::Reading AnalogThresholdComparator::read() {
    Reading reading;

    // Select analog input ADC4
    ADMUX &= ~BV(MUX3) & ~BV(MUX1) & ~BV(MUX0);
    ADMUX |= BV(MUX2);

    // start conversion and wait until value is available
    ADCSRA |= BV(ADSC);
    while(ADCSRA & BV(ADSC));

    if (ADC > threshold) {
        reading.leftFound = true;
        PORTD |= BV(PORTD1);
    } else {
        reading.leftFound = false;
        PORTD &= ~BV(PORTD1);
    }

    // Select analog input ADC5 and do the comparison again
    ADMUX &= ~BV(MUX3) & ~BV(MUX1);
    ADMUX |= BV(MUX2) | BV(MUX0);

    ADCSRA |= BV(ADSC);
    while(ADCSRA & BV(ADSC));

    if (ADC > threshold) {
        reading.rightFound = true;
        PORTD |= BV(PORTD2);
    } else {
        reading.rightFound = false;
        PORTD &= ~BV(PORTD2);
    }

    return reading;
}
