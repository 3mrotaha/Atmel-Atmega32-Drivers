/*
 * KPAD_config.c
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */


#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "KPAD_config.h"

/*Please Set The Port and The Pin Number for the KeyPad Rows And Columns*/

PAD_t KPAD_AstrKeyPadConfig[NUM_KPAD] = {
		/*For the KeyPad Number 1*/
		{
				/*Set the ROWS Ports And Pins*/
			 {
				{DIO_u8PORTC,DIO_u8PIN4}, 	//	ROW 1
				{DIO_u8PORTD,DIO_u8PIN4},	// 	ROW	2
				{DIO_u8PORTD,DIO_u8PIN5},	//	ROW	3
				{DIO_u8PORTD,DIO_u8PIN6}	//	ROW	4
			},
				/*Set the COLUMNS Ports And Pins */
			 {
				{DIO_u8PORTC, DIO_u8PIN7},  //	COLUMN 	1
				{DIO_u8PORTD, DIO_u8PIN1},  // 	COLUMN	2
				{DIO_u8PORTD, DIO_u8PIN2},  //	COLUMN	3
				{DIO_u8PORTD, DIO_u8PIN3}   //	COLUMN	4
			}
		},

		/*For the KeyPad Number 2*/

		{
				/*Set the ROWS Ports And Pins*/
			 {
				{DIO_u8PORTC,DIO_u8PIN1}, 	//	ROW 1
				{DIO_u8PORTA,DIO_u8PIN4},	// 	ROW	2
				{DIO_u8PORTA,DIO_u8PIN5},	//	ROW	3
				{DIO_u8PORTA,DIO_u8PIN6}	//	ROW	4
			},
				/*Set the COLUMNS Ports And Pins */
			 {
				{DIO_u8PORTC, DIO_u8PIN2},  //	COLUMN 	1
				{DIO_u8PORTA, DIO_u8PIN1},  // 	COLUMN	2
				{DIO_u8PORTA, DIO_u8PIN2},  //	COLUMN	3
				{DIO_u8PORTA, DIO_u8PIN3}   //	COLUMN	4
			}
		}


		/*For the KeyPad Number 3*/



};


