/*
 * SSegment_int.h
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#ifndef HAL_SEVEN_SEGMENT_SSEGMENT_INT_H_
#define HAL_SEVEN_SEGMENT_SSEGMENT_INT_H_

ES_t SSegment_enuInit(SEG_t *Copy_pstrSegConfig);

ES_t SSegment_enuDisplayNum(u8 Copy_u8Num, u8 Copy_u8SegID);

ES_t SSegment_enuEnableCMN(u8 Copy_u8SegID);

ES_t SSegment_enuDisableCMN(u8 Copy_u8SegID);

ES_t SSegment_enuEnableDot(u8 Copy_u8SegID);

ES_t SSegment_enuDisableDot(u8 Copy_u8SegID);

ES_t SSegment_enuClearDislay(u8 Copy_u8SegID);

#endif /* HAL_SEVEN_SEGMENT_SSEGMENT_INT_H_ */
