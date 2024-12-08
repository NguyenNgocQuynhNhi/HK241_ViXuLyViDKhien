/*
 * scheduler.c
 *
 *  Created on: Nov 30, 2024
 *      Author: DEll P5530
 */


#include "scheduler.h"

List list;

void SCH_Init(void) {
	list.head = NULL;
	list.tail = NULL;
    list.numTask = 0;
}

void SCH_Add_Task(void (*function)(), uint32_t Delay, uint32_t Period){
	sTask * newTask = (sTask *) malloc (sizeof(sTask));
	if (newTask == NULL)
		return;

	newTask->pTask = function;
	newTask->Delay = Delay/10; // scale for TIM2 10ms run
	newTask->Period = Period/10;
	newTask->RunMe = 0;
	newTask->next = NULL;
	newTask->prev = NULL;

	if(list.head == NULL){
		list.head = newTask;
		list.tail = newTask;
	}
	else{
		newTask->prev = list.tail;
		list.tail->next = newTask;
		list.tail = newTask;
	}
	list.numTask++;
}

void SCH_Update(void){
	sTask * temp = list.head;
	while(temp != NULL){
		if(temp->Delay > 0){
			temp->Delay --;
		}
		else{
			temp->RunMe++;
			temp->Delay = temp->Period;
		}
		temp = temp->next;
	}
}
void SCH_Dispatch_Task(void){

	sTask * temp = list.head;
	while(temp != NULL){
		if(temp->RunMe > 0){
			temp->RunMe--;
			temp->pTask();
			if(temp->Period == 0){
				sTask * delTask = temp;
				temp = temp->next;
				SCH_Delete_Task(delTask->pTask);
				continue;
			}
		}
		temp = temp->next;
	}
}
uint8_t SCH_Delete_Task(void (*function)()){
	if(list.numTask == 0)
		return 0;
	sTask * temp = list.head;
	while(temp != 0){
		if(temp->pTask == function){
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_15);
			if(temp->prev == NULL){ // delete head
				temp->next->prev = NULL;
				list.head = temp->next;
			}
			else if (temp->next == NULL){ //delete tail
				temp->prev->next = NULL;
				list.tail = temp->prev;
			}
			else{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			list.numTask--;
			free(temp);
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}



//#include "scheduler.h"
//
//sTasks SCH_tasks_G[SCH_MAX_TASKS];
//uint8_t current_index_task = 0;
//
//void SCH_Init(void) {
//	current_index_task = 0;
//}
//
//void SCH_Add_Task (void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD)
//{
//	if (current_index_task < SCH_MAX_TASKS) {
//		SCH_tasks_G[current_index_task].pTask = pFunction;
//		SCH_tasks_G[current_index_task].Delay = DELAY;
//		SCH_tasks_G[current_index_task].Period = PERIOD;
//		SCH_tasks_G[current_index_task].RunMe = 0;
//
//		SCH_tasks_G[current_index_task].TaskID = current_index_task;
//
//		current_index_task++;
//	}
//}
//
//void SCH_Update(void) {
//	for (int i = 0; i < current_index_task; i++) {
//		if (SCH_tasks_G[i].Delay > 0) {
//			SCH_tasks_G[i].Delay--;
//		}
//		else {
//			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
//			SCH_tasks_G[i].RunMe += 1;
//		}
//	}
//}
//
//void SCH_Dispatch_Tasks(void)
//{
//	for (int i = 0; i < current_index_task; i++) {
//		if (SCH_tasks_G[i].RunMe > 0) {
//			SCH_tasks_G[i].RunMe--;
//
//			(*SCH_tasks_G[i].pTask)();
//
//			//one-shot task need to be deleted after finishing running
//			if (SCH_tasks_G[i].Period == 0) {
//				SCH_Delete(SCH_tasks_G[i].TaskID);
//
//				i--;
//			}
//		}
//	}
//}
//
//void SCH_Delete(uint32_t ID)
//{
//	for (int i = 0; i < current_index_task; i++) {
//		if (SCH_tasks_G[i].TaskID == ID) {
//			for (int j = i; j < current_index_task - 1; j++) {
//				SCH_tasks_G[j] = SCH_tasks_G[j + 1];
//			}
//
//			current_index_task--;
//			return;
//		}
//	}
//	HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_SET);
//}
//
//uint32_t SCH_Get_Task_ID(void (*pFunction)()) {
//    for (uint8_t i = 0; i < current_index_task; i++) {
//        if (SCH_tasks_G[i].pTask == pFunction) {
//            return SCH_tasks_G[i].TaskID;
//        }
//    }
//    // Trả về giá trị không hợp lệ nếu không tìm thấy
//    return -1;
//}
//
//void SCH_Delete_Task_By_Function(void (*pFunction)()) {
//    uint32_t taskID = SCH_Get_Task_ID(pFunction);
//    if (taskID != (uint32_t)-1) {
//
//        SCH_Delete(taskID);
//        HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
//    }
//    else {
////    	HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_SET);
//    }
//}


