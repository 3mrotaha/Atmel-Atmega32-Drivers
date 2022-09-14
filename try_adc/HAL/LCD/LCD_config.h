/*
 * LCD_config.h
 *
 *  Created on: Feb 23, 2022
 *      Author: amrmo
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define LCD_BIT_MODE	FOUR_BIT_MODE

#define RS_PORT			DIO_uint8_PORTC
#define RS_PIN			DIO_uint8_PIN0

#define RW_PORT       	DIO_uint8_PORTC
#define RW_PIN         	DIO_uint8_PIN1

#define EN_PORT        	DIO_uint8_PORTC
#define EN_PIN         	DIO_uint8_PIN2

#define D7_PORT       	DIO_uint8_PORTC
#define D7_PIN         	DIO_uint8_PIN3

#define D6_PORT        	DIO_uint8_PORTC
#define D6_PIN         	DIO_uint8_PIN4

#define D5_PORT        	DIO_uint8_PORTC
#define D5_PIN         	DIO_uint8_PIN5

#define D4_PORT       	DIO_uint8_PORTC
#define D4_PIN        	DIO_uint8_PIN6

#define D3_PORT         DIO_uint8_PORTC
#define D3_PIN          DIO_uint8_PIN7

#define D2_PORT         DIO_uint8_PORTD
#define D2_PIN          DIO_uint8_PIN0

#define D1_PORT         DIO_uint8_PORTD
#define D1_PIN          DIO_uint8_PIN1

#define D0_PORT       	DIO_uint8_PORTD
#define D0_PIN        	DIO_uint8_PIN3

#define FRACTION_MAX_RANGE	4

#endif /* LCD_CONFIG_H_ */
