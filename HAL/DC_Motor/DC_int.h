/*
 * DC_int.h
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#ifndef HAL_DC_MOTOR_DC_INT_H_
#define HAL_DC_MOTOR_DC_INT_H_

ErrorStates_t DC_enuInit(DC_t *Copy_pstrMotorConfig);

ErrorStates_t DC_enuSetMotorDir(uint8 MotorID, uint8 Copy_u8Direction);

ErrorStates_t DC_enuTogMotorDir(uint8 MotorID);

ErrorStates_t DC_enuControlSpeed(uint8 MotorID, uint8 Copy_uint8Speed);

#endif /* HAL_DC_MOTOR_DC_INT_H_ */
