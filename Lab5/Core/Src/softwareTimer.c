/*
 * softwareTimer.c
 *
 *  Created on: Dec 8, 2024
 *      Author: DEll P5530
 */


#include "softwareTimer.h"


int waitOK_flag = 0;
int waitOK_counter = 0;
void setTimerForWaitingOK(int duration)
{
	waitOK_counter = duration / TICK;
	waitOK_flag = 0;
}


void timerRun()
{
	if (waitOK_counter > 0) {
		waitOK_counter = waitOK_counter - 1;
		if (waitOK_counter <= 0) {
			waitOK_flag = 1;
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	timerRun();
}
