/*
 * ex8.h
 *
 *  Created on: Sep 29, 2024
 *      Author: DEll P5530
 */

#ifndef INC_EX8_H_
#define INC_EX8_H_

void setNumberOnClock(uint8_t num) {
	if (num == 0) {
		HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin
//							| LED_6_Pin | LED_7_Pin | LED_8_Pin | LED_9_Pin
//							| LED_10_Pin | LED_11_Pin | LED_12_Pin, GPIO_PIN_RESET);
	}
	else if (num == 1) {
		HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_2_Pin | LED_4_Pin | LED_5_Pin
//							| LED_6_Pin | LED_7_Pin | LED_8_Pin | LED_9_Pin
//							| LED_10_Pin | LED_11_Pin | LED_12_Pin, GPIO_PIN_RESET);
	}
	else if (num == 2) {
		HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_5_Pin
//							| LED_6_Pin | LED_7_Pin | LED_8_Pin | LED_9_Pin
//							| LED_10_Pin | LED_11_Pin | LED_12_Pin, GPIO_PIN_RESET);
	}
	else if (num == 3) {
		HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin
//							| LED_6_Pin | LED_7_Pin | LED_8_Pin | LED_9_Pin
//							| LED_10_Pin | LED_11_Pin | LED_12_Pin, GPIO_PIN_RESET);
	}
	else if (num == 4) {
		HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin
//							| LED_5_Pin | LED_7_Pin | LED_8_Pin | LED_9_Pin
//							| LED_10_Pin | LED_11_Pin | LED_12_Pin, GPIO_PIN_RESET);
	}
	else if (num == 5) {
		HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin
//							| LED_5_Pin | LED_6_Pin | LED_8_Pin | LED_9_Pin
//							| LED_10_Pin | LED_11_Pin | LED_12_Pin, GPIO_PIN_RESET);
	}
	else if (num == 6) {
		HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin
//							| LED_5_Pin | LED_6_Pin | LED_7_Pin | LED_9_Pin
//							| LED_10_Pin | LED_11_Pin | LED_12_Pin, GPIO_PIN_RESET);
	}
	else if (num == 7) {
		HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin
//							| LED_5_Pin | LED_6_Pin | LED_7_Pin | LED_8_Pin
//							| LED_10_Pin | LED_11_Pin | LED_12_Pin, GPIO_PIN_RESET);
	}
	else if (num == 8) {
		HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin
//							| LED_5_Pin | LED_6_Pin | LED_7_Pin | LED_8_Pin
//							| LED_9_Pin | LED_11_Pin | LED_12_Pin, GPIO_PIN_RESET);
	}
	else if (num == 9) {
		HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin
//							| LED_5_Pin | LED_6_Pin | LED_7_Pin | LED_8_Pin
//							| LED_9_Pin | LED_10_Pin | LED_12_Pin, GPIO_PIN_RESET);
	}
	else if (num == 10) {
		HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin
//							| LED_5_Pin | LED_6_Pin | LED_7_Pin | LED_8_Pin
//							| LED_9_Pin | LED_10_Pin | LED_11_Pin, GPIO_PIN_RESET);
	}
	else if (num == 11) {
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, LED_12_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin
//							| LED_5_Pin | LED_6_Pin | LED_7_Pin | LED_8_Pin
//							| LED_9_Pin | LED_10_Pin | LED_11_Pin, GPIO_PIN_RESET);
	}
}

void RunExercise8() {
	  if (counter >= 12) {
		  counter = 0;
	  }
	  setNumberOnClock(counter++);
	  HAL_Delay(1000);
}

#endif /* INC_EX8_H_ */
