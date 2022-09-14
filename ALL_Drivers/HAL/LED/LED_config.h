/*
 * LED_config.h
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#ifndef HAL_LED_LED_CONFIG_H_
#define HAL_LED_LED_CONFIG_H_

#define LED_NUM  3
typedef struct{
	u8 LED_Port;
	u8 LED_pin;
	u8 LED_State;
	u8 LED_Connection;
}LED_t;

#endif /* HAL_LED_LED_CONFIG_H_ */
