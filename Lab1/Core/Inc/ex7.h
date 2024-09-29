/*
 * ex7.h
 *
 *  Created on: Sep 29, 2024
 *      Author: DEll P5530
 */

#ifndef INC_EX7_H_
#define INC_EX7_H_

void turnOnAllClock() {
	HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin
						| LED_5_Pin | LED_6_Pin | LED_7_Pin | LED_8_Pin
						| LED_9_Pin | LED_10_Pin | LED_11_Pin | LED_12_Pin, GPIO_PIN_SET);
}

void clearAllClock() {
	HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin
						| LED_5_Pin | LED_6_Pin | LED_7_Pin | LED_8_Pin
						| LED_9_Pin | LED_10_Pin | LED_11_Pin | LED_12_Pin, GPIO_PIN_RESET);
}

void RunExercise7() {
	turnOnAllClock();
	HAL_Delay(1000);
	clearAllClock();
	HAL_Delay(1000);
}

#endif /* INC_EX7_H_ */
