/*
 * main.c
 *
 *  Created on: Oct 9, 2021
 *      Author: amrmo
 */


#include "LIB/ErrorStates.h"
#include "LIB/std_Types.h"

#include "DIO/DIO_config.h"
#include "DIO/DIO_priv.h"
#include "DIO/DIO_int.h"

#include "Registers.h"


int main(void){

	// NORMAL MODE TIMER 0
	DIO_enuSetPinDir(DIO_PORTA, DIO_PIN6, OUTPUT);

	while(1){
		TCCR0 |= 0x01;
		TCNT0 = 0xF2;
		while(!(TIFR & 1));

		TCCR0 = 0;

		DIO_enuTogPinValue(DIO_PORTA, DIO_PIN6);

	}

	return 0;
}
