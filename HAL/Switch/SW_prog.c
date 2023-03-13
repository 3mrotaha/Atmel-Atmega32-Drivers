/*
 * SW_prog.c
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"

#include "SW_config.h"

#include "../../MCAL/DIO/DIO_int.h"


ErrorStates_t SW_enuInit(SW_t* Copy_pstrSwitches){
	ErrorStates_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrSwitches != NULL){
		uint8 Local_uint8Iterator;
		for(Local_uint8Iterator = 0; Local_uint8Iterator < SW_NUM; Local_uint8Iterator++){
			Local_enuErrorState = DIO_enuSetPinDir(Copy_pstrSwitches[Local_uint8Iterator].SW_uint8PORTID, Copy_pstrSwitches[Local_uint8Iterator].SW_uint8PinID, INPUT);
			Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrSwitches[Local_uint8Iterator].SW_uint8PORTID, Copy_pstrSwitches[Local_uint8Iterator].SW_uint8PinID, Copy_pstrSwitches[Local_uint8Iterator].SW_uint8State);
		}
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ErrorStates_t SW_enuGetState(SW_t* Copy_pstrSwitches, uint8* Copy_puint8Value){
	ErrorStates_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrSwitches != NULL && Copy_puint8Value != NULL){
		Local_enuErrorState = DIO_enuGetPinValue(Copy_pstrSwitches->SW_uint8PORTID, Copy_pstrSwitches->SW_uint8PinID, Copy_puint8Value);
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
