/*
 * softwareTimer.h
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

#include "main.h"
#define TICK	10


extern int timer_flag[3];
extern int timer_counter[3];
extern TIM_HandleTypeDef htim2;

void setTimer(int, int);
void timerRun();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *);

#endif /* INC_SOFTWARETIMER_H_ */
