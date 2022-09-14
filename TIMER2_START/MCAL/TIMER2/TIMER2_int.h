/*
 * TIMER2_int.h
 *
 *  Created on: Mar 14, 2022
 *      Author: amrmo
 */

#ifndef MCAL_TIMER2_TIMER2_INT_H_
#define MCAL_TIMER2_TIMER2_INT_H_


ES_t TIMER2_enuInit(void);

ES_t TIMER2_enuSyncDelay(uint_32 Copy_uint32TimeMs);

ES_t TIMER2_enuAsyncDelay(uint_32 Copy_uint32TimeMs, void (*Copy_pfConfig)(void*), void* Copy_pParameter);

ES_t TIMER2_enuOutputCompare(uint_8 Copy_uint8OCRCounts, uint_8 Copy_uint8OCMode);

ES_t TIMER2_enuSetWaveGenMode(uint_8 Copy_uint8WaveMode);

ES_t TIMER2_enuGeneratePWM(uint_8 Copy_uint8OCMode, uint_8 Copy_uint8OCRcounts);

ES_t TIMER2_enuCallBack(void (*Copy_pfConfig)(void*), void* Copy_pParameter);


#endif /* MCAL_TIMER2_TIMER2_INT_H_ */
