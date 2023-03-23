/*
 * SPI_priv.h
 *
 * Created: 2/8/2023 5:13:14 AM
 *  Author: amrmo
 */ 

#include "../../LIB/std_types.h"

#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

// SPCR bits
#define SPCR_SPIE_BIT	7
#define SPCR_SPE_BIT	6
#define SPCR_DORD_BIT	5
#define SPCR_MSTR_BIT	4
#define SPCR_CPOL_BIT	3
#define SPCR_CPHA_BIT	2
#define SPCR_SPR1_BIT	1
#define SPCR_SPR0_BIT	0
// SPSR bits
#define SPSR_SPIF_BIT	7
#define SPSR_WCOL_BIT	6
#define SPSR_SPI2X_BIT	0
// MCU TYPE
#define  MASTER_MCU	1
#define	 SLAVE_MCU	0
// SPI speed
#define NORMAL_SPEED 0
#define DOUBLE_SPEED 1
// SPI Clock rate
#define FOSC_4	0
#define FOSC_8  1
#define FOSC_16 2
#define FOSC_32 3
// SPI data order
#define LSB_FIRST 0
#define MSB_FIRST 1
// SPI Clock polarity
#define CPOL_SET 1
#define CPOL_CLEARED 0
// SPI Clock phase
#define CPHA_SET 1
#define CPHA_CLEARED 0
// SPI Interrupt
#define SPI_INTERRUPT_DISABLE 0
#define SPI_INTERRUPT_ENABLE 1


typedef struct{
	uint8 EXINT_ID;
	uint8 ssPort;
	uint8 sspin;
}ST_Slave_t;

static void SPI_voidMasterReceive(void);

#endif /* SPI_PRIV_H_ */