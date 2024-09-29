/*
 * ex10.h
 *
 *  Created on: Sep 29, 2024
 *      Author: DEll P5530
 */

#ifndef INC_EX10_H_
#define INC_EX10_H_

uint8_t hour = 3;
uint8_t minute = 39;
uint8_t second = 50;

void runExercise10() {
	currentTime = HAL_GetTick();
  	clearAllClock();

	setNumberOnClock(hour);
	setNumberOnClock(minute/5);
	setNumberOnClock(second/5);

	if (currentTime - previousTime >= 5000) {
		second = second + 5;
		if (second - 60 >= 0) {
			second = 0;
			minute = minute + 1;
			if (minute == 60) {
				minute = 0;
				hour = hour + 1;
				if (hour == 12) {
					hour = 0;
				}
			}
		}
		previousTime = currentTime;
	}
	HAL_Delay(10);
}

#endif /* INC_EX10_H_ */
