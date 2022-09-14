/*
 * main.c
 *
 *  Created on: Feb 20, 2022
 *      Author: amrmo
 */

#include <util/delay.h>
typedef unsigned char u8;
typedef unsigned int u32;
//#define  F_CPU 1000000UL

#define PORTA 	*((u8*) 0x3B)
#define DDRA 	*((u8*) 0x3A)
#define PINA	*((volatile u8*) 0x39)
#define PORTB   *((u8*) 0x38)
#define DDRB	*((u8*) 0x37)
int main(){
	DDRA = 0b01111111;
	PORTA = 0xff;
	DDRB = 0b00000011;
	PORTB = 0;
	u8 seg[10] = {// x g f e  d c b a
	0x3f,	// zero:  x 0 1 1  1 1 1 1   ___a___
	0x06,	// one:   x 0 0 0  0 1 1 0  |       |
	0x5B,	// two:   x 1 0 1  1 0 1 1  f       b
	0x4f,	// three: x 1 0 0  1 1 1 1  |       |
	0x66,	// four:  x 1 1 0  0 1 1 0   ___g___
	0x6d,	// five:  x 1 1 0  1 1 0 1  |       |
	0x7d,	// six:   x 1 1 1  1 1 0 1  e       c
	0x07,	// seven: x 0 0 0  0 1 1 1  |       |
	0x7f,	//eight:  x 1 1 1  1 1 1 1   ___d___
	0x6f	// nine:  x 1 1 0  1 1 1 1
	};
	u32 switch_state, one, deci, counter = 0;
	while(1){
		switch_state = (PINA >> 7);
		if(switch_state == 0){
			counter++;
			_delay_ms(10);
			while(!(PINA >> 7) & 1);
		}
		one = counter % 10;
		deci = counter / 10;
		PORTB = 0b00000001;
		PORTA = 0b10000000;
		PORTA |= ~seg[one];
		_delay_ms(15);
		PORTB = 0b00000010;
		PORTA = 0b10000000;
		PORTA |= ~seg[deci];
		_delay_ms(15);

	}
	return 0;
}
