/*
 * ADC_prog.c
 *
 *  Created on: Feb 25, 2022
 *      Author: amrmo
 */
#include "std_types.h"
#include "Error_States.h"

#include "ADC_priv.h"
#include "ADC_config.h"


static void (*ADC_pfuncForCallBack) (void*) = NULL;
static void *ADC_pvoidParameter = NULL;

ES_t ADC_enuInit(void){
	ES_t Local_enuErrorStates = ES_NOK;
	/*Switching ON ADC*/
	ADCSRA |= (BIT_MASK1 << ADC_ENABLE_BIT);
	/*Initial set Voltage Reference*/
	ADMUX |= (SELECT_ADC_VOLTAGE << ADC_REF_SELECTION_BITS);
	/*Initial set Prescaler*/
	ADCSRA |= (SELECT_ADC_PRESCALER << ADC_PRESCALER_BITS);
	/*Initial set ADJUSTMENT*/
#if SELECT_ADC_ADJUSTMENT == ADC_uint8RIGHT_ADJUSTED
	ADMUX &= ~(BIT_MASK1 << ADC_ADLAR_BIT);
	Local_enuErrorStates = ES_OK;
#elif SELECT_ADC_ADJUSTMENT == ADC_uint8LEFT_ADJUSTED
	ADMUX |= (BIT_MASK << ADC_ADLAR_BIT);
	Local_enuErrorStates = ES_OK;
#endif

	return Local_enuErrorStates;
}

ES_t ADC_enuEnable(void){
	ES_t Local_enuErrorStates = ES_NOK;
	if(!((ADCSRA >> ADC_ENABLE_BIT) & BIT_MASK1)){
			ADCSRA |= (BIT_MASK1 << ADC_ENABLE_BIT);
			Local_enuErrorStates = ES_OK;
	}
	else{
			Local_enuErrorStates = ES_ALLREADY_IS_SET;
	}
	return Local_enuErrorStates;
}

ES_t ADC_enuDisable(void){
	ES_t Local_enuErrorStates = ES_NOK;
	if(((ADCSRA >> ADC_ENABLE_BIT) & BIT_MASK1)){
		ADCSRA &= ~(BIT_MASK1 << ADC_ENABLE_BIT);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_ALLREADY_IS_CLEARED;
	}
	return Local_enuErrorStates;
}

ES_t ADC_enuSetVoltReference(uint_8 Copy_uint8Voltage){
	ES_t Local_enuErrorStates = ES_NOK;
	ADMUX &= ~(BIT_MASK2 << ADC_REF_SELECTION_BITS);
	ADMUX |= (Copy_uint8Voltage << ADC_REF_SELECTION_BITS);
	return Local_enuErrorStates =  ES_OK;
}

ES_t ADC_enuSetPrescaler(uint_8 Copy_uint8Prescaler){
	ES_t Local_enuErrorStates = ES_NOK;
	ADCSRA &= ~(BIT_MASK3 << ADC_PRESCALER_BITS);
	ADCSRA |= (Copy_uint8Prescaler << ADC_PRESCALER_BITS);
	return Local_enuErrorStates = ES_OK;
}

ES_t ADC_enuSetAdjustment(uint_8 Copy_uint8Adjustment){
	ES_t Local_enuErrorStates = ES_NOK;
	ADMUX &= ~(BIT_MASK1 << ADC_ADLAR_BIT);
	ADMUX |= (Copy_uint8Adjustment << ADC_ADLAR_BIT);
	return Local_enuErrorStates;
}

ES_t ADC_enuAutoTriggerEnable(void){
	ES_t Local_enuErrorStates = ES_NOK;
	if(!((ADCSRA >> ADC_AUTOTRIGGER_BIT) & BIT_MASK1)){
		ADCSRA |= (BIT_MASK1 << ADC_AUTOTRIGGER_BIT);
		ADCSRA |= (BIT_MASK1 << ADC_INTFLAG_BIT);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_ALLREADY_IS_SET;
	}
	return Local_enuErrorStates;
}

ES_t ADC_enuAutoTriggerDisable(void){
	ES_t Local_enuErrorStates = ES_NOK;
	if(((ADCSRA >> ADC_AUTOTRIGGER_BIT) & BIT_MASK1)){
		ADCSRA &= ~(BIT_MASK1 << ADC_AUTOTRIGGER_BIT);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_ALLREADY_IS_CLEARED;
	}
	return Local_enuErrorStates;
}

ES_t ADC_enuTriggerSource(uint_8 Copy_uint8TriggerSource){
	ES_t Local_enuErrorStates = ES_NOK;
	SFIOR &= ~(BIT_MASK3 << ADC_AUTOTRIGGER_SRC_BITS);
	SFIOR |= (Copy_uint8TriggerSource << ADC_AUTOTRIGGER_SRC_BITS);
	return Local_enuErrorStates;
}

ES_t ADC_enuStartConversion(void){
	ES_t Local_enuErrorStates = ES_NOK;
	if(!((ADCSRA >> ADC_STARTCONV_BIT) & BIT_MASK1)){
		ADCSRA |= (BIT_MASK1 << ADC_STARTCONV_BIT);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_ALLREADY_IS_SET;
	}
	return Local_enuErrorStates;
}

ES_t ADC_enuWaitOnFlag(void){
	ES_t Local_enuErrorStates = ES_NOK;

	while(!((ADCSRA >> ADC_INTFLAG_BIT) & BIT_MASK1)); // wait on flag
	ADCSRA |= (BIT_MASK1 << ADC_INTFLAG_BIT);
	Local_enuErrorStates = ES_OK;

	return Local_enuErrorStates;
}

ES_t ADC_enuSelectChannel(uint_8 Copy_uint8Channel){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_uint8Channel <= ADC_MAX_NUM_OF_CHANNELS){	// SELECT CHANNEL
		ADMUX &= ~(BIT_MASK5 << ADC_MUX_BITS);
		ADMUX |= (Copy_uint8Channel << ADC_MUX_BITS);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_CHANNEL_OUT_OF_RANGE;
	}
	return Local_enuErrorStates;
}

ES_t ADC_enuReadValue(sint_16* Copy_sint16ADCValue){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_sint16ADCValue != NULL){
		if(!((ADMUX >> ADC_ADLAR_BIT) & BIT_MASK1)){ // right adjusted
			*Copy_sint16ADCValue = ADC_DATA_REGS;
		}
		else if(((ADMUX >> ADC_ADLAR_BIT) & BIT_MASK1)){ // left adjusted
			*Copy_sint16ADCValue = ADCH;
		}
			Local_enuErrorStates = ES_OK;
	}
	else {
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ES_t ADC_enuEnableInterrupt(void){
	ES_t Local_enuErrorStates = ES_NOK;
	if(!((ADCSRA >> ADC_INTENABLE_BIT) & BIT_MASK1)){
		ADCSRA |= (BIT_MASK1 << ADC_INTENABLE_BIT);
		SREG |= (BIT_MASK1 << I_BIT);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_ALLREADY_IS_SET;
	}
	return Local_enuErrorStates;
}

ES_t ADC_enuDisableInterrupt(void){
	ES_t Local_enuErrorStates = ES_NOK;
	if(((ADCSRA >> ADC_INTENABLE_BIT) & BIT_MASK1)){
		ADCSRA &= ~(BIT_MASK1 << ADC_INTENABLE_BIT);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_ALLREADY_IS_CLEARED;
	}
	return Local_enuErrorStates;
}

ES_t ADC_enuCallBack(void (*Copy_pfuncConfig)(void*), void* Copy_voidParameter){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_pfuncConfig != NULL && Copy_voidParameter != NULL){
		ADC_pfuncForCallBack = Copy_pfuncConfig;
		ADC_pvoidParameter = Copy_voidParameter;
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}
ADC_ISR{
	if(ADC_pfuncForCallBack != NULL && ADC_pvoidParameter != NULL){
		ADC_pfuncForCallBack(ADC_pvoidParameter);
	}
}
