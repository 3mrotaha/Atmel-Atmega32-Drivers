/*
 * SSegment_config.h
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#ifndef HAL_SEVEN_SEGMENT_SSEGMENT_CONFIG_H_
#define HAL_SEVEN_SEGMENT_SSEGMENT_CONFIG_H_

#define 	NUM_SEV_SEGMENTS	2

typedef struct{
	u8	SegA_Port;
	u8 	SegA_Pin;

	u8	SegB_Port;
	u8 	SegB_Pin;

	u8	SegC_Port;
	u8 	SegC_Pin;

	u8	SegD_Port;
	u8 	SegD_Pin;

	u8	SegE_Port;
	u8 	SegE_Pin;

	u8	SegF_Port;
	u8 	SegF_Pin;

	u8	SegG_Port;
	u8 	SegG_Pin;

	u8 Cmn_Port;
	u8 Cmn_Pin;

	u8 Dot_Port;
	u8 Dot_Pin;

	u8 Seg_Type;


}SEG_t;

#endif /* HAL_SEVEN_SEGMENT_SSEGMENT_CONFIG_H_ */
