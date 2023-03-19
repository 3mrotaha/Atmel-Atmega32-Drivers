/*
 * SPI_prog.c
 *
 * Created: 2/8/2023 5:14:45 AM
 *  Author: amrmo
 */ 

#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"
#include "../../LIB/Bit_Level.h"
#include "../../LIB/GPRs.h"

#include "../DIO/DIO_int.h"
#include "../EX_Interrupt/EXINT_int.h"

#include "SPI_priv.h"
#include "SPI_config.h"


ErrorStates_t SPI_enuInit(void);

ErrorStates_t SPI_enuMasterTransmit(uint8 Copy_uint8byte, ST_Slave_t Copy_stSlave);

ErrorStates_t SPI_enuSlaveReceive(uint8 *Copy_uint8Byte);

uint8 SPI_uint8WaitTransmit(void);

ErrorStates_t SPI_enuCallBack(void (*Copy_pfRoutine) (void*), void* Copy_pParameter);