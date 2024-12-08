/*
 * scheduler.h
 *
 *  Created on: Nov 30, 2024
 *      Author: DEll P5530
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

typedef struct {
	void (*pTask) (void);
	uint32_t	Delay;
	uint32_t	Period;
	uint32_t	RunMe;

	uint32_t	TaskID;
}sTasks;

#define SCH_MAX_TASKS	40

void SCH_Init(void);

void SCH_Add_Task (void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);	//tuong tu setTimer

void SCH_Update(void);	//vai tro tuong tu timerRun => goi trong ngat Timer

void SCH_Dispatch_Tasks(void);	//kiem tra flag =>goi trong while(1)

void SCH_Delete(uint32_t ID);

#endif /* INC_SCHEDULER_H_ */
