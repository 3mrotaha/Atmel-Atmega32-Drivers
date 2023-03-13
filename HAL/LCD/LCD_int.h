/*
 * LCD_int.h
 *
 *  Created on: Feb 23, 2022
 *      Author: amrmo
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ErrorStates_t LCD_enuInit(void);

ErrorStates_t LCD_enuSendCommand(uint8 Copy_uint8Command);

ErrorStates_t LCD_enuDisplayChar(uint8 Copy_uint8Data);

ErrorStates_t LCD_enuDisplayString(uint8* Copy_uint8Data);

ErrorStates_t LCD_enuDisplayInteger(sint64 Copy_uint32Data);

ErrorStates_t LCD_enuDisplayFloat(f64_t Copy_f64_tData);

#endif /* LCD_INT_H_ */
