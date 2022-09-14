/*
 * TIMER0_priv.h
 *
 *  Created on: Feb 28, 2022
 *      Author: amrmo
 */

#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_

#define BIT_MASK1									1
#define BIT_MASK2									3
#define BIT_MASK3									7

#define TIMER0_INT_OVF								0
#define TIMER0_INT_COMP								1

#define TIMER0_OVF_MODE								0
#define TIMER0_PHASE_CORRECT_PWM_MODE				1
#define TIMER0_CTC_MODE								2
#define TIMER0_FAST_PWM_MODE					    3


#define TIMER0_NON_PWM_NORMAL						0
#define TIMER0_NON_PWM_TOGGLE						1
#define TIMER0_NON_PWM_CLEAR 						2
#define TIMER0_NON_PWM_SET   						3

#define TIMER0_FAST_PWM_NORMAL						0
#define TIMER0_FAST_PWM_CLEAR 						2
#define TIMER0_FAST_PWM_SET   						3

#define TIMER0_PHASECORRECT_PWM_NORMAL				0
#define TIMER0_PHASECORRECT_PWM_CLEAR 				2
#define TIMER0_PHASECORRECT_PWM_SET   				3


#define TIMER0_STOP_TIMER							0
#define TIMER0_PRESCALER_1							1
#define TIMER0_PRESCALER_8							2
#define TIMER0_PRESCALER_64							3
#define TIMER0_PRESCALER_256						4
#define TIMER0_PRESCALER_1024						5
#define TIMER0_EX_CLOCK_FALLING_EDGE				6
#define TIMER0_EX_CLOCK_RISING_EDGE					7


#define TCCR0                                       *((volatile uint_8*) 0x53)
#define TIMER0_CLOCKSELECT_BITS						0
#define TIMER0_WGM00_BIT							6
#define TIMER0_WGM01_BIT							3
#define TIMER0_COM_BITS								4
#define TIMER0_FOC0_BIT								6

#define TCNT0                                       *((volatile uint_8*) 0x52)
#define OCR0                                        *((volatile uint_8*) 0x5C)
#define TIMSK                                       *((volatile uint_8*) 0x59)
#define TIMER0_OCIE0_BIT							1
#define TIMER0_TOIE0_BIT							0

#define TIFR                                        *((volatile uint_8*) 0x58)
#define TIMER0_OCF0_BIT								1
#define TIMER0_TOV0_BIT								0

#define SREG                                        *((volatile uint_8*) 0x5F)
#define I_BIT										7

#define TIMER0_OVF_ISR								void __vector_11(void)__attribute__((signal, used));\
													void __vector_11(void)

#define TIMER0_COMP_ISR								void __vector_10(void)__attribute__((signal, used));\
													void __vector_10(void)


#endif /* TIMER0_PRIV_H_ */
