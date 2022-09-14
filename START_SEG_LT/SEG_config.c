/*
 * SEG_config.c
 *
 *  Created on: Feb 22, 2022
 *      Author: amrmo
 */

#include "std_types.h"
#include "Error_States.h"

#include "SEG_config.h"

#include "DIO_int.h"


SEG_t SEG_AstrSevenSegment[SEG_NUM] = {
		{
				COMMON_ANODE, //Type
				DIO_uint8_PORTA, DIO_uint8_PIN7, // COM
				DISCONNECTED, DISCONNECTED, // DOT
				DIO_uint8_PORTA, DIO_uint8_PIN0, // A
				DIO_uint8_PORTA, DIO_uint8_PIN1, // B
				DIO_uint8_PORTA, DIO_uint8_PIN2, // C
				DIO_uint8_PORTA, DIO_uint8_PIN3, // D
				DIO_uint8_PORTA, DIO_uint8_PIN4, // E
				DIO_uint8_PORTA, DIO_uint8_PIN5, // F
				DIO_uint8_PORTA, DIO_uint8_PIN6 // G
		},
		{
				COMMON_CATHOD, // Type
				DISCONNECTED, DISCONNECTED, // COM
				DISCONNECTED, DISCONNECTED, // DOT
				DIO_uint8_PORTB, DIO_uint8_PIN0, // A
				DIO_uint8_PORTB, DIO_uint8_PIN1, // B
				DIO_uint8_PORTB, DIO_uint8_PIN2, // C
				DIO_uint8_PORTB, DIO_uint8_PIN3, // D
				DIO_uint8_PORTB, DIO_uint8_PIN4, // E
				DIO_uint8_PORTB, DIO_uint8_PIN5, // F
				DIO_uint8_PORTB, DIO_uint8_PIN6 // G
		}
};
