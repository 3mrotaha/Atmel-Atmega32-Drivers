/*
 * TIMER0_priv.h
 *
 *  Created on: Oct 7, 2021
 *      Author: amrmo
 */

#ifndef MCAL_TIMER0_TIMER0_PRIV_H_
#define MCAL_TIMER0_TIMER0_PRIV_H_

#define OCR0		*((volatile u8*) 0x5C)

#define TIMSK		*((volatile u8*) 0x59)

#define TIFR		*((volatile u8*) 0x58)

#define TCCR0		*((volatile u8*) 0x53)

#define TCNT0		*((volatile u8*) 0x52)



#endif /* MCAL_TIMER0_TIMER0_PRIV_H_ */
