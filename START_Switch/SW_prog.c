/*
 * SW_prog.c
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#include "std_types.h"
#include "Error_States.h"

#include "SW_config.h"

#include "DIO_int.h"


ES_t SW_enuInit(SW_t* Copy_pstrSwitches){
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrSwitches != NULL){
		uint_8 Local_uint8Iterator;
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

ES_t SW_enuGetState(SW_t* Copy_pstrSwitches, uint_8* Copy_puint8Value){
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrSwitches != NULL && Copy_puint8Value != NULL){
		Local_enuErrorState = DIO_enuGetPinValue(Copy_pstrSwitches->SW_uint8PORTID, Copy_pstrSwitches->SW_uint8PinID, Copy_puint8Value);
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
