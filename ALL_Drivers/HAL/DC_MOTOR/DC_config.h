/*
 * DC_config.h
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#ifndef HAL_DC_MOTOR_DC_CONFIG_H_
#define HAL_DC_MOTOR_DC_CONFIG_H_

#define NUM_MOTORS	1

typedef struct{
	u8 DC_Port1;
	u8 DC_Pin1;

	u8 DC_Port2;
	u8 DC_Pin2;

	u8 DC_Dir;
}DC_t;

#endif /* HAL_DC_MOTOR_DC_CONFIG_H_ */
