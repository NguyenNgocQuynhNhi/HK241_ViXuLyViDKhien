/*
 * scheduler.h
 *
 *  Created on: Nov 30, 2024
 *      Author: DEll P5530
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_


#include "global.h"
#include <stdlib.h>
#include <stdint.h>
#include "main.h"
typedef struct sTask{
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	struct sTask * next;
	struct sTask * prev;
}sTask;
typedef struct List{
	sTask * head;
	sTask * tail;
	uint8_t numTask;
}List;
extern List list;
void SCH_Init(void);
void SCH_Add_Task (void (*function) (), uint32_t, uint32_t);
void SCH_Update(void);
void SCH_Dispatch_Task(void);
uint8_t SCH_Delete_Task(void (*function)() );




//#include <stdint.h>
//#include "main.h"
//
//typedef struct {
//	void (*pTask) (void);
//	uint32_t	Delay;
//	uint32_t	Period;
//	uint32_t	RunMe;
//
//	uint32_t	TaskID;
//}sTasks;
//
//#define SCH_MAX_TASKS	40
//
//void SCH_Init(void);
//
//void SCH_Add_Task (void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);	//tuong tu setTimer
//
//void SCH_Update(void);	//vai tro tuong tu timerRun => goi trong ngat Timer
//
//void SCH_Dispatch_Tasks(void);	//kiem tra flag =>goi trong while(1)
//
//void SCH_Delete(uint32_t ID);
//
//uint32_t SCH_Get_Task_ID(void (*pFunction)());
//
//void SCH_Delete_Task_By_Function(void (*pFunction)());

#endif /* INC_SCHEDULER_H_ */
