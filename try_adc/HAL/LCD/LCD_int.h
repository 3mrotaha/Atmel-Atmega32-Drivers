/*
 * LCD_int.h
 *
 *  Created on: Feb 23, 2022
 *      Author: amrmo
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuSendCommand(uint_8 Copy_uint8Command);

ES_t LCD_enuDisplayChar(uint_8 Copy_uint8Data);

ES_t LCD_enuDisplayString(uint_8* Copy_uint8Data);

ES_t LCD_enuDisplayInteger(sint_64 Copy_uint32Data);

ES_t LCD_enuDisplayFloat(f64 Copy_f64Data);

#endif /* LCD_INT_H_ */
