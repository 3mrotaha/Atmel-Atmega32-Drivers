/*
 * TIMER2_prog.c
 *
 *  Created on: Mar 14, 2022
 *      Author: amrmo
 */

#include "../../LIB/std_types.h"
#include "../../LIB/Error_States.h"

#include "../DIO/DIO_int.h"

#include "TIMER2_priv.h"
#include "TIMER2_config.h"


static volatile uint_32 TIMER2_uint32NumOVF;
static volatile uint_8 TIMER2_uint32Preload;

static volatile void (*TIMER2_PfInterruptConfig[TIMER2_INTERRUPTS]) (void*) = {NULL, NULL};
static volatile void *TIMER2_PParameters[TIMER2_INTERRUPTS]= {NULL, NULL};

ES_t TIMER2_enuInit(void){
	ES_t Local_enuErrorStates= ES_NOK;

	/* Set Prescaler */
	TCCR2 &= ~(BIT_MASK3 << CS20_BIT);
	TCCR2 |= (TIMER2_PRESCALER << CS20_BIT);

	/* Set Wave Generation Mode */
	TCCR2 &= ~(BIT_MASK1 << WGM20_BIT);
	TCCR2 &= ~(BIT_MASK1 << WGM21_BIT);
	TCCR2 |= ((TIMER2_WAVE_GENERATON_MODE & BIT_MASK1) << WGM20_BIT);
	TCCR2 |= (((TIMER2_WAVE_GENERATON_MODE >> BIT_MASK1) & BIT_MASK1) << WGM21_BIT);

	/*Set Compare Output Mode*/
	TCCR2 &= ~(BIT_MASK2 << COM20_BIT);
	TCCR2 |= (TIMER2_COMPARE_OUTPUT_MODE << COM20_BIT);
	return Local_enuErrorStates;
}

ES_t TIMER2_enuSyncDelay(uint_32 Copy_uint32TimeMs){
	ES_t Local_enuErrorStates= ES_NOK;
	f32 Local_f32OVFTime = 256.0 * ((f32)TIMER2_PRESCALER_VALUE / TIMER2_CLOCK_FREQUANCY); // time for single overflow
	f32 Local_f32NumOVF = Copy_uint32TimeMs / Local_f32OVFTime; // NUM of overflows required

	uint_32 Local_uint32NumOvf_int = (uint_32) Local_f32NumOVF + 1;
	if(Local_f32NumOVF - (uint_32)Local_f32NumOVF != 0){
		uint_8 Local_uint8Preload = 256.0 - (256.0 * (Local_f32NumOVF - (uint_32)Local_f32NumOVF));
		TCNT2 = (uint_8)Local_uint8Preload;
	}

	while(Local_uint32NumOvf_int){
		while(!((TIFR >> TOV2_BIT) & BIT_MASK1));
		TIFR |= (BIT_MASK1 << TOV2_BIT);
		Local_uint32NumOvf_int--;
	}
	return Local_enuErrorStates = ES_OK;
}

ES_t TIMER2_enuAsyncDelay(uint_32 Copy_uint32TimeMs, void (*Copy_pfConfig)(void*), void* Copy_pParameter){
	ES_t Local_enuErrorStates= ES_NOK;

	f32 Local_f32OVFTime = 256.0 * ((f32)TIMER2_PRESCALER_VALUE / TIMER2_CLOCK_FREQUANCY); // time for single overflow
	f32 Local_f32NumOVF = Copy_uint32TimeMs / Local_f32OVFTime; // NUM of overflows required

	uint_32 Local_uint32NumOvf_int = (uint_32) Local_f32NumOVF + 1;

	if(Local_f32NumOVF - (uint_32)Local_f32NumOVF != 0){
		uint_8 Local_uint8Preload = 256.0 - (256.0 * (Local_f32NumOVF - (uint_32)Local_f32NumOVF));
		TCNT2 = TIMER2_uint32Preload = Local_uint8Preload;
		OCR2 = TIMER2_uint32Preload;
	}

	TIMER2_uint32NumOVF = Local_uint32NumOvf_int;

	if(Copy_pfConfig != NULL){
		TIMER2_PfInterruptConfig[TIMER2_OVF_INT] = Copy_pfConfig;
		TIMER2_PParameters[TIMER2_OVF_INT] = Copy_pParameter;
		SREG |= (BIT_MASK1 << I_BIT);
		TIMSK |= (BIT_MASK1 << TOIE2_BIT);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}

	return Local_enuErrorStates;
}

ES_t TIMER2_enuOutputCompare(uint_8 Copy_uint8OCRCounts, uint_8 Copy_uint8OCMode){
	ES_t Local_enuErrorStates= ES_NOK;
	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTD, DIO_uint8_PIN7, OUTPUT);
	OCR2 = Copy_uint8OCRCounts;
	TCCR2 &= ~(BIT_MASK2 << COM20_BIT);
	TCCR2 |= (Copy_uint8OCMode << COM20_BIT);
	return Local_enuErrorStates;
}

ES_t TIMER2_enuSetWaveGenMode(uint_8 Copy_uint8WaveMode){
	ES_t Local_enuErrorStates = ES_NOK;
	TCCR2 &= ~(BIT_MASK1 << WGM20_BIT);
	TCCR2 &= ~(BIT_MASK1 << WGM21_BIT);
	TCCR2 |= ((Copy_uint8WaveMode & BIT_MASK1) << WGM20_BIT);
	TCCR2 |= (((Copy_uint8WaveMode >> BIT_MASK1) & BIT_MASK1) << WGM21_BIT);
	return Local_enuErrorStates;
}

ES_t TIMER2_enuGeneratePWM(uint_8 Copy_uint8OCMode, uint_8 Copy_uint8OCRcounts){
	ES_t Local_enuErrorStates= ES_NOK;
	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTD, DIO_uint8_PIN7, OUTPUT);
	OCR2 = Copy_uint8OCRcounts;
	TCCR2 &= ~(BIT_MASK2 << COM20_BIT);
	TCCR2 |= (Copy_uint8OCMode << COM20_BIT);
	return Local_enuErrorStates;
}

ES_t TIMER2_enuCallBack(void (*Copy_pfConfig)(void*), void* Copy_pParameter){
	ES_t Local_enuErrorStates= ES_NOK;
	if(Copy_pfConfig != NULL){
		TIMER2_PfInterruptConfig[TIMER2_COMP_INT] = Copy_pfConfig;
		TIMER2_PParameters[TIMER2_COMP_INT] = Copy_pParameter;
		SREG |= (BIT_MASK1 << I_BIT);
		TIMSK |= (BIT_MASK1 << OCIE2_BIT);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ISR(TIMER2_OVF_VECT){
	static uint_32 Local_uint32Counts = 0;
	if(TIMER2_PfInterruptConfig[TIMER2_OVF_INT] != NULL){
		Local_uint32Counts+=1;
		if(Local_uint32Counts == TIMER2_uint32NumOVF){
			Local_uint32Counts = 0;
			TCNT2 = TIMER2_uint32Preload;
			TIMER2_PfInterruptConfig[TIMER2_OVF_INT](TIMER2_PParameters[TIMER2_OVF_INT]);
		}

	}
}

ISR(TIMER2_COMP_VECT){
	if(TIMER2_PfInterruptConfig != NULL){
		TIMER2_PfInterruptConfig[TIMER2_COMP_INT](TIMER2_PParameters[TIMER2_COMP_INT]);
	}
}
