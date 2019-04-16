/*
 * PARTNER 1: Jay Park jpark178@ucr.edu
 * PARTNER 2: Ivan Liang ilian001@ucr.edu
 * LAB SECTION: 023
 * ASSIGNMENT : LAB #1 EXERCISE #4
 * I acknowledge all content contained herein, excluding template or example code, is my original work.
 */ 

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // input
	DDRB = 0x00; PORTB = 0xFF; // input
	DDRC = 0x00; PORTC = 0xFF; // input
	DDRD = 0xFF; PORTD = 0x00; // output
	unsigned short temp = 0x00;
	unsigned char max = 0x8C;
	
	while(1) {
		temp = PINA + PINB + PINC;
		if(PINA > max || PINB > max || PINC > max || temp > max) {
			PORTD = 0x01;
		} else {
			PORTD = PORTD & 0xFE;
		}
		if(PINA - PINC > 0x50) {
			PORTD = 0x02;
		} else {
			PORTD = PORTD & 0xFD;
		}
	}
}

