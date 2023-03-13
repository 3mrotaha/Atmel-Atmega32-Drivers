/*
 * DC_config.h
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#ifndef HAL_DC_MOTOR_DC_CONFIG_H_
#define HAL_DC_MOTOR_DC_CONFIG_H_

#define NUM_MOTORS	1
#define SPEED_CONTROL_PIN1	5
#define SPEED_CONTROL_PIN2	4
#define MOTOR_NORMAL_SPEED  6

typedef struct{
	uint8 DC_Port1;
	uint8 DC_Pin1;

	uint8 DC_Port2;
	uint8 DC_Pin2;

	uint8 DC_Dir;
	uint8 DC_SpeedCtrlPin;
}DC_t;

#endif /* HAL_DC_MOTOR_DC_CONFIG_H_ */
