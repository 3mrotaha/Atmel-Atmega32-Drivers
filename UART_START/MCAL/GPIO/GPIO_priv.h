/*
 * GPIO_priv.h
 *
 *  Created on: Mar 20, 2022
 *      Author: amrmo
 */

#ifndef MCAL_GPIO_GPIO_PRIV_H_
#define MCAL_GPIO_GPIO_PRIV_H_

#define SREG	*((volatile uint_8*)0x5F)
#define I_BIT	7

#define ISR(VECT_NUM)					void VECT_NUM (void) __attribute__((signal, used));\
										void VECT_NUM (void)

#endif /* MCAL_GPIO_GPIO_PRIV_H_ */
