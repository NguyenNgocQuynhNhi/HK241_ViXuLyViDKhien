/*
 * update7seg.h
 *
 *  Created on: Oct 15, 2024
 *      Author: DEll P5530
 */

#ifndef INC_UPDATE7SEG_H_
#define INC_UPDATE7SEG_H_

#include "main.h"
#include "7segmentsLed.h"

//const int MAX_LED = 4;
//int index_led = 0;
//int led_buffer[4] = {1, 2, 3, 4};

extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];

void update7SEG(int index);
void updateClockBuffer(int hour, int minute);

#endif /* INC_UPDATE7SEG_H_ */
