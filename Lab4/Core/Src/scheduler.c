/*
 * scheduler.c
 *
 *  Created on: Nov 30, 2024
 *      Author: DEll P5530
 */


#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Init(void) {
	current_index_task = 0;
}

void SCH_Add_Task (void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD)
{
	if (current_index_task < SCH_MAX_TASKS) {
		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY;
		SCH_tasks_G[current_index_task].Period = PERIOD;
		SCH_tasks_G[current_index_task].RunMe = 0;

		SCH_tasks_G[current_index_task].TaskID = current_index_task;

		current_index_task++;
	}
}

void SCH_Update(void) {
	for (int i = 0; i < current_index_task; i++) {
		if (SCH_tasks_G[i].Delay > 0) {
			SCH_tasks_G[i].Delay--;
		}
		else {
			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe += 1;
		}
	}
}

void SCH_Dispatch_Tasks(void)
{
	for (int i = 0; i < current_index_task; i++) {
		if (SCH_tasks_G[i].RunMe > 0) {
			SCH_tasks_G[i].RunMe--;

			(*SCH_tasks_G[i].pTask)();

			//one-shot task need to be deleted after finishing running
			if (SCH_tasks_G[i].Period == 0) {
				SCH_Delete(SCH_tasks_G[i].TaskID);

				i--;
			}
		}
	}
}

void SCH_Delete(uint32_t ID)
{
	for (int i = 0; i < current_index_task; i++) {
		if (SCH_tasks_G[i].TaskID == ID) {
			for (int j = i; j < current_index_task - 1; j++) {
				SCH_tasks_G[j] = SCH_tasks_G[j + 1];
			}

			current_index_task--;
			return;
		}
	}
	HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_SET);
}

uint32_t SCH_Get_Task_ID(void (*pFunction)()) {
    for (uint8_t i = 0; i < current_index_task; i++) {
        if (SCH_tasks_G[i].pTask == pFunction) {
            return SCH_tasks_G[i].TaskID;
        }
    }
    // Trả về giá trị không hợp lệ nếu không tìm thấy
    return -1;
}

void SCH_Delete_Task_By_Function(void (*pFunction)()) {
    uint32_t taskID = SCH_Get_Task_ID(pFunction);
    if (taskID != (uint32_t)-1) {

        SCH_Delete(taskID);
        HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
    }
    else {
//    	HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_SET);
    }
}

