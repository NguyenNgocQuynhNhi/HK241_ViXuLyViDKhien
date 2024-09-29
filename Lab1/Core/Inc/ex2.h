/*
 * ex2.h
 *
 *  Created on: Sep 29, 2024
 *      Author: DEll P5530
 */

#ifndef INC_EX2_H_
#define INC_EX2_H_

//uint32_t currentTime = 0;
//uint32_t previousTime = 0;

uint8_t state = 0;

void RunExercise2() {
	  currentTime = HAL_GetTick();
	  if (state == 0) {
		  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET); //	turn on the red led
//		  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port | GREEN_LED_GPIO_Port, YELLOW_LED_Pin | GREEN_LED_Pin, GPIO_PIN_SET); // turn off the yellow led and the green led
		  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_SET); // turn off the yellow led
		  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_SET); // turn off the green led
		  if (currentTime - previousTime >= 5000) {
			  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET); // turn off the red led
			  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_RESET); // turn on the green led
			  state = 1;
			  previousTime = currentTime;
		  }
	  }
	  else if (state == 1) {
		  if (currentTime - previousTime >= 3000) {
			  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_SET); // turn off the green led
			  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_RESET); // turn on the yellow led
			  state = 2;
			  previousTime = currentTime;
		  }
	  }
	  else {
		  if (currentTime - previousTime >= 2000) {
			  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_SET); // turn off the yellow led
			  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET); // turn on the red led
			  state = 0;
			  previousTime = currentTime;
		  }
	  }
}

#endif /* INC_EX2_H_ */
