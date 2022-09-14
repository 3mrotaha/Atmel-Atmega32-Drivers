/*
 * LED_config.c
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "LED_config.h"
#include "LED_priv.h"


LED_t LED_AstrLEDConfig[LED_NUM] = {
		{DIO_u8PORTD, DIO_u8PIN0, DIO_u8LOW, LED_IS_SOURCE},
		{DIO_u8PORTD, DIO_u8PIN7, DIO_u8HIGH, LED_IS_SINK},
		{DIO_u8PORTB, DIO_u8PIN2, DIO_u8LOW, LED_IS_SOURCE}
};

// SINK MEANS THAT THE OUTPUT OF THE PIN WOULD BE 0 TO ACTIVATE

// SOURCE MEANS THAT THE OUTPUT OF THE PIN WOULD BE 1 TO ACTIVATE
