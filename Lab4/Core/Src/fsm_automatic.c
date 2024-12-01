/*
 * fsm_automatic.c
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */

#include "fsm_automatic.h"

void (*nextTask_Switch_State)() = NULL;
void oneSecondTask()
{
	if (manual == 0) {
		if (vertical_counter > 0) {
			vertical_counter--;
		}

		if (horizontal_counter > 0) {
			horizontal_counter--;
		}
	}

	updateClockBuffer(vertical_counter, horizontal_counter);
}

void scan7SegLedTask()
{
	if (ledIndex >= MAX_LED) {
		ledIndex = 0;
	}
	update7seg(ledIndex++);
}

void startAutoTask()
{
	status = START;

	initial();
	manual = 0;

	SCH_Add_Task(redGreenTask, 100, 0);
}

void redGreenTask()
{
	status = RED_GREEN_AUTO;

	turnOnRedGreen();

	vertical_counter = redCounter;
	horizontal_counter = greenCounter;
	updateClockBuffer(vertical_counter, horizontal_counter);

	SCH_Add_Task(redYellowTask, greenCounter * 100, 0);
	nextTask_Switch_State = redYellowTask;
}

void redYellowTask()
{
	status = RED_YELLOW_AUTO;

	turnOnRedYellow();

	vertical_counter = yellowCounter;
	horizontal_counter = yellowCounter;
	updateClockBuffer(vertical_counter, horizontal_counter);

	SCH_Add_Task(greenRedTask, yellowCounter * 100, 0);
	nextTask_Switch_State = greenRedTask;
}

void greenRedTask()
{
	status = GREEN_RED_AUTO;

	turnOnGreenRed();

	vertical_counter = greenCounter;
	horizontal_counter = redCounter;
	updateClockBuffer(vertical_counter, horizontal_counter);

	SCH_Add_Task(yellowRedTask, greenCounter * 100, 0);
	nextTask_Switch_State = yellowRedTask;
}
void yellowRedTask()
{
	status = YELLOW_RED_AUTO;

	turnOnYellowRed();

	vertical_counter = yellowCounter;
	horizontal_counter = yellowCounter;
	updateClockBuffer(vertical_counter, horizontal_counter);

	SCH_Add_Task(redGreenTask, yellowCounter * 100, 0);
	nextTask_Switch_State = redGreenTask;
}

void fsm_automatic_run()
{
	switch (status) {
	case START:
		//TODO
		initial();
		manual = 0;

		SCH_Add_Task(redGreenTask, 100, 0);

		//SET UP FOR THE NEXT STATE



//		if (isButton1Pressed()) {
//			status = START_MANUAL;
//			turnOffAllLeds();
//			newRedCounter = redCounter;
//			newYellowCounter = yellowCounter;
//			newGreenCounter = greenCounter;
//		}
		break;

	case RED_GREEN_AUTO:
		//TODO

		//SET UP FOR THE NEXT STATE



//		if (isButton1Pressed()) {
//			status = START_MANUAL;
//			turnOffAllLeds();
//			newRedCounter = redCounter;
//			newYellowCounter = yellowCounter;
//			newGreenCounter = greenCounter;
//		}

		break;

	case RED_YELLOW_AUTO:
		//TODO

//		//SET UP FOR THE NEXT STATE



//		if (isButton1Pressed()) {
//			status = START_MANUAL;
//			turnOffAllLeds();
//			newRedCounter = redCounter;
//			newYellowCounter = yellowCounter;
//			newGreenCounter = greenCounter;
//		}
		break;

	case GREEN_RED_AUTO:
		//TODO

//		//SET UP FOR THE NEXT STATE



//		if (isButton1Pressed()) {
//			status = START_MANUAL;
//			turnOffAllLeds();
//			newRedCounter = redCounter;
//			newYellowCounter = yellowCounter;
//			newGreenCounter = greenCounter;
//		}

		break;

	case YELLOW_RED_AUTO:
		//TODO
//
//		//SET UP FOR THE NEXT STATE



//		if (isButton1Pressed()) {
//			status = START_MANUAL;
//			turnOffAllLeds();
//			newRedCounter = redCounter;
//			newYellowCounter = yellowCounter;
//			newGreenCounter = greenCounter;
//		}
		break;
	default:
		return;
	}

	if (isButton1Pressed()) {
		status = START_MANUAL;
		turnOffAllLeds();

		//SCH_Delete_Task_By_Function(fsm_automatic_run);
		SCH_Delete_Task_By_Function(nextTask_Switch_State);

		SCH_Add_Task(fsm_manual_run, 0, 1000);
	}

}
