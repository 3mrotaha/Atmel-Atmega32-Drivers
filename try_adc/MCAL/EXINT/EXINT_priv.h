/*
 * EXINT_priv.h
 *
 *  Created on: Feb 24, 2022
 *      Author: amrmo
 */

#ifndef EXINT_PRIV_H_
#define EXINT_PRIV_H_

#define EXINT_FALLING_EDGE		2
#define EXINT_RISING_EDGE		3
#define EXINT_LOW_LEVE			0
#define EXINT_LOGICAL_CHANGE	1

#define EXINT_ENABLED			80
#define EXINT_DISABLED			82

#define EXINT_INT0				0
#define EXINT_INT1				1
#define EXINT_INT2				2

#define EXINT_BIT_MASK			1

#define MCUCR		*((volatile uint_8*)0x55)
#define EXINT_ISC00_BIT			0
#define EXINT_ISC01_BIT			1
#define EXINT_ISC10_BIT			2
#define EXINT_ISC11_BIT			3

#define MCUCSR      *((volatile uint_8*)0x54)
#define EXINT_ISC2_BIT			6
#define EXINT2_FALLING_EDGE		0
#define EXINT2_RISING_EDGE		1


#define GICR        *((volatile uint_8*)0x5B)
#define EXINT_INT0_BIT			6
#define EXINT_INT1_BIT			7
#define EXINT_INT2_BIT			5
#define GIFR        *((volatile uint_8*)0x5A)
#define EXINT_INTF0_BIT			6
#define EXINT_INTF1_BIT			7
#define EXINT_INTF2_BIT			5

#ifndef SREG
#define SREG        *((volatile uint_8*)0x5F)
#endif
#define EXINT_L_BIT				7

#define EXINT0_ISR		void __vector_1(void)__attribute__((signal, used));\
						void __vector_1(void)

#define EXINT1_ISR		void __vector_2(void)__attribute__((signal, used));\
						void __vector_2(void)

#define EXINT2_ISR		void __vector_3(void)__attribute__((signal, used));\
						void __vector_3(void)


#endif /* EXINT_PRIV_H_ */
