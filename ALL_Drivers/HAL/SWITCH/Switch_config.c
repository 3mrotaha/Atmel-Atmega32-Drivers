/*
 * Switch_config.c
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Switch_config.h"
#include "Switch_priv.h"

SW_t  SW_AstrSwitchConfig[SWITCH_NUM] = {
		{DIO_u8PORTC, DIO_u8PIN1, DIO_u8PULL_UP},
		{DIO_u8PORTC, DIO_u8PIN3, DIO_u8PULL_UP}
};
