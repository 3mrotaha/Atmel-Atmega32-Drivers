/*
 * main.c
 *
 *  Created on: Mar 7, 2022
 *      Author: amrmo
 */

#include "LIB/std_types.h"
#include "LIB/Error_States.h"

#include "MCAL/DIO/DIO_int.h"

#include "MCAL/TIMER1/TIMER1_priv.h"
#include "MCAL/TIMER1/TIMER1_int.h"
#include "util/delay.h"

void tog(void);
void tog2(void);
void tog3(void);
uint_16 ICR_value;
int main(void){
	TIMER1_enuInit();

	DIO_enuSetPortDir(DIO_uint8_PORTC, 0xff);
	DIO_enuSetPortDir(DIO_uint8_PORTA, 0xff);

	TIMER1_enuInputCaptureEnable(0, 1);


	TIMER1_enuCallBack(&tog, NULL, TIMER1_ICR_INT);

	//TIMER1_enuASyncDelay(1500, &tog2, NULL);
//	TIMER1_enuSetWaveMode(PWM_PHASE_AND_FREQUANCY_CORRECT_OCR_TOP, 600);
//	TIMER1_enuGeneratePWM_OC1B(250, CLEAR_OC1B_ON_COMPARE_MATCH);
	while(1){

	TIMER1_enuGetInputCapture(&ICR_value);
	}

	return 0;
}

void tog(void){
	DIO_enuSetPortValue(DIO_uint8_PORTC, ICR_value);
}
void tog2(void){
	DIO_enuTogPortValue(DIO_uint8_PORTC);
}
void tog3(void){
	DIO_enuSetPortValue(DIO_uint8_PORTC, 0xf1);
}
