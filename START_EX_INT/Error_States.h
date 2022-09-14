/*
 * Error_States.h
 *
 *  Created on: Feb 21, 2022
 *      Author: amrmo
 */

#ifndef ERROR_STATES_H_
#define ERROR_STATES_H_

typedef enum{
	ES_OK,
	ES_NOK,
	ES_NULL_POINTER,
	ES_PORT_OUT_OF_RANGE,
	ES_PIN_OUT_OF_RANGE,
	ES_COMMON_DETECTION_ERROR,
	ES_EXINT_OUT_OF_RANGE
}ES_t;

#endif /* ERROR_STATES_H_ */
