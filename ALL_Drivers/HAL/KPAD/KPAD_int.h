/*
 * KPAD_int.h
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#ifndef HAL_KPAD_KPAD_INT_H_
#define HAL_KPAD_KPAD_INT_H_

ES_t KPAD_enuInit(PAD_t *Copy_pstrKeysConfig);

ES_t KPAD_enuGetKeyValue(u8 Copy_u8KpadID, u8 *Copy_u8Value);


#endif /* HAL_KPAD_KPAD_INT_H_ */
