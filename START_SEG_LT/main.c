/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: amrmo
 */

#include "std_types.h"
#include "Error_States.h"

#include "SEG_config.h"
#include "SEG_int.h"

#include "util/delay.h"

extern SEG_t SEG_AstrSevenSegment[SEG_NUM];

int main(void){

	SEG_enuInit(SEG_AstrSevenSegment);
	SEG_enuEnableCommon(&SEG_AstrSevenSegment[0]);
	while(1){
		for(uint_8 i = 0; i < 10; i++){
			SEG_enuDisplayNum(&SEG_AstrSevenSegment[0], i);
			for(uint_8 j = 0; j < 10; j++){
				SEG_enuDisplayNum(&SEG_AstrSevenSegment[1], j);
				_delay_ms(250);
			}
		}
	}

	return 0;
}
