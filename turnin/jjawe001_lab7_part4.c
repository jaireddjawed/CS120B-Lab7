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

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;

	ADC_init();

	unsigned short my_short = 0x00;
	unsigned char MAX = 0xFF;
	unsigned char tmpB = 0x00;

	while (1) {
		my_short = ADC;

		unsigned char my_char = (char) my_short;
		
		if (my_char <= MAX/8) {
			tmpB = 0x01;
		}
		else if (my_char <= MAX/4) {
			tmpB = 0x03;
		}
		else if (my_char <= (3*MAX)/8) {
			tmpB = 0x07;
		}
		else if (my_char <= MAX/2) {
			tmpB = 0x0F;
		}
		else if (my_char <= (MAX * 5)/8) {
			tmpB = 0x1F;
		}
		else if (my_char <= (MAX * 3)/4) {
			tmpB = 0x3F;
		}
		else if (my_char <= (MAX * 7)/ 8) {
			tmpB = 0x7F;
		}
		else {
			tmpB = 0xFF;
		}

		PORTB = tmpB;
	}
    return 1;
}
