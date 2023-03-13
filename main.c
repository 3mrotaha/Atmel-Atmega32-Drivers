/*
 * main.c
 *
 * Created: 1/31/2023 1:53:12 AM
 *  Author: amrmo
 */ 
#include "util/delay.h"
#include "LIB/std_types.h" 
#include "LIB/ErrorStates.h"

#include "MCAL/ADC/ADC_priv.h"
#include "MCAL/ADC/ADC_config.h"
#include "MCAL/ADC/ADC_int.h"

#include "HAL/LCD/LCD_int.h"


int main(void){
	LCD_enuInit();
	ADC_enuEnable();
	ADC_enuSetVoltReference(SELECT_ADC_VOLTAGE);
	ADC_enuSetPrescaler(SELECT_ADC_PRESCALER);
	ADC_enuSelectChannel(0);
	uint16 value = 0, prevValue = 0;
	while(1){
		ADC_enuStartConversion();
		ADC_enuWaitOnFlag();
		ADC_enuReadValue(&value);
		if(prevValue != value){		
			LCD_enuSendCommand(0x01);	
			LCD_enuDisplayInteger(value);
			prevValue = value;
		}		
	}
	return 0;
}
