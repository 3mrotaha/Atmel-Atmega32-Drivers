/*
 * Switch_prog.c
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Switch_config.h"

extern SW_t  SW_AstrSwitchConfig[SWITCH_NUM];

ES_t SW_enuInit(SW_t *Copy_pstrSwitchConfig){
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrSwitchConfig != NULL){
		u8 Local_u8Iterator;
		for(Local_u8Iterator = 0; Local_u8Iterator< SWITCH_NUM; Local_u8Iterator++){
			DIO_enuSetPinDir(Copy_pstrSwitchConfig[Local_u8Iterator].SW_Port, Copy_pstrSwitchConfig[Local_u8Iterator].SW_Pin, DIO_u8INPUT);
		}
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;

}

ES_t SW_enuGetSwitchState(u8 SwitchID, u8 *SwitchVal){
	ES_t Local_enuErrorState = ES_NOK;

		if(SwitchID <= SWITCH_NUM){
			DIO_enuGetPinValue(SW_AstrSwitchConfig[SwitchID].SW_Port, SW_AstrSwitchConfig[SwitchID].SW_Pin, SwitchVal);
			Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
		}


	return Local_enuErrorState;

}
