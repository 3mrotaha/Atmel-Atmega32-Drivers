/*
 * TIMER1_priv.h
 *
 *  Created on: Mar 7, 2022
 *      Author: amrmo
 */

#ifndef MCAL_TIMER1_TIMER1_PRIV_H_
#define MCAL_TIMER1_TIMER1_PRIV_H_

#define TCCR1A	*((volatile uint_8*)0x4F)
#define WGM10_BIT	0
#define WGM11_BIT	1
#define FOC1B_BIT	2
#define FOC1A_BIT	3
#define COM1B0_BIT	4
#define COM1B1_BIT	5
#define COM1A0_BIT	6
#define COM1A1_BIT	7


#define TCCR1B	*((volatile uint_8*)0x4E)
#define CS10_BIT	0
#define	CS11_BIT	1
#define CS12_BIT	2
#define WGM12_BIT	3
#define WGM13_BIT	4
#define ICES1_BIT	6
#define ICNC_BIT	7

#define TCNT1H	*((volatile uint_8*)0x4D)
#define TCNT1L	*((volatile uint_8*)0x4C)
#define TCNT1	*((volatile uint_16*)0x4C)


#define OCR1AH	*((volatile uint_8*)0x4B)
#define OCR1AL	*((volatile uint_8*)0x4A)
#define OCR1A	*((volatile uint_16*)0x4A)


#define OCR1BH	*((volatile uint_8*)0x49)
#define OCR1BL	*((volatile uint_8*)0x48)
#define OCR1B	*((volatile uint_16*)0x48)

#define ICR1H	*((volatile uint_8*)0x47)
#define ICR1L	*((volatile uint_8*)0x46)
#define ICR1	*((volatile uint_16*)0x46)

#define TIMSK	*((volatile uint_8*)0x59)
#define TOIE1_BIT	2
#define OCIE1B_BIT	3
#define OCIE1A_BIT	4
#define	TICIE1_BIT	5

#define TIFR	*((volatile uint_8*)0x58)
#define	TOV1_BIT	2
#define	OCF1B_BIT	3
#define	OCF1A_BIT	4
#define ICF1_BIT	5

#define SREG	*((volatile uint_8*)0x5f)
#define I_BIT	7

#define BIT_MASK1									1
#define BIT_MASK2									3
#define BIT_MASK3									7
#define BIT_MASK4									15
#define BIT_MASK5									31

#define TIMER1_TOTAL_COUNTS							65535

#define NO_PRESCALER_TIMER_STOP						0
#define PRESCALER_1									1
#define PRESCALER_8									2
#define PRESCALER_64								3
#define PRESCALER_256								4
#define PRESCALER_1024								5
#define EXTERNAL_CLK_FALLING_EDGE					6
#define EXTERNAL_CLK_RISING_EDGE					7

#define TIMER1_PRESCALER_VAL_1   					1
#define TIMER1_PRESCALER_VAL_8   					8
#define TIMER1_PRESCALER_VAL_64  					64
#define TIMER1_PRESCALER_VAL_256 					256
#define TIMER1_PRESCALER_VAL_1024					1024

#define NORMAL_MODE     	    					0

#define PWM_PHASE_CORRECT_8BIT 						1
#define PWM_PHASE_CORRECT_9BIT 						2
#define PWM_PHASE_CORRECT_10BIT						3

#define CTC_MODE_OCR_TOP       						4

#define FAST_PWM_8BIT								5
#define FAST_PWM_9BIT          						6
#define FAST_PWM_10BIT         						7

#define PWM_PHASE_AND_FREQUANCY_CORRECT_ICR_TOP  	8
#define PWM_PHASE_AND_FREQUANCY_CORRECT_OCR_TOP  	9

#define PWM_PHASE_CORRECT_ICR_TOP              		10
#define PWM_PHASE_CORRECT_OCR_TOP			   		11

#define CTC_MODE_ICR_TOP					   		12

#define FAST_PWM_ICR_TOP              				14
#define FAST_PWM_OCR_TOP             				15


#define TOGGLE_OC1A_ON_COMPARE_MATCH				1
#define CLEAR_OC1A_ON_COMPARE_MATCH 				2
#define SET_OC1A_ON_COMPARE_MATCH 					3

#define TOGGLE_OC1B_ON_COMPARE_MATCH				1
#define CLEAR_OC1B_ON_COMPARE_MATCH 				2
#define SET_OC1B_ON_COMPARE_MATCH   				3


#define TIMER1_OVF_INT								0
#define TIMER1_COMPA_INT							1
#define TIMER1_COMPB_INT							2
#define TIMER1_ICR_INT								3

#define TIMER1_INTERRUPTS							4

#define TIMER1_CAPT_VECT				__vector_6
#define TIMER1_COMPA_VECT				__vector_7
#define TIMER1_COMPB_VECT				__vector_8
#define TIMER1_OVF_VECT					__vector_9

#define ISR(VECT_NUM)		void VECT_NUM(void) __attribute__((signal, used));\
							void VECT_NUM(void)

#endif /* MCAL_TIMER1_TIMER1_PRIV_H_ */
