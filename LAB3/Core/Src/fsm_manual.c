/*
 * fsm_manual.c
 *
 *  Created on: Nov 24, 2024
 *      Author: DEll P5530
 */

#include "fsm_manual.h"
#include "trafficLights.h"
#include "button.h"

int manual = 0;

void fsm_manual_run(){
	switch(status) {
	case START_MANUAL:
		//TODO:
		toggleAllLeds();
		manual = 1;

		//SET UP FOR THE NEXT STATE
		if (isButton1Pressed()) {
			status = RED_MANUAL;
			turnOffAllLeds();

			horizontal_counter = 2;
			vertical_counter = newRedCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}

		if (isButton3Pressed()) {
			status = START;
		}
		break;
	case RED_MANUAL:
		//TODO:
		toggleRed();

		//SET UP FOR THE NEXT STATE
		if (isButton1Pressed()) {
			status = YELLOW_MANUAL;
			turnOffAllLeds();

			horizontal_counter = 3;
			vertical_counter = newYellowCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}

		if (isButton2Pressed()) {
			newRedCounter++;
			if (newRedCounter >= 99) {
				newRedCounter = redCounter;
			}
			vertical_counter = newRedCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}

		if (isButton3Pressed()) {
			status = START;
		}
		break;
	case YELLOW_MANUAL:
		//TODO:
		toggleYellow();

		//SET UP FOR THE NEXT STATE
		if (isButton1Pressed()) {
			status = GREEN_MANUAL;
			turnOffAllLeds();

			horizontal_counter = 4;
			vertical_counter = newGreenCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}

		if (isButton2Pressed()) {
			newYellowCounter++;
			if (newYellowCounter >= newRedCounter) {
				newYellowCounter = yellowCounter;
			}
			vertical_counter = newYellowCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}

		if (isButton3Pressed()) {
			status = START;
		}
		break;
	case GREEN_MANUAL:
		//TODO:
		toggleGreen();

		//SET UP FOR THE NEXT STATE
		if (isButton1Pressed()) {
			status = RED_MANUAL;
			turnOffAllLeds();

			horizontal_counter = 2;
			vertical_counter = newRedCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}

		if (isButton2Pressed()) {
			newGreenCounter = newRedCounter - newYellowCounter;
			vertical_counter = newGreenCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}

		if (isButton3Pressed()) {
			redCounter = newRedCounter;
			greenCounter = newGreenCounter;
			yellowCounter = newYellowCounter;

			status = START;
		}
		break;

	}
}
