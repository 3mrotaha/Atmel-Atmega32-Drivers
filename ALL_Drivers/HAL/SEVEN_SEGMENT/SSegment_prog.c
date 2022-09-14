/*
 * SSegment_prog.c
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "SSegment_config.h"
#include "SSegment_priv.h"

u8 SSegment_Au8Nums[NUM_TO_DISPLAY] ={
 	 	 	0x3f,
		0x06,
		0x5B,
		0x4F,
		0x66,
		0x6D,
		0x7D,
		0x07,
		0x7F,
		0x6F
};

extern SEG_t SSegment_Astr7SegConfig[NUM_SEV_SEGMENTS];
ES_t SSegment_enuInit(SEG_t *Copy_pstrSegConfig){
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrSegConfig != NULL){
		u8 Local_enuIterator;
		for(Local_enuIterator = 0; Local_enuIterator < NUM_SEV_SEGMENTS; Local_enuIterator++){

			DIO_enuSetPinDir(Copy_pstrSegConfig[Local_enuIterator].SegA_Port, Copy_pstrSegConfig[Local_enuIterator].SegA_Pin, DIO_u8OUTPUT);
			DIO_enuSetPinDir(Copy_pstrSegConfig[Local_enuIterator].SegB_Port, Copy_pstrSegConfig[Local_enuIterator].SegB_Pin, DIO_u8OUTPUT);
			DIO_enuSetPinDir(Copy_pstrSegConfig[Local_enuIterator].SegC_Port, Copy_pstrSegConfig[Local_enuIterator].SegC_Pin, DIO_u8OUTPUT);
			DIO_enuSetPinDir(Copy_pstrSegConfig[Local_enuIterator].SegD_Port, Copy_pstrSegConfig[Local_enuIterator].SegD_Pin, DIO_u8OUTPUT);
			DIO_enuSetPinDir(Copy_pstrSegConfig[Local_enuIterator].SegE_Port, Copy_pstrSegConfig[Local_enuIterator].SegE_Pin, DIO_u8OUTPUT);
			DIO_enuSetPinDir(Copy_pstrSegConfig[Local_enuIterator].SegF_Port, Copy_pstrSegConfig[Local_enuIterator].SegF_Pin, DIO_u8OUTPUT);
			DIO_enuSetPinDir(Copy_pstrSegConfig[Local_enuIterator].SegG_Port, Copy_pstrSegConfig[Local_enuIterator].SegG_Pin, DIO_u8OUTPUT);
			DIO_enuSetPinDir(Copy_pstrSegConfig[Local_enuIterator].Cmn_Port,  Copy_pstrSegConfig[Local_enuIterator].Cmn_Pin,  DIO_u8OUTPUT);
			if(Copy_pstrSegConfig[Local_enuIterator].Dot_Port != NOT_CONNECTED && Copy_pstrSegConfig[Local_enuIterator].Dot_Pin != NOT_CONNECTED){
				DIO_enuSetPinDir(Copy_pstrSegConfig[Local_enuIterator].Dot_Port, Copy_pstrSegConfig[Local_enuIterator].Dot_Pin, DIO_u8OUTPUT);
			}
		}

		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

ES_t SSegment_enuDisplayNum(u8 Copy_u8Num, u8 Copy_u8SegID){
	ES_t Local_enuErrorState = ES_NOK;

		if(Copy_u8SegID <= NUM_SEV_SEGMENTS){
			if(SSegment_Astr7SegConfig[Copy_u8SegID].Seg_Type == COMMON_CATHODE){

				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegA_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegA_Pin, ((SSegment_Au8Nums[Copy_u8Num] >> 0) & BIT_MASK));
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegB_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegB_Pin, ((SSegment_Au8Nums[Copy_u8Num] >> 1) & BIT_MASK));
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegC_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegC_Pin, ((SSegment_Au8Nums[Copy_u8Num] >> 2) & BIT_MASK));
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegD_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegD_Pin, ((SSegment_Au8Nums[Copy_u8Num] >> 3) & BIT_MASK));
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegE_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegE_Pin, ((SSegment_Au8Nums[Copy_u8Num] >> 4) & BIT_MASK));
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegF_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegF_Pin, ((SSegment_Au8Nums[Copy_u8Num] >> 5) & BIT_MASK));
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegG_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegG_Pin, ((SSegment_Au8Nums[Copy_u8Num] >> 6) & BIT_MASK));

			}
			else if(SSegment_Astr7SegConfig[Copy_u8SegID].Seg_Type == COMMON_ANODE){

				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegA_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegA_Pin, ~((SSegment_Au8Nums[Copy_u8Num] >> 0) & BIT_MASK));
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegB_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegB_Pin, ~((SSegment_Au8Nums[Copy_u8Num] >> 1) & BIT_MASK));
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegC_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegC_Pin, ~((SSegment_Au8Nums[Copy_u8Num] >> 2) & BIT_MASK));
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegD_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegD_Pin, ~((SSegment_Au8Nums[Copy_u8Num] >> 3) & BIT_MASK));
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegE_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegE_Pin, ~((SSegment_Au8Nums[Copy_u8Num] >> 4) & BIT_MASK));
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegF_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegF_Pin, ~((SSegment_Au8Nums[Copy_u8Num] >> 5) & BIT_MASK));
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegG_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegG_Pin, ~((SSegment_Au8Nums[Copy_u8Num] >> 6) & BIT_MASK));

			}
			Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
		}

	return Local_enuErrorState;
}

ES_t SSegment_enuEnableCMN(u8 Copy_u8SegID){
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8SegID < NUM_SEV_SEGMENTS){
		if(SSegment_Astr7SegConfig[Copy_u8SegID].Cmn_Port != NOT_CONNECTED && SSegment_Astr7SegConfig[Copy_u8SegID].Cmn_Pin != NOT_CONNECTED){
			if(SSegment_Astr7SegConfig[Copy_u8SegID].Seg_Type == COMMON_CATHODE){
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].Cmn_Port, SSegment_Astr7SegConfig[Copy_u8SegID].Cmn_Pin, DIO_u8LOW);

			}
			else if(SSegment_Astr7SegConfig[Copy_u8SegID].Seg_Type == COMMON_ANODE){
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].Cmn_Port, SSegment_Astr7SegConfig[Copy_u8SegID].Cmn_Pin, DIO_u8HIGH);
			}
			Local_enuErrorState = ES_OK;
		}
	}
	else{
		Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}


ES_t SSegment_enuDisableCMN( u8 Copy_u8SegID){
	ES_t Local_enuErrorState = ES_NOK;

		if(Copy_u8SegID <= NUM_SEV_SEGMENTS){
			if(SSegment_Astr7SegConfig[Copy_u8SegID].Cmn_Port != NOT_CONNECTED && SSegment_Astr7SegConfig[Copy_u8SegID].Cmn_Pin != NOT_CONNECTED){
				if(SSegment_Astr7SegConfig[Copy_u8SegID].Seg_Type == COMMON_CATHODE){
					DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].Cmn_Port, SSegment_Astr7SegConfig[Copy_u8SegID].Cmn_Pin, DIO_u8HIGH);

				}
				else if(SSegment_Astr7SegConfig[Copy_u8SegID].Seg_Type == COMMON_ANODE){
					DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].Cmn_Port, SSegment_Astr7SegConfig[Copy_u8SegID].Cmn_Pin, DIO_u8LOW);
				}
				Local_enuErrorState = ES_OK;
			}
		}
		else{
			Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
		}

	return Local_enuErrorState;
}

ES_t SSegment_enuEnableDot(u8 Copy_u8SegID){
	ES_t Local_enuErrorState = ES_NOK;


			if(Copy_u8SegID <= NUM_SEV_SEGMENTS){
				if(SSegment_Astr7SegConfig[Copy_u8SegID].Seg_Type == COMMON_CATHODE){
					DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].Dot_Port, SSegment_Astr7SegConfig[Copy_u8SegID].Dot_Pin, DIO_u8HIGH);
				}
				else if(SSegment_Astr7SegConfig[Copy_u8SegID].Seg_Type == COMMON_ANODE){
					DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].Dot_Port, SSegment_Astr7SegConfig[Copy_u8SegID].Dot_Pin, DIO_u8LOW);
				}
				Local_enuErrorState = ES_OK;
			}
			else{
				Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
			}

	return Local_enuErrorState;
}

ES_t SSegment_enuDisableDot(u8 Copy_u8SegID){
	ES_t Local_enuErrorState = ES_NOK;


			if(Copy_u8SegID <= NUM_SEV_SEGMENTS){
				if(SSegment_Astr7SegConfig[Copy_u8SegID].Seg_Type == COMMON_CATHODE){
					DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].Dot_Port, SSegment_Astr7SegConfig[Copy_u8SegID].Dot_Pin, DIO_u8LOW);
				}
				else if(SSegment_Astr7SegConfig[Copy_u8SegID].Seg_Type == COMMON_ANODE){
					DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].Dot_Port, SSegment_Astr7SegConfig[Copy_u8SegID].Dot_Pin, DIO_u8HIGH);
				}
				Local_enuErrorState = ES_OK;
			}
			else{
				Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
			}

	return Local_enuErrorState;

}

ES_t SSegment_enuClearDislay(u8 Copy_u8SegID){
	ES_t Local_enuErrorState = ES_NOK;

		if(Copy_u8SegID <= NUM_SEV_SEGMENTS){
			if(SSegment_Astr7SegConfig[Copy_u8SegID].Seg_Type == COMMON_CATHODE){
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegA_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegA_Pin, DIO_u8LOW);
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegB_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegB_Pin, DIO_u8LOW);
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegC_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegC_Pin, DIO_u8LOW);
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegD_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegD_Pin, DIO_u8LOW);
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegE_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegE_Pin, DIO_u8LOW);
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegF_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegF_Pin, DIO_u8LOW);
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegG_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegG_Pin, DIO_u8LOW);
			}
			else if(SSegment_Astr7SegConfig[Copy_u8SegID].Seg_Type == COMMON_ANODE){
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegA_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegA_Pin, DIO_u8HIGH);
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegB_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegB_Pin, DIO_u8HIGH);
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegC_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegC_Pin, DIO_u8HIGH);
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegD_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegD_Pin, DIO_u8HIGH);
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegE_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegE_Pin, DIO_u8HIGH);
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegF_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegF_Pin, DIO_u8HIGH);
				DIO_enuSetPinValue(SSegment_Astr7SegConfig[Copy_u8SegID].SegG_Port, SSegment_Astr7SegConfig[Copy_u8SegID].SegG_Pin, DIO_u8HIGH);
			}
			Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
		}

	return Local_enuErrorState;
}
