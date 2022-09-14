/*
 * main.c
 *
 *  Created on: Feb 26, 2022
 *      Author: amrmo
 */

#include "std_types.h"
#include "Error_States.h"

#include "ADC_priv.h"
#include "ADC_config.h"
#include "ADC_int.h"

#include  "util/delay.h"
void tog(int d);
int o = 0;
int main(void){
	ADC_enuInit();
	//sint_16 Local_sint16Value;
	ADC_enuEnableInterrupt();
	ADC_enuAutoTriggerEnable();
	ADC_enuTriggerSource(ADC_EXTERNAL_INTERRUPT0);
	ADC_enuCallBack(&tog, &o);
	ADC_enuSelectChannel(ADC_SINGLEENFED_CH0);
	while(1){
		ADC_enuStartConversion();

	}


}
void tog(int d){
	o = d;
	*((uint_8*)0x37) |= 0x02;
	*((uint_8*)0x38) ^= (BIT_MASK1 << 1);
	_delay_ms(200);
}
