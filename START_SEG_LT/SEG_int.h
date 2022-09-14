/*
 * SEG_int.h
 *
 *  Created on: Feb 22, 2022
 *      Author: amrmo
 */

#ifndef SEG_INT_H_
#define SEG_INT_H_

ES_t SEG_enuInit(SEG_t* Copy_pstrSevenSeg);

ES_t SEG_enuEnableCommon(SEG_t* Copy_pstrSevenSeg);

ES_t SEG_enuDisableCommon(SEG_t* Copy_pstrSevenSeg);

ES_t SEG_enuEnableDot(SEG_t* Copy_pstrSevenSeg);

ES_t SEG_enuDisableDot(SEG_t* Copy_pstrSevenSeg);

ES_t SEG_enuDisplayNum(SEG_t* Copy_pstrSevenSeg, uint_8 Copy_uint8Number);


#endif /* SEG_INT_H_ */
