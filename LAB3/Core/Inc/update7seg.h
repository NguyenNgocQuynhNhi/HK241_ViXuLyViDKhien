/*
 * update7seg.h
 *
 *  Created on: Nov 19, 2024
 *      Author: DEll P5530
 */

#ifndef INC_UPDATE7SEG_H_
#define INC_UPDATE7SEG_H_

#include "global.h"

#define	 MAX_LED 4
extern int ledIndex;
extern int led_buffer[4];
void updateClockBuffer(int , int );
void update7seg();


#endif /* INC_UPDATE7SEG_H_ */
