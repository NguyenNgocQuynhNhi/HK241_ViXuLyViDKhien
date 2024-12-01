/*
 * fsm_automatic.h
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_


#include "global.h"
#include "trafficLights.h"
#include "led7segments.h"
#include "update7seg.h"
#include "button.h"
#include "fsm_manual.h"

#include "scheduler.h"



void oneSecondTask();
void scan7SegLedTask();

void startAutoTask();
void redGreenTask();
void redYellowTask();
void greenRedTask();
void yellowRedTask();


void fsm_automatic_run();

#endif /* INC_FSM_AUTOMATIC_H_ */
