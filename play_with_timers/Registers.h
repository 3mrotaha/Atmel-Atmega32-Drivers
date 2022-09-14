/*
 * Registers.h
 *
 *  Created on: Oct 9, 2021
 *      Author: amrmo
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

// TIMER0 REGISTERS
#define  OCR0	*((volatile u8*) 0x5C)
#define  TIMSK	*((volatile u8*) 0x59)
#define  TIFR	*((volatile u8*) 0x58)
#define  TCCR0	*((volatile u8*) 0x53)
#define  TCNT0	*((volatile u8*) 0x52)




#endif /* REGISTERS_H_ */
