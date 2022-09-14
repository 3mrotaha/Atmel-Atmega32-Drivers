/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#include "std_types.h"
#include "Error_States.h"
#include "DIO_int.h"
#include "util/delay.h"

int main(void){


	//DIO_enuInit();

	uint_8 seg[10] = {// x g f e  d c b a
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

	DIO_enuSetPortDir(DIO_uint8_PORTA, 0b11111111);
	DIO_enuSetPortValue(DIO_uint8_PORTA, 0b00000000);
	while(1){

		for(uint_8 i = 0; i<10; i++){
			DIO_enuSetPortValue(DIO_uint8_PORTA, seg[i]);
			_delay_ms(250);
			DIO_enuSetPortValue(DIO_uint8_PORTA, 0b00000000);
			_delay_ms(50);
			for(uint_8 j = 0; j < 6; j++){
				DIO_enuSetPinValue(DIO_uint8_PORTA, j, HIGH);
				_delay_ms(100);
				DIO_enuSetPinValue(DIO_uint8_PORTA, j, LOW);
				_delay_ms(100);
			}
		}
	}
	return 0;
}
