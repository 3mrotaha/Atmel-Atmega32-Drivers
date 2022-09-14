/*
 * main.c
 *
 *  Created on: Mar 18, 2022
 *      Author: amrmo
 */

#include "LIB/std_types.h"
#include "LIB/Error_States.h"

#include "MCAL/DIO/DIO_int.h"

#include "MCAL/TIMER2/TIMER2_priv.h"
#include "MCAL/TIMER2/TIMER2_int.h"




void tog(void);
int main(void){
	 TIMER2_enuInit();

	DIO_enuSetPinDir(0, 0, OUTPUT);
//	TIMER2_enuAsyncDelay(1253, &tog, NULL);
	//TIMER2_enuSetWaveGenMode(TIMER2_CTC_MODE);
	//TIMER2_enuOutputCompare(5, TIMER2_TOGGLE_OC2);
//	TIMER2_enuGeneratePWM(TIMER2_PWM_CLEAR_OC2, 25);
	while(1){

	}
	return 0;
}

void tog(void){
	DIO_enuTogPinValue(0, 0);
}
