/*
 * displayLCD.h
 *
 *  Created on: Dec 6, 2024
 *      Author: DEll P5530
 */

#ifndef INC_DISPLAYLCD_H_
#define INC_DISPLAYLCD_H_


#include "i2c-lcd.h"


extern int led_buffer[4];
void updateClockBuffer(int vertical_counter, int horizontal_counter);

void lcd_start_auto();
void lcd_auto();
void lcd_start_manual();
void lcd_red_manual();
void lcd_yellow_manual();
void lcd_green_manual();
#endif /* INC_DISPLAYLCD_H_ */
