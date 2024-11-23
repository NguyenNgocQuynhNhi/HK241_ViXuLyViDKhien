/*
 * update7seg.c
 *
 *  Created on: Nov 19, 2024
 *      Author: DEll P5530
 */

#include "update7seg.h"

int ledIndex = 0;
int led_buffer[4] = {0, 0, 0,0 };

void updateClockBuffer(int vertical_counter, int horizontal_counter){
		led_buffer[0] = vertical_counter / 10;
		led_buffer[1] = vertical_counter % 10;
		led_buffer[2] = horizontal_counter / 10;
		led_buffer[3] = horizontal_counter % 10;
}
void update7seg()
{
//	turnOff7SEG();
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
	HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, 1);
	switch (ledIndex) {

		case 0:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);	//turn on the first 7-segment led
			display7SEG(led_buffer[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);	//turn on the second 7-segment led
			display7SEG(led_buffer[1]);
			break;
		case 2:
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);	//turn on the third 7-segment led
			display7SEG(led_buffer[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);	//turn on the fourth 7-segment led
			display7SEG(led_buffer[3]);
			break;
		default:
			HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 1);
			break;
	}
	if((++ledIndex) >= 4) ledIndex = 0;

}
