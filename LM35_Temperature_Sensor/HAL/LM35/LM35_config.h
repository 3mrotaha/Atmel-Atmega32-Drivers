/*
 * LM35_config.h
 *
 *  Created on: Oct 9, 2021
 *      Author: amrmo
 */

#ifndef HAL_LM35_LM35_CONFIG_H_
#define HAL_LM35_LM35_CONFIG_H_

/* USE One Channel Of Range :
 *
 *	  	ADC_enuSingleEndedChannel0
 *    	ADC_enuSingleEndedChannel1
 *    	ADC_enuSingleEndedChannel2
 *    	ADC_enuSingleEndedChannel3
 *    	ADC_enuSingleEndedChannel4
 *    	ADC_enuSingleEndedChannel5
 *    	ADC_enuSingleEndedChannel6
 *    	ADC_enuSingleEndedChannel7
 */

#define SENSOR_POS_CHANNEL		ADC_enuSingleEndedChannel1
#define SENSOR_NEG_CHANNEL		ADC_enuSingleEndedChannel2

#endif /* HAL_LM35_LM35_CONFIG_H_ */
