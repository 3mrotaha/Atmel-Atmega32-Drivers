/*
 * main.c
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */


#include "LIB/std_Types.h"
#include "LIB/ErrorStates.h"

#include "HAL/LCD/LCD_config.h"
#include "HAL/LCD/LCD_int.h"


int main(void){

	LCD_enuInit();
	LCD_enuSendCommand(0x80);
	LCD_enuDisplayString("LCD 2x16 Driver", 15);
	LCD_enuSendCommand(0xC0);
	LCD_enuDisplayString("Let's Try it", 12);
	while(1){

	}
	return 0;
}




