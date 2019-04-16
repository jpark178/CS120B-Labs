/*
 * PARTNER 1: Jay Park jpark178@ucr.edu
 * PARTNER 2: Ivan Liang ilian001@ucr.edu
 * LAB SECTION: 023
 * ASSIGNMENT : LAB #1 EXERCISE #3
 * I acknowledge all content contained herein, excluding template or example code, is my original work.
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;// configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00;//configure port C's 8 pins as outputs, initialize to 0
	unsigned char cntavail = 0x04;//temp variable to hold the value of B.
	unsigned char tmp = 0x01;
	while(1) {
		cntavail = 0x04;
		for(char i = 0; i < 4; i++) {
			if((PINA & tmp) == 0) {
				tmp = tmp << 1;
			}
			if((PINA & tmp) > 0) {
				cntavail --;
				tmp = tmp << 1;
			}
		}
		if(PINA == 0x0F) {
			PORTC = 0x80;
		}
		else {
			PORTC = cntavail;
		}
		tmp = 0x01;
	}
}

