/*
 * main.c
 *
 *  Created on: Feb 18, 2022
 *      Author: amrmo
 */
#define F_CPU 1000000UL
#include <util/delay.h>

typedef unsigned char u8;

#define PORTA 	*((u8*) 0x3B)
#define DDRA 	*((u8*) 0x3A)

int main(){
	DDRA |= ~0;
	PORTA &= 0;
	while(1){
		for(int i = 0; i < 7; i++){
			PORTA |= (1 << i);
			_delay_ms(250);
			PORTA &= ~(1 << i);
		}
	}
	
	return 0;
}
