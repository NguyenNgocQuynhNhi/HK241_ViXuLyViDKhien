/*
 * ex5.h
 *
 *  Created on: Sep 29, 2024
 *      Author: DEll P5530
 */

#ifndef INC_EX5_H_
#define INC_EX5_H_

int counterRed = 5;
uint32_t counterTime = 0;
uint32_t preLed = 0;
uint32_t curLed = 0;

void RunExercise5() {

	RunExercise3();

	if (counterRed <= 0) {
		counterRed = 5;
	}
	display7SEG(counterRed);
	curLed = HAL_GetTick();
	if (curLed - preLed >= 1000) {
		counterRed = counterRed - 1;
		preLed = curLed;
	}
}

#endif /* INC_EX5_H_ */
