/*
 * update7seg.h
 *
 *  Created on: Nov 19, 2024
 *      Author: DEll P5530
 */

#ifndef INC_UPDATE7SEG_H_
#define INC_UPDATE7SEG_H_


#include "led7segments.h"

extern const int MAX_LED;
extern int ledIndex;

void updateClockBuffer(int vertical_counter, int horizontal_counter);
void update7seg(int index);


#endif /* INC_UPDATE7SEG_H_ */
