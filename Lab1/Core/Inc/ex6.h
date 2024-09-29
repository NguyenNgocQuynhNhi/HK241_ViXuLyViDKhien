/*
 * ex6.h
 *
 *  Created on: Sep 29, 2024
 *      Author: DEll P5530
 */

#ifndef INC_EX6_H_
#define INC_EX6_H_

void RunExercise6() {
	  currentTime = HAL_GetTick();
	  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET);
	  if (currentTime - previousTime >= 1000) {
		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET);
	  }
	  if (currentTime - previousTime >= 2000) {
		  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_SET);
	  }
	  if (currentTime - previousTime >= 3000) {
		  HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_SET);
	  }
	  if (currentTime - previousTime >= 4000) {
		  HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_SET);
	  }
	  if (currentTime - previousTime >= 5000) {
		  HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_SET);
	  }
	  if (currentTime - previousTime >= 6000) {
		  HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_SET);
	  }
	  if (currentTime - previousTime >= 7000) {
		  HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_SET);
	  }
	  if (currentTime - previousTime >= 8000) {
		  HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_SET);
	  }
	  if (currentTime - previousTime >= 9000) {
		  HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_SET);
	  }
	  if (currentTime - previousTime >= 10000) {
		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
	  }
	  if (currentTime - previousTime >= 11000) {
		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
	  }
	  if (currentTime - previousTime >= 12000) {
		  HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin | LED_7_Pin | LED_8_Pin | LED_9_Pin | LED_10_Pin | LED_11_Pin | LED_12_Pin, GPIO_PIN_RESET);
		  previousTime = currentTime;
	  }
}

#endif /* INC_EX6_H_ */
