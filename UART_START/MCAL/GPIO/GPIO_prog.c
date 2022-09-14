/*
 * GPIO_prog.c
 *
 *  Created on: Mar 20, 2022
 *      Author: amrmo
 */

#include "../../LIB/std_types.h"
#include "../../LIB/Error_States.h"
#include "../../LIB/Bit_Level.h"

#include "GPIO_priv.h"


ES_t GPIO_enuGlobalInterruptEnable(void){
	ES_t Local_enuErrorStates = ES_NOK;
	SREG |= (BIT_MASK1 << I_BIT);
	return Local_enuErrorStates = ES_OK;
}

ES_t GPIO_enuGlobalInterruptDisable(void){
	ES_t Local_enuErrorStates = ES_NOK;
	SREG &= ~(BIT_MASK1 << I_BIT);
	return Local_enuErrorStates = ES_OK;
}
