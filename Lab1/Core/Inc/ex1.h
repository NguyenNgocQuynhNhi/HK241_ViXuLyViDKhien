/*
 * ex1.h
 *
 *  Created on: Sep 29, 2024
 *      Author: DEll P5530
 */

#ifndef INC_EX1_H_
#define INC_EX1_H_

uint32_t currentTime = 0;
uint32_t previousTime = 0;
uint8_t redOnYellowOff = 0;

void RunExercise1() {
	  currentTime = HAL_GetTick();
	  if (currentTime - previousTime >= 2000) {
		  if (redOnYellowOff == 0) {
			  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET); // turn off the red led
			  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_RESET); // turn on the yellow led
		  }
		  else {
			  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET); // turn on the red led
			  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_SET); //turn off the yellow led
		  }
		  previousTime = currentTime;
		  redOnYellowOff = 1 - redOnYellowOff;
	  }
}


#endif /* INC_EX1_H_ */
