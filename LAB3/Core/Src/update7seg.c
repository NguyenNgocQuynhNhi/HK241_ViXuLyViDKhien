/*
 * update7seg.c
 *
 *  Created on: Nov 19, 2024
 *      Author: DEll P5530
 */

#include "update7seg.h"
#include "led7segments.h"

const int MAX_LED = 4;
int ledIndex = 0;
int led_buffer[4] = {0, 0, 0, 0};

void updateClockBuffer(int vertical_counter, int horizontal_counter)
{

		led_buffer[0] = vertical_counter / 10;
		led_buffer[1] = vertical_counter % 10;

		led_buffer[2] = horizontal_counter / 10;
		led_buffer[3] = horizontal_counter % 10;

}

void update7seg(int index)
{
	switch (index) {
		case 0:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);	//turn on the first 7-segment led
			HAL_GPIO_WritePin(GPIOA, EN2_Pin | EN3_Pin | EN4_Pin, GPIO_PIN_SET); 	//turn off the other 3 leds

			display7SEG(led_buffer[index]);
			break;
		case 1:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);	//turn on the second 7-segment led
			HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN3_Pin | EN4_Pin, GPIO_PIN_SET);	//turn off the other 3 leds

			display7SEG(led_buffer[index]);
			break;
		case 2:
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);	//turn on the third 7-segment led
			HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN4_Pin, GPIO_PIN_SET);	//turn off the other 3 leds

			display7SEG(led_buffer[index]);
			break;
		case 3:
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);	//turn on the fourth 7-segment led
			HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin , GPIO_PIN_SET);	//turn off the other 3 leds

			display7SEG(led_buffer[index]);
			break;
		default:
			break;
	}

}
