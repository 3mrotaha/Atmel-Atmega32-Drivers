/*
 * EXINT_config.c
 *
 *  Created on: Feb 24, 2022
 *      Author: amrmo
 */
#include "std_types.h"
#include "Error_States.h"

#include "EXINT_config.h"
#include "EXINT_int.h"


EXINT_t EXINT_AstrExINTConfig[EXINT_NUM] = {
		{EXINTuint8_INT0, EXINTuint8_ENABLED, EXINTuint8_FALLING_EDGE},
		{EXINTuint8_INT1, EXINTuint8_ENABLED, EXINTuint8_LOGICAL_CHANGE},
		{EXINTuint8_INT2, EXINTuint8_ENABLED, EXINTuint8_RISING_EDGE}
};
