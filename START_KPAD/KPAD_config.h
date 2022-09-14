/*
 * KPAD_config.h
 *
 *  Created on: Feb 23, 2022
 *      Author: amrmo
 */

#ifndef KPAD_CONFIG_H_
#define KPAD_CONFIG_H_

#define NUM_OF_KPADS	1

#define NUM_OF_COLUMNS	4
#define NUM_OF_ROWS		4


typedef struct{
	struct{
		uint_8 R_uint8Port;
		uint_8 R_uint8Pin;
	}KPAD_strRows[NUM_OF_ROWS];

	struct{
			uint_8 C_uint8Port;
			uint_8 C_uint8Pin;
		}KPAD_strCols[NUM_OF_COLUMNS];
}KPAD_t;

#define PAD_KEY_VALUES	{\
		{ 7, 8, 9, '+'},\
		{ 4, 5, 6, '-'},\
		{ 1, 2, 3, 'x'},\
		{'c',0,'=', '/'}\
	}
#endif /* KPAD_CONFIG_H_ */
