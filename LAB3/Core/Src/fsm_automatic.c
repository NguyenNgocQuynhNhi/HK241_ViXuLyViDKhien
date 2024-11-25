/*
 * fsm_automatic.c
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */

#include "fsm_automatic.h"


void fsm_automatic_run()
{
	if (oneSecond_flag == 1) {
		setTimerFor1Second(1000);
		//TODO:
		if (vertical_counter > 0 && horizontal_counter > 0 && manual == 0) {
			vertical_counter--;
			horizontal_counter--;
		}
//		else {
//			vertical_counter = 0;
//			horizontal_counter = 0;
//		}
		updateClockBuffer(vertical_counter, horizontal_counter);
	}

	if (timer7seg_flag == 1) {
		setTimerFor7segLed(250);
		//TODO:
		if (ledIndex >= MAX_LED) {
			ledIndex = 0;
		}
		update7seg(ledIndex++);
	}


	switch (status) {
	case START:
		//TODO
		initial();
		manual = 0;

		//SET UP FOR THE NEXT STATE
		if (timer1_flag == 1) {
			status = RED_GREEN_AUTO;
			setTimer1(greenCounter * 1000);

			vertical_counter = redCounter;
			horizontal_counter = greenCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}

		if (isButton1Pressed()) {
			status = START_MANUAL;
			turnOffAllLeds();
			newRedCounter = redCounter;
			newYellowCounter = yellowCounter;
			newGreenCounter = greenCounter;
		}
		break;

	case RED_GREEN_AUTO:
		//TODO
		turnOnRedGreen();

		//SET UP FOR THE NEXT STATE
		if (timer1_flag == 1) {
			status = RED_YELLOW_AUTO;
			setTimer1(yellowCounter * 1000);

			vertical_counter = yellowCounter;
			horizontal_counter = yellowCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}

		if (isButton1Pressed()) {
			status = START_MANUAL;
			turnOffAllLeds();
			newRedCounter = redCounter;
			newYellowCounter = yellowCounter;
			newGreenCounter = greenCounter;
		}

		break;

	case RED_YELLOW_AUTO:
		//TODO
		turnOnRedYellow();

		//SET UP FOR THE NEXT STATE
		if (timer1_flag == 1) {
			status = GREEN_RED_AUTO;
			setTimer1(greenCounter * 1000);

			vertical_counter = greenCounter;
			horizontal_counter = redCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}

		if (isButton1Pressed()) {
			status = START_MANUAL;
			turnOffAllLeds();
			newRedCounter = redCounter;
			newYellowCounter = yellowCounter;
			newGreenCounter = greenCounter;
		}
		break;

	case GREEN_RED_AUTO:
		//TODO
		turnOnGreenRed();

		//SET UP FOR THE NEXT STATE
		if (timer1_flag == 1) {
			status = YELLOW_RED_AUTO;
			setTimer1(yellowCounter * 1000);

			horizontal_counter = yellowCounter;
			vertical_counter = yellowCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}

		if (isButton1Pressed()) {
			status = START_MANUAL;
			turnOffAllLeds();
			newRedCounter = redCounter;
			newYellowCounter = yellowCounter;
			newGreenCounter = greenCounter;
		}

		break;

	case YELLOW_RED_AUTO:
		//TODO
		turnOnYellowRed();

		//SET UP FOR THE NEXT STATE
		if (timer1_flag == 1) {
			status = RED_GREEN_AUTO;
			setTimer1(greenCounter * 1000);

			vertical_counter = redCounter;
			horizontal_counter = greenCounter;
			updateClockBuffer(vertical_counter, horizontal_counter);
		}

		if (isButton1Pressed()) {
			status = START_MANUAL;
			turnOffAllLeds();
			newRedCounter = redCounter;
			newYellowCounter = yellowCounter;
			newGreenCounter = greenCounter;
		}
		break;
	default:
		break;
	}

}
