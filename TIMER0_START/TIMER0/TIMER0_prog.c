/*
 * TIMER0_prog.c
 *
 *  Created on: Feb 28, 2022
 *      Author: amrmo
 */


#include "../LIB/std_types.h"
#include "../LIB/Error_States.h"

#include "../DIO/DIO_int.h"

#include "TIMER0_priv.h"
#include "TIMER0_config.h"


static uint_32 TIMER0_uint32NumOVF;
static uint_8 TIMER0_uint32Preload;

static void (*TIMER0_ApfuncCalledFuncs[2])(void*) = {NULL, NULL};
static void* TIMER0_ApvoidParameters[2] = {NULL, NULL};

ES_t TIMER0_enuInit(void){
	ES_t Local_enuErrorStates = ES_NOK;

	TCCR0 &= ~(BIT_MASK3 << TIMER0_CLOCKSELECT_BITS);
	TCCR0 |= (SELECT_CLOCK_SOURCE << TIMER0_CLOCKSELECT_BITS);
	TCCR0 &= ~(BIT_MASK2 << TIMER0_COM_BITS);
	TCCR0 |= (SELECT_COMPARE_OUTPUT_MODE << TIMER0_COM_BITS);
	TIMSK &= ~(BIT_MASK1 << TIMER0_TOIE0_BIT);
	TIMSK &= ~(BIT_MASK1 << TIMER0_OCIE0_BIT);

#if SELECT_WAVE_GENERATION_MODE == TIMER0_OVF_MODE
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM01_BIT);

	Local_enuErrorStates = ES_OK;
#elif SELECT_WAVE_GENERATION_MODE == TIMER0_PHASE_CORRECT_PWM_MODE
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM01_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM00_BIT);
	Local_enuErrorStates = ES_OK;
#elif SELECT_WAVE_GENERATION_MODE == TIMER0_CTC_MODE
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM01_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM01_BIT);
	Local_enuErrorStates = ES_OK;
#elif SELECT_WAVE_GENERATION_MODE == TIMER0_FAST_PWM_MODE
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM01_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM01_BIT);
	Local_enuErrorStates = ES_OK;
#else
#error "Error! you didn't select the wave generation mode"
#endif

	return Local_enuErrorStates;
}

ES_t TIMER0_enuSetSyncDelay(uint_32 Copy_uint32TimeMS){
	ES_t Local_enuErrorStates = ES_NOK;

	f32 Local_f32OVFTime = 256 * ((f32)PRESCALED_CLOCK_SOURCE / SELECT_TIMER_FREQ);
	f32 Local_f32NumOVF = Copy_uint32TimeMS/Local_f32OVFTime;
	uint_32 Local_uint32NumOVF_int = (uint_32)Local_f32NumOVF + 1;

	if((Local_f32NumOVF - (uint_32)Local_f32NumOVF) != 0.0){
		f32 Local_uint8Preload = 256.0 - (256.0 * (Local_f32NumOVF - (uint_32)Local_f32NumOVF));
		if((Local_uint8Preload - (uint_32)Local_uint8Preload) >= 0.5 && (Local_uint8Preload - (uint_32)Local_uint8Preload) < 1){
			TCNT0 = (uint_8)Local_uint8Preload + 1;
		}
		else{
			TCNT0 = (uint_8)Local_uint8Preload;
		}
	}
	else{
		TIMER0_uint32NumOVF = (uint_32)Local_f32NumOVF;
		TCNT0 = 0;
	}

	while(Local_uint32NumOVF_int){
		while(!((TIFR >> TIMER0_TOV0_BIT) & BIT_MASK1));
		TIFR |= (BIT_MASK1 << TIMER0_TOV0_BIT);
		Local_uint32NumOVF_int--;
	}
	return Local_enuErrorStates = ES_OK;
}

ES_t TIMER0_enuSetAsyncDelay(uint_32 Copy_uint32TimeMS, void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter){
	ES_t Local_enuErrorStates = ES_NOK;

	TIMSK |= (BIT_MASK1 << TIMER0_TOIE0_BIT);
	f32 Local_f32OVFTime = 256 * ((f32)PRESCALED_CLOCK_SOURCE / SELECT_TIMER_FREQ);
	f32 Local_f32NumOVF = Copy_uint32TimeMS/Local_f32OVFTime;
	uint_32 Local_uint32NumOVF_int = (uint_32)Local_f32NumOVF + 1;

	if((Local_f32NumOVF - (uint_32)Local_f32NumOVF) != 0.0){
		TIMER0_uint32NumOVF = Local_uint32NumOVF_int;
		uint_8 Local_uint8Preload = 256.0 - (256.0 * (Local_f32NumOVF - (uint_32)Local_f32NumOVF));
		TCNT0 = Local_uint8Preload;
		TIMER0_uint32Preload = Local_uint8Preload;
	}
	else{
		TCNT0 = 0;
		TIMER0_uint32Preload = 0;
		TIMER0_uint32NumOVF = (uint_32)Local_f32NumOVF;
	}

	if(Copy_pfuncCallFunc != NULL){
		TIMER0_ApfuncCalledFuncs[TIMER0_INT_OVF] = Copy_pfuncCallFunc;
		TIMER0_ApvoidParameters[TIMER0_INT_OVF] = Copy_pvoidParameter;
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ES_t TIMER0_enuEnableOVFInterrupt(void){
	ES_t Local_enuErrorStates = ES_NOK;
	TIMSK |= (BIT_MASK1 << TIMER0_TOIE0_BIT);
	return Local_enuErrorStates = ES_OK;
}

ES_t TIMER0_enuDisableOVFInterrupt(void){
	ES_t Local_enuErrorStates = ES_NOK;
	TIMSK &= ~(BIT_MASK1 << TIMER0_TOIE0_BIT);
	return Local_enuErrorStates = ES_OK;
}

ES_t TIMER0_enuSetCompareMatch(uint_8 Copy_uint8Counts, uint_8 Copy_uint8OCMode){
	ES_t Local_enuErrorStates = ES_NOK;
	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN3, OUTPUT);
	TCCR0 &= ~(BIT_MASK2 << TIMER0_COM_BITS);
	TCCR0 |= (Copy_uint8OCMode << TIMER0_COM_BITS);
	OCR0 = Copy_uint8Counts;
	TIMSK |= (BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates;
}

ES_t TIMER0_enuCorrectPhasePWM(uint_8 Copy_uint8Counts, uint_8 Copy_uint8OCMode){
	ES_t Local_enuErrorStates = ES_NOK;
	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN3, OUTPUT);
	TCCR0 &= ~(BIT_MASK2 << TIMER0_COM_BITS);
	TCCR0 |= (Copy_uint8OCMode << TIMER0_COM_BITS);
	OCR0 = Copy_uint8Counts;
	TIMSK |= (BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates;
}

ES_t TIMER0_enuFastPWM(uint_8 Copy_uint8Counts, uint_8 Copy_uint8OCMode){
	ES_t Local_enuErrorStates = ES_NOK;
	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN3, OUTPUT);
	TCCR0 &= ~(BIT_MASK2 << TIMER0_COM_BITS);
	TCCR0 |= (Copy_uint8OCMode << TIMER0_COM_BITS);
	OCR0 = Copy_uint8Counts;
	TIMSK |= (BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates;
}

ES_t TIMER0_enuEnableCOMPInterrupt(void){
	ES_t Local_enuErrorStates = ES_NOK;
	TIMSK |= (BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates = ES_OK;
}

ES_t TIMER0_enuDisableCOMPInterrupt(void){
	ES_t Local_enuErrorStates = ES_NOK;
	TIMSK &= ~(BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates = ES_OK;
}

ES_t TIMER0_enuCTCCallBack(void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter){

	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_pfuncCallFunc != NULL){
		TIMER0_ApfuncCalledFuncs[TIMER0_INT_COMP] = Copy_pfuncCallFunc;
		TIMER0_ApvoidParameters[TIMER0_INT_COMP] = Copy_pvoidParameter;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}


ES_t TIMER0_enuFastPWMByDutyCycle(f32 Copy_uint8DutyCycle, uint_8 Copy_uint8OCMode){
	ES_t Local_enuErrorStates = ES_NOK;

	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN3, OUTPUT);

	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM01_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM01_BIT);

	TCCR0 &= ~(BIT_MASK2 << TIMER0_COM_BITS);
	TCCR0 |= (Copy_uint8OCMode << TIMER0_COM_BITS);

	OCR0 = (uint_8)(Copy_uint8DutyCycle * 256.0);

	TIMSK |= (BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates;
}

ES_t TIMER0_enuPhaseCorrectByDutyCycle(f32 Copy_uint8DutyCycle, uint_8 Copy_uint8OCMode){
	ES_t Local_enuErrorStates = ES_NOK;

	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN3, OUTPUT);

	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM00_BIT);
	TCCR0 &= ~(BIT_MASK1 << TIMER0_WGM01_BIT);
	TCCR0 |= (BIT_MASK1 << TIMER0_WGM00_BIT);

	TCCR0 &= ~(BIT_MASK2 << TIMER0_COM_BITS);
	TCCR0 |= (Copy_uint8OCMode << TIMER0_COM_BITS);

	OCR0 = (uint_8)(Copy_uint8DutyCycle * 255.0);

	TIMSK |= (BIT_MASK1 << TIMER0_OCIE0_BIT);
	return Local_enuErrorStates;
}

TIMER0_OVF_ISR{

	static uint_32 counts = 0;
	if(TIMER0_ApfuncCalledFuncs[TIMER0_INT_OVF] != NULL){
		counts++;
		if(counts == TIMER0_uint32NumOVF){
			counts = 0;
			TCNT0 = TIMER0_uint32Preload;
			TIMER0_ApfuncCalledFuncs[TIMER0_INT_OVF](TIMER0_ApvoidParameters[TIMER0_INT_OVF]);
		}
	}
}

TIMER0_COMP_ISR{
	if(TIMER0_ApfuncCalledFuncs[TIMER0_INT_COMP] != NULL){
		TIMER0_ApfuncCalledFuncs[TIMER0_INT_COMP](TIMER0_ApvoidParameters[TIMER0_INT_COMP]);
	}
}
