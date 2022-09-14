/*
 * SSegment_config.c
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */


#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "SSegment_config.h"
#include "SSegment_priv.h"

SEG_t SSegment_Astr7SegConfig[NUM_SEV_SEGMENTS] = {
		{
			DIO_u8PORTB, DIO_u8PIN0,
			DIO_u8PORTB, DIO_u8PIN1,
			DIO_u8PORTB, DIO_u8PIN2,
			DIO_u8PORTB, DIO_u8PIN3,
			DIO_u8PORTB, DIO_u8PIN4,
			DIO_u8PORTB, DIO_u8PIN5,
			DIO_u8PORTB, DIO_u8PIN6,

			DIO_u8PORTD, DIO_u8PIN0,

			NOT_CONNECTED, NOT_CONNECTED,


			COMMON_CATHODE

		}, // SEG1

		{
			DIO_u8PORTC, DIO_u8PIN0,
			DIO_u8PORTC, DIO_u8PIN3,
			DIO_u8PORTC, DIO_u8PIN5,
			DIO_u8PORTC, DIO_u8PIN6,
			DIO_u8PORTD, DIO_u8PIN7,
			DIO_u8PORTB, DIO_u8PIN7,
			DIO_u8PORTA, DIO_u8PIN7,

			DIO_u8PORTA, DIO_u8PIN0,

			NOT_CONNECTED, NOT_CONNECTED,

			COMMON_ANODE

		} // SEG2
};
