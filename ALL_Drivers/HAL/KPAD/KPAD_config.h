/*
 * KPAD_config.h
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#ifndef HAL_KPAD_KPAD_CONFIG_H_
#define HAL_KPAD_KPAD_CONFIG_H_

#define NUM_KPAD 	2

#define NUM_COLS	4
#define NUM_ROWS	4

typedef struct{

	 struct{
		u8 R_Port;
		u8 R_Pin;
	}KROWS[NUM_ROWS];

	 struct{
		u8 C_Port;
		u8 C_Pin;
	}KCOLS[NUM_COLS];

}PAD_t;

#define KEYS_VALUES		{\
		{7,8,9,'+'},\
		{4,5,6,'-'},\
		{1,2,3,'x'},\
		{'c',0,'=', '/'}\
	}

#endif /* HAL_KPAD_KPAD_CONFIG_H_ */
