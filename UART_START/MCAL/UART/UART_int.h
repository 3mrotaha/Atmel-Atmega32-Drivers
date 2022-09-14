/*
 * UART_int.h
 *
 *  Created on: Mar 19, 2022
 *      Author: amrmo
 */

#ifndef UART_INT_H_
#define UART_INT_H_

/********************************************************************/
/*	Function Name : UART_enuInit									*/
/*  Parameters    : void											*/
/*  Return Type   :	ErrorState (enum)								*/
/*  Functionality : This Function is Used For the Initialization	*/
/*  				Of the UART peripheral						  	*/
/********************************************************************/
ES_t UART_enuInit(void);

/********************************************************************/
/*   (TRANSMITTER AND RECEIVER ENABLE/DISABLE FUNCTIONS) 	  		*/
/* Use These Functions In Order To Enable Or Disable UART     		*/
/* Transmitter Or Receiver 								   	  		*/
/********************************************************************/
/*																	*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuEnableTransmitter					*   */
/* *  Parameters    : void										*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Enable The UART       *   */
/* *				  Transmitter								*	*/
/* **************************************************************   */
/**/ ES_t UART_enuEnableTransmitter(void); 						  /**/
/*															  		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuDisableTransmitter				*   */
/* *  Parameters    : void										*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Disable The UART      *   */
/* *				  Transmitter								*	*/
/* **************************************************************   */
/**/ ES_t UART_enuDisableTransmitter(void);						  /**/
/*  														  		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuEnableReceiver					*   */
/* *  Parameters    : void										*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Enable The UART       *   */
/* *				  Receiver									*	*/
/* **************************************************************   */
/**/ ES_t UART_enuEnableReceiver(void);    						  /**/
/*                                                            		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuDisableReceiver					*   */
/* *  Parameters    : void										*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Disable The UART      *   */
/* *				  Receiver									*	*/
/* **************************************************************   */
/**/ ES_t UART_enuDisableReceiver(void);   						  /**/
/********************************************************************/



/********************************************************************/
/*	 		(DATA TRANSMITION AND RECEIVE)					  		*/
/* Use These Functions In Order To Send Or Receive Data       		*/
/* to/from A Device i.e Bluetooth Device					  		*/
/* these data can be characters, string or number             		*/
/********************************************************************/
/* **************************************************************  	*/
/* *  Function Name : UART_enuTransmitChar						*   */
/* *  Parameters    : Copy_uint8Data(unsigned Character)   		*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Send a Character in   *   */
/* *				  5-bit to 8-bit Data Buffer From the MCU	*	*/
/* *				  to a deviece i.e Bluetooth device		  	*	*/
/* **************************************************************   */
/**/ ES_t UART_enuTransmitChar(uint_8 Copy_uint8Data);			  /**/
/*															  		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuReceiveChar						*   */
/* *  Parameters    : Copy_uint8Data                            *   */
/* * 				  (pointer to unsigned Character)   		*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Receive a Character   *   */
/* *				  in 5-bit to 8-bit Data Buffer From a	 	*	*/
/* *				  deviece i.e Bluetooth device to the MCU 	*	*/
/* **************************************************************   */
/**/  ES_t UART_enuReceiveChar(uint_8 *Copy_uint8Data);			  /**/
/*  														  		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuTransmitString					*   */
/* *  Parameters    : Copy_uint8Data                            *   */
/* * 				  (pointer to unsigned Character)   		*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Send a String in      *   */
/* *				  5-bit to 8-bit Data Buffer From the MCU	*	*/
/* *				  to a deviece i.e Bluetooth device 	 	*	*/
/* **************************************************************   */
/**/ ES_t UART_enuTransmitString(uint_8 *Copy_uint8Data);   	  /**/
/*                                                            		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuReceiveString						*   */
/* *  Parameters    : Copy_uint8Data                            *   */
/* * 				  (pointer to unsigned Character)   		*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Receive a String      *   */
/* *				  in 5-bit to 8-bit Data Buffer From the 	*	*/
/* *				  a deviece i.e Bluetooth device to MCU 	*	*/
/* **************************************************************   */
/**/ ES_t UART_enuReceiveString(uint_8 *Copy_uint8Data);   		  /**/
/*															  		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuReceiveNumber						*   */
/* *  Parameters    : Copy_f32Number (pointer to float)			*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Receive a Number      *   */
/* *				  in 5-bit to 8-bit Data Buffer From 	 	*	*/
/* *				  a deviece i.e Bluetooth device to MCU 	*	*/
/* **************************************************************   */
/**/  ES_t UART_enuReceiveNumber(f32 *Copy_f32Number);			  /**/
/*															  		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuTransmitNumber					*   */
/* *  Parameters    : Copy_f32Number (float)			   		*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Receive a Number      *   */
/* *				  in 5-bit to 8-bit Data Buffer From the 	*	*/
/* *				  MCU to a device i.e. (Bluetooth Device) 	*	*/
/* **************************************************************   */
/**/  ES_t UART_enuTransmitNumber(f32 Copy_f32Number);			  /**/
/********************************************************************/


/********************************************************************/
/*				(UART ChARACTERESTICS)						  		*/
/* Use These Functions In Order To Change the Baud Rate       		*/
/* Value, Reset the Character Size 						 	  		*/
/********************************************************************/
/* **************************************************************  	*/
/* *  Function Name : UART_enuSetBaudRate						*   */
/* *  Parameters    : Copy_uint8Value (unsigned short int)		*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Reset the UART Baud   *   */
/* *				  Rate Value to another Value              	*	*/
/* **************************************************************   */
/**/ ES_t UART_enuSetBaudRate(uint_16 Copy_uint8Value);			  /**/
/*															  		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuResetCharacterSize				*   */
/* *  Parameters    : Copy_uint8Value (unsigned character)		*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Reset the UART   	 	*   */
/* *				  Character Size 5-, 6-, 7-, 8- or 9-bit    *	*/
/* **************************************************************   */
/**/ ES_t UART_enuResetCharacterSize(uint_8 Copy_uint8Value);	  /**/
/********************************************************************/


/********************************************************************/
/*				(MULTI-PROCESSOR MODE)						  		*/
/*  In Multi Processor Mode Use Only These Functions          		*/
/********************************************************************/
/* **************************************************************	*/
/* * 												      		*	*/
/* * 												      		*	*/
/* **************************************************************	*/
/**/ ES_t UART_enuEnableMultiProcessorMode(void);				  /**/
/*															  		*/
/* **************************************************************	*/
/* * 												      		*	*/
/* * 												      		*	*/
/* **************************************************************	*/
/**/  ES_t UART_enuDisableMultiProcessorMode(void);				  /**/
/*  														  		*/
/* **************************************************************	*/
/* * 												      		* 	*/
/* * 												      		*	*/
/* **************************************************************	*/
/**/ ES_t UART_enuSendMCUAddress(const uint_8 *Copy_puintAddress);/**/
/*  														  		*/
/* **************************************************************	*/
/* * 												      		*	*/
/* * 												      		*	*/
/* **************************************************************	*/
/**/ ES_t UART_enuGetMCUAddress(uint_8 *Copy_puintAddress);		  /**/
/*                                                            		*/
/* **************************************************************	*/
/* * 												      		*	*/
/* * 												      		*	*/
/* **************************************************************	*/
/*																	*/
/**/ ES_t UART_enuCheckAddress(const uint_8 *Copy_puintAddress);  /**/
/* **************************************************************	*/
/* * 												      		*	*/
/* * 												      		*	*/
/* **************************************************************	*/
/**/ ES_t UART_enuSendDataToMCU(const uint_8 *Copy_puint8Data);   /**/
/*															  		*/
/* **************************************************************	*/
/* * 												      		*	*/
/* * 												      		*	*/
/* **************************************************************	*/
/**/ ES_t UART_enuGetDataFromMaster(uint_8 *Copy_puint8Data);	  /**/
/*															  		*/
/* **************************************************************	*/
/* * 												      		*	*/
/* * 												      		*	*/
/* **************************************************************	*/
/**/ ES_t UART_enuToSendAddress(void);							  /**/
/*															  		*/
/* **************************************************************	*/
/* * 												      		*	*/
/* * 												      		*	*/
/* **************************************************************	*/
/**/ ES_t UART_enuToSendData(void);								  /**/
/*															  		*/
/********************************************************************/


/********************************************************************/
/*					(UART INTERRUPTS)						  		*/
/*  Use These Functions In Order To Enable Or Disable UART    		*/
/*  Interrupts (RXC, TXC, UDRE)					  	          		*/
/********************************************************************/
/* **************************************************************  	*/
/* *  Function Name : UART_enuEnableRXCInterrupt				*   */
/* *  Parameters    : void										*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Enable the UART   	*   */
/* *				  Interrupt On the Receive Complete 	  	*	*/
/* **************************************************************   */
/**/ ES_t UART_enuEnableRXCInterrupt(void);						  /**/
/*															  		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuDisableRXCInterrupt				*   */
/* *  Parameters    : void										*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Disable the UART   	*   */
/* *				  Interrupt On the Receive Complete 	  	*	*/
/* **************************************************************   */
/**/  ES_t UART_enuDisableRXCInterrupt(void);					  /**/
/*  														  		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuEnableTXCInterrupt				*   */
/* *  Parameters    : void										*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Enable the UART   	*   */
/* *				  Interrupt On the Transmition Complete 	*	*/
/* **************************************************************   */
/**/ ES_t UART_enuEnableTXCInterrupt(void);						  /**/
/*                                                            		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuDisableTXCInterrupt				*   */
/* *  Parameters    : void										*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Disable the UART   	*   */
/* *				  Interrupt On the Transmition Complete 	*	*/
/* **************************************************************   */
/**/ ES_t UART_enuDisableTXCInterrupt(void);			    	  /**/
/*                                                            		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuEnableUDREInterrupt				*   */
/* *  Parameters    : void										*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Enable the UART   	*   */
/* *				  Interrupt On the Empty of Data Buffer 	*	*/
/* **************************************************************   */
/**/ ES_t UART_enuEnableUDREInterrupt(void);					  /**/
/*                                                            		*/
/* **************************************************************  	*/
/* *  Function Name : UART_enuDisbleUDREInterrupt				*   */
/* *  Parameters    : void										*   */
/* *  Return Type   : ErrorState (enum)							*	*/
/* *  Functionality : Use This Funtion To Disable the UART   	*   */
/* *				  Interrupt On the Empty of Data Buffer 	*	*/
/* **************************************************************   */
/**/ ES_t UART_enuDisbleUDREInterrupt(void);					  /**/
/*                                                            		*/
/********************************************************************/


/********************************************************************/
/*	Function Name : UART_enuCallBack								*/
/*  Parameters    : - Copy_pFuncConfig(Pointer to function with 	*/
/* 						poitner to void Parameter)					*/
/* 					- Copy_pParameter(pointer to void)				*/
/* 					- Copy_Interrupt_Type(unsigned Character)		*/
/*  Return Type   :	ErrorState (enum)								*/
/*  Functionality : Use This Function To Call Back Another Function */
/*					to Execute it on the Interrupt detected 		*/
/********************************************************************/
ES_t UART_enuCallBack(void (*Copy_pFuncConfig)(void*), void* Copy_pParameter, uint_8 Copy_Interrupt_Type);


#endif /* UART_INT_H_ */
