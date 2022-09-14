/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: amrmo
 */

#include "std_types.h"
#include "Error_States.h"

#include "SevenSeg_int.h"

#include "util/delay.h"
int main(void){

	SEG_enuInit();
	SEG_enuEnableCommon();
	while(1){
		for(uint_8 i = 0; i < 10; i++){
			SEG_enuDisplay(i);
			_delay_ms(1000);
		}
	}
	return 0;
}
