/*
 * KPAD_prog.c
 *
 *  Created on: Feb 23, 2022
 *      Author: amrmo
 */

#include "std_types.h"
#include "Error_States.h"

#include "DIO_priv.h"
#include "DIO_int.h"

#include "KPAD_config.h"
#include "KPAD_priv.h"

#include "util/delay.h"

extern uint_8 KPAD_Auint8PadKeys[NUM_OF_ROWS][NUM_OF_COLUMNS];

ES_t KPAD_enuInit(KPAD_t* Copy_pstrKeyPadConfig){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_pstrKeyPadConfig != NULL){
		uint_8 Local_uint8Iterator1;
		uint_8 Local_uint8Iterator2;
		for(Local_uint8Iterator1 = 0; Local_uint8Iterator1 < NUM_OF_KPADS; Local_uint8Iterator1++){

			for(Local_uint8Iterator2 = 0; Local_uint8Iterator2 < NUM_OF_ROWS; Local_uint8Iterator2++){
				Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrKeyPadConfig[Local_uint8Iterator1].KPAD_strRows[Local_uint8Iterator2].R_uint8Port, Copy_pstrKeyPadConfig[Local_uint8Iterator1].KPAD_strRows[Local_uint8Iterator2].R_uint8Pin, INPUT);
				Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrKeyPadConfig[Local_uint8Iterator1].KPAD_strRows[Local_uint8Iterator2].R_uint8Port, Copy_pstrKeyPadConfig[Local_uint8Iterator1].KPAD_strRows[Local_uint8Iterator2].R_uint8Pin, PULL_UP);
			}

			for(Local_uint8Iterator2 = 0; Local_uint8Iterator2 < NUM_OF_ROWS; Local_uint8Iterator2++){
				Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrKeyPadConfig[Local_uint8Iterator1].KPAD_strCols[Local_uint8Iterator2].C_uint8Port, Copy_pstrKeyPadConfig[Local_uint8Iterator1].KPAD_strCols[Local_uint8Iterator2].C_uint8Pin, OUTPUT);
				Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrKeyPadConfig[Local_uint8Iterator1].KPAD_strCols[Local_uint8Iterator2].C_uint8Port, Copy_pstrKeyPadConfig[Local_uint8Iterator1].KPAD_strCols[Local_uint8Iterator2].C_uint8Pin, HIGH);
			}
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ES_t KPAD_enuGetPressedkey(KPAD_t* Copy_pstrKeyPadConfig, uint_8* Copy_puint8Value){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_pstrKeyPadConfig != NULL && Copy_puint8Value != NULL){
		*Copy_puint8Value = 0;
		uint_8 Local_uint8RowsIterator, Local_uint8ColsIterator, Local_uint_8GetKey;

		for(Local_uint8ColsIterator = 0; Local_uint8ColsIterator < NUM_OF_COLUMNS; Local_uint8ColsIterator++){
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrKeyPadConfig->KPAD_strCols[Local_uint8ColsIterator].C_uint8Port, Copy_pstrKeyPadConfig->KPAD_strCols[Local_uint8ColsIterator].C_uint8Pin, LOW);
			for(Local_uint8RowsIterator = 0; Local_uint8RowsIterator < NUM_OF_ROWS; Local_uint8RowsIterator++){
				Local_enuErrorStates = DIO_enuGetPinValue(Copy_pstrKeyPadConfig->KPAD_strRows[Local_uint8RowsIterator].R_uint8Port, Copy_pstrKeyPadConfig->KPAD_strRows[Local_uint8RowsIterator].R_uint8Pin, &Local_uint_8GetKey);
				if(!Local_uint_8GetKey){
					_delay_ms(5);
					Local_enuErrorStates = DIO_enuGetPinValue(Copy_pstrKeyPadConfig->KPAD_strRows[Local_uint8RowsIterator].R_uint8Port, Copy_pstrKeyPadConfig->KPAD_strRows[Local_uint8RowsIterator].R_uint8Pin, &Local_uint_8GetKey);
					if(!Local_uint_8GetKey){
						_delay_ms(5);
						while(!Local_uint_8GetKey){
							Local_enuErrorStates = DIO_enuGetPinValue(Copy_pstrKeyPadConfig->KPAD_strRows[Local_uint8RowsIterator].R_uint8Port, Copy_pstrKeyPadConfig->KPAD_strRows[Local_uint8RowsIterator].R_uint8Pin, &Local_uint_8GetKey);
						}
						*Copy_puint8Value = KPAD_Auint8PadKeys[Local_uint8RowsIterator][Local_uint8ColsIterator];
					}
				}
			}
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrKeyPadConfig->KPAD_strCols[Local_uint8ColsIterator].C_uint8Port, Copy_pstrKeyPadConfig->KPAD_strCols[Local_uint8ColsIterator].C_uint8Pin, HIGH);
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}
