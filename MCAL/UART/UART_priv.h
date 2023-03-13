/*
 * UART_priv.h
 *
 *  Created on: Mar 19, 2022
 *      Author: amrmo
 */

#ifndef UART_PRIV_H_
#define UART_PRIV_H_
 

#define UBRR_CALC(BAUDRATE_VAL)			(F_CPU/(UART_MODE * 8 *(BAUDRATE_VAL)) - 1)


#define URSEL_BIT		7
#define UMSEL_BIT		6
#define UPM1_BIT		5
#define UPM0_BIT		4
#define USBS_BIT		3
#define UCSZ1_BIT		2
#define UCSZ0_BIT		1
#define UCPOL_BIT		0

#define RXCIE_BIT		7
#define TXCIE_BIT		6
#define UDRIE_BIT		5
#define RXEN_BIT		4
#define TXEN_BIT		3
#define UCSZ2_BIT		2
#define RXB8_BIT		1
#define TXB8_BIT		0

#define RXC_BIT			7
#define TXC_BIT			6
#define UDRE_BIT		5
#define FE_BIT			4
#define DOR_BIT			3
#define PE_BIT			2
#define U2X_BIT			1
#define MPCM_BIT		0

#define UART_NORMAL_MODE			2
#define UART_DOUBLE_SPEED_MODE		1

#define TYPE_DATA					50
#define TYPE_ADDRESS				43

#define ENABLE			121
#define DISABLE			122

#define UART_INT_TXC		0
#define UART_INT_RXC		1
#define UART_INT_UDRE		2
#define UART_INTERRUPTS		3

static inline void UART_voidConvert_to_Number(const uint8 *data, f32_t *Number);

static inline void UART_voidStringify_Number(f32_t number, uint8 *data);

static inline void UART_voidRecieveString(uint8* Copy_puint8Data);

static inline void UART_voidTransmitString(uint8* Copy_puint8Data);

static inline void UART_voidWaitOnTXC(void);

static inline void UART_voidWaitOnRXC(void);

static inline void UART_voidWaitOnUDRE(void);

static inline void UART_voidResetCharacterSize(uint8 Copy_uint8Value);

static uint8 UART_uint8String_Compare(const uint8* Data, const uint8* String);

static inline void UART_voidTransmit9BitData(const uint8* Copy_puint8Data, const uint8 Copy_uint8Type);

static inline void UART_voidReceive9BitData(uint8* Copy_puint8Data);
#endif /* UART_PRIV_H_ */
