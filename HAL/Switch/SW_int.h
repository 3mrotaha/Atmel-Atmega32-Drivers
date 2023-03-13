/*
 * SW_int.h
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#ifndef SW_INT_H_
#define SW_INT_H_



ErrorStates_t SW_enuInit(SW_t* Copy_pstrSwitches);

ErrorStates_t SW_enuGetState(SW_t* Copy_pstrSwitches, uint8* Copy_puint8Value);

#endif /* SW_INT_H_ */
