/*
 * DIO_priv.h
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define DIO_uint8_OUTPUT			1
#define DIO_uint8_INPUT				0

#define DIO_uint8_PULL_UP			1
#define DIO_uint8_FLOAT				0
#define DIO_uint8_HIGH				1
#define DIO_uint8_LOW				0


#define BIT_MASK		1

#define CONC_HELP(PD7,PD6,PD5,PD4,PD3,PD2,PD1,PD0)	0b##PD7##PD6##PD5##PD4##PD3##PD2##PD1##PD0
#define CONC(PD7,PD6,PD5,PD4,PD3,PD2,PD1,PD0)		CONC_HELP(PD7,PD6,PD5,PD4,PD3,PD2,PD1,PD0)

#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7

#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3

#define DDRA			*((uint_8*) 0x3A)
#define PORTA			*((uint_8*) 0x3B)
#define PINA			*((volatile uint_8*) 0x39)

#define DDRB			*((uint_8*) 0x37)
#define PORTB			*((uint_8*) 0x38)
#define PINB			*((volatile uint_8*) 0x36)

#define DDRC			*((uint_8*) 0x34)
#define PORTC			*((uint_8*) 0x35)
#define PINC			*((volatile uint_8*) 0x33)

#define DDRD			*((uint_8*) 0x31)
#define PORTD			*((uint_8*) 0x32)
#define PIND			*((volatile uint_8*) 0x30)


#endif /* DIO_PRIV_H_ */
