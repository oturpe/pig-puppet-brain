// Controller for pig puppet/robot. The puppet walks around on wheels and
// makes various body movements.
//
// Author: Otto Urpelainen
// Email: oturpe@iki.fi
// Created on: 2015-08-26

#include "config.h"

#include "Atmega168Utils.h"
#include <avr/io.h>
#include <util/delay.h>

/// Initializes analog to digital conversion by setting the reference and
/// prescaler.
void initializeAdc() {
  /*
  Atmega328p::setVoltageReference(Atmega328p::VREF_VCC);
  Atmega328p::setAdcPrescalerValue(ADC_PRESCALER);

  // Enable adc
  ADCSRA |= BV(ADEN);

// Disable digital input from pins that are used for adc.
  DIDR0 |= BV(ADC0D) | BV(ADC1D) | BV(ADC2D) | BV(ADC3D);
  */
}

int16_t readAnalog0() {
  /*
  // Select analog input ADC0
   ADMUX &= ~BV(MUX3) & ~BV(MUX2) & ~BV(MUX1) & ~BV(MUX0);

  // start conversion and wait until value is available
  ADCSRA |= BV(ADSC);
  while(ADCSRA & BV(ADSC));

  return ADC;
  */
}

int16_t readAnalog1() {
  /*
  // Select analog input ADC1
   ADMUX &= ~BV(MUX3) & ~BV(MUX2) & ~BV(MUX1);
   ADMUX |= BV(MUX0);

  // start conversion and wait until value is available
  ADCSRA |= BV(ADSC);
  while(ADCSRA & BV(ADSC));

  return ADC;
  */
}

int16_t readAnalog2() {
  /*
  // Select analog input ADC2
   ADMUX &= ~BV(MUX3) & ~BV(MUX2) & ~BV(MUX0);
   ADMUX |= BV(MUX1);

  // start conversion and wait until value is available
  ADCSRA |= BV(ADSC);
  while(ADCSRA & BV(ADSC));

  return ADC;
  */
}

int16_t readAnalog3() {
  /*
  // Select analog input ADC3
   ADMUX &= ~BV(MUX3) & ~BV(MUX2);
   ADMUX |= BV(MUX1) | BV(MUX0);

  // start conversion and wait until value is available
  ADCSRA |= BV(ADSC);
  while(ADCSRA & BV(ADSC));

  return ADC;
  */
}

int main() {

    #ifdef DEBUG
        // Some debug stuff?
    #endif

    //initializeAdc();

    DDRB |= BV(DDB1);

    while(true) {
         _delay_ms(500);
        PORTB |= BV(PORTB1);
         _delay_ms(500);
        PORTB &= ~BV(PORTB1);
    }
}
