/*
 * TIMER0_int.h
 *
 *  Created on: Feb 28, 2022
 *      Author: amrmo
 */

#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

#define TIMER0_uint8NON_PWM_NORMAL						0
#define TIMER0_uint8NON_PWM_TOGGLE						1
#define TIMER0_uint8NON_PWM_CLEAR 						2
#define TIMER0_uint8NON_PWM_SET   						3

#define TIMER0_uint8FAST_PWM_NORMAL						0
#define TIMER0_uint8FAST_PWM_CLEAR 						2
#define TIMER0_uint8FAST_PWM_SET   						3

#define TIMER0_uint8PHASECORRECT_PWM_NORMAL				0
#define TIMER0_uint8PHASECORRECT_PWM_CLEAR 				2
#define TIMER0_uint8PHASECORRECT_PWM_SET   				3

#define TIMER0_uint8INT_OVF								0
#define TIMER0_uint8INT_COMP							1


ES_t TIMER0_enuInit(void);

ES_t TIMER0_enuSetSyncDelay(uint_32 Copy_uint32TimeMS);

ES_t TIMER0_enuSetAsyncDelay(uint_32 Copy_uint32TimeMS, void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter);

ES_t TIMER0_enuEnableOVFInterrupt(void);

ES_t TIMER0_enuDisableOVFInterrupt(void);

ES_t TIMER0_enuSetCompareMatch(uint_8 Copy_uint8Counts, uint_8 Copy_uint8OCMode);

ES_t TIMER0_enuCorrectPhasePWM(uint_8 Copy_uint8Counts, uint_8 Copy_uint8OCMode);

ES_t TIMER0_enuFastPWM(uint_8 Copy_uint8Counts, uint_8 Copy_uint8OCMode);

ES_t TIMER0_enuFastPWMByDutyCycle(f32 Copy_uint8DutyCycle, uint_8 Copy_uint8OCMode);

ES_t TIMER0_enuPhaseCorrectByDutyCycle(f32 Copy_uint8DutyCycle, uint_8 Copy_uint8OCMode);

ES_t TIMER0_enuEnableCOMPInterrupt(void);

ES_t TIMER0_enuDisableCOMPInterrupt(void);

ES_t TIMER0_enuCTCCallBack(void (*Copy_pfuncCallFunc) (void*), void* Copy_pvoidParameter);

#endif /* TIMER0_INT_H_ */
