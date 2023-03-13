/*
 * SEG_prog.c
 *
 *  Created on: Feb 22, 2022
 *      Author: amrmo
 */

#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL//DIO/DIO_priv.h"
#include "../../MCAL//DIO/DIO_int.h"

#include "SEG_config.h"
#include "SEG_priv.h"


extern uint8 seg[10];

ErrorStates_t SEG_enuInit(SEG_t* Copy_pstrSevenSeg){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	if(Copy_pstrSevenSeg != NULL){
		uint8 Local_uint8Iterator;
		for(Local_uint8Iterator = 0; Local_uint8Iterator < SEG_NUM; Local_uint8Iterator++){
			if(Copy_pstrSevenSeg[Local_uint8Iterator].Common_Type == COMMON_uint8ANODE){
				Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].A_Port, Copy_pstrSevenSeg[Local_uint8Iterator].A_Pin, OUTPUT);
				Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].B_Port, Copy_pstrSevenSeg[Local_uint8Iterator].B_Pin, OUTPUT);
				Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].C_Port, Copy_pstrSevenSeg[Local_uint8Iterator].C_Pin, OUTPUT);
				Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].D_Port, Copy_pstrSevenSeg[Local_uint8Iterator].D_Pin, OUTPUT);
				Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].E_Port, Copy_pstrSevenSeg[Local_uint8Iterator].E_Pin, OUTPUT);
				Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].F_Port, Copy_pstrSevenSeg[Local_uint8Iterator].F_Pin, OUTPUT);
				Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].G_Port, Copy_pstrSevenSeg[Local_uint8Iterator].G_Pin, OUTPUT);

				if(Copy_pstrSevenSeg[Local_uint8Iterator].Common_Port != SEG_uint8DISCONNECTED && Copy_pstrSevenSeg[Local_uint8Iterator].Common_Pin != SEG_uint8DISCONNECTED){
					Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].Common_Port, Copy_pstrSevenSeg[Local_uint8Iterator].Common_Pin, OUTPUT);
				}

				if(Copy_pstrSevenSeg[Local_uint8Iterator].Dot_Port != SEG_uint8DISCONNECTED && Copy_pstrSevenSeg[Local_uint8Iterator].Dot_Pin != SEG_uint8DISCONNECTED){
					Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].Dot_Port, Copy_pstrSevenSeg[Local_uint8Iterator].Dot_Pin, OUTPUT);;
				}
			}
			else if(Copy_pstrSevenSeg[Local_uint8Iterator].Common_Type == COMMON_uint8CATHOD){
					Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].A_Port, Copy_pstrSevenSeg[Local_uint8Iterator].A_Pin, OUTPUT);
					Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].B_Port, Copy_pstrSevenSeg[Local_uint8Iterator].B_Pin, OUTPUT);
					Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].C_Port, Copy_pstrSevenSeg[Local_uint8Iterator].C_Pin, OUTPUT);
					Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].D_Port, Copy_pstrSevenSeg[Local_uint8Iterator].D_Pin, OUTPUT);
					Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].E_Port, Copy_pstrSevenSeg[Local_uint8Iterator].E_Pin, OUTPUT);
					Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].F_Port, Copy_pstrSevenSeg[Local_uint8Iterator].F_Pin, OUTPUT);
					Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].G_Port, Copy_pstrSevenSeg[Local_uint8Iterator].G_Pin, OUTPUT);

					if(Copy_pstrSevenSeg[Local_uint8Iterator].Common_Port != SEG_uint8DISCONNECTED && Copy_pstrSevenSeg[Local_uint8Iterator].Common_Pin != SEG_uint8DISCONNECTED){
						Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].Common_Port, Copy_pstrSevenSeg[Local_uint8Iterator].Common_Pin, OUTPUT);
					}

					if(Copy_pstrSevenSeg[Local_uint8Iterator].Dot_Port != SEG_uint8DISCONNECTED && Copy_pstrSevenSeg[Local_uint8Iterator].Dot_Pin != SEG_uint8DISCONNECTED){
						Local_enuErrorStates = DIO_enuSetPinDir(Copy_pstrSevenSeg[Local_uint8Iterator].Dot_Port, Copy_pstrSevenSeg[Local_uint8Iterator].Dot_Pin, OUTPUT);
					}
			}
			else{
					Local_enuErrorStates = ES_COMMON_DETECTION_ERROR;
				}
		}

	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}

	return Local_enuErrorStates;
}


ErrorStates_t SEG_enuEnableCommon(SEG_t* Copy_pstrSevenSeg){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_pstrSevenSeg != NULL){
		if(Copy_pstrSevenSeg->Common_Type == COMMON_uint8ANODE){
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->Common_Port, Copy_pstrSevenSeg->Common_Pin, HIGH);
		}
		else if(Copy_pstrSevenSeg->Common_Type == COMMON_uint8CATHOD){
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->Common_Port, Copy_pstrSevenSeg->Common_Pin, LOW);
		}
		else{
			Local_enuErrorStates = ES_COMMON_DETECTION_ERROR;
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}


ErrorStates_t SEG_enuDisableCommon(SEG_t* Copy_pstrSevenSeg){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_pstrSevenSeg != NULL){
		if(Copy_pstrSevenSeg->Common_Type == COMMON_uint8ANODE){
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->Common_Port, Copy_pstrSevenSeg->Common_Pin, LOW);
		}
		else if(Copy_pstrSevenSeg->Common_Type == COMMON_uint8CATHOD){
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->Common_Port, Copy_pstrSevenSeg->Common_Pin, HIGH);
		}
		else{
			Local_enuErrorStates = ES_COMMON_DETECTION_ERROR;
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}


ErrorStates_t SEG_enuEnableDot(SEG_t* Copy_pstrSevenSeg){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_pstrSevenSeg != NULL){
		if(Copy_pstrSevenSeg->Common_Type == COMMON_uint8ANODE){
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->Dot_Port, Copy_pstrSevenSeg->Dot_Pin, LOW);
		}
		else if(Copy_pstrSevenSeg->Common_Type == COMMON_uint8CATHOD){
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->Dot_Port, Copy_pstrSevenSeg->Dot_Pin, HIGH);
		}
		else{
			Local_enuErrorStates = ES_COMMON_DETECTION_ERROR;
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}


ErrorStates_t SEG_enuDisableDot(SEG_t* Copy_pstrSevenSeg){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_pstrSevenSeg != NULL){
		if(Copy_pstrSevenSeg->Common_Type == COMMON_uint8ANODE){
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->Dot_Port, Copy_pstrSevenSeg->Dot_Pin, HIGH);
		}
		else if(Copy_pstrSevenSeg->Common_Type == COMMON_uint8CATHOD){
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->Dot_Port, Copy_pstrSevenSeg->Dot_Pin, LOW);
		}
		else{
			Local_enuErrorStates = ES_COMMON_DETECTION_ERROR;
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}


ErrorStates_t SEG_enuDisplayNum(SEG_t* Copy_pstrSevenSeg, uint8 Copy_uint8Number){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_pstrSevenSeg != NULL){
		if(Copy_pstrSevenSeg->Common_Type == COMMON_uint8ANODE){
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->A_Port, Copy_pstrSevenSeg->A_Pin, BIT_MASK & ~(seg[Copy_uint8Number] >> 0));
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->B_Port, Copy_pstrSevenSeg->B_Pin, BIT_MASK & ~(seg[Copy_uint8Number] >> 1));
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->C_Port, Copy_pstrSevenSeg->C_Pin, BIT_MASK & ~(seg[Copy_uint8Number] >> 2));
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->D_Port, Copy_pstrSevenSeg->D_Pin, BIT_MASK & ~(seg[Copy_uint8Number] >> 3));
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->E_Port, Copy_pstrSevenSeg->E_Pin, BIT_MASK & ~(seg[Copy_uint8Number] >> 4));
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->F_Port, Copy_pstrSevenSeg->F_Pin, BIT_MASK & ~(seg[Copy_uint8Number] >> 5));
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->G_Port, Copy_pstrSevenSeg->G_Pin, BIT_MASK & ~(seg[Copy_uint8Number] >> 6));
		}
		else if(Copy_pstrSevenSeg->Common_Type == COMMON_uint8CATHOD){
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->A_Port, Copy_pstrSevenSeg->A_Pin, BIT_MASK & (seg[Copy_uint8Number] >> 0));
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->B_Port, Copy_pstrSevenSeg->B_Pin, BIT_MASK & (seg[Copy_uint8Number] >> 1));
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->C_Port, Copy_pstrSevenSeg->C_Pin, BIT_MASK & (seg[Copy_uint8Number] >> 2));
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->D_Port, Copy_pstrSevenSeg->D_Pin, BIT_MASK & (seg[Copy_uint8Number] >> 3));
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->E_Port, Copy_pstrSevenSeg->E_Pin, BIT_MASK & (seg[Copy_uint8Number] >> 4));
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->F_Port, Copy_pstrSevenSeg->F_Pin, BIT_MASK & (seg[Copy_uint8Number] >> 5));
			Local_enuErrorStates = DIO_enuSetPinValue(Copy_pstrSevenSeg->G_Port, Copy_pstrSevenSeg->G_Pin, BIT_MASK & (seg[Copy_uint8Number] >> 6));
		}
		else{
			Local_enuErrorStates = ES_COMMON_DETECTION_ERROR;
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}


