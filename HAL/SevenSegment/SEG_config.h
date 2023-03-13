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

	uint8 Common_Type;

	uint8 Common_Port;
	uint8 Common_Pin;

	uint8 Dot_Port;
	uint8 Dot_Pin;

	uint8 A_Port;
	uint8 A_Pin;

	uint8 B_Port;
	uint8 B_Pin;

	uint8 C_Port;
	uint8 C_Pin;

	uint8 D_Port;
	uint8 D_Pin;

	uint8 E_Port;
	uint8 E_Pin;

	uint8 F_Port;
	uint8 F_Pin;

	uint8 G_Port;
	uint8 G_Pin;

}SEG_t;

#endif /* SEG_CONFIG_H_ */
