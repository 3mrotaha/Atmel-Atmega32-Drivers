/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: amrmo
 */

#include "std_types.h"
#include "Error_States.h"

#include "EXINT_priv.h"
#include "EXINT_config.h"
#include "EXINT_int.h"

#include "util/delay.h"

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

void tog_led(int d);
void loop_led(int d);
void change_led(int d);
int p = 20;
int x = 10;
int y = 40;

extern EXINT_t EXINT_AstrExINTConfig[EXINT_NUM];
int main(void){

	EXINT_enuInit(EXINT_AstrExINTConfig);
	DDRA = 0xff;
	DDRB = 0xfb;
	DDRC = 0xff;

	DDRD &= ~(EXINT_BIT_MASK << 0);
	DDRD |= (EXINT_BIT_MASK << 0);

//	PORTD |= (EXINT_BIT_MASK << 3);

	PORTA = 0;
	PORTC = 0xff;
	PORTB = 0xff;

	EXINT_enuCallBack(&tog_led, &p, EXINTuint8_INT1);
	EXINT_enuCallBack(&loop_led, &x, EXINTuint8_INT0);
	EXINT_enuCallBack(&change_led, &y, EXINTuint8_INT2);

	while(1){
		PORTC = ~PORTC;
		_delay_ms(500);
		PORTA = ~PORTA;
		_delay_ms(500);
		PORTB = ~PORTB;
		_delay_ms(500);
	}
	return 0;
}
void tog_led(int d){
	PORTD ^= (EXINT_BIT_MASK << 0);
	_delay_ms(1000);
	PORTD ^= (EXINT_BIT_MASK << 0);
	PORTA = d;
}

void change_led(int d){
	PORTD ^= (EXINT_BIT_MASK << 0);
	_delay_ms(1000);
	PORTD ^= (EXINT_BIT_MASK << 0);
	PORTB = d & 0xfb;
}

void loop_led(int d){
	PORTD ^= (EXINT_BIT_MASK << 0);
	_delay_ms(1000);
	PORTD ^= (EXINT_BIT_MASK << 0);
	PORTC = d;
}
