/*
 * Switch_config.h
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#ifndef HAL_SWITCH_SWITCH_CONFIG_H_
#define HAL_SWITCH_SWITCH_CONFIG_H_

#define SWITCH_NUM 2
typedef struct{
	u8 SW_Port;
	u8 SW_Pin;
	u8 SW_State;
}SW_t;

#endif /* HAL_SWITCH_SWITCH_CONFIG_H_ */
