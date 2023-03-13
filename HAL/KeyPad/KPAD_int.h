/*
 * KPAD_int.h
 *
 *  Created on: Feb 23, 2022
 *      Author: amrmo
 */

#ifndef KPAD_INT_H_
#define KPAD_INT_H_

ErrorStates_t KPAD_enuInit(KPAD_t* Copy_pstrKeyPadConfig);

ErrorStates_t KPAD_enuGetPressedkey(KPAD_t* Copy_pstrKeyPadConfig, uint8* Copy_puint8Value);

#endif /* KPAD_INT_H_ */
