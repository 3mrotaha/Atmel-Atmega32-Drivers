/*
 * LED_int.h
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#define LED_SINK	8
#define LED_SOURCE	9

ES_t LED_enuInit(LED_t* Copy_pstrLeds);

ES_t LED_enuTurnON(LED_t* Copy_pstrLeds);

ES_t LED_enuTurnOFF(LED_t* Copy_pstrLeds);

#endif /* LED_INT_H_ */
