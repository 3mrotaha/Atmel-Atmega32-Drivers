/*
 * Switch_int.h
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#ifndef HAL_SWITCH_SWITCH_INT_H_
#define HAL_SWITCH_SWITCH_INT_H_

ES_t SW_enuInit(SW_t *Copy_pstrSwitchConfig);

ES_t SW_enuGetSwitchState(u8 SwitchID, u8 *SwitchVal);


#endif /* HAL_SWITCH_SWITCH_INT_H_ */
