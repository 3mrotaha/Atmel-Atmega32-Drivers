/*
 * SPI_config.h
 *
 * Created: 2/8/2023 5:13:39 AM
 *  Author: amrmo
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_
/*
	select the mcu as a master or slave mode
	- MASTER_MCU
	- SLAVE_MCU
*/
#define MCU_MODE MASTER_MCU
// if the mcu is a master, select number of slaves for this master mcu, otherwise, skip this configuration
#define SLAVES_NUM	 1
/*
	 select the spi clock rate
	 - FOSC_4
	 - FOSC_8
	 - FOSC_16
	 - FOSC_32
*/
#define SPI_CLOCK_RATE	FOSC_4
/*
	choose even the spi speed is normal or doubled
	- NORMAL_SPEED
	- DOUBLE_SPEED
*/
#define SPI_SPEED	NORMAL_SPEED
/*
	choose the spi data order
	- MSB_FIRST: to send the most significant bit first
	- LSB_FIRST: to send the least significant bit first
*/
#define DATA_ORDER	LSB_FIRST

/*
	select the Clock polarity:
	- CPOL_SET: Leading edge is RISING, Trailing edge is FALLING
	- CPOL_CLEARED: Leading edge is FALLING, Trailing edge is RISING
*/
#define CLOCK_POLARITY CPOL_CLEARED
/*
	select the clock phase:
	- CPHA_SET: Leading edge SAMPLE, Trailing edge SETUP
	- CPHA_CLEARED: Leading edge SETUP, Trailing edge SAMPLE
*/
#define CLOCK_PHASE CPHA_CLEARED
/*
	Choose even to enable or disable the spi interrupt
	- SPI_INTERRUPT_ENABLE: An interrupt request is generated on the transmit end flag setting
	- SPI_INTERRUPT_DISABLE: no interrupt request is generated.
*/
#define SPI_INTERRUPT SPI_INTERRUPT_DISABLE
#endif /* SPI_CONFIG_H_ */