/*
 * main.c
 *
 *  Created on: Feb 18, 2022
 *      Author: amrmo
 */
#include <util/delay.h>
#define F_CPU 1000000UL


typedef unsigned char u8;

#define PORTA 	*((u8*) 0x3B)
#define DDRA 	*((u8*) 0x3A)

int main(void){
	DDRA |= ~0;
	PORTA &= 0;
	while(1){
		for(int i = 0; i < 8; i++){
			PORTA |= (1 << i);
			_delay_ms(250);
			PORTA &= ~(1 << i);
		}
		for(int i = 0, j = 7; i < 4, j > 3 ; i++, j--){
			PORTA |= (1 << i);
			PORTA |= (1 << j);
			_delay_ms(250);
			PORTA &= ~(1 << i);
			PORTA &= ~(1 << j);
		}
		for(int i = 3, j = 4; i > 0, j < 8 ; i--, j++){
			PORTA |= (1 << i);
			PORTA |= (1 << j);
			_delay_ms(250);
			PORTA &= ~(1 << i);
			PORTA &= ~(1 << j);
		}
		_delay_ms(250);
	}

	return 0;
}
