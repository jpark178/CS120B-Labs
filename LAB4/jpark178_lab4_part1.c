/*	Partner 1 Name & E-mail: Jay Park jpark178@ucr.edu
 *	Partner 2 Name & E-mail: Ivan Liang ilian001@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab # 4 Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>
enum States{startState, initialState, onState} state;
unsigned char tmpA = 0x00;
unsigned char tmpB = 0x00;

void tick() {
    tmpA = PINA;

    switch(state) {
        case startState:
            state = initialState;
            break;
        
        case initialState:
            if(!(tmpA & 0x01)) {
                state = initialState;
            }
            else if(tmpA & 0x01) {
                 state = onState;
            }
            break;
        
        case onState:
            if(!(tmpA & 0x01)) {
                state = onState;
            }
            else if(tmpA & 0x01) {
                 state = initialState;
            }
            break;
        default:
            state = startState;
            break;
    }
    
    switch(state) {
        case initialState:
            tmpB = 0x01;
            PORTB = tmpB;
            break;
        
        case onState:
            tmpB = 0x02;
            PORTB = tmpB;
            break;
            
        default:
            break;  
    }   
}

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
	
    state = startState;
    
    while(1) {
        tick();
    }
}
