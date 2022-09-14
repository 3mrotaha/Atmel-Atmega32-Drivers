/*
 * main.c
 *
 *  Created on: Mar 1, 2022
 *      Author: amrmo
 */

#include "LIB/std_types.h"
#include "LIB/Error_States.h"


#include "DIO/DIO_int.h"

#include "TIMER0/TIMER0_int.h"

#include "util/delay.h"

uint_8 x;
void Tog(void);
int main(void){

	TIMER0_enuInit();
	//DIO_enuSetPortDir(DIO_uint8_PORTC, OUTPUT);
	DIO_enuSetPortDir(DIO_uint8_PORTA, 0xff);
	DIO_enuSetPortValue(DIO_uint8_PORTA, 0xff);
	*((volatile uint_8*) 0x5F) |= (1 << 7);

	//TIMER0_enuCTCCallBack(&Tog, NULL);
	//TIMER0_enuFastPWMByDutyCycle(.9, TIMER0_uint8PHASECORRECT_PWM_SET);
	//TIMER0_enuPhaseCorrectByDutyCycle(0.7, TIMER0_uint8PHASECORRECT_PWM_CLEAR);
		uint_8 j = 0;
	for(f32 i =0; i < 1; i+= 0.1){
		TIMER0_enuPhaseCorrectByDutyCycle(i, TIMER0_uint8PHASECORRECT_PWM_CLEAR);
		if(i >= 0.9){
			i = 0.1;
			_delay_ms(1000);
			if(j < 8){
				j+=1;
			}
			else{
				DIO_enuSetPortValue(DIO_uint8_PORTA, 0xff);
				j = 0;
			}
		}
		else if(i >= 0.5){
			DIO_enuSetPinValue(DIO_uint8_PORTA, j, LOW);
		}
		else{
			DIO_enuSetPinValue(DIO_uint8_PORTA, j-1, HIGH);
		}
		_delay_ms(500);
	}
	DIO_enuSetPortValue(DIO_uint8_PORTA, 0x00);
	while(1){

	}
	return 0;
}
void Tog(void){

}
