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

#define ADMUX									*((volatile uint_8*)0x27)
#define ADC_REF_SELECTION_BITS						6
#define ADC_ADLAR_BIT								5
#define ADC_MUX_BITS								0

#define ADCSRA									*((volatile uint_8*)0x26)
#define ADC_ENABLE_BIT							7
#define ADC_STARTCONV_BIT						6
#define ADC_AUTOTRIGGER_BIT						5
#define ADC_INTFLAG_BIT							4
#define ADC_INTENABLE_BIT						3
#define ADC_PRESCALER_BITS						0

#define ADC_DATA_REGS							*((volatile sint_16*)0x24)
#define ADCL									*((volatile sint_8*)0x24)
#define ADCH									*((volatile sint_8*)0x25)

#define SFIOR									*((volatile uint_8*)0x50)
#define ADC_AUTOTRIGGER_SRC_BITS				5
#ifndef SREG
#define SREG									*((volatile uint_8*)0x5f)
#endif
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


#define ADC_ISR		void __vector_16(void)__attribute__((signal, used));\
						void __vector_16(void)

#endif /* ADC_PRIV_H_ */
