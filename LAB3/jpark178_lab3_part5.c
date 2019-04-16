/*
 * PARTNER 1: Jay Park jpark178@ucr.edu
 * PARTNER 2: Ivan Liang ilian001@ucr.edu
 * LAB SECTION: 023
 * ASSIGNMENT : LAB #2 EXERCISE #5
 * I acknowledge all content contained herein, excluding template or example code, is my original work.
 */

#include <avr/io.h>

int main(void)
{
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x01;
	
	unsigned short seatSensor = 0x0000;
	unsigned char tmp = 0x00;
	unsigned char output = 0x01;
	while(1)
	{
		seatSensor = (PIND << 1);
		tmp = PINB & 0x01;
		seatSensor = seatSensor | tmp;
		if(seatSensor >= 0x0046) // if weight is great than or equal to 70 pounds
		{
			output = 0x02;  // PB1 is lit on for "airbag"
		}
		else if((seatSensor < 0x0046) && (seatSensor > 0x0005)) // if weight between 5 and 70 pounds
		{
			output = 0x04; // PB2 is lit on for "airbag disabled"
		}
		PORTB = output;
		seatSensor = 0x0000;
		output = 0x01;
	}
}

