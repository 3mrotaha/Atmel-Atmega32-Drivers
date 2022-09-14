/*
 * DC_config.c
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */


#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "DC_config.h"
#include "DC_priv.h"


DC_t DC_AstrMotorConfig[NUM_MOTORS] = {
		{DIO_u8PORTB, DIO_u8PIN4, DIO_u8PORTB, DIO_u8PIN7, CLOCKWISE}
};
