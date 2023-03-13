/*
 * TIMER2_priv.h
 *
 *  Created on: Mar 14, 2022
 *      Author: amrmo
 */

#ifndef MCAL_TIMER2_TIMER2_PRIV_H_
#define MCAL_TIMER2_TIMER2_PRIV_H_


#define BIT_MASK1	1
#define BIT_MASK2	3
#define BIT_MASK3	7
#define BIT_MASK4	15
#define BIT_MASK5	31

#define I_BIT	7

#define TOIE2_BIT	6
#define OCIE2_BIT	7

#define TOV2_BIT	6
#define OCF2_BIT	7

#define CS20_BIT	0
#define CS21_BIT	1
#define CS22_BIT	2
#define WGM21_BIT	3
#define COM20_BIT	4
#define COM21_BIT	5
#define WGM20_BIT	6
#define FOC2_BIT	7

#define TCR2UB_BIT	0
#define OCR2UB_BIT	1
#define TCN2UB_BIT	2
#define AS2_BIT		3

#define TIMER2_NO_CLOCK_SOURCE			0
#define TIMER2_PRESCALER_1    			1
#define TIMER2_PRESCALER_8    			2
#define TIMER2_PRESCALER_32   			3
#define TIMER2_PRESCALER_64   			4
#define TIMER2_PRESCALER_128  			5
#define TIMER2_PRESCALER_256  			6
#define TIMER2_PRESCALER_1024 			7

#define TIMER2_NO_CLOCK_SOURCE    		0
#define TIMER2_PRESCALER_VALUE_1  		1
#define TIMER2_PRESCALER_VALUE_8  		8
#define TIMER2_PRESCALER_VALUE_32 		32
#define TIMER2_PRESCALER_VALUE_64 		64
#define TIMER2_PRESCALER_VALUE_128		128
#define TIMER2_PRESCALER_VALUE_256		256
#define TIMER2_PRESCALER_VALUE_1024		1024

#define TIMER2_NON_PWM_MODE           	0
#define TIMER2_FAST_PWM					1
#define TIMER2_CTC_MODE					2
#define TIMER2_PHASE_CORRECT_PWM_MODE	3

#define TIMER2_NORMAL					0
#define TIMER2_TOGGLE_OC2				1
#define TIMER2_CLEAR_OC2				2
#define TIMER2_SET_OC2              	3


#define TIMER2_PWM_NORMAL   			0
#define TIMER2_PWM_CLEAR_OC2			2
#define TIMER2_PWM_SET_OC2  			3

#define TIMER2_OVF_INT					0
#define TIMER2_COMP_INT					1
#define TIMER2_INTERRUPTS				2
#endif /* MCAL_TIMER2_TIMER2_PRIV_H_ */
