/*
 * softwareTimer.h
 *
 *  Created on: Dec 8, 2024
 *      Author: DEll P5530
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_


#include "main.h"

#define TICK	10


extern int waitOK_flag;
void setTimerForWaitingOK(int duration);
void timerRun();

#endif /* INC_SOFTWARETIMER_H_ */
