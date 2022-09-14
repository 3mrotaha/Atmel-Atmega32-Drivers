/*
 * SSegment_priv.h
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#ifndef HAL_SEVEN_SEGMENT_SSEGMENT_PRIV_H_
#define HAL_SEVEN_SEGMENT_SSEGMENT_PRIV_H_

#define COMMON_CATHODE 	100

#define COMMON_ANODE	99

#define NUM_TO_DISPLAY	10

#define BIT_MASK 	1

#define NOT_CONNECTED	33

#define SEVEN_SEGMENT_VALUES	  {\
		 	 	 	 	 	 	 	0x3f,\
									0x06,\
									0x5B,\
									0x4F,\
									0x66,\
									0x6D,\
									0x7D,\
									0x07,\
									0x7F,\
									0x6F\
}

#endif /* HAL_SEVEN_SEGMENT_SSEGMENT_PRIV_H_ */
