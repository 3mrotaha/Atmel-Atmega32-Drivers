/*
 * ADC_INT_VECT.h
 *
 *  Created on: Feb 25, 2022
 *      Author: amrmo
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_


ErrorStates_t ADC_enuInit(void);

ErrorStates_t ADC_enuEnable(void);

ErrorStates_t ADC_enuDisable(void);

ErrorStates_t ADC_enuSetVoltReference(uint8 Copy_uint8Voltage);

ErrorStates_t ADC_enuSetPrescaler(uint8 Copy_uint8Prescaler);

ErrorStates_t ADC_enuSetAdjustment(uint8 Copy_uint8Adjustment);

ErrorStates_t ADC_enuSelectChannel(uint8 Copy_uint8Channel);

ErrorStates_t ADC_enuReadValue(sint16* Copy_sint16ADCValue);

ErrorStates_t ADC_enuWaitOnFlag(void);





ErrorStates_t ADC_enuAutoTriggerEnable(void);

ErrorStates_t ADC_enuAutoTriggerDisable(void);

ErrorStates_t ADC_enuTriggerSource(uint8 Copy_uint8TriggerSource);

ErrorStates_t ADC_enuStartConversion(void);

ErrorStates_t ADC_enuEnableInterrupt(void);

ErrorStates_t ADC_enuDisableInterrupt(void);

ErrorStates_t ADC_enuCallBack(void (*Copy_pfuncConfig)(void*), void* Copy_voidParameter);


#define ADC_AREF							0
#define ADC_AVCC							1
#define ADC_INT_VECTERNAL_REF					3

#define ADC_PRESCALER_2						1
#define ADC_PRESCALER_4						2
#define ADC_PRESCALER_8						3
#define ADC_PRESCALER_16					4
#define ADC_PRESCALER_32					5
#define ADC_PRESCALER_64					6
#define ADC_PRESCALER_128					7

#define ADC_RIGHT_ADJUSTED					0
#define ADC_LEFT_ADJUSTED					1

#define ADC_FREE_RUNNING					0
#define ADC_ANALOG_COMPARATOR				1
#define ADC_EXTERNAL_INTERRUPT0				2
#define ADC_TIMERCOUNTER0_COMPMATCH			3
#define ADC_TIMERCOUNTER0_OVERFLOW			4
#define ADC_TIMERCOUNTER_COMPMATCHB			5
#define ADC_TIMERCOUNTER1_OVERFLOW			6
#define ADC_TIMERCOUNTER1_CAPTEVENT			7

#define ADC_SINGLEENFED_CH0					0
#define ADC_SINGLEENFED_CH1					1
#define ADC_SINGLEENFED_CH2					2
#define ADC_SINGLEENFED_CH3					3
#define ADC_SINGLEENFED_CH4					4
#define ADC_SINGLEENFED_CH5					5
#define ADC_SINGLEENFED_CH6					6
#define ADC_SINGLEENFED_CH7					7

#define ADC_DIFFRENTIAL_CH00_10x				8
#define ADC_DIFFRENTIAL_CH10_10x				9

#define ADC_DIFFRENTIAL_CH00_200x				10
#define ADC_DIFFRENTIAL_CH10_200x			11

#define ADC_DIFFRENTIAL_CH22_10x				12
#define ADC_DIFFRENTIAL_CH32_10x				13

#define ADC_DIFFRENTIAL_CH22_200x				14
#define ADC_DIFFRENTIAL_CH32_200x				15

#define ADC_DIFFRENTIAL_CH01_				16
#define ADC_DIFFRENTIAL_CH11_				17
#define ADC_DIFFRENTIAL_CH21_				18
#define ADC_DIFFRENTIAL_CH31_				19
#define ADC_DIFFRENTIAL_CH41_				20
#define ADC_DIFFRENTIAL_CH51_				21
#define ADC_DIFFRENTIAL_CH61_				22
#define ADC_DIFFRENTIAL_CH71_				23

#define ADC_DIFFRENTIAL_CH02_				24
#define ADC_DIFFRENTIAL_CH12_				25
#define ADC_DIFFRENTIAL_CH22_				26
#define ADC_DIFFRENTIAL_CH32_				27
#define ADC_DIFFRENTIAL_CH42_				28
#define ADC_DIFFRENTIAL_CH52_				29


#endif /* ADC_INT_H_ */
