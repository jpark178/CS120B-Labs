/*
 * PARTNER 1: Jay Park jpark178@ucr.edu
 * PARTNER 2: Ivan Liang ilian001@ucr.edu
 * LAB SECTION: 023
 * ASSIGNMENT : LAB #2 EXERCISE #2
 * I acknowledge all content contained herein, excluding template or example code, is my original work.
 */

#include <avr/io.h>

int main(void) {
    DDRA = 0x00; PORTA = 0xFF; // input
    DDRB = 0xFF; PORTB = 0x00; // output
	unsigned char fuelSensor = 0x00;
	
    while (1) {
		if(PINA > 0x00) {
			fuelSensor = fuelSensor | 0x20;
			fuelSensor = fuelSensor | 0x40;
		}
		if(PINA > 0x02) {
			fuelSensor = fuelSensor | 0x10;
			fuelSensor = fuelSensor | 0x40;
		}
		if(PINA > 0x04) {
			fuelSensor = fuelSensor | 0x08;
			fuelSensor = fuelSensor & 0xBF;
		}
		if(PINA > 0x07) {
			fuelSensor = fuelSensor | 0x04;
			fuelSensor = fuelSensor & 0xBF;
		}
		if(PINA > 0x09) {
			fuelSensor = fuelSensor | 0x02;
			fuelSensor = fuelSensor & 0xBF;
		}
		if(PINA > 0x0C) {
			fuelSensor = fuelSensor | 0x01;
			fuelSensor = fuelSensor & 0xBF;
		}
		PORTB = fuelSensor;
		fuelSensor = 0x00;
	}
}
