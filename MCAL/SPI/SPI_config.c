/*
 * SPI_config.c
 *
 * Created: 3/18/2023 4:28:04 PM
 *  Author: amrmo
 */ 

#include "../DIO/DIO_int.h"
#include "SPI_priv.h"
#include "SPI_config.h"


ST_Slave_t SPI_AstSlaves[SLAVES_NUM] = {
	{0, DIO_uint8_PORTD, DIO_uint8_PIN0},
};