#include "config.h"

#include <avr/io.h>

#include "Atmega168Utils.h"
#include "AnalogThresholdComparator.h"

AnalogThresholdComparator::AnalogThresholdComparator(uint16_t threshold,
                                                     uint16_t hysteresis)
      : threshold(threshold), hysteresis(hysteresis) {
}

AnalogThresholdComparator::~AnalogThresholdComparator() {
}

void AnalogThresholdComparator::recordAmbientReading() {
    uint16_t leftAmbientReading = 0;
    uint16_t rightAmbientReading = 0;

    uint8_t repeats = 10;
    for(int i = 0; i < repeats; i++) {
        // Select analog input ADC4
        ADMUX &= ~BV(MUX3) & ~BV(MUX1) & ~BV(MUX0);
        ADMUX |= BV(MUX2);

        // start conversion and wait until value is available
        ADCSRA |= BV(ADSC);
        while(ADCSRA & BV(ADSC));

        // Record reading as ambient value
        leftAmbientReading += ADC;

        // Select analog input ADC5 and do the comparison again
        ADMUX &= ~BV(MUX3) & ~BV(MUX1);
        ADMUX |= BV(MUX2) | BV(MUX0);

        // start conversion and wait until value is available
        ADCSRA |= BV(ADSC);
        while(ADCSRA & BV(ADSC));

        // Record reading as ambient value
        rightAmbientReading += ADC;
    }

    leftAmbientReading /= repeats;
    leftFindThreshold = leftAmbientReading + threshold;
    leftLoseThreshold = leftAmbientReading + threshold - hysteresis;

    rightAmbientReading /= repeats;
    rightFindThreshold = leftAmbientReading + threshold;
    rightLoseThreshold = leftAmbientReading + threshold - hysteresis;
}

Reading AnalogThresholdComparator::read() {
    Reading reading;

    // Select analog input ADC4
    ADMUX &= ~BV(MUX3) & ~BV(MUX1) & ~BV(MUX0);
    ADMUX |= BV(MUX2);

    // start conversion and wait until value is available
    ADCSRA |= BV(ADSC);
    while(ADCSRA & BV(ADSC));

    if(!currentReading.left && ADC > leftFindThreshold) {
        reading.left = true;
    } else if(currentReading.left && ADC < leftLoseThreshold) {
        reading.left = false;
    } else {
        reading.left = currentReading.left;
    }

    // Select analog input ADC5 and do the comparison again
    ADMUX &= ~BV(MUX3) & ~BV(MUX1);
    ADMUX |= BV(MUX2) | BV(MUX0);

    ADCSRA |= BV(ADSC);
    while(ADCSRA & BV(ADSC));

    if (!currentReading.right && ADC > rightFindThreshold) {
        reading.right = true;
    } else if(currentReading.right && ADC < rightLoseThreshold) {
        reading.right = false;
    } else {
        reading.right = currentReading.right;
    }

    if(currentReading == reading) {
        currentReading.support();
    } else {
        currentReading = reading;
    }

    if(currentReading.isValid()) {
        setIndicators();
    }

    return currentReading;
}

void AnalogThresholdComparator::setIndicators() {
    if(currentReading.left) {
        PORTD |= BV(PORTD1);
    } else {
        PORTD &= ~BV(PORTD1);
    }

    if(currentReading.right) {
        PORTD |= BV(PORTD2);
    } else {
        PORTD &= ~BV(PORTD2);
    }
}