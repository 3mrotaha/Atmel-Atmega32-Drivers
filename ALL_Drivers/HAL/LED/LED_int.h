/*
 * LED_int.h
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

ES_t LED_enuInit(LED_t *Copy_pstrLedConfig);

ES_t LED_enuLedON(u8 Copy_u8LedID);

ES_t LED_enuLedOFF(u8 Copy_u8LedID);

#endif /* HAL_LED_LED_INT_H_ */
