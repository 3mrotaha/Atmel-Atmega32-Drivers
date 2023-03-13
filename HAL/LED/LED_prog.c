/*
 * LED_prog.c
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"

#include "LED_config.h"
#include "LED_priv.h"

#include "../../MCAL/DIO/DIO_int.h"


ErrorStates_t LED_enuInit(LED_t* Copy_pstrLeds){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_pstrLeds != NULL){
		uint8 Local_uint8Iterator;
		for(Local_uint8Iterator = 0; Local_uint8Iterator < LED_NUM; Local_uint8Iterator++){
			Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrLeds[Local_uint8Iterator].SW_uint8PORTID, Copy_pstrLeds[Local_uint8Iterator].SW_uint8PinID, OUTPUT);
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrLeds[Local_uint8Iterator].SW_uint8PORTID, Copy_pstrLeds[Local_uint8Iterator].SW_uint8PinID, Copy_pstrLeds[Local_uint8Iterator].SW_uint8State);
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}

	return Local_enuErrorStates;
}

ErrorStates_t LED_enuTurnON(LED_t* Copy_pstrLeds){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_pstrLeds != NULL){
		if(Copy_pstrLeds->SW_uint8Connection == LED_uint8SINK){
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrLeds->SW_uint8PORTID, Copy_pstrLeds->SW_uint8PinID, LOW);
		}
		else if(Copy_pstrLeds->SW_uint8Connection == LED_uint8SOURCE){
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrLeds->SW_uint8PORTID, Copy_pstrLeds->SW_uint8PinID, HIGH);
		}
		else{
			Local_enuErrorStates = ES_OUT_OF_RANGE;
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}

	return Local_enuErrorStates;
}

ErrorStates_t LED_enuTurnOFF(LED_t* Copy_pstrLeds){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	if(Copy_pstrLeds != NULL){
			if(Copy_pstrLeds->SW_uint8Connection == LED_uint8SINK){
				Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrLeds->SW_uint8PORTID, Copy_pstrLeds->SW_uint8PinID, HIGH);
			}
			else if(Copy_pstrLeds->SW_uint8Connection == LED_uint8SOURCE){
				Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrLeds->SW_uint8PORTID, Copy_pstrLeds->SW_uint8PinID, LOW);
			}
			else{
				Local_enuErrorStates = ES_OUT_OF_RANGE;
			}
		}
		else{
			Local_enuErrorStates = ES_NULL_POINTER;
		}

	return Local_enuErrorStates;
}
