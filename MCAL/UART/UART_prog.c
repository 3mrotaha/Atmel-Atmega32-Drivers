/*
 * UART_prog.c
 *
 *  Created on: Mar 19, 2022
 *      Author: amrmo
 */

#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"
#include "../../LIB/Bit_Level.h"
#include "../../LIB/GPRs.h"


#include "UART_priv.h"
#include "UART_config.h"

static void (*UART_pfCalledFunc[UART_INTERRUPTS]) (void*) = {NULL, NULL, NULL};
static void *UART_pParameter[UART_INTERRUPTS] = {NULL, NULL, NULL};

ErrorStates_t UART_enuInit(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	/*Enable receiver and transmitter*/
	UCSRA = (BIT_MASK1 << U2X_BIT);
	UCSRB = (BIT_MASK1 << TXEN_BIT)|(BIT_MASK1 << RXEN_BIT);
	/*Set the Baud Rate Value*/
	uint16 Local_uint16_tUBRRValue = UBRR_CALC(BAUD_RATE_VALUE);
	Local_uint16_tUBRRValue &= ~(BIT_MASK1 << 15);
	UBRRL = (uint8) Local_uint16_tUBRRValue;
	UBRRH = (uint8)(Local_uint16_tUBRRValue >> 8);
	/*Set the frame format: 8 bit data, 1 stop bit*/
	UCSRC = (BIT_MASK1 << URSEL_BIT)|(BIT_MASK2 << UCSZ0_BIT);
	UCSRB |= (BIT_MASK1 << UCSZ2_BIT);
	return Local_enuErrorStates;
}

ErrorStates_t UART_enuTransmitChar(uint8 Copy_uint8Data){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	while(!((UCSRA >> UDRE_BIT) & BIT_MASK1))
		;
	UDR = Copy_uint8Data;
	return Local_enuErrorStates;
}

ErrorStates_t UART_enuReceiveChar(uint8 *Copy_uint8Data){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	while(!((UCSRA >> RXC_BIT) & BIT_MASK1))
		;
	*Copy_uint8Data = UDR;
	return Local_enuErrorStates;
}

ErrorStates_t UART_enuTransmitString(uint8 *Copy_uint8Data){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_uint8Data != NULL){

		UART_voidTransmitString(Copy_uint8Data);

		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}

	return Local_enuErrorStates;
}

ErrorStates_t UART_enuReceiveString(uint8 *Copy_uint8Data){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_uint8Data != NULL){

		UART_voidRecieveString(Copy_uint8Data);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}

	return Local_enuErrorStates;
}

ErrorStates_t UART_enuReceiveNumber(f32_t *Copy_f32Number){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_f32Number != NULL){
		uint8* Local_puintData = "\0";

		UART_voidRecieveString(Local_puintData);

		UART_voidConvert_to_Number(Local_puintData, Copy_f32Number);
		Local_enuErrorStates = ES_OK;
	}
	else {
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ErrorStates_t UART_enuTransmitNumber(f32_t Copy_f32Number){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	uint8* Local_puintData = "\0";

	UART_voidStringify_Number(Copy_f32Number, Local_puintData);

	UART_voidTransmitString(Local_puintData);
	return Local_enuErrorStates;
}

ErrorStates_t UART_enuEnableTransmitter(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	UCSRB |= (BIT_MASK1 << TXEN_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t UART_enuDisableTransmitter(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	UCSRB &= ~(BIT_MASK1 << TXEN_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t UART_enuEnableReceiver(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	UCSRB |= (BIT_MASK1 << RXEN_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t UART_enuDisableReceiver(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	UCSRB &= ~(BIT_MASK1 << RXEN_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t UART_enuSetBaudRate(uint16 Copy_uint8Value){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	uint16 Local_uint16_tUBRRValue = UBRR_CALC(Copy_uint8Value);
	Local_uint16_tUBRRValue &= ~(BIT_MASK1 << 15); // clear the ursel bit
	UBRRL = (uint8) Local_uint16_tUBRRValue;
	UBRRH = (uint8)(Local_uint16_tUBRRValue >> 8);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t UART_enuResetCharacterSize(uint8 Copy_uint8Value){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	UART_voidResetCharacterSize(Copy_uint8Value);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t UART_enuEnableMultiProcessorMode(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	UCSRA |= (BIT_MASK1 << MPCM_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t UART_enuDisableMultiProcessorMode(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	UCSRA &= ~(BIT_MASK1 << MPCM_BIT);
	return Local_enuErrorStates;
}

ErrorStates_t UART_enuSendMCUAddress(const uint8 *Copy_puintAddress){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_puintAddress != NULL){
		UART_voidTransmit9BitData(Copy_puintAddress, TYPE_ADDRESS);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ErrorStates_t UART_enuSendDataToMCU(const uint8 *Copy_puint8Data){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_puint8Data != NULL){
		UART_voidTransmit9BitData(Copy_puint8Data, TYPE_DATA);
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ErrorStates_t UART_enuGetMCUAddress(uint8 *Copy_puintAddress){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_puintAddress != NULL){
		if((UCSRB >> RXB8_BIT) & BIT_MASK1){
			UART_voidReceive9BitData(Copy_puintAddress);
		}
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ErrorStates_t UART_enuCheckAddress(const uint8 *Copy_puintAddress){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_puintAddress != NULL){
		if((UCSRB >> RXB8_BIT) & BIT_MASK1){
			if(UART_uint8String_Compare(Copy_puintAddress, MCU_ADDRESS)){
				UCSRA &= ~(BIT_MASK1 << MPCM_BIT);
			}
			else{
				UCSRA |= (BIT_MASK1 << MPCM_BIT);
			}
		}
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}


ErrorStates_t UART_enuGetDataFromMaster(uint8 *Copy_puint8Data){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_puint8Data != NULL){
		if(!((UCSRB >> RXB8_BIT) & BIT_MASK1) && !(UCSRA & BIT_MASK1)){
			UART_voidReceive9BitData(Copy_puint8Data);
		}
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}


 ErrorStates_t UART_enuToSendAddress(void){
	 ErrorStates_t Local_enuErrorState = ES_NOK;
	 uint8 Local_uint8UCSRC = UBRRH;
	 Local_uint8UCSRC = UCSRC;
	 Local_uint8UCSRC |= (BIT_MASK1 << USBS_BIT);
	 Local_uint8UCSRC |= (BIT_MASK1 << URSEL_BIT)|(BIT_MASK1 << USBS_BIT);
	 UCSRC = Local_uint8UCSRC;
	 return Local_enuErrorState;
 }

 ErrorStates_t UART_enuToSendData(void){
	 ErrorStates_t Local_enuErrorState = ES_NOK;
	 uint8 Local_uint8UCSRC = UBRRH;
	 Local_uint8UCSRC = UCSRC;
	 Local_uint8UCSRC = (Local_uint8UCSRC | (BIT_MASK1 << URSEL_BIT)) & ~(BIT_MASK1 << USBS_BIT);
	 UCSRC = Local_uint8UCSRC;
	 return Local_enuErrorState;
 }


ErrorStates_t UART_enuEnableRXCInterrupt(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	UCSRB |= (BIT_MASK1 << RXCIE_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t UART_enuDisableRXCInterrupt(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	UCSRB &= ~(BIT_MASK1 << RXCIE_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t UART_enuEnableTXCInterrupt(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	UCSRB |= (BIT_MASK1 << TXCIE_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t UART_enuDisableTXCInterrupt(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	UCSRB &= ~(BIT_MASK1 << TXCIE_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t UART_enuEnableUDREInterrupt(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	UCSRB |= (BIT_MASK1 << UDRIE_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t UART_enuDisableUDREnterrupt(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	UCSRB &= ~(BIT_MASK1 << UDRIE_BIT);
	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t UART_enuCallBack(void (*Copy_pFuncConfig)(void*), void* Copy_pParameter, uint8 Copy_Interrupt_Type){
	ErrorStates_t Local_enuErrorStates = ES_OK;
	if(Copy_pFuncConfig != NULL){
		if(Copy_Interrupt_Type == UART_INT_RXC){
			UART_pfCalledFunc[UART_INT_RXC] = *Copy_pFuncConfig;
			UART_pParameter[UART_INT_RXC] = Copy_pParameter;
			Local_enuErrorStates = ES_OK;
		}
		else if(Copy_Interrupt_Type == UART_INT_TXC) {
			UART_pfCalledFunc[UART_INT_TXC] = *Copy_pFuncConfig;
			UART_pParameter[UART_INT_TXC] = Copy_pParameter;
			Local_enuErrorStates = ES_OK;
		}
		else if(Copy_Interrupt_Type == UART_INT_UDRE) {
			UART_pfCalledFunc[UART_INT_UDRE] = *Copy_pFuncConfig;
			UART_pParameter[UART_INT_UDRE] = Copy_pParameter;
			Local_enuErrorStates = ES_OK;
		}
		else{
#warning "Selection Of UART Interrupt type is not going right!"
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

static inline void UART_voidStringify_Number(f32_t number, uint8 *data) {
    if(number != 0){
		uint32 number_int = (uint32) number, Max_fract = MAX_TRANSMITTED_FRACTION;
		f32_t fract = number - number_int;

		uint8 Get_number[15] = "\0";
		sint16 index = 0, index_rev = 0;

		while(number_int) {
			Get_number[index] = ('0' + number_int % 10);
			number_int /= 10;
			index++;
		}
		index -= 1;
		while(index >= 0) {
			data[index_rev++] = Get_number[index--];
		}
		if(fract != 0) {
			data[index_rev++] = '.';

			while(fract && Max_fract) {
				data[index_rev++] = ((uint32) (fract * 10) + '0');
				fract = (fract * 10) - (uint32) (fract * 10);
				Max_fract-=1;
			}
		}
    }
    else{
    	*data = '0';
    }
}

static inline void UART_voidConvert_to_Number(const uint8 *data, f32_t *Number) {
	uint8  Integer_string[15] = "\0";
	uint8 	Fraction_string[15] = "\0";

    uint8 flag = 1, i_num = 0, i_int = 0, i_fract = 0;
    uint32 number_int = 0;

    f32_t int_factor = 0.1, fract_factor = 10, number_float = 0;

    while(data[i_num] != '\0') {
        if(flag) {
            if(data[i_num] == '.') {
                flag = 0;
            }
            else {
                Integer_string[i_int] = data[i_num];
                i_int++;
                int_factor *= 10;
            }
        }
        else {
            Fraction_string[i_fract] = data[i_num];
            i_fract++;
        }
        i_num++;
    }

    Integer_string[i_int] = '\0', Fraction_string[i_fract] = '\0';

    i_int = 0, i_fract = 0;
    while(Integer_string[i_int] != '\0') {
        number_int += int_factor * (Integer_string[i_int] - '0');
        int_factor /= 10;
        i_int++;
    }

    while(Fraction_string[i_fract] != '\0') {
        number_float += (float) (Fraction_string[i_fract] - '0') / fract_factor;
        fract_factor *= 10;
        i_fract++;
    }
    if((number_int + number_float) != 0.0){
		*Number = number_int + number_float;
    }
}

static inline void UART_voidRecieveString(uint8* Copy_puint8Data){

	uint8 Local_uint8Iterator = 0, Local_uint8Data;

	while(1){
			UART_voidWaitOnRXC();
			Local_uint8Data = UDR;
			if(Local_uint8Data != '\0' && !(Local_uint8Data == '\r' || Local_uint8Data == '\n')){
				Copy_puint8Data[Local_uint8Iterator] = Local_uint8Data;
			}

			if(Local_uint8Data == '\r' || Local_uint8Data == '\n'){
				Copy_puint8Data[Local_uint8Iterator] = '\0';
				break;
			}
			Local_uint8Iterator++;
	}
}

static inline void UART_voidTransmitString(uint8* Copy_puint8Data){
	uint8 Local_uint8Iterator = 0;
		while(Copy_puint8Data[Local_uint8Iterator] != '\0'){
			UART_voidWaitOnUDRE();

			UDR = Copy_puint8Data[Local_uint8Iterator];
			Local_uint8Iterator++;

		}
}

static inline void UART_voidWaitOnTXC(void){
	while(!((UCSRA >> TXC_BIT) & BIT_MASK1))
		;
}

static inline void UART_voidWaitOnRXC(void){
	while(!((UCSRA >> RXC_BIT) & BIT_MASK1))
			;
}

static inline void UART_voidWaitOnUDRE(void){
	while(!((UCSRA >> UDRE_BIT) & BIT_MASK1))
			;
}

static inline void UART_voidResetCharacterSize(uint8 Copy_uint8Value){
	uint8 Local_uint8ucsrc = UBRRH;
	Local_uint8ucsrc = UCSRC;
	Local_uint8ucsrc |= (BIT_MASK1 << URSEL_BIT); // select the register ucsra
	Local_uint8ucsrc &= ~(BIT_MASK2 << UCSZ0_BIT);
	Local_uint8ucsrc = ((Copy_uint8Value & BIT_MASK2) << UCSZ0_BIT);

	UCSRB &= ~(BIT_MASK1 << UCSZ2_BIT);
	UCSRB |= (((Copy_uint8Value >> UCSZ2_BIT) & BIT_MASK1) << UCSZ2_BIT);
	UCSRC = Local_uint8ucsrc;
}

static uint8 UART_uint8String_Compare(const uint8* Data, const uint8* String){
	uint8 Local_uint8Iterator = 0;
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

static inline void UART_voidTransmit9BitData(const uint8* Copy_puint8Data, const uint8 Copy_uint8Type){
	if(Copy_puint8Data != NULL){
		uint8 Local_uint8Iterator = 0;
		while(Copy_puint8Data[Local_uint8Iterator] != '\0'){
			UART_voidWaitOnUDRE();

			UCSRB &= ~(BIT_MASK1 << TXB8_BIT);
			if(Copy_uint8Type == TYPE_ADDRESS)
				UCSRB |= (BIT_MASK1 << TXB8_BIT);

			UDR = Copy_puint8Data[Local_uint8Iterator];
			Local_uint8Iterator++;
		}
	}
}

static inline void UART_voidReceive9BitData(uint8* Copy_puint8Data){
	if(Copy_puint8Data != NULL){
		uint8 Local_uint8Iterator = 0, Local_uint8RXB8 = 0;
		while(1){
			UART_voidWaitOnRXC();

			Local_uint8RXB8 = ((UCSRB >> RXB8_BIT) & BIT_MASK1);
			Copy_puint8Data[Local_uint8Iterator] = UDR;

			if(Copy_puint8Data[Local_uint8Iterator] == '\r' || Copy_puint8Data[Local_uint8Iterator] == '\n'){
				Copy_puint8Data[Local_uint8Iterator] = '\0';
				break;
			}
			Local_uint8Iterator++;
		}
	}
}

ISR(UART_RXC_VECT){
	if(UART_pfCalledFunc[UART_INT_RXC] != NULL){
		UART_pfCalledFunc[UART_INT_RXC](UART_pParameter[UART_INT_RXC]);
	}
}

ISR(UART_TXC_VECT){
	if(UART_pfCalledFunc[UART_INT_TXC] != NULL){
			UART_pfCalledFunc[UART_INT_TXC](UART_pParameter[UART_INT_TXC]);
	}
}

ISR(UART_UDRE_VECT){
	if(UART_pfCalledFunc[UART_INT_UDRE] != NULL){
			UART_pfCalledFunc[UART_INT_UDRE](UART_pParameter[UART_INT_UDRE]);
	}
}
