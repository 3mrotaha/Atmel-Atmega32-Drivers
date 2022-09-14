/*
 * EXINT_prog.c
 *
 *  Created on: Feb 24, 2022
 *      Author: amrmo
 */

#include "std_types.h"
#include "Error_States.h"

#include "EXINT_priv.h"
#include "EXINT_config.h"

void* EXINT_pvoidParameter[EXINT_NUM] = {NULL, NULL, NULL};
void (*EXINT_pvoidfuncCallBack[EXINT_NUM])(void*) = {NULL, NULL, NULL};


ES_t EXINT_enuInit(EXINT_t* Copy_pstrExIntConfig){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_pstrExIntConfig != NULL){
		uint_8 Local_uint8Iterator;
		for(Local_uint8Iterator = 0; Local_uint8Iterator < EXINT_NUM; Local_uint8Iterator++){
			if(Copy_pstrExIntConfig[Local_uint8Iterator].Local_uint8INTConfig == EXINT_ENABLED){
				MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC00_BIT);
				MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC01_BIT);
				MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC10_BIT);
				MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC11_BIT);
				MCUCSR &= ~(EXINT_BIT_MASK << EXINT_ISC2_BIT);
				SREG |= (EXINT_BIT_MASK << EXINT_L_BIT);
				switch(Copy_pstrExIntConfig[Local_uint8Iterator].Local_uint8INTID){
					case EXINT_INT0:
						GICR |= (EXINT_BIT_MASK << EXINT_INT0_BIT);
						MCUCR |= (Copy_pstrExIntConfig[Local_uint8Iterator].Local_uint8TriggerType << EXINT_ISC00_BIT);
						GIFR |= (EXINT_BIT_MASK << EXINT_INT0_BIT);
						Local_enuErrorStates = ES_OK;
						break;
					case EXINT_INT1:
						GICR |= (EXINT_BIT_MASK << EXINT_INT1_BIT);
						MCUCR |= (Copy_pstrExIntConfig[Local_uint8Iterator].Local_uint8TriggerType << EXINT_ISC10_BIT);
						GIFR |= (EXINT_BIT_MASK << EXINT_INT1_BIT);
						Local_enuErrorStates = ES_OK;
						break;
					case EXINT_INT2:
						GICR |= (EXINT_BIT_MASK << EXINT_INT2_BIT);
						if(Copy_pstrExIntConfig[Local_uint8Iterator].Local_uint8TriggerType == EXINT_FALLING_EDGE){
							MCUCSR |= (EXINT2_FALLING_EDGE << EXINT_ISC2_BIT);
						}
						else if(Copy_pstrExIntConfig[Local_uint8Iterator].Local_uint8TriggerType == EXINT_RISING_EDGE){
							MCUCSR |= (EXINT2_RISING_EDGE << EXINT_ISC2_BIT);
						}
						GIFR |= (EXINT_BIT_MASK << EXINT_INT2_BIT);
						Local_enuErrorStates = ES_OK;
						break;
					default:
						Local_enuErrorStates = ES_EXINT_OUT_OF_RANGE;
						break;
				}
			}
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}

	return Local_enuErrorStates;
}

ES_t EXINT_enuIntEnable(EXINT_t* Copy_pstrExIntConfig, uint_8 Copy_uint8TriggerType){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_pstrExIntConfig != NULL){
		SREG |= (EXINT_BIT_MASK << EXINT_L_BIT);
		switch(Copy_pstrExIntConfig->Local_uint8INTID){
			case EXINT_INT0:
				MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC00_BIT);
				MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC01_BIT);
				GICR |= (EXINT_BIT_MASK << EXINT_INT0_BIT);
				MCUCR |= (Copy_uint8TriggerType << EXINT_ISC00_BIT);
				GIFR |= (EXINT_BIT_MASK << EXINT_INT0_BIT);
				Local_enuErrorStates = ES_OK;
				break;
			case EXINT_INT1:
				MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC10_BIT);
				MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC11_BIT);
				GICR |= (EXINT_BIT_MASK << EXINT_INT1_BIT);
				MCUCR |= (Copy_uint8TriggerType << EXINT_ISC10_BIT);
				GIFR |= (EXINT_BIT_MASK << EXINT_INT1_BIT);
				Local_enuErrorStates = ES_OK;
				break;
			case EXINT_INT2:
				MCUCSR &= ~(EXINT_BIT_MASK << EXINT_ISC2_BIT);
				GICR |= (EXINT_BIT_MASK << EXINT_INT2_BIT);
				MCUCSR |= (Copy_uint8TriggerType << EXINT_ISC2_BIT);
				GIFR |= (EXINT_BIT_MASK << EXINT_INT2_BIT);
				Local_enuErrorStates = ES_OK;
				break;
		default:
			Local_enuErrorStates = ES_EXINT_OUT_OF_RANGE;
			break;
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ES_t EXINT_enuIntDisable(EXINT_t* Copy_pstrExIntConfig){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_pstrExIntConfig != NULL){
		switch(Copy_pstrExIntConfig->Local_uint8INTID){
		case EXINT_INT0:
			GICR &= ~(EXINT_BIT_MASK << EXINT_INT0_BIT);
			MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC00_BIT);
			MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC01_BIT);
			Local_enuErrorStates = ES_OK;
			break;
		case EXINT_INT1:
			GICR &= ~(EXINT_BIT_MASK << EXINT_INT1_BIT);
			MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC10_BIT);
			MCUCR &= ~(EXINT_BIT_MASK << EXINT_ISC11_BIT);
			Local_enuErrorStates = ES_OK;
			break;
		case EXINT_INT2:
			GICR &= ~(EXINT_BIT_MASK << EXINT_INT2_BIT);
			MCUCSR &= ~(EXINT_BIT_MASK << EXINT_ISC2_BIT);
			Local_enuErrorStates = ES_OK;
			break;
		default:
			Local_enuErrorStates = ES_EXINT_OUT_OF_RANGE;
			break;
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ES_t EXINT_enuCallBack(void (*Copy_pvoidfunCall)(void*), void *Copy_pvoidParameter, uint_8 Copy_uint8IntID){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_pvoidfunCall != NULL && Copy_pvoidParameter != NULL){
		switch(Copy_uint8IntID){
			case EXINT_INT0:
				EXINT_pvoidfuncCallBack[EXINT_INT0] = Copy_pvoidfunCall;
				EXINT_pvoidParameter[EXINT_INT0] = Copy_pvoidParameter;
				Local_enuErrorStates = ES_OK;
				break;
			case EXINT_INT1:
				EXINT_pvoidfuncCallBack[EXINT_INT1] = Copy_pvoidfunCall;
				EXINT_pvoidParameter[EXINT_INT1] = Copy_pvoidParameter;
				Local_enuErrorStates = ES_OK;
				break;
			case EXINT_INT2:
				EXINT_pvoidfuncCallBack[EXINT_INT2] = Copy_pvoidfunCall;
				EXINT_pvoidParameter[EXINT_INT2] = Copy_pvoidParameter;
				Local_enuErrorStates = ES_OK;
				break;
			default:
				Local_enuErrorStates = ES_EXINT_OUT_OF_RANGE;
				break;
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

EXINT0_ISR{
	if(EXINT_pvoidfuncCallBack[EXINT_INT0] != NULL && EXINT_pvoidParameter[EXINT_INT0] != NULL){
		EXINT_pvoidfuncCallBack[EXINT_INT0](EXINT_pvoidParameter[EXINT_INT0]);
	}
}

EXINT1_ISR{
	if(EXINT_pvoidfuncCallBack[EXINT_INT1] != NULL && EXINT_pvoidParameter[EXINT_INT1] != NULL){
		EXINT_pvoidfuncCallBack[EXINT_INT1](EXINT_pvoidParameter[EXINT_INT1]);
	}
}

EXINT2_ISR{
	if(EXINT_pvoidfuncCallBack[EXINT_INT2] != NULL && EXINT_pvoidParameter[EXINT_INT2] != NULL){
		EXINT_pvoidfuncCallBack[EXINT_INT2](EXINT_pvoidParameter[EXINT_INT2]);
	}
}
