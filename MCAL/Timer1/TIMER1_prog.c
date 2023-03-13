/*
 * TIMER1_prog.c
 *
 *  Created on: Mar 7, 2022
 *      Author: amrmo
 */


#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"
#include "../../LIB/Bit_Level.h"
#include "../../LIB/GPRs.h"
#include "../DIO/DIO_int.h"

#include "TIMER1_priv.h"
#include "TIMER1_config.h"

void (*TIMER1_PfInterruptFuncs[TIMER1_INTERRUPTS])(void*) = {NULL, NULL, NULL, NULL};
void *TIMER1_PfuntionsParameters[TIMER1_INTERRUPTS] = {NULL, NULL, NULL, NULL};

uint32 TIMER1_AsyncOVFs = 0;
uint32 TIMER1_AsyncPreload = 0;

ErrorStates_t TIMER1_enuInit(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	// SET TIMER1 PRESCALER
	TCCR1B &= ~(BIT_MASK3 << CS10_BIT);
	TCCR1B |= (TIMER1_PRESCALER << CS10_BIT);

	// SET TIMER1 COMPARE MATCH A AND B
	TCCR1A &= ~(BIT_MASK4 << COM1B0_BIT);
	TCCR1A |= (TIMER1_COMPB_OUTPUT_MODE << COM1B0_BIT);
	TCCR1A |= (TIMER1_COMPA_OUTPUT_MODE << COM1A0_BIT);

	// SET WAVE GENERATION MODE
	TCCR1A &= ~(BIT_MASK2 << WGM10_BIT);
	TCCR1B &= ~(BIT_MASK2 << WGM12_BIT);
	TCCR1A |= ((TIMER1_WAVE_GEN_MODE & BIT_MASK2) << WGM10_BIT);
	TCCR1B |= (((TIMER1_WAVE_GEN_MODE >> 2) & BIT_MASK2) << WGM12_BIT);

	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t TIMER1_enuSyncDelay(uint32 Copy_uint32TimeMs){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	f32_t Local_TimeOVF = TIMER1_TOTAL_COUNTS * ((f32_t)TIMER1_PRESCALER_VALUE/TIMER1_FREQUANCY);
	f32_t Local_NumOVF = (f32_t)Copy_uint32TimeMs / Local_TimeOVF;
	uint32 Local_NumOVF_int = (uint32) Local_NumOVF + 1;
	if((Local_NumOVF - (uint32) Local_NumOVF)){
		uint16 Local_uint16Preload = TIMER1_TOTAL_COUNTS - (TIMER1_TOTAL_COUNTS * (f32_t)(Local_NumOVF - (uint32) Local_NumOVF));
		TCNT1 = Local_uint16Preload;
	}

	while(Local_NumOVF_int){
		while(!((TIFR >> TOV1_BIT) & BIT_MASK1));
		TIFR |= (BIT_MASK1 << TOV1_BIT);
		Local_NumOVF_int -= 1;
	}

	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t TIMER1_enuASyncDelay(uint32 Copy_uint32TimeMs, void (*Copy_pfDelay) (void*), void* Copy_pParameter){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	f32_t Local_TimeOVF = TIMER1_TOTAL_COUNTS * ((f32_t)TIMER1_PRESCALER_VALUE/TIMER1_FREQUANCY);
	f32_t Local_NumOVF = (f32_t)Copy_uint32TimeMs / Local_TimeOVF;
	uint32 Local_NumOVF_int = (uint32) Local_NumOVF + 1;
	if((Local_NumOVF - (uint32) Local_NumOVF)){
		uint16 Local_uint16Preload = TIMER1_TOTAL_COUNTS - (TIMER1_TOTAL_COUNTS * (f32_t)(Local_NumOVF - (uint32) Local_NumOVF));
		TCNT1 = Local_uint16Preload;
		TIMER1_AsyncPreload = Local_uint16Preload;
	}

	TIMER1_AsyncOVFs = Local_NumOVF_int;
	if(Copy_pfDelay != NULL){
		TIMER1_PfInterruptFuncs[TIMER1_OVF_INT] = Copy_pfDelay;
		TIMER1_PfuntionsParameters[TIMER1_OVF_INT] = Copy_pParameter;
		TIMSK |= (BIT_MASK1 << TOIE1_BIT);
		SREG |= (BIT_MASK1 << I_BIT);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}


ErrorStates_t TIMER1_enuCompareOutput_OCR1A(uint16 Copy_uint16CompMatch, uint8 Copy_CompMode, void (*Copy_pfCTC) (void*), void* Copy_pParameter){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	DIO_enuSetPinDir(DIO_uint8_PORTD, DIO_uint8_PIN5, OUTPUT);
	OCR1A = Copy_uint16CompMatch;
	TCCR1A |= (Copy_CompMode << COM1A0_BIT);

	if(Copy_pfCTC != NULL){
		TIMER1_PfInterruptFuncs[TIMER1_COMPA_INT] = Copy_pfCTC;
		TIMER1_PfuntionsParameters[TIMER1_COMPA_INT] = Copy_pParameter;
		TIMSK |= (BIT_MASK1 << OCIE1A_BIT);
		SREG |= (BIT_MASK1 << I_BIT);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ErrorStates_t TIMER1_enuCompareOutput_OCR1B(uint16 Copy_uint16CompMatch, uint8 Copy_CompMode, void (*Copy_pfCTC) (void*), void* Copy_pParameter){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

		DIO_enuSetPinDir(DIO_uint8_PORTD, DIO_uint8_PIN5, OUTPUT);
		OCR1B = Copy_uint16CompMatch;
		TCCR1A |= (Copy_CompMode << COM1B0_BIT);

		if(Copy_pfCTC != NULL){
			TIMER1_PfInterruptFuncs[TIMER1_COMPB_INT] = Copy_pfCTC;
			TIMER1_PfuntionsParameters[TIMER1_COMPB_INT] = Copy_pParameter;
			TIMSK |= (BIT_MASK1 << OCIE1B_BIT);
			SREG |= (BIT_MASK1 << I_BIT);
			Local_enuErrorStates = ES_OK;
		}
		else{
			Local_enuErrorStates = ES_NULL_POINTER;
		}
		return Local_enuErrorStates;
}

ErrorStates_t TIMER1_enuSetWaveMode(uint8 Copy_uint8WaveMode,  uint16 Copy_uint16TcntTop){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	TCCR1A &= ~(BIT_MASK2 << WGM10_BIT);
	TCCR1B &= ~(BIT_MASK2 << WGM12_BIT);
	TCCR1A |= ((Copy_uint8WaveMode & BIT_MASK2) << WGM10_BIT);
	TCCR1B |= (((Copy_uint8WaveMode >> 2) & BIT_MASK2) << WGM12_BIT);
	// Defining the top of tcnt1 by ocr1a or icr1
	if(Copy_uint8WaveMode == PWM_PHASE_AND_FREQUANCY_CORRECT_ICR_TOP ||Copy_uint8WaveMode == PWM_PHASE_CORRECT_ICR_TOP ||
			Copy_uint8WaveMode == FAST_PWM_ICR_TOP ||Copy_uint8WaveMode == CTC_MODE_ICR_TOP){
		// Defining the Top by ICR1
		ICR1 = Copy_uint16TcntTop;
		Local_enuErrorStates = ES_OK;
	}
	else if(Copy_uint8WaveMode == CTC_MODE_OCR_TOP || Copy_uint8WaveMode == PWM_PHASE_AND_FREQUANCY_CORRECT_OCR_TOP ||
			Copy_uint8WaveMode == PWM_PHASE_CORRECT_OCR_TOP || Copy_uint8WaveMode == FAST_PWM_OCR_TOP){
		// Defining the Top by OCR1A
		OCR1A = Copy_uint16TcntTop;
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_TOP_IS_NOT_SELECTED;
	}
	return Local_enuErrorStates;
}

ErrorStates_t TIMER1_enuGeneratePWM_OC1A(uint16 Copy_uint16OCRAValue, uint8 Copy_uint8CompMode){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTD, DIO_uint8_PIN5, OUTPUT);

	OCR1A = Copy_uint16OCRAValue;

	//TCCR1A &= ~(BIT_MASK2 << COM1A0_BIT);
	//TCCR1A |= (Copy_uint8CompMode << COM1A0_BIT);

	return Local_enuErrorStates;
}

ErrorStates_t TIMER1_enuGeneratePWM_OC1B(uint16 Copy_uint16OCRBValue, uint8 Copy_uint8CompMode){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTD, DIO_uint8_PIN4, OUTPUT);

	OCR1B = Copy_uint16OCRBValue;

	TCCR1A &= ~(BIT_MASK2 << COM1B0_BIT);
	TCCR1A |= (Copy_uint8CompMode << COM1B0_BIT);

	return Local_enuErrorStates;
}

ErrorStates_t TIMER1_enuCTC_OC1A(uint16 Copy_uint16OCRAValue, uint8 Copy_uint8CompMode){
	ErrorStates_t Local_enuErrorState = ES_NOK;
	Local_enuErrorState = DIO_enuSetPinDir(DIO_uint8_PORTD, DIO_uint8_PIN5, OUTPUT);

	TCCR1A &= ~(BIT_MASK2 << COM1A0_BIT);
	TCCR1A |= (Copy_uint8CompMode << COM1A0_BIT);

	OCR1A = Copy_uint16OCRAValue;

	return Local_enuErrorState;
}

ErrorStates_t TIMER1_enuCTC_OC1B(uint16 Copy_uint16OCRBValue, uint8 Copy_uint8CompMode){
	ErrorStates_t Local_enuErrorState = ES_NOK;
	Local_enuErrorState = DIO_enuSetPinDir(DIO_uint8_PORTD, DIO_uint8_PIN4, OUTPUT);

	TCCR1A &= ~(BIT_MASK2 << COM1B0_BIT);
	TCCR1A |= (Copy_uint8CompMode << COM1B0_BIT);

	OCR1B = Copy_uint16OCRBValue;

	return Local_enuErrorState;
}

ErrorStates_t TIMER1_enuInputCaptureEnable(uint8 Copy_uint8NoiseCanceller, uint8 Copy_uint8Edge){
	ErrorStates_t Local_enuErrorStates =  ES_NOK;
	Local_enuErrorStates = DIO_enuSetPinDir(DIO_uint8_PORTD, DIO_uint8_PIN6, INPUT);
	// Manipulate the Noise Canceller
	TCCR1B &= ~(BIT_MASK1 << ICNC_BIT);
	TCCR1B |= (Copy_uint8NoiseCanceller << ICNC_BIT);

	// Detecting the Edge of Input Capture
	TCCR1B &= ~(BIT_MASK1 << ICES1_BIT);
	TCCR1B |= (Copy_uint8Edge << ICES1_BIT);

	return Local_enuErrorStates;
}

ErrorStates_t TIMER1_enuGetInputCapture(uint16 *Copy_puint16CaptValue){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_puint16CaptValue != NULL){
		while(!((TIFR >> ICF1_BIT) & BIT_MASK1));

		*Copy_puint16CaptValue = ICR1;

		TIFR |= (BIT_MASK1 << ICF1_BIT);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}


ErrorStates_t TIMER1_enuCallBack(void (*Copy_PfFunctionConfig)(void*), void* Copy_Pparameter, uint8 Copy_uint8InterruptType){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_PfFunctionConfig != NULL){
		SREG |= (BIT_MASK1 << I_BIT);
		if(Copy_uint8InterruptType == TIMER1_COMPA_INT){
			TIMER1_PfInterruptFuncs[Copy_uint8InterruptType] = Copy_PfFunctionConfig;
			TIMER1_PfuntionsParameters[Copy_uint8InterruptType] = Copy_Pparameter;
			TIMSK |= (BIT_MASK1 << OCIE1A_BIT);
			Local_enuErrorStates = ES_OK;
		}
		else if(Copy_uint8InterruptType == TIMER1_COMPB_INT){
			TIMER1_PfInterruptFuncs[Copy_uint8InterruptType] = Copy_PfFunctionConfig;
			TIMER1_PfuntionsParameters[Copy_uint8InterruptType] = Copy_Pparameter;
			TIMSK |= (BIT_MASK1 << OCIE1B_BIT);
			Local_enuErrorStates = ES_OK;
		}
		else if (Copy_uint8InterruptType == TIMER1_ICR_INT) {
			TIMER1_PfInterruptFuncs[Copy_uint8InterruptType] = Copy_PfFunctionConfig;
			TIMER1_PfuntionsParameters[Copy_uint8InterruptType] = Copy_Pparameter;
			TIMSK |= (BIT_MASK1 << TICIE1_BIT);
			Local_enuErrorStates = ES_OK;
		}
		else{
			Local_enuErrorStates = ES_CALL_OUT_OF_RANGE;
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ISR(TIMER1_OVF_VECT){
	static uint32 Local_uint32countOVF = 0;
	if(TIMER1_PfInterruptFuncs[TIMER1_OVF_INT] != NULL){
		Local_uint32countOVF++;
		if(Local_uint32countOVF == TIMER1_AsyncOVFs){
			TIMER1_PfInterruptFuncs[TIMER1_OVF_INT](TIMER1_PfuntionsParameters[TIMER1_OVF_INT]);
			Local_uint32countOVF = 0;
			TCNT1 = TIMER1_AsyncPreload;
		}
	}
}

ISR(TIMER1_COMPA_VECT){
	if(TIMER1_PfInterruptFuncs[TIMER1_COMPA_INT] != NULL){
		TIMER1_PfInterruptFuncs[TIMER1_COMPA_INT](TIMER1_PfuntionsParameters[TIMER1_COMPA_INT]);
	}
}

ISR(TIMER1_COMPB_VECT){
	if(TIMER1_PfInterruptFuncs[TIMER1_COMPB_INT] != NULL){
		TIMER1_PfInterruptFuncs[TIMER1_COMPB_INT](TIMER1_PfuntionsParameters[TIMER1_COMPB_INT]);
	}
}

ISR(TIMER1_CAPT_VECT){
	if(TIMER1_PfInterruptFuncs[TIMER1_ICR_INT] != NULL){
		TIMER1_PfInterruptFuncs[TIMER1_ICR_INT](TIMER1_PfuntionsParameters[TIMER1_ICR_INT]);
	}
}
