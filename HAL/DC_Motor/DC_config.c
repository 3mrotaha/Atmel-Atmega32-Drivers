/*
 * DC_config.c
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */


#include "../../LIB/ErrorStates.h"
#include "../../LIB/std_types.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "DC_config.h"
#include "DC_priv.h"


DC_t DC_AstrMotorConfig[NUM_MOTORS] = {
		{DIO_uint8_PORTD, DIO_uint8_PIN5, DIO_uint8_PORTB, DIO_uint8_PIN7, ANTICLOCKWISE, SPEED_CONTROL_PIN1}
};
