/*
 * ADC_priv.h
 *
 *  Created on: Feb 25, 2022
 *      Author: amrmo
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

#define BIT_MASK1								1
#define BIT_MASK2								3
#define BIT_MASK4								15
#define BIT_MASK5								31
#define BIT_MASK3								7


#define ADC_REF_SELECTION_BITS						6
#define ADC_ADLAR_BIT								5
#define ADC_MUX_BITS								0


#define ADC_ENABLE_BIT							7
#define ADC_STARTCONV_BIT						6
#define ADC_AUTOTRIGGER_BIT						5
#define ADC_INT_VECTFLAG_BIT							4
#define ADC_INT_VECTENABLE_BIT						3
#define ADC_PRESCALER_BITS						0


#define ADC_AUTOTRIGGER_SRC_BITS				5

#define	I_BIT									7


#define ADC_uint8AREF							0
#define ADC_uint8AVCC							1
#define ADC_uint8INTERNAL_REF					3

#define ADC_uint8PRESCALER_2_					1
#define ADC_uint8PRESCALER_4_					2
#define ADC_uint8PRESCALER_8_					3
#define ADC_uint8PRESCALER_16_					4
#define ADC_uint8PRESCALER_32_					5
#define ADC_uint8PRESCALER_64_					6
#define ADC_uint8PRESCALER_128_					7

#define ADC_uint8RIGHT_ADJUSTED					90
#define ADC_uint8LEFT_ADJUSTED					70

#define ADC_MAX_NUM_OF_CHANNELS					29


#endif /* ADC_PRIV_H_ */
