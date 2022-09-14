/*
 * UART_config.h
 *
 *  Created on: Mar 19, 2022
 *      Author: amrmo
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


#define UART_MODE	UART_DOUBLE_SPEED_MODE

#define MULTI_PROCESSOR_COMMUNICATION_MODE	DISABLE

#define CHARACTER_SIZE			8

#define BAUD_RATE_VALUE			(4800UL)

#define MAX_TRANSMITTED_FRACTION	4


/*
 * "0x6ffdacabe" --> master
 * "0x8bc2df5b1" --> slave 1
 * "0x90ba8ab53" --> slave 2
 * */
#define MCU_ADDRESS					"0x90ba8ab53"
#endif /* UART_CONFIG_H_ */
