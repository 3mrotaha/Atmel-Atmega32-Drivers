/*
 * TIMER1_int.h
 *
 *  Created on: Mar 7, 2022
 *      Author: amrmo
 */

#ifndef MCAL_TIMER1_TIMER1_INT_H_
#define MCAL_TIMER1_TIMER1_INT_H_

/*********************************************************************
 *********************************************************************
 ** Function Name: TIMER1_enuInit									**
 ** Return Type: ES_t (Error State)									**
 ** Arguments:	Void												**
 ** Functionality:	Intiate the Timer1 Prescaler, Compare Match		**
 ** 				and wave Generation Mode						**
 ** 																**
 *********************************************************************
 *********************************************************************/
ES_t TIMER1_enuInit(void);

/*********************************************************
 *********************************************************
 ** Function Name:										**
 ** Return Type:										**
 ** Arguments:											**
 ** Functionality:										**
 ** 													**
 *********************************************************
 *********************************************************/
ES_t TIMER1_enuSyncDelay(uint_32 Copy_uint32TimeMS);

/*********************************************************
 *********************************************************
 ** Function Name:										**
 ** Return Type:										**
 ** Arguments:											**
 ** Functionality:										**
 ** 													**
 *********************************************************
 *********************************************************/
ES_t TIMER1_enuASyncDelay(uint_32 Copy_uint32TimeMS, void (*Copy_pfDelay) (void*), void* Copy_pParameter);

/*********************************************************
 *********************************************************
 ** Function Name:										**
 ** Return Type:										**
 ** Arguments:											**
 ** Functionality:										**
 ** 													**
 *********************************************************
 *********************************************************/
ES_t TIMER1_enuCompareOutput_OCR1A(uint_16 Copy_uint16CompMatch, uint_8 Copy_CompMode, void (*Copy_pfCTC) (void*), void* Copy_pParameter);

/*********************************************************
 *********************************************************
 ** Function Name:										**
 ** Return Type:										**
 ** Arguments:											**
 ** Functionality:										**
 ** 													**
 *********************************************************
 *********************************************************/
ES_t TIMER1_enuCompareOutput_OCR1B(uint_16 Copy_uint16CompMatch, uint_8 Copy_CompMode, void (*Copy_pfCTC) (void*), void* Copy_pParameter);

/*********************************************************
 *********************************************************
 ** Function Name:										**
 ** Return Type:										**
 ** Arguments:											**
 ** Functionality:										**
 ** 													**
 *********************************************************
 *********************************************************/
ES_t TIMER1_enuSetWaveMode(uint_8 Copy_uint8WaveMode, uint_16 Copy_uint16TcntTop);

/*********************************************************
 *********************************************************
 ** Function Name:										**
 ** Return Type:										**
 ** Arguments:											**
 ** Functionality:										**
 ** 													**
 *********************************************************
 *********************************************************/
ES_t TIMER1_enuGeneratePWM_OC1A(uint_16 Copy_uint16OCRAValue, uint_8 Copy_uint8CompMode);

/*********************************************************
 *********************************************************
 ** Function Name:										**
 ** Return Type:										**
 ** Arguments:											**
 ** Functionality:										**
 ** 													**
 *********************************************************
 *********************************************************/
ES_t TIMER1_enuGeneratePWM_OC1B(uint_16 Copy_uint16OCRBValue, uint_8 Copy_uint8CompMode);

/*********************************************************
 *********************************************************
 ** Function Name:										**
 ** Return Type:										**
 ** Arguments:											**
 ** Functionality:										**
 ** 													**
 *********************************************************
 *********************************************************/
ES_t TIMER1_enuCTC_OC1A(uint_16 Copy_uint16OCRAValue, uint_8 Copy_uint8CompMode);

/*********************************************************
 *********************************************************
 ** Function Name:										**
 ** Return Type:										**
 ** Arguments:											**
 ** Functionality:										**
 ** 													**
 *********************************************************
 *********************************************************/
ES_t TIMER1_enuCTC_OC1B(uint_16 Copy_uint16OCRBValue, uint_8 Copy_uint8CompMode);

/*********************************************************
 *********************************************************
 ** Function Name:										**
 ** Return Type:										**
 ** Arguments:											**
 ** Functionality:										**
 ** 													**
 *********************************************************
 *********************************************************/
ES_t TIMER1_enuInputCaptureEnable(uint_8 Copy_uint8NoiseCanceller, uint_8 Copy_uint8Edge);

/*********************************************************
 *********************************************************
 ** Function Name:										**
 ** Return Type:										**
 ** Arguments:											**
 ** Functionality:										**
 ** 													**
 *********************************************************
 *********************************************************/
ES_t TIMER1_enuGetInputCapture(uint_16 *Copy_puint16CaptValue);


/*********************************************************
 *********************************************************
 ** Function Name:										**
 ** Return Type:										**
 ** Arguments:											**
 ** Functionality:										**
 ** 													**
 *********************************************************
 *********************************************************/
ES_t TIMER1_enuCallBack(void (*Copy_PfFunctionConfig)(void*), void* Copy_Pparameter, uint_8 Copy_uint8InterruptType);

#endif /* MCAL_TIMER1_TIMER1_INT_H_ */
