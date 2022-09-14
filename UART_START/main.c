/*
 * main.c
 *
 *  Created on: Mar 20, 2022
 *      Author: amrmo
 */

#include "LIB/std_types.h"
#include "LIB/Error_States.h"
#include "LIB/Bit_Level.h"

#include "HAL/LCD/LCD_int.h"

#include "MCAL/DIO/DIO_int.h"
#include "MCAL/UART/UART_int.h"
#include "MCAL/TIMER2/TIMER2_int.h"
#include "MCAL/UART/UART_config.h"

#include "util/delay.h"


#define NOT_COMMAND (!String_Compare(Data, "\\Back") && !String_Compare(Data, "\\Clear") && !String_Compare(Data, "\\NewL"))

#define MCU_NUMBER	0

uint_16 String_Compare(const uint_8* Data, const uint_8* String);
uint_8 Get_Length(const uint_8* Data);

int main(void){
	UART_enuInit();
	LCD_enuInit();
	uint_8 *Data = "TOGGLE LED", *Address = "0x90ba8ab53";
	uint_8 *Data_slave = "\0", *Address_slave = "\0";
	uint_8 Lcd_line = 0x01;
	//UART_enuEnableMultiProcessorMode();
	UART_enuResetCharacterSize(7);
	while(1){
#if MCU_NUMBER == 0
		UART_enuSendMCUAddress(Address);
		UART_enuSendDataToMCU(Data);
#elif MCU_NUMBER == 1
					while(!String_Compare(Address_slave, MCU_ADDRESS))
						UART_enuGetMCUAddress(Address_slave);

					UART_enuCheckAddress(Address_slave);
					UART_enuGetDataFromMaster(Data_slave);

				if(*Data_slave != '\\' && *Data_slave != '\0'){
					LCD_enuSendCommand(0x01);
					LCD_enuDisplayString(Data_slave);
					_delay_ms(1000);
					//UART_enuTransmitString("MCU(1) : The Screen is busy\n");
				}
//				else if(String_Compare(Data, "\\Clear") && *Data != '\0'){
//					Lcd_line = 0x01;
//					LCD_enuSendCommand(Lcd_line);
//					UART_enuTransmitString("MCU(1) : Cleared Successfully\n");
//				}
//				else if(String_Compare(Data, "\\NewL")  && *Data != '\0'){
//					if(Lcd_line == 0xC0){
//						Lcd_line = 0x80;
//					}
//					else{
//						Lcd_line =0xC0;
//					}
//					LCD_enuSendCommand(Lcd_line);
//					UART_enuTransmitString("MCU(1) : New Line Is Ready\n");
//				}
//				else if(String_Compare(Data, "\\")  && NOT_COMMAND && *Data != '\0'){
//					UART_enuTransmitString("MCU(1) : Command Error\n");
//				}
#elif MCU_NUMBER == 2
				UART_enuGetMCUAddress(Address);
				UART_enuCheckAddress(Address);
				UART_enuGetDataFromMaster(Data);
				if(!String_Compare(Data, "\\Clear") && *Data != '\\' && *Data != '\0'){

					LCD_enuDisplayString(Data);
					UART_enuTransmitString("MCU(1) : The Screen is busy\n");
				}
				else if(String_Compare(Data, "\\Clear") && *Data != '\0'){
					Lcd_line = 0x01;
					LCD_enuSendCommand(Lcd_line);
					UART_enuTransmitString("MCU(1) : Cleared Successfully\n");
				}
				else if(String_Compare(Data, "\\NewL")  && *Data != '\0'){
					if(Lcd_line == 0xC0){
						Lcd_line = 0x80;
					}
					else{
						Lcd_line =0xC0;
					}
					LCD_enuSendCommand(Lcd_line);
					UART_enuTransmitString("MCU(1) : New Line Is Ready\n");
				}
				else if(String_Compare(Data, "\\")  && NOT_COMMAND && *Data != '\0'){
					UART_enuTransmitString("MCU(1) : Command Error\n");
				}
#endif
	}

	return 0;
}

uint_16 String_Compare(const uint_8* Data, const uint_8* String){
	uint_8 Local_uint8Iterator = 0;
	while(String[Local_uint8Iterator] != '\0'){
		if(Data[Local_uint8Iterator] != String[Local_uint8Iterator]){
			return 0;
		}
		Local_uint8Iterator++;
	}
	if(Data[Local_uint8Iterator] != String[Local_uint8Iterator]){
		return 0;
	}
	return 1;
}

uint_8 Get_Length(const uint_8* Data){
	uint_8 Local_uint8Iterator = 0;
	while(Data[Local_uint8Iterator] != '\0'){
		Local_uint8Iterator++;
	}
	return Local_uint8Iterator;
}







