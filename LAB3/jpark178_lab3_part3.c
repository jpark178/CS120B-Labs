/*
 * PARTNER 1: Jay Park jpark178@ucr.edu
 * PARTNER 2: Ivan Liang ilian001@ucr.edu
 * LAB SECTION: 023
 * ASSIGNMENT : LAB #2 EXERCISE #3
 * I acknowledge all content contained herein, excluding template or example code, is my original work.
 */

#include <avr/io.h>

int main(void) {
    DDRA = 0x00; PORTA = 0xFF; // input
    DDRB = 0xFF; PORTB = 0x00; // output
	unsigned char fuelSensor = 0x00;
	unsigned char seatBelt = 0x00;
	unsigned char driverSeat = 0x00;
	unsigned char ignitionKey = 0x00;
	
    while (1) {
		seatBelt = PINA & 0x40;
		driverSeat = PINA & 0x20;
		ignitionKey = PINA & 0x10;
		
		if((PINA > 0x00) && (PINA <= 0x02)) {
			fuelSensor = 0x60;
		}
		if((PINA > 0x02) && (PINA <= 0x04)) {
			fuelSensor = 0x70;
		}
		if((PINA > 0x04) && (PINA <= 0x06)) {
			fuelSensor = 0x38;
		}
		if((PINA > 0x06) && (PINA <= 0x09)) {
			fuelSensor = 0x3C;
		}
		if((PINA > 0x09) && (PINA <= 0x0C)) {
			fuelSensor = 0x3E;
		}
		if((PINA > 0x0C) && (PINA <= 0x0F)) {
			fuelSensor = 0x3F;
		}
		if(ignitionKey == 0x10) {
			if(driverSeat == 0x20) {
				if(seatBelt == 0x40) {
					PORTB = fuelSensor;
				} else {
					PORTB = fuelSensor | 0x80;
				}
			}
		} else {
			PORTB = fuelSensor;		
		}
	}
}
