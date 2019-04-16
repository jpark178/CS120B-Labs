/*	Partner 1 Name & E-mail: Jay Park jpark178@ucr.edu
 *	Partner 2 Name & E-mail: Ivan Liang ilian001@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab # 4 Exercise # 3
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

enum state {startState, initialState, yState, poundState, waitState, unlockState, lockState} state;
unsigned char tmpA = 0x00;

void Tick_DoorLock() {
	tmpA = PINA;

	switch (state) {
		case startState:
		state = initialState;
		break;
		
		case initialState:
		if ((tmpA & 0x07) == 0x04) {
			state = poundState;
		}
		else if (tmpA & 0x80) {
			state = lockState;
		} else {
			state = initialState;
		}
		break;

		case yState:
		state = unlockState;
		break;
		
		case poundState:
		state = waitState;
		break;
		
		case waitState:
		if ((tmpA & 0x07) == 0x02) {
			state = yState;
		}
		else if (((tmpA & 0x07) == 0x04) || !tmpA) {
			state = waitState;
		}
		else if ((tmpA & 0x07) != 0x02) {
			state = initialState;
		}
		else if (tmpA == 0x80) {
			state = lockState;
		} else {
			state = waitState;
		}
		break;
		
		case lockState:
		if (!tmpA) {
			state = initialState;
		} else {
			state = lockState;
		}
		break;
		
		case unlockState:
		if (tmpA & 0x87) {
			state = initialState;
		} else {
			state = unlockState;
		}
		break;
		
		default:
		break;
	}
	switch (state) {
		case startState:
		PORTB = 0x00;
		PORTC = 0x00;
		break;
		
		case initialState:
		break;
		
		case poundState:
		PORTC = 0x04;
		break;
		
		case yState:
		PORTC = 0x02;
		break;
		
		case waitState:
		PORTC = 0x03;
		break;
		
		case unlockState:
		PORTB = 0x01;
		PORTC = 0x05;
		break;
		
		case lockState:
		PORTB = 0x00;
		PORTC = 0x06;
		break;
		
	}
	
}
int main(void) {
	
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	state = startState;
	
	while (1) {
		Tick_DoorLock();
	}
}