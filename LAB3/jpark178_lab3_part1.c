/*
 * PARTNER 1: Jay Park jpark178@ucr.edu
 * PARTNER 2: Ivan Liang ilian001@ucr.edu
 * LAB SECTION: 023
 * ASSIGNMENT : LAB #2 EXERCISE #1
 * I acknowledge all content contained herein, excluding template or example code, is my original work.
 */ 

#include <avr/io.h>


int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // input
	DDRB = 0x00; PORTB = 0xFF; // input
	DDRC = 0xFF; PORTC = 0x00; // output
	unsigned char outputOne = 0x00;
	unsigned char shift = 0x01;

			
    while (1) {
		outputOne = 0x00;
		for(char i = 0; i < 8; i++) {
			if((PINA & shift) > 0) {
				outputOne++;
			}
			if((PINB & shift) > 0) {
				outputOne++;
			}
		shift = shift << 1;
		}
		if((PINA == 0x00) && (PINB == 0x00)) {
			PORTC = 0x00;
		}
		if((PINA == 0xFF) && (PINB == 0xFF)) {
			PORTC = 0x10;
		}
		PORTC = outputOne;
		shift = 0x01;		
    }
}