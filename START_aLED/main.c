/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#include "std_types.h"
#include "Error_States.h"

#include "LED_config.h"
#include "LED_priv.h"
#include "LED_int.h"

#include "util/delay.h"


extern LED_t SW_AstrLEDs[LED_NUM];

int main(void){

	LED_enuInit(SW_AstrLEDs);
	while(1){
		uint_8 Local_uint8Iterator;
		for(Local_uint8Iterator = 0; Local_uint8Iterator <LED_NUM; Local_uint8Iterator++){
			LED_enuTurnON(&SW_AstrLEDs[Local_uint8Iterator]);
			_delay_ms(250);
		}

		for(Local_uint8Iterator = 0; Local_uint8Iterator < LED_NUM; Local_uint8Iterator++){
			LED_enuTurnOFF(&SW_AstrLEDs[Local_uint8Iterator]);
			_delay_ms(250);
		}
	}
	return 0;
}
