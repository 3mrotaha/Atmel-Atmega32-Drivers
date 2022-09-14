/*
 * DIO_int.h
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIO_uint8_PIN0				0
#define DIO_uint8_PIN1				1
#define DIO_uint8_PIN2				2
#define DIO_uint8_PIN3				3
#define DIO_uint8_PIN4				4
#define DIO_uint8_PIN5				5
#define DIO_uint8_PIN6				6
#define DIO_uint8_PIN7				7

#define DIO_uint8_PORTA				0
#define DIO_uint8_PORTB				1
#define DIO_uint8_PORTC				2
#define DIO_uint8_PORTD				3


#define OUTPUT			1
#define INPUT			0

#define PULL_UP			1
#define FLOAT			0
#define HIGH			1
#define LOW				0
ES_t DIO_enuInit(void);

ES_t DIO_enuSetPortDir(uint_8 Copy_uint8PortID, uint_8 Copy_uint8Value);

ES_t DIO_enuSetPortValue(uint_8 Copy_uint8PortID, uint_8 Copy_uint8Value);

ES_t DIO_enuTogPortValue(uint_8 Copy_uint8PortID);

ES_t DIO_enuGetPortValue(uint_8 Copy_uint8PortID, uint_8 *Copy_uint8Value);

ES_t DIO_enuSetPinDir(uint_8 Copy_uint8PortID, uint_8 Copy_uint8PinID, uint_8 Copy_uint8Value);

ES_t DIO_enuSetPinValue(uint_8 Copy_uint8PortID, uint_8 Copy_uint8PinID, uint_8 Copy_uint8Value);

ES_t DIO_enuTogPinValue(uint_8 Copy_uint8PortID, uint_8 Copy_uint8PinID);

ES_t DIO_enuGetPinValue(uint_8 Copy_uint8PortID, uint_8 Copy_uint8PinID, uint_8 *Copy_uint8Value);




#endif /* DIO_INT_H_ */
