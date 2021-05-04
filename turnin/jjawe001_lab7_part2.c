/*	Author: lab
 *  Partner(s) Name: Jaired Jawed
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

// Note: I determined the MAX value used in exercises 3 and 4 after
// using a flashlight on the photoresistor
// the max value is 0x3E0

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;

	unsigned short my_short = 0x00;
	ADC_init();
	
	unsigned char tmpB = 0x00;
	unsigned char tmpD = 0x00;

    /* Insert your solution below */
    while (1) {
	my_short = ADC;
	
	tmpB = (char) my_short;
	tmpD = (char)(my_short >> 8);

	PORTB = tmpB;
	PORTD = tmpD;
    }
 

    return 1;
}
