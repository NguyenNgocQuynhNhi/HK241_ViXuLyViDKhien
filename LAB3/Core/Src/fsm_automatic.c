/*
 * fsm_automatic.c
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */

#include "fsm_automatic.h"

void fsm_automatic_run()
{
	switch (status) {
	case START:
		//TODO
		  setTimer(1, 1000);
		  setTimer(2, 250);
		turnOff7SEG();
		turnOffLed();
		//SET UP FOR THE NEXT STATE
		//if (timer_flag[0] == 1) {
			status = RED_GREEN_AUTO;
			setTimer(0, greenCounter * 1000);
			vertical_counter = redCounter;
			horizontal_counter = greenCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		//}
		break;
	case RED_GREEN_AUTO:
		turnOnRedGreen();
		//SET UP FOR THE NEXT STATE
		if (timer_flag[0] == 1) {
			turnOffLed();
			status = RED_YELLOW_AUTO;
			//redYellow = 1;
			setTimer(0, yellowCounter * 1000);
			horizontal_counter = yellowCounter;
			vertical_counter = yellowCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}
		break;
	case RED_YELLOW_AUTO:
		//TODO
		turnOnRedYellow();
		//SET UP FOR THE NEXT STATE
		if (timer_flag[0] == 1) {
			turnOffLed();
			status = GREEN_RED_AUTO;
			//greenRed = 1;
			setTimer(0, greenCounter* 1000);
			vertical_counter = greenCounter;
			horizontal_counter = redCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}
		break;
	case GREEN_RED_AUTO:
		//TODO
		turnOnGreenRed();
		//SET UP FOR THE NEXT STATE
		if (timer_flag[0] == 1) {
			turnOffLed();
			status = YELLOW_RED_AUTO;
			//yellowRed = 1;
			setTimer(0, yellowCounter * 1000);
			vertical_counter = yellowCounter;
			horizontal_counter = yellowCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}
		break;
	case YELLOW_RED_AUTO:
		//TODO
		turnOnYellowRed();
		//SET UP FOR THE NEXT STATE
		if (timer_flag[0] == 1) {
			turnOffLed();
			status = RED_GREEN_AUTO;
			//redGreen = 1;
			setTimer(0, greenCounter * 1000);
			vertical_counter = redCounter;
			horizontal_counter = greenCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}
		break;
	default:
		break;
	}
	if (timer_flag[1] == 1) {
		setTimer(1, 1000);
		vertical_counter--;
		horizontal_counter--;
		updateClockBuffer(vertical_counter, horizontal_counter);
	}
	if (timer_flag[2] == 1) {
		setTimer(2, 250);
		update7seg();
	}
}

