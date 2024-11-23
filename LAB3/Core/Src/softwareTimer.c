/*
 * softwareTimer.c
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */

#include "softwareTimer.h"

int timer_flag[3] = {0, 0, 0};
int timer_counter[3] = {0, 0, 0};
TIM_HandleTypeDef htim2;
void setTimer(int timer, int duration)
{
	timer_counter[timer] = duration / TICK;
	timer_flag[timer] = 0;
}

void timerRun()
{
	for(int i = 0; i < 3; i++){
		if (timer_counter[i] > 0) {
			timer_counter[i]--;
			if (timer_counter[i] <= 0) {
				timer_flag[i] = 1;
			}
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim2)
{
	timerRun();
}
