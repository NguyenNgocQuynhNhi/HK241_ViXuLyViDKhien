/*
 * update7seg.c
 *
 *  Created on: Oct 15, 2024
 *      Author: DEll P5530
 */

#include "update7seg.h"
//#include "7segmentsLed.h"

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 8, 0, 5};


void update7SEG(int index) {
	  switch (index) {
	  	  case 0:
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);	//turn on the first 7-segment led
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);		//turn off the second 7-segment led
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);		//turn off the third 7-segment led
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);		//turn off the fourth 7-segment led

			  //display1();
			  display7SEG(led_buffer[index]);
//			  index = 1;
			  break;
	  	  case 1:
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);		//turn off the first 7-segment led
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);	//turn on the second 7-segment led
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);		//turn off the third 7-segment led
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);		//turn off the fourth 7-segment led

			  //display2();
			  display7SEG(led_buffer[index]);
//			  index = 2;
			  break;
	  	  case 2:
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);		//turn off the first 7-segment led
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);		//turn off the second 7-segment led
			  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);	//turn on the third 7-segment led
			  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);		//turn off the fourth 7-segment led

			  //display3();
			  display7SEG(led_buffer[index]);
//			  index = 3;
	  		  break;
	  	  case 3:
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);	//turn off the first 7-segment led
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);	//turn off the second 7-segment led
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);	//turn off the third 7-segment led
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);	//turn on the fourth 7-segment led

				//display0();
				display7SEG(led_buffer[index]);
//				index = 0;
	  		  break;
	  	  default:
//	  		  index = 0;
//	  		  if (index >= MAX_LED) {
//	  			  index = 0;
//	  		  }
	  		  break;

	  }
}

void updateClockBuffer(int hour, int minute) {
	if (hour < 10) {
		led_buffer[0] = 0;
		led_buffer[1] = hour;
	}
	else {
		led_buffer[0] = hour / 10;
		led_buffer[1] = hour % 10;
	}

	if (minute < 10) {
		led_buffer[3] = minute;
		led_buffer[2] = 0;
	}
	else {
		led_buffer[2] = minute / 10;
		led_buffer[3] = minute % 10;
	}
}
