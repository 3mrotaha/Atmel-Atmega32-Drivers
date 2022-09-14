/*
 * LCD_prog.c
 *
 *  Created on: Feb 23, 2022
 *      Author: amrmo
 */

#include "../../LIB/std_types.h"
#include "../../LIB/Error_States.h"
#include "../../LIB/Bit_Level.h"

#include "../../MCAL/DIO/DIO_priv.h"
#include "../../MCAL/DIO/DIO_int.h"

#include "LCD_priv.h"
#include "LCD_config.h"

#include "util/delay.h"

ES_t LCD_enuInit(void){
	ES_t Local_enuErrorStates = ES_NOK;
	Local_enuErrorStates = DIO_enuSetPinDir(RS_PORT, RS_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(RW_PORT, RW_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(EN_PORT, EN_PIN, OUTPUT);

	Local_enuErrorStates = DIO_enuSetPinDir(D7_PORT, D7_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(D6_PORT, D6_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(D5_PORT, D5_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(D4_PORT, D4_PIN, OUTPUT);
	_delay_ms(30);
#if LCD_BIT_MODE == EIGHT_BIT_MODE

	Local_enuErrorStates = DIO_enuSetPinDir(D3_PORT, D3_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(D2_PORT, D2_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(D1_PORT, D1_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(D0_PORT, D0_PIN, OUTPUT);

	Local_enuErrorStates = LCD_enuToSendCommand(0x38);
	_delay_ms(1);

#elif LCD_BIT_MODE == FOUR_BIT_MODE
	Local_enuErrorStates = LCD_enuToSendCommand(0x28);
	_delay_ms(1);
#endif

	Local_enuErrorStates = LCD_enuToSendCommand(0x0f);
	_delay_ms(1);
	Local_enuErrorStates = LCD_enuToSendCommand(0x01);
	_delay_ms(2);
	Local_enuErrorStates = LCD_enuToSendCommand(0x06);

	return Local_enuErrorStates;
}

ES_t LCD_enuSendCommand(uint_8 Copy_uint8Command){
	ES_t Local_enuErrorStates = ES_NOK;

	Local_enuErrorStates = LCD_enuToSendCommand(Copy_uint8Command);

	return Local_enuErrorStates = ES_OK;
}

ES_t LCD_enuDisplayChar(uint_8 Copy_uint8Data){
	ES_t Local_enuErrorStates = ES_NOK;

	Local_enuErrorStates = LCD_enuSendData(Copy_uint8Data);

	return Local_enuErrorStates;
}

ES_t LCD_enuDisplayString(uint_8* Copy_uint8Data){
	ES_t Local_enuErrorStates = ES_NOK;
	uint_8 Local_uint8Iterator = 0;
	if(Copy_uint8Data != NULL){
		while(Copy_uint8Data[Local_uint8Iterator] != '\0'){
			Local_enuErrorStates = LCD_enuSendData(Copy_uint8Data[Local_uint8Iterator]);
			Local_uint8Iterator++;
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ES_t LCD_enuDisplayInteger(sint_64 Copy_uint32Data){
	ES_t Local_enuErrorStates = ES_NOK;
	Local_enuErrorStates = LCD_enuDisplayNumber(Copy_uint32Data);
	return Local_enuErrorStates;
}

ES_t LCD_enuDisplayFloat(f64 Copy_f64Data){
	ES_t Local_enuErrorStates = ES_NOK;
	uint_64 Local_uint64RealNum;
	f64	Local_f64Fraction;
	if(Copy_f64Data < 0){
		Local_enuErrorStates = LCD_enuSendData('-');
		Copy_f64Data *= -1;
	}

	Local_uint64RealNum = (uint_64) Copy_f64Data;
	Local_f64Fraction = Copy_f64Data - Local_uint64RealNum;

	Local_enuErrorStates = LCD_enuDisplayNumber(Local_uint64RealNum);
	Local_enuErrorStates = LCD_enuSendData('.');

	uint_8 Local_uint8Iterator;
	for(Local_uint8Iterator = 0; Local_uint8Iterator < FRACTION_MAX_RANGE; Local_uint8Iterator++)
		Local_f64Fraction *= 10;

	Local_enuErrorStates = LCD_enuDisplayNumber(Local_f64Fraction);
	return Local_enuErrorStates;
}

static inline ES_t LCD_enuSendData(uint_8 Copy_uint8Data){
	ES_t Local_enuErrorStates = ES_NOK;
	Local_enuErrorStates = DIO_enuSetPinValue(RS_PORT, RS_PIN, HIGH);
	Local_enuErrorStates = DIO_enuSetPinValue(RW_PORT, RW_PIN, LOW);
	Local_enuErrorStates = DIO_enuSetPinValue(EN_PORT, EN_PIN, LOW);

	Local_enuErrorStates = DIO_enuSetPinValue(D7_PORT, D7_PIN, BIT_MASK1 & (Copy_uint8Data >> 7));
	Local_enuErrorStates = DIO_enuSetPinValue(D6_PORT, D6_PIN, BIT_MASK1 & (Copy_uint8Data >> 6));
	Local_enuErrorStates = DIO_enuSetPinValue(D5_PORT, D5_PIN, BIT_MASK1 & (Copy_uint8Data >> 5));
	Local_enuErrorStates = DIO_enuSetPinValue(D4_PORT, D4_PIN, BIT_MASK1 & (Copy_uint8Data >> 4));

#if LCD_BIT_MODE == EIGHT_BIT_MODE
	Local_enuErrorStates = DIO_enuSetPinValue(D3_PORT, D3_PIN, BIT_MASK1 & (Copy_uint8Data >> 3));
	Local_enuErrorStates = DIO_enuSetPinValue(D2_PORT, D2_PIN, BIT_MASK1 & (Copy_uint8Data >> 2));
	Local_enuErrorStates = DIO_enuSetPinValue(D1_PORT, D1_PIN, BIT_MASK1 & (Copy_uint8Data >> 1));
	Local_enuErrorStates = DIO_enuSetPinValue(D0_PORT, D0_PIN, BIT_MASK1 & (Copy_uint8Data >> 0));
#elif LCD_BIT_MODE == FOUR_BIT_MODE
	Local_enuErrorStates = DIO_enuSetPinValue(EN_PORT, EN_PIN, HIGH);
	_delay_ms(10);
	Local_enuErrorStates = DIO_enuSetPinValue(EN_PORT, EN_PIN, LOW);
	_delay_ms(10);
	Local_enuErrorStates = DIO_enuSetPinValue(D7_PORT, D7_PIN, BIT_MASK1 & (Copy_uint8Data >> 3));
	Local_enuErrorStates = DIO_enuSetPinValue(D6_PORT, D6_PIN, BIT_MASK1 & (Copy_uint8Data >> 2));
	Local_enuErrorStates = DIO_enuSetPinValue(D5_PORT, D5_PIN, BIT_MASK1 & (Copy_uint8Data >> 1));
	Local_enuErrorStates = DIO_enuSetPinValue(D4_PORT, D4_PIN, BIT_MASK1 & (Copy_uint8Data >> 0));
#endif

	Local_enuErrorStates = DIO_enuSetPinValue(EN_PORT, EN_PIN, HIGH);
	_delay_ms(10);
	Local_enuErrorStates = DIO_enuSetPinValue(EN_PORT, EN_PIN, LOW);
	_delay_ms(10);
	return Local_enuErrorStates;
}

static inline ES_t LCD_enuToSendCommand(uint_8 Copy_uint8Command){
	ES_t Local_enuErrorStates;
	Local_enuErrorStates = DIO_enuSetPinValue(RS_PORT, RS_PIN, LOW);
	Local_enuErrorStates = DIO_enuSetPinValue(RW_PORT, RW_PIN, LOW);
	Local_enuErrorStates = DIO_enuSetPinValue(EN_PORT, EN_PIN, LOW);

	Local_enuErrorStates = DIO_enuSetPinValue(D7_PORT, D7_PIN, BIT_MASK1 & (Copy_uint8Command >> 7));
	Local_enuErrorStates = DIO_enuSetPinValue(D6_PORT, D6_PIN, BIT_MASK1 & (Copy_uint8Command >> 6));
	Local_enuErrorStates = DIO_enuSetPinValue(D5_PORT, D5_PIN, BIT_MASK1 & (Copy_uint8Command >> 5));
	Local_enuErrorStates = DIO_enuSetPinValue(D4_PORT, D4_PIN, BIT_MASK1 & (Copy_uint8Command >> 4));

#if LCD_BIT_MODE == EIGHT_BIT_MODE
	Local_enuErrorStates = DIO_enuSetPinValue(D3_PORT, D3_PIN, BIT_MASK1 & (Copy_uint8Command >> 3));
	Local_enuErrorStates = DIO_enuSetPinValue(D2_PORT, D2_PIN, BIT_MASK1 & (Copy_uint8Command >> 2));
	Local_enuErrorStates = DIO_enuSetPinValue(D1_PORT, D1_PIN, BIT_MASK1 & (Copy_uint8Command >> 1));
	Local_enuErrorStates = DIO_enuSetPinValue(D0_PORT, D0_PIN, BIT_MASK1 & (Copy_uint8Command >> 0));
#elif LCD_BIT_MODE == FOUR_BIT_MODE
	if(Copy_uint8Command == 0x28){
		Local_enuErrorStates = DIO_enuSetPinValue(EN_PORT, EN_PIN, HIGH);
		_delay_ms(10);
		Local_enuErrorStates = DIO_enuSetPinValue(EN_PORT, EN_PIN, LOW);
		_delay_ms(10);
		Local_enuErrorStates = DIO_enuSetPinValue(D7_PORT, D7_PIN, BIT_MASK1 & (Copy_uint8Command >> 7));
		Local_enuErrorStates = DIO_enuSetPinValue(D6_PORT, D6_PIN, BIT_MASK1 & (Copy_uint8Command >> 6));
		Local_enuErrorStates = DIO_enuSetPinValue(D5_PORT, D5_PIN, BIT_MASK1 & (Copy_uint8Command >> 5));
		Local_enuErrorStates = DIO_enuSetPinValue(D4_PORT, D4_PIN, BIT_MASK1 & (Copy_uint8Command >> 4));
	}
	Local_enuErrorStates = DIO_enuSetPinValue(EN_PORT, EN_PIN, HIGH);
	_delay_ms(10);
	Local_enuErrorStates = DIO_enuSetPinValue(EN_PORT, EN_PIN, LOW);
	_delay_ms(10);
	Local_enuErrorStates = DIO_enuSetPinValue(D7_PORT, D7_PIN, BIT_MASK1 & (Copy_uint8Command >> 3));
	Local_enuErrorStates = DIO_enuSetPinValue(D6_PORT, D6_PIN, BIT_MASK1 & (Copy_uint8Command >> 2));
	Local_enuErrorStates = DIO_enuSetPinValue(D5_PORT, D5_PIN, BIT_MASK1 & (Copy_uint8Command >> 1));
	Local_enuErrorStates = DIO_enuSetPinValue(D4_PORT, D4_PIN, BIT_MASK1 & (Copy_uint8Command >> 0));
#endif

	Local_enuErrorStates = DIO_enuSetPinValue(EN_PORT, EN_PIN, HIGH);
	_delay_ms(10);
	Local_enuErrorStates = DIO_enuSetPinValue(EN_PORT, EN_PIN, LOW);
	_delay_ms(10);

	return Local_enuErrorStates;
}

static inline ES_t LCD_enuDisplayNumber(sint_64 Copy_uint32Data){
	ES_t Local_enuErrorStates = ES_NOK;

	uint_8 Local_uint8Digits = 1;
	sint_64 Local_uint8Dividor = 10;

	if(Copy_uint32Data < 0){
		Local_enuErrorStates = LCD_enuSendData('-');
		Copy_uint32Data *= -1;
	}

	while(Copy_uint32Data / Local_uint8Dividor){
		Local_uint8Dividor *= 10;
		++Local_uint8Digits;
	}

	while(Local_uint8Digits--){
		Local_uint8Dividor /= 10;
		Local_enuErrorStates = LCD_enuSendData('0' + (Copy_uint32Data / Local_uint8Dividor));
		Copy_uint32Data -= ((Copy_uint32Data / Local_uint8Dividor) * Local_uint8Dividor);
	}

	return Local_enuErrorStates;
}
