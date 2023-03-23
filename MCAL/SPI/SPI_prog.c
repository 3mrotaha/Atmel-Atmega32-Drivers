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



extern ST_Slave_t SPI_AstSlaves[SLAVES_NUM];
static void (*SPI_pfRoutine)(void*) = NULL;
static void *SPI_pParameter = NULL; 
static uint8 SPI_uint8Byte;

ErrorStates_t SPI_enuInit(void){
	#if MCU_MODE == MASTER_MCU	
		// initialize the slaves pins as output and high
		for(uint8 Iterator = 0; Iterator < SLAVES_NUM; Iterator++){
			DIO_enuSetPinDir(SPI_AstSlaves[Iterator].ssPort, SPI_AstSlaves[Iterator].sspin, OUTPUT);
			DIO_enuSetPinValue(SPI_AstSlaves[Iterator].ssPort, SPI_AstSlaves[Iterator].sspin, HIGH);
			EXINT_enuCallBack(&SPI_voidMasterReceive, NULL, SPI_AstSlaves[Iterator].EXINT_ID);
			EXINT_enuIntEnable(SPI_AstSlaves[Iterator].EXINT_ID, EXINTuint8_FALLING_EDGE);
		}
		// set the sck pin as output
		DIO_enuSetPinDir(DIO_uint8_PORTB,DIO_uint8_PIN7,OUTPUT);
		// set the mosi as output
		DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN5, OUTPUT);
		// set the miso as input
		DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN6, INPUT);
	#elif MCU_MODE == SLAVE_MCU
		// set the sck pin as input
		DIO_enuSetPinDir(DIO_uint8_PORTB,DIO_uint8_PIN7,INPUT);
		// set the mosi as input
		DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN5, INPUT);
		// set the miso as output
		DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN6, OUTPUT);
		// set the direction & value of ss pin
		DIO_enuSetPinDir(DIO_uint8_PORTB, DIO_uint8_PIN4, OUTPUT);
		DIO_enuSetPinValue(DIO_uint8_PORTB, DIO_uint8_PIN4, HIGH);
	#else
		#error "you have to select the mcu mode as SLAVE_MCU or MASTER_MCU";
	#endif
	// initializing the spcr content
	// interrupt; enable spi; data order; master or slave; clock polarity; clock phase; clock rate
	SPCR = (SPI_INTERRUPT << SPCR_SPIE_BIT) | (BIT_MASK1 << SPCR_SPE_BIT) | (DATA_ORDER << SPCR_DORD_BIT)
			| (MCU_MODE << SPCR_MSTR_BIT) | (CLOCK_POLARITY << SPCR_CPOL_BIT) | (CLOCK_PHASE << SPCR_CPHA_BIT)
			| (SPI_CLOCK_RATE << SPCR_SPR0_BIT);
	// Initialize the spsr content
	// double speed mode
	SPSR |= (SPI_SPEED << SPSR_SPI2X_BIT);		
}

ErrorStates_t SPI_enuMasterTransmit(uint8 Copy_uint8Byte, uint8 Copy_stSlaveID){
	if(SPI_AstSlaves[Copy_stSlaveID].EXINT_ID < EXINT_NUM){

		EXINT_enuIntDisable(SPI_AstSlaves[Copy_stSlaveID].EXINT_ID);
		
		// assign the byte to be sent to the spi data register and start transmission
		SPDR = Copy_uint8Byte;
		// select the slave
		DIO_enuSetPinValue(SPI_AstSlaves[Copy_stSlaveID].ssPort, SPI_AstSlaves[Copy_stSlaveID].sspin, LOW);
		// wait on the flag to send
		while(!((SPSR >> SPSR_SPIF_BIT) & BIT_MASK1));
		
		// select the slave
		DIO_enuSetPinValue(SPI_AstSlaves[Copy_stSlaveID].ssPort, SPI_AstSlaves[Copy_stSlaveID].sspin, HIGH);

		
		EXINT_enuIntEnable(SPI_AstSlaves[Copy_stSlaveID].EXINT_ID, EXINTuint8_FALLING_EDGE);
		
		return ES_OK;
	}
	else{				
		return ES_OUT_OF_RANGE;
	}
}

ErrorStates_t SPI_enuSlaveReceive(uint8 *Copy_uint8Byte){
	if(Copy_uint8Byte != NULL){
		// wait until the flag is set
		while(!((SPSR >> SPSR_SPIF_BIT) & BIT_MASK1));
	
		// copy content
		*Copy_uint8Byte = SPDR;
		
		return ES_OK;
	}
	else{
		return ES_NULL_POINTER;
	}
}

uint8 SPI_uint8WaitTransmit(void){
	
	while(!((SPSR >> SPSR_SPIF_BIT) & BIT_MASK1));
	
	uint8 local_uint8Flush = SPDR;
	
	return 1;
}
ErrorStates_t SPI_enuMasterReceive(uint8 *Copy_puint8Byte){
	if(Copy_puint8Byte != NULL){
		*Copy_puint8Byte = SPI_uint8Byte;
		return ES_OK;
	}
	else{
		return ES_NULL_POINTER;
	}
}
static void SPI_voidMasterReceive(void){
		SPDR = 'R';
			
		while(!((SPSR >> SPSR_SPIF_BIT) & BIT_MASK1));
		
		SPI_uint8Byte = SPDR;		
}

ErrorStates_t SPI_enuSlaveTransmit(uint8 Copy_uint8Byte){
	if(Copy_uint8Byte != '\0'){
		// set the slave low to generate interrupt on the master pin
		DIO_enuSetPinValue(DIO_uint8_PORTB, DIO_uint8_PIN4, LOW);
		
		// assign the byte to be sent to the spi data register and start transmission
		SPDR = Copy_uint8Byte;
		// wait on the flag to send
		while(!((SPSR >> SPSR_SPIF_BIT) & BIT_MASK1));		
		
		uint8 local_uint8Flush = SPDR;
		
		DIO_enuSetPinValue(DIO_uint8_PORTB, DIO_uint8_PIN4, HIGH);
		
		return ES_OK;
	}
	else{
		return ES_NOK;
	}
}

ErrorStates_t SPI_enuCallBack(void (*Copy_pfRoutine) (void*), void* Copy_pParameter){
	if(Copy_pfRoutine != NULL){
		SPI_pfRoutine = Copy_pfRoutine;
		SPI_pParameter = Copy_pParameter;
		return ES_OK;
	}
	else{		
		return ES_NULL_POINTER;
	}
}

ISR(SPI_VECT){
	if(SPI_pfRoutine != NULL)
		SPI_pfRoutine(SPI_pParameter);
}