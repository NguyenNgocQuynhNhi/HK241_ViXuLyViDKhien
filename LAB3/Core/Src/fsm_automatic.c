/*
 * fsm_automatic.c
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */

#include "fsm_automatic.h"

//int hour = 15, minute = 59, second = 50;	//TEST


void fsm_automatic_run()
{

//----------------TEST-------------------------
//	  if (oneSecond_flag == 1) {
//		  setTimerFor1Second(1000);
//		  //TODO:
//		  second = second + 1;
//		  if (second >= 60) {
//			  second = 0;
//			  minute = minute + 1;
//		  }
//		  if (minute >= 60) {
//			  minute = 0;
//			  hour = hour + 1;
//		  }
//		  if (hour >= 24) {
//			  hour = 0;
//		  }
//		  updateClockBuffer(hour, minute);
//	  }
//----------------TEST-------------------------

//------------PROTEUS SHUT DOWN----------------------
//	if (oneSecond_flag == 1) {
//		setTimerFor1Second(1000);
//		//TODO:
//		if (vertical_counter > 0) {
//			vertical_counter--;
//		}
//		else {
////			vertical_counter = 0;
//			vertical_counter = redCounter;
//		}
//
//		if (horizontal_counter > 0) {
//			horizontal_counter--;
//		}
//		else {
////			horizontal_counter = 0;
//			horizontal_counter = greenCounter;
//		}

//		if (redCounter > 0) {
//			redCounter--;
//		}
//		else {
//			redCounter = 5;
//		}
//		if (greenCounter > 0) {
//			greenCounter--;
//		}
//		else {
//			greenCounter = 3;
//		}
//		updateClockBuffer(redCounter, greenCounter);
//	}
//------------PROTEUS SHUT DOWN----------------------

	if (redGreen == 1) {
		vertical_counter = redCounter;
		horizontal_counter = greenCounter;
		updateClockBuffer(vertical_counter, horizontal_counter);
		redGreen = 0;
	}

	if (redYellow == 1) {
		vertical_counter = yellowCounter;
		horizontal_counter = yellowCounter;
		updateClockBuffer(vertical_counter, horizontal_counter);
		redYellow = 0;
	}

	if (greenRed == 1) {
		vertical_counter = greenCounter;
		horizontal_counter = redCounter;
		updateClockBuffer(vertical_counter, horizontal_counter);
		greenRed = 0;
	}

	if (yellowRed == 1) {
		horizontal_counter = yellowCounter;
		vertical_counter = yellowCounter;
		updateClockBuffer(vertical_counter, horizontal_counter);
		yellowRed = 0;
	}

	if (oneSecond_flag == 1) {
		setTimerFor1Second(1000);
		setTimerFor7segLed(250);
		//TODO:
//		if (vertical_counter > 0 && horizontal_counter > 0) {
//			vertical_counter--;
//			horizontal_counter--;
//		}
//		else {
//			vertical_counter = 0;
//			horizontal_counter = 0;
//		}
		vertical_counter--;
		horizontal_counter--;
		updateClockBuffer(vertical_counter, horizontal_counter);
	}

	switch (status) {
	case START:
		//TODO
		initial();
//		updateClockBuffer(hour, minute);	//TEST


		//SET UP FOR THE NEXT STATE
		if (timer1_flag == 1) {
			status = RED_GREEN_AUTO;
			redGreen = 1;
			setTimer1(3000);
			setTimerFor1Second(1000);
			setTimerFor7segLed(250);

//			vertical_counter = redCounter;
//			horizontal_counter = greenCounter;
//			updateClockBuffer(vertical_counter, horizontal_counter);
		}
		break;

	case RED_GREEN_AUTO:
		//TODO
		turnOnRedGreen();

		//SET UP FOR THE NEXT STATE
		if (timer1_flag == 1) {
			status = RED_YELLOW_AUTO;
			redYellow = 1;
			setTimer1(2000);
			setTimerFor1Second(1000);
			setTimerFor7segLed(250);

//			horizontal_counter = yellowCounter;
//			updateClockBuffer(vertical_counter, horizontal_counter);
		}
		break;

	case RED_YELLOW_AUTO:
		//TODO
		turnOnRedYellow();

		//SET UP FOR THE NEXT STATE
		if (timer1_flag == 1) {
			status = GREEN_RED_AUTO;
			greenRed = 1;
			setTimer1(3000);
			setTimerFor1Second(1000);
			setTimerFor7segLed(250);

//			vertical_counter = greenCounter;
//			horizontal_counter = redCounter;
//			updateClockBuffer(vertical_counter, horizontal_counter);
		}
		break;

	case GREEN_RED_AUTO:
		//TODO
		turnOnGreenRed();

		//SET UP FOR THE NEXT STATE
		if (timer1_flag == 1) {
			status = YELLOW_RED_AUTO;
			yellowRed = 1;
			setTimer1(2000);
			setTimerFor1Second(1000);
			setTimerFor7segLed(250);

//			vertical_counter = yellowCounter;
//			updateClockBuffer(vertical_counter, horizontal_counter);
		}
		break;

	case YELLOW_RED_AUTO:
		//TODO
		turnOnYellowRed();

		//SET UP FOR THE NEXT STATE
		if (timer1_flag == 1) {
			status = RED_GREEN_AUTO;
			redGreen = 1;
			setTimer1(3000);
			setTimerFor1Second(1000);
			setTimerFor7segLed(250);

//			vertical_counter = redCounter;
//			horizontal_counter = greenCounter;
//			updateClockBuffer(vertical_counter, horizontal_counter);
		}
		break;
	default:
		break;
	}


	if (timer7seg_flag == 1) {
			setTimerFor7segLed(250);
			//TODO:
			if (ledIndex >= MAX_LED) {
				ledIndex = 0;
			}
			update7seg(ledIndex++);
		}

}
