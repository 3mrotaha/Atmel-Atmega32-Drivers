/*
 * LED_prog.c
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "LED_priv.h"
#include "LED_config.h"

LED_t LED_AstrLEDConfig[LED_NUM];

ES_t LED_enuInit(LED_t *Copy_pstrLedConfig){
	ES_t Local_enuErrorStete = ES_NOK;

	if(Copy_pstrLedConfig != NULL){
		u8 Local_u8Iterator;
		for(Local_u8Iterator = 0; Local_u8Iterator < LED_NUM; Local_u8Iterator++){
			DIO_enuSetPinDir(Copy_pstrLedConfig[Local_u8Iterator].LED_Port, Copy_pstrLedConfig[Local_u8Iterator].LED_pin, DIO_u8OUTPUT);

			if(Copy_pstrLedConfig[Local_u8Iterator].LED_Connection == LED_IS_SINK){
				DIO_enuSetPinValue(Copy_pstrLedConfig[Local_u8Iterator].LED_Port, Copy_pstrLedConfig[Local_u8Iterator].LED_pin, DIO_u8HIGH);
			}
			else if(Copy_pstrLedConfig[Local_u8Iterator].LED_Connection == LED_IS_SOURCE){
				DIO_enuSetPinValue(Copy_pstrLedConfig[Local_u8Iterator].LED_Port, Copy_pstrLedConfig[Local_u8Iterator].LED_pin, DIO_u8LOW);
			}
		}
		Local_enuErrorStete = ES_OK;
	}
	else{
		Local_enuErrorStete = ES_NULL_POINTER;
	}
	return Local_enuErrorStete;
}

ES_t LED_enuLedON(u8 Copy_u8LedID){
	ES_t Local_enuErrorStete = ES_NOK;


		if(Copy_u8LedID <= LED_NUM){
			if(LED_AstrLEDConfig[Copy_u8LedID].LED_Connection == LED_IS_SINK){
				DIO_enuSetPinValue(LED_AstrLEDConfig[Copy_u8LedID].LED_Port, LED_AstrLEDConfig[Copy_u8LedID].LED_pin, DIO_u8LOW);
			}
			else if(LED_AstrLEDConfig[Copy_u8LedID].LED_Connection == LED_IS_SOURCE){
				DIO_enuSetPinValue(LED_AstrLEDConfig[Copy_u8LedID].LED_Port, LED_AstrLEDConfig[Copy_u8LedID].LED_pin, DIO_u8HIGH);
			}
			Local_enuErrorStete = ES_OK;
		}
		else{
			Local_enuErrorStete = ES_COMPONENT_OUT_OF_RANGE;
		}


	return Local_enuErrorStete;
}

ES_t LED_enuLedOFF(u8 Copy_u8LedID){
	ES_t Local_enuErrorStete = ES_NOK;


		if(Copy_u8LedID <= LED_NUM){
			if(LED_AstrLEDConfig[Copy_u8LedID].LED_Connection == LED_IS_SINK){
				DIO_enuSetPinValue(LED_AstrLEDConfig[Copy_u8LedID].LED_Port, LED_AstrLEDConfig[Copy_u8LedID].LED_pin, DIO_u8HIGH);
			}
			else if(LED_AstrLEDConfig[Copy_u8LedID].LED_Connection == LED_IS_SOURCE){
				DIO_enuSetPinValue(LED_AstrLEDConfig[Copy_u8LedID].LED_Port, LED_AstrLEDConfig[Copy_u8LedID].LED_pin, DIO_u8LOW);
			}
			Local_enuErrorStete = ES_OK;
		}
		else{
			Local_enuErrorStete = ES_COMPONENT_OUT_OF_RANGE;
		}


	return Local_enuErrorStete;
}
