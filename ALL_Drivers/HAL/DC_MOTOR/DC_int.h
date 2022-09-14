/*
 * DC_int.h
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#ifndef HAL_DC_MOTOR_DC_INT_H_
#define HAL_DC_MOTOR_DC_INT_H_

ES_t DC_enuInit(DC_t *Copy_pstrMotorConfig);

ES_t DC_enuSetMotorDir(u8 MotorID, u8 Copy_u8Direction);

ES_t DC_enuTogMotorDir(u8 MotorID);

#endif /* HAL_DC_MOTOR_DC_INT_H_ */
