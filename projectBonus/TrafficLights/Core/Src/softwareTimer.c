/*
 * softwareTimer.c
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */

#include "softwareTimer.h"

int timer1_flag = 0;
int timer1_counter = 0;
void setTimer1(int duration)
{
	timer1_counter = duration / TICK;
	timer1_flag = 0;
}

int oneSecond_flag = 0;
int oneSecond_counter = 0;
void setTimerFor1Second(int duration)
{
	oneSecond_counter = duration / TICK;
	oneSecond_flag = 0;
}


void timerRun()
{
	if (timer1_counter > 0) {
		timer1_counter = timer1_counter - 1;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}

	if (oneSecond_counter > 0) {
		oneSecond_counter = oneSecond_counter - 1;
		if (oneSecond_counter <= 0) {
			oneSecond_flag = 1;
		}
	}
}
