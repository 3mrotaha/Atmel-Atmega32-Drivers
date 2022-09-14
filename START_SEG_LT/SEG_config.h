/*
 * SEG_config.h
 *
 *  Created on: Feb 22, 2022
 *      Author: amrmo
 */

#ifndef SEG_CONFIG_H_
#define SEG_CONFIG_H_

#define SEG_NUM		2

#define COMMON_ANODE	20
#define COMMON_CATHOD	30
#define DISCONNECTED	40

typedef struct{

	uint_8 Common_Type;

	uint_8 Common_Port;
	uint_8 Common_Pin;

	uint_8 Dot_Port;
	uint_8 Dot_Pin;

	uint_8 A_Port;
	uint_8 A_Pin;

	uint_8 B_Port;
	uint_8 B_Pin;

	uint_8 C_Port;
	uint_8 C_Pin;

	uint_8 D_Port;
	uint_8 D_Pin;

	uint_8 E_Port;
	uint_8 E_Pin;

	uint_8 F_Port;
	uint_8 F_Pin;

	uint_8 G_Port;
	uint_8 G_Pin;

}SEG_t;

#endif /* SEG_CONFIG_H_ */
