/*
 * SevenSeg_prog.c
 *
 *  Created on: Feb 22, 2022
 *      Author: amrmo
 */

#include "std_types.h"
#include "Error_States.h"

#include "DIO_priv.h"
#include "DIO_int.h"

#include "SevenSeg_config.h"
#include "SevenSeg_priv.h"

extern uint_8 seg[10];
ES_t SEG_enuInit(void){
	ES_t Local_enuErrorStates = ES_NOK;

#if SEG_COMMON == SEG_uint8COM_CATHOD

	Local_enuErrorStates = DIO_enuSetPinDir(A_PORT, A_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(B_PORT, B_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(C_PORT, C_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(D_PORT, D_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(E_PORT, E_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(F_PORT, F_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(G_PORT, G_PIN, OUTPUT);

	Local_enuErrorStates = DIO_enuSetPinValue(A_PORT, A_PIN, LOW);
	Local_enuErrorStates = DIO_enuSetPinValue(B_PORT, B_PIN, LOW);
	Local_enuErrorStates = DIO_enuSetPinValue(C_PORT, C_PIN, LOW);
	Local_enuErrorStates = DIO_enuSetPinValue(D_PORT, D_PIN, LOW);
	Local_enuErrorStates = DIO_enuSetPinValue(E_PORT, E_PIN, LOW);
	Local_enuErrorStates = DIO_enuSetPinValue(F_PORT, F_PIN, LOW);
	Local_enuErrorStates = DIO_enuSetPinValue(G_PORT, G_PIN, LOW);

#if	 SEG_COMMON_CONNECTION == SEG_uint8CONNECTED
	Local_enuErrorStates = DIO_enuSetPinDir(COMMON_PORT, COMMON_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinValue(COMMON_PORT, COMMON_PIN, LOW);
#endif

#if SEG_DOT == SEG_uint8CONNECTED
	Local_enuErrorStates = DIO_enuSetPinDir(DOT_PORT, DOT_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinValue(DOT_PORT, DOT_PIN, LOW);
#endif


#elif SEG_COMMON == SEG_uint8COM_ANODE

	Local_enuErrorStates = DIO_enuSetPinDir(A_PORT, A_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(B_PORT, B_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(C_PORT, C_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(D_PORT, D_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(E_PORT, E_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(F_PORT, F_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinDir(G_PORT, G_PIN, OUTPUT);

	Local_enuErrorStates = DIO_enuSetPinValue(A_PORT, A_PIN, HIGH);
	Local_enuErrorStates = DIO_enuSetPinValue(B_PORT, B_PIN, HIGH);
	Local_enuErrorStates = DIO_enuSetPinValue(C_PORT, C_PIN, HIGH);
	Local_enuErrorStates = DIO_enuSetPinValue(D_PORT, D_PIN, HIGH);
	Local_enuErrorStates = DIO_enuSetPinValue(E_PORT, E_PIN, HIGH);
	Local_enuErrorStates = DIO_enuSetPinValue(F_PORT, F_PIN, HIGH);
	Local_enuErrorStates = DIO_enuSetPinValue(G_PORT, G_PIN, HIGH);

#if	 SEG_COMMON_CONNECTION == SEG_uint8CONNECTED
	Local_enuErrorStates = DIO_enuSetPinDir(COMMON_PORT, COMMON_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinValue(COMMON_PORT, COMMON_PIN, HIGH);
#endif

#if SEG_DOT == SEG_uint8CONNECTED
	Local_enuErrorStates = DIO_enuSetPinDir(DOT_PORT, DOT_PIN, OUTPUT);
	Local_enuErrorStates = DIO_enuSetPinValue(DOT_PORT, DOT_PIN, HIGH);
#endif

#endif



	return Local_enuErrorStates;
}

ES_t SEG_enuEnableCommon(void){
	ES_t Local_enuErrorStates = ES_NOK;
#if SEG_COMMON == SEG_uint8COM_CATHOD
	Local_enuErrorStates = DIO_enuSetPinValue(COMMON_PORT, COMMON_PIN, LOW);
#elif SEG_COMMON == SEG_uint8COM_ANODE
	Local_enuErrorStates = DIO_enuSetPinValue(COMMON_PORT, COMMON_PIN, HIGH);
#endif
	return Local_enuErrorStates;
}

ES_t SEG_enuDisableCommon(void){
	ES_t Local_enuErrorStates = ES_NOK;
#if SEG_COMMON == SEG_uint8COM_CATHOD
	Local_enuErrorStates = DIO_enuSetPinValue(COMMON_PORT, COMMON_PIN, HIGH);
#elif SEG_COMMON == SEG_uint8COM_ANODE
	Local_enuErrorStates = DIO_enuSetPinValue(COMMON_PORT, COMMON_PIN, LOW);
#endif
	return Local_enuErrorStates;
}

ES_t SEG_enuEnableDot(void){
	ES_t Local_enuErrorStates = ES_NOK;
#if SEG_DOT == SEG_uint8CONNECTED
#if SEG_COMMON == SEG_uint8COM_CATHOD
	Local_enuErrorStates = DIO_enuSetPinValue(DOT_PORT, DOT_PIN, HIGH);
#elif SEG_COMMON == SEG_uint8COM_ANODE
	Local_enuErrorStates = DIO_enuSetPinValue(DOT_PORT, DOT_PIN, LOW);
#endif
#endif
	return Local_enuErrorStates;
}

ES_t SEG_enuDisableDot(void){
	ES_t Local_enuErrorStates = ES_NOK;
#if SEG_DOT == SEG_uint8CONNECTED
#if SEG_COMMON == SEG_uint8COM_CATHOD
	Local_enuErrorStates = DIO_enuSetPinValue(DOT_PORT, DOT_PIN, LOW);
#elif SEG_COMMON == SEG_uint8COM_ANODE
	Local_enuErrorStates = DIO_enuSetPinValue(DOT_PORT, DOT_PIN, HIGH);
#endif
#endif
	return Local_enuErrorStates;
}

ES_t SEG_enuDisplay(uint_8 Copy_uint8Number){
	ES_t Local_enuErrorStates = ES_NOK;
#if SEG_COMMON == SEG_uint8COM_CATHOD
	Local_enuErrorStates = DIO_enuSetPinValue(A_PORT, A_PIN, BIT_MASK & (seg[Copy_uint8Number] >> 0));
	Local_enuErrorStates = DIO_enuSetPinValue(B_PORT, B_PIN, BIT_MASK & (seg[Copy_uint8Number] >> 1));
	Local_enuErrorStates = DIO_enuSetPinValue(C_PORT, C_PIN, BIT_MASK & (seg[Copy_uint8Number] >> 2));
	Local_enuErrorStates = DIO_enuSetPinValue(D_PORT, D_PIN, BIT_MASK & (seg[Copy_uint8Number] >> 3));
	Local_enuErrorStates = DIO_enuSetPinValue(E_PORT, E_PIN, BIT_MASK & (seg[Copy_uint8Number] >> 4));
	Local_enuErrorStates = DIO_enuSetPinValue(F_PORT, F_PIN, BIT_MASK & (seg[Copy_uint8Number] >> 5));
	Local_enuErrorStates = DIO_enuSetPinValue(G_PORT, G_PIN, BIT_MASK & (seg[Copy_uint8Number] >> 6));
#elif SEG_COMMON == SEG_uint8COM_ANODE
	Local_enuErrorStates = DIO_enuSetPinValue(A_PORT, A_PIN, BIT_MASK & ~(seg[Copy_uint8Number] >> 0));
	Local_enuErrorStates = DIO_enuSetPinValue(B_PORT, B_PIN, BIT_MASK & ~(seg[Copy_uint8Number] >> 1));
	Local_enuErrorStates = DIO_enuSetPinValue(C_PORT, C_PIN, BIT_MASK & ~(seg[Copy_uint8Number] >> 2));
	Local_enuErrorStates = DIO_enuSetPinValue(D_PORT, D_PIN, BIT_MASK & ~(seg[Copy_uint8Number] >> 3));
	Local_enuErrorStates = DIO_enuSetPinValue(E_PORT, E_PIN, BIT_MASK & ~(seg[Copy_uint8Number] >> 4));
	Local_enuErrorStates = DIO_enuSetPinValue(F_PORT, F_PIN, BIT_MASK & ~(seg[Copy_uint8Number] >> 5));
	Local_enuErrorStates = DIO_enuSetPinValue(G_PORT, G_PIN, BIT_MASK & ~(seg[Copy_uint8Number] >> 6));
#endif
	return Local_enuErrorStates;
}


