/*	Partner 1 Name & E-mail: Jay Park jpark178@ucr.edu
 *	Partner 2 Name & E-mail: Ivan Liang ilian001@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab # 4 Exercise # 2
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

enum states { startState, initialState, waitUpState, waitDownState, incrementState, decrementState, resetState} state;

unsigned char tmpA = 0x00;
unsigned char tmpC = 0x00;

void Tick_IncrDecr() {
	switch (state) {
		case startState:
		state = initialState;
		break;
		
		case initialState:
		state = waitUpState;
		break;
		
		case waitUpState:
		tmpA = PINA;
		if ((tmpA & 0x01) && (!(tmpA & 0x02))) {
			state = incrementState;
		}
		else if ((!(tmpA & 0x01)) && (tmpA & 0x02)) {
			state = decrementState;
		}
		else if ((tmpA & 0x03) == 0x03) {
			state = resetState;
		}
		else if ((tmpA & 0x03) != 0x03) {
			state = waitUpState;
		} else {
			state = waitUpState;
		}
		break;
		
		case waitDownState:
		if (tmpA == PINA) {
			state = waitDownState;
		} 
		else if (tmpA != PINA) {
			state = waitDownState;
		} else {
			state = waitUpState;
		}
		break;

		case incrementState:
		state = waitDownState;
		break;
		
		case decrementState:
		state = waitDownState;
		break;
		
		case resetState:
		state = waitDownState;
		break;
		
		default:
		state = waitDownState;
		break;
		
	}
	
	switch (state) {
		case startState:
		break;
		
		case initialState:
		tmpC = 7;
		break;
		
		case waitUpState:
		PORTC = tmpC;
		break;

		case waitDownState:
		PORTC = tmpC;
		break;
		
		case incrementState:
		if (tmpC + 1 <= 9) {
			++tmpC;
		}
		break;
		
		case decrementState:
		if (tmpC - 1 >= 0) {
			--tmpC;
		}
		break;
		
		case resetState:
		tmpC = 0;
		
		default:
		break;
	}
}


int main(void) {
	DDRA = 0x00; PORTA = 0xFF; 
	DDRC = 0xFF; PORTC = 0x00; 
	
	state = startState;
	while (1) {
		Tick_IncrDecr();
	}
}