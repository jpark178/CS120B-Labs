/*
 * PARTNER 1: Jay Park jpark178@ucr.edu
 * PARTNER 2: Ivan Liang ilian001@ucr.edu
 * LAB SECTION: 023
 * ASSIGNMENT : LAB #1 EXERCISE #1
 * I acknowledge all content contained herein, excluding template or example code, is my original work.
 */ 

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize as 0's
	unsigned char tmp_input = 0x00;
	while(1) {
	    if (PINA == 0x01 && PINB == 0x00) {
		  tmp_input = PINA;
		  PORTC = tmp_input;
	    } else {
		  PORTC == 0x00;
	  }
	}
	return 0;
}

