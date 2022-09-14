/*
 * KPAD_prog.c
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_int.h"


#include "KPAD_config.h"
#include "KPAD_priv.h"

extern PAD_t KPAD_AstrKeyPadConfig[NUM_KPAD];

ES_t KPAD_enuInit(PAD_t *Copy_pstrKeysConfig){
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrKeysConfig != NULL){
		u8 Local_u8Iterator, Local_ROWSIterator, Local_COLSIterator;
		for(Local_u8Iterator = 0; Local_u8Iterator < NUM_KPAD; Local_u8Iterator++){

			for(Local_ROWSIterator = 0; Local_ROWSIterator < NUM_ROWS; Local_ROWSIterator++){
				DIO_enuSetPinDir(Copy_pstrKeysConfig[Local_u8Iterator].KROWS[Local_ROWSIterator].R_Port, Copy_pstrKeysConfig[Local_u8Iterator].KROWS[Local_ROWSIterator].R_Pin, DIO_u8INPUT);
				DIO_enuSetPinValue(Copy_pstrKeysConfig[Local_u8Iterator].KROWS[Local_ROWSIterator].R_Port, Copy_pstrKeysConfig[Local_u8Iterator].KROWS[Local_ROWSIterator].R_Pin,  DIO_u8PULL_UP);
			}
			for(Local_COLSIterator = 0; Local_COLSIterator < NUM_COLS; Local_COLSIterator++){
				DIO_enuSetPinDir(Copy_pstrKeysConfig[Local_u8Iterator].KCOLS[Local_COLSIterator].C_Port, Copy_pstrKeysConfig[Local_u8Iterator].KCOLS[Local_COLSIterator].C_Pin,  DIO_u8OUTPUT);
				DIO_enuSetPinValue(Copy_pstrKeysConfig[Local_u8Iterator].KCOLS[Local_COLSIterator].C_Port, Copy_pstrKeysConfig[Local_u8Iterator].KCOLS[Local_COLSIterator].C_Pin,  DIO_u8HIGH);
			}


		}
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

ES_t KPAD_enuGetKeyValue(u8 Copy_u8KpadID, u8 *Copy_u8Value){

	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_u8Value != NULL)
		{

			*Copy_u8Value = KEY_NOT_PRESSED;

			u8 Local_Au8KeyValues[NUM_ROWS][NUM_COLS] = KEYS_VALUES;

			u8 Local_u8PinValue = KEY_NOT_PRESSED;

			u8 Local_u8RowIter , Local_u8ColIter;

			for (Local_u8ColIter =0; Local_u8ColIter < NUM_COLS ; Local_u8ColIter ++)
			{
				DIO_enuSetPinValue(KPAD_AstrKeyPadConfig[Copy_u8KpadID].KCOLS[Local_u8ColIter].C_Port,KPAD_AstrKeyPadConfig[Copy_u8KpadID].KCOLS[Local_u8ColIter].C_Pin, DIO_u8LOW);

				for (Local_u8RowIter =0 ; Local_u8RowIter < NUM_ROWS ; Local_u8RowIter ++)
				{
					DIO_enuGetPinValue(KPAD_AstrKeyPadConfig[Copy_u8KpadID].KROWS[Local_u8RowIter].R_Port, KPAD_AstrKeyPadConfig[Copy_u8KpadID].KROWS[Local_u8RowIter].R_Pin, &Local_u8PinValue);
					if (! Local_u8PinValue)
					{
						_delay_ms(10);
						DIO_enuGetPinValue(KPAD_AstrKeyPadConfig[Copy_u8KpadID].KROWS[Local_u8RowIter].R_Port, KPAD_AstrKeyPadConfig[Copy_u8KpadID].KROWS[Local_u8RowIter].R_Pin, &Local_u8PinValue);
						if (! Local_u8PinValue)
						{
							while (! Local_u8PinValue)
							{
								DIO_enuGetPinValue(KPAD_AstrKeyPadConfig[Copy_u8KpadID].KROWS[Local_u8RowIter].R_Port, KPAD_AstrKeyPadConfig[Copy_u8KpadID].KROWS[Local_u8RowIter].R_Pin, &Local_u8PinValue);
							}

							*Copy_u8Value = Local_Au8KeyValues[Local_u8RowIter][Local_u8ColIter];

							return Local_enuErrorState=ES_OK;
						}
					}
				}

				DIO_enuSetPinValue(KPAD_AstrKeyPadConfig[Copy_u8KpadID].KCOLS[Local_u8ColIter].C_Port,KPAD_AstrKeyPadConfig[Copy_u8KpadID].KCOLS[Local_u8ColIter].C_Pin, DIO_u8HIGH);
			}
		}
		else
		{
			Local_enuErrorState = ES_NULL_POINTER;
		}
	return Local_enuErrorState;
}
