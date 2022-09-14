/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#include "std_types.h"
#include "Error_States.h"

#include "LCD_int.h"


#include "util/delay.h"

int main(void){

	LCD_enuInit();

	while(1){
		LCD_enuSendCommand(0x80);
		LCD_enuDisplayChar('A');
		LCD_enuDisplayChar('m');
		LCD_enuDisplayChar('r');
		LCD_enuDisplayString(" TAHA");
		LCD_enuDisplayChar(' ');
		LCD_enuDisplayChar('0');
		LCD_enuSendCommand(0xc0);
		LCD_enuDisplayFloat(-19.6589);
		LCD_enuDisplayChar(' ');
		LCD_enuDisplayInteger(-1902000);
		_delay_ms(500);
		//LCD_enuSendCommand(0x01);
	}

	return 0;
}
