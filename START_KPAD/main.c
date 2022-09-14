/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: amrmo
 */

#include "std_types.h"
#include "Error_States.h"

#include "DIO_priv.h"
#include "DIO_int.h"

#include "KPAD_config.h"
#include "KPAD_int.h"

#include "util/delay.h"


extern KPAD_t KPAD_AstrKeyPadConfig[NUM_OF_KPADS];

int main(void){
	KPAD_enuInit(KPAD_AstrKeyPadConfig);
	uint_8 Local_uint8GetKey;
	while(1){
		KPAD_enuGetPressedkey(&KPAD_AstrKeyPadConfig[0], &Local_uint8GetKey);
		DDRC = Local_uint8GetKey;
	}

	return 0;
}
