/*
 * KPAD_config.c
 *
 *  Created on: Feb 23, 2022
 *      Author: amrmo
 */

#include "../../LIB/std_types.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "KPAD_config.h"


KPAD_t KPAD_AstrKeyPadConfig[NUM_OF_KPADS] = {
	{
		{
				{DIO_uint8_PORTA, DIO_uint8_PIN0},
				{DIO_uint8_PORTA, DIO_uint8_PIN1},
				{DIO_uint8_PORTA, DIO_uint8_PIN2},
				{DIO_uint8_PORTA, DIO_uint8_PIN3}
		},
		{
				{DIO_uint8_PORTA, DIO_uint8_PIN4},
				{DIO_uint8_PORTA, DIO_uint8_PIN5},
				{DIO_uint8_PORTA, DIO_uint8_PIN6},
				{DIO_uint8_PORTA, DIO_uint8_PIN7}
		}
	}
};
