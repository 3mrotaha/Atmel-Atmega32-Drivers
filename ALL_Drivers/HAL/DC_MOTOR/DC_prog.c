/*
 * DC_prog.c
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */


#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "DC_config.h"
#include "DC_priv.h"

extern DC_t DC_AstrMotorConfig[NUM_MOTORS] ;

ES_t DC_enuInit(DC_t *Copy_pstrMotorConfig){
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrMotorConfig != NULL){
	u8 Local_u8Iterator;
		for(Local_u8Iterator = 0; Local_u8Iterator < NUM_MOTORS; Local_u8Iterator++){
			DIO_enuSetPinDir(Copy_pstrMotorConfig[Local_u8Iterator].DC_Port1, Copy_pstrMotorConfig[Local_u8Iterator].DC_Pin1, DIO_u8OUTPUT);
			DIO_enuSetPinDir(Copy_pstrMotorConfig[Local_u8Iterator].DC_Port2, Copy_pstrMotorConfig[Local_u8Iterator].DC_Pin2, DIO_u8OUTPUT);

			DIO_enuSetPinValue(Copy_pstrMotorConfig[Local_u8Iterator].DC_Port1, Copy_pstrMotorConfig[Local_u8Iterator].DC_Pin1, DIO_u8LOW);
			DIO_enuSetPinValue(Copy_pstrMotorConfig[Local_u8Iterator].DC_Port2, Copy_pstrMotorConfig[Local_u8Iterator].DC_Pin2, DIO_u8LOW);

		}
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

ES_t DC_enuSetMotorDir(u8 Copy_u8MotorID, u8 Copy_u8Direction){
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8MotorID <= NUM_MOTORS && (Copy_u8Direction == CLOCKWISE || Copy_u8Direction == ANTICLOCKWISE)){
			switch(Copy_u8Direction){
			case CLOCKWISE:
				DIO_enuSetPinValue(DC_AstrMotorConfig[Copy_u8MotorID].DC_Port1, DC_AstrMotorConfig[Copy_u8MotorID].DC_Pin1, DIO_u8HIGH);
				DIO_enuSetPinValue(DC_AstrMotorConfig[Copy_u8MotorID].DC_Port2, DC_AstrMotorConfig[Copy_u8MotorID].DC_Pin2, DIO_u8LOW);

				break;
			case ANTICLOCKWISE:
				DIO_enuSetPinValue(DC_AstrMotorConfig[Copy_u8MotorID].DC_Port1, DC_AstrMotorConfig[Copy_u8MotorID].DC_Pin1, DIO_u8LOW);
				DIO_enuSetPinValue(DC_AstrMotorConfig[Copy_u8MotorID].DC_Port2, DC_AstrMotorConfig[Copy_u8MotorID].DC_Pin2, DIO_u8HIGH);
				break;
			}
			Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
		}

	return Local_enuErrorState;
}

ES_t DC_enuTogMotorDir(u8 Copy_u8MotorID){
	ES_t Local_enuErrorState = ES_NOK;

		if(Copy_u8MotorID <= NUM_MOTORS){
			DIO_enuTogPinValue(DC_AstrMotorConfig[Copy_u8MotorID].DC_Port1, DC_AstrMotorConfig[Copy_u8MotorID].DC_Pin1);
			DIO_enuTogPinValue(DC_AstrMotorConfig[Copy_u8MotorID].DC_Port2, DC_AstrMotorConfig[Copy_u8MotorID].DC_Pin2);

			Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
		}

	return Local_enuErrorState;
}
