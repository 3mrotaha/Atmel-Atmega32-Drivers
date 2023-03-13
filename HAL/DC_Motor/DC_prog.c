/*
 * DC_prog.c
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */


#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"
#include "../../MCAL/DIO/DIO_config.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/Timer1/TIMER1_int.h"
#include "../../MCAL/Timer1/TIMER1_priv.h"
#include "../../MCAL/Timer1/TIMER1_config.h"

#include "DC_config.h"
#include "DC_priv.h"

extern DC_t DC_AstrMotorConfig[NUM_MOTORS] ;

ErrorStates_t DC_enuInit(DC_t *Copy_pstrMotorConfig){
	ErrorStates_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrMotorConfig != NULL){
	uint8 Local_uint8Iterator;
		for(Local_uint8Iterator = 0; Local_uint8Iterator < NUM_MOTORS; Local_uint8Iterator++){
			DIO_enuSetPinDir(Copy_pstrMotorConfig[Local_uint8Iterator].DC_Port1, Copy_pstrMotorConfig[Local_uint8Iterator].DC_Pin1, OUTPUT);
			DIO_enuSetPinDir(Copy_pstrMotorConfig[Local_uint8Iterator].DC_Port2, Copy_pstrMotorConfig[Local_uint8Iterator].DC_Pin2, OUTPUT);

			DIO_enuSetPinValue(Copy_pstrMotorConfig[Local_uint8Iterator].DC_Port1, Copy_pstrMotorConfig[Local_uint8Iterator].DC_Pin1, LOW);
			DIO_enuSetPinValue(Copy_pstrMotorConfig[Local_uint8Iterator].DC_Port2, Copy_pstrMotorConfig[Local_uint8Iterator].DC_Pin2, LOW);
			if(Copy_pstrMotorConfig[Local_uint8Iterator].DC_SpeedCtrlPin != MOTOR_NORMAL_SPEED){
				TIMER1_enuInit();				
				TIMER1_enuSetWaveMode(TIMER1_WAVE_GEN_MODE, 0x0000);
				if(Copy_pstrMotorConfig[Local_uint8Iterator].DC_SpeedCtrlPin == SPEED_CONTROL_PIN1){
					TIMER1_enuCTC_OC1A(0, TIMER1_COMPA_OUTPUT_MODE);
				}
				else{
					TIMER1_enuCTC_OC1B(0, TIMER1_COMPB_OUTPUT_MODE);
				}
			}
		}
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

ErrorStates_t DC_enuSetMotorDir(uint8 Copy_uint8MotorID, uint8 Copy_uint8Direction){
	ErrorStates_t Local_enuErrorState = ES_NOK;

	if(Copy_uint8MotorID < NUM_MOTORS && (Copy_uint8Direction == CLOCKWISE || Copy_uint8Direction == ANTICLOCKWISE)){
			switch(Copy_uint8Direction){
			case CLOCKWISE:
				DIO_enuSetPinValue(DC_AstrMotorConfig[Copy_uint8MotorID].DC_Port1, DC_AstrMotorConfig[Copy_uint8MotorID].DC_Pin1, HIGH);
				DIO_enuSetPinValue(DC_AstrMotorConfig[Copy_uint8MotorID].DC_Port2, DC_AstrMotorConfig[Copy_uint8MotorID].DC_Pin2, LOW);

				break;
			case ANTICLOCKWISE:
				DIO_enuSetPinValue(DC_AstrMotorConfig[Copy_uint8MotorID].DC_Port1, DC_AstrMotorConfig[Copy_uint8MotorID].DC_Pin1, LOW);
				DIO_enuSetPinValue(DC_AstrMotorConfig[Copy_uint8MotorID].DC_Port2, DC_AstrMotorConfig[Copy_uint8MotorID].DC_Pin2, HIGH);
				break;
			}
			Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
		}

	return Local_enuErrorState;
}

ErrorStates_t DC_enuTogMotorDir(uint8 Copy_uint8MotorID){
	ErrorStates_t Local_enuErrorState = ES_NOK;

		if(Copy_uint8MotorID < NUM_MOTORS){
			DIO_enuTogPinValue(DC_AstrMotorConfig[Copy_uint8MotorID].DC_Port1, DC_AstrMotorConfig[Copy_uint8MotorID].DC_Pin1);
			DIO_enuTogPinValue(DC_AstrMotorConfig[Copy_uint8MotorID].DC_Port2, DC_AstrMotorConfig[Copy_uint8MotorID].DC_Pin2);

			Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
		}

	return Local_enuErrorState;
}

ErrorStates_t DC_enuControlSpeed(uint8 MotorID, uint8 Copy_uint8Speed){
	if(MotorID < NUM_MOTORS){
		switch(DC_AstrMotorConfig[MotorID].DC_SpeedCtrlPin){
			case SPEED_CONTROL_PIN1:
				TIMER1_enuGeneratePWM_OC1A((uint16) ((Copy_uint8Speed/100.0) * 255.0), TIMER1_COMPA_OUTPUT_MODE);
				break;
			case SPEED_CONTROL_PIN2:
				TIMER1_enuGeneratePWM_OC1B((uint16) ((Copy_uint8Speed/100.0) * 255.0), TIMER1_COMPB_OUTPUT_MODE);
				break;
			default:
				return ES_PIN_OUT_OF_RANGE;
		}
		return ES_OK;
	}
}
