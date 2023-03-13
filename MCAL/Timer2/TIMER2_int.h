/*
 * TIMER2_int.h
 *
 *  Created on: Mar 14, 2022
 *      Author: amrmo
 */

#ifndef MCAL_TIMER2_TIMER2_INT_H_
#define MCAL_TIMER2_TIMER2_INT_H_


ErrorStates_t TIMER2_enuInit(void);

ErrorStates_t TIMER2_enuSyncDelay(uint32 Copy_uint32TimeMs);

ErrorStates_t TIMER2_enuAsyncDelay(uint32 Copy_uint32TimeMs, void (*Copy_pfConfig)(void*), void* Copy_pParameter);

ErrorStates_t TIMER2_enuOutputCompare(uint8 Copy_uint8OCRcounts, uint8 Copy_uint8OCRMode);

ErrorStates_t TIMER2_enuSetWaveGenMode(uint8 Copy_uint8WaveMode);

ErrorStates_t TIMER2_enuGeneratePWM(uint8 Copy_uint8OCRMode, uint8 Copy_uint8OCRcounts);

ErrorStates_t TIMER2_enuCallBack(void (*Copy_pfConfig)(void*), void* Copy_pParameter);


#endif /* MCAL_TIMER2_TIMER2_INT_H_ */
