/*
 * ex1.c
 *
 *  Created on: Sep 29, 2024
 *      Author: DEll P5530
 */

//#include "ex1.h"
//
//void RunExercise1() {
//	  currentTime = HAL_GetTick();
//	  if (currentTime - previousTime >= 2000) {
//		  if (redOnYellowOff == 0) {
//			  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET); // turn off the red led
//			  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_RESET); // turn on the yellow led
//		  }
//		  else {
//			  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET); // turn on the red led
//			  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_SET); //turn off the yellow led
//		  }
//		  previousTime = currentTime;
//		  redOnYellowOff = 1 - redOnYellowOff;
//	  }
//}
