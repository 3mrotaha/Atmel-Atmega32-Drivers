/*
 * SPI_int.h
 *
 * Created: 2/8/2023 5:14:02 AM
 *  Author: amrmo
 */ 

#include "SPI_priv.h"
#ifndef SPI_INT_H_
#define SPI_INT_H_

ErrorStates_t SPI_enuInit(void);

ErrorStates_t SPI_enuMasterTransmit(uint8 Copy_uint8byte, uint8 Copy_stSlaveID);

ErrorStates_t SPI_enuSlaveReceive(uint8 *Copy_puint8Byte);

ErrorStates_t SPI_enuMasterReceive(uint8 *Copy_puint8Byte);

ErrorStates_t SPI_enuSlaveTransmit(uint8 Copy_uint8Byte);

uint8 SPI_uint8WaitTransmit(void);

ErrorStates_t SPI_enuCallBack(void (*Copy_pfRoutine) (void*), void* Copy_pParameter);

#endif /* SPI_INT_H_ */