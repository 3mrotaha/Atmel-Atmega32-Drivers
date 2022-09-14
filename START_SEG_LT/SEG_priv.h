/*
 * SEG_priv.h
 *
 *  Created on: Feb 22, 2022
 *      Author: amrmo
 */

#ifndef SEG_PRIV_H_
#define SEG_PRIV_H_


#define COMMON_uint8ANODE		20
#define COMMON_uint8CATHOD		30
#define SEG_uint8DISCONNECTED	40


uint_8 seg[10] = {//  x g f e  d c b a
	0x3f,	// zero:  x 0 1 1  1 1 1 1   ___a___
	0x06,	// one:   x 0 0 0  0 1 1 0  |       |
	0x5B,	// two:   x 1 0 1  1 0 1 1  f       b
	0x4f,	// three: x 1 0 0  1 1 1 1  |       |
	0x66,	// four:  x 1 1 0  0 1 1 0   ___g___
	0x6d,	// five:  x 1 1 0  1 1 0 1  |       |
	0x7d,	// six:   x 1 1 1  1 1 0 1  e       c
	0x07,	// seven: x 0 0 0  0 1 1 1  |       |
	0x7f,	//eight:  x 1 1 1  1 1 1 1   ___d___
	0x6f	// nine:  x 1 1 0  1 1 1 1
};

#endif /* SEG_PRIV_H_ */
