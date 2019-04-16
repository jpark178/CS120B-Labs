/*
 * PARTNER 1: Jay Park jpark178@ucr.edu
 * PARTNER 2: Ivan Liang ilian001@ucr.edu
 * LAB SECTION: 023
 * ASSIGNMENT : LAB #2 EXERCISE #4
 * I acknowledge all content contained herein, excluding template or example code, is my original work.
 */

#include <avr/io.h>

int main(void) {
	
	DDRA = 0x00; PORTA = 0xFF;
	DDRD = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	
    while (1) {
		tmpB = (PINA & 0xF0) >> 4;
		tmpC = (PINA & 0x0F) << 4;
		
		PORTB = tmpB;
		PORTC = tmpC;
    }
}

