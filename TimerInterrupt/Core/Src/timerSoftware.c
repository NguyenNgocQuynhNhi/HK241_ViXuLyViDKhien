/*
 * timerSoftware.c
 *
 *  Created on: Oct 15, 2024
 *      Author: DEll P5530
 */

#include "timerSoftware.h"

int timer1_counter;
int timer1_flag = 0;

//int first7SegLed_counter;
//int second7SegLed_counter;
//int third7SegLed_counter;
//int fourth7SegLed_counter;
int dot_counter;

//int first7SegLed_flag;
//int second7SegLed_flag;
//int third7SegLed_flag;
//int fourth7SegLed_flag;
int dot_flag;


int segmentsLed_counter;
int segmentsLed_flag;
void setTimerFor7SegLed(int duration) {
	segmentsLed_counter = duration;
	segmentsLed_flag = 0;
}


//void setTimerForFirst7SegLed(int duration) {
//	first7SegLed_counter = duration;
//	first7SegLed_flag = 0;
//}
//
//void setTimerForSecond7SegLed(int duration) {
//	second7SegLed_counter = duration;
//	second7SegLed_flag = 0;
//}

void setTimerForDot(int duration) {
	dot_counter = duration;
	dot_flag = 0;
}

//void setTimerForThird7SegLed(int duration) {
//	third7SegLed_counter = duration;
//	third7SegLed_flag = 0;
//}
//void setTimerForFourth7SegLed(int duration) {
//	fourth7SegLed_counter = duration;
//	fourth7SegLed_flag = 0;
//}

void setTimer1(int duration) {
	timer1_counter = duration;
	timer1_flag = 0;
}

int clock_counter;
int clock_flag = 0;
void setTimerForClock(int duration) {
	clock_counter = duration;
	clock_flag = 0;
}

void timerRun() {
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}

//	if (first7SegLed_counter > 0) {
//		first7SegLed_counter = first7SegLed_counter - 1;
//		if (first7SegLed_counter <= 0) {
//			first7SegLed_flag = 1;
//		}
//	}
//
//	if (second7SegLed_counter > 0) {
//		second7SegLed_counter = second7SegLed_counter - 1;
//		if (second7SegLed_counter <= 0) {
//			second7SegLed_flag = 1;
//		}
//	}

	if (dot_counter > 0) {
		dot_counter = dot_counter - 1;
		if (dot_counter <= 0) {
			dot_flag = 1;
		}
	}

//	if (third7SegLed_counter > 0) {
//		third7SegLed_counter = third7SegLed_counter - 1;
//		if (third7SegLed_counter <= 0) {
//			third7SegLed_flag = 1;
//		}
//	}

	if (segmentsLed_counter > 0) {
		segmentsLed_counter = segmentsLed_counter - 1;
		if (segmentsLed_counter <= 0) {
			segmentsLed_flag = 1;
		}
	}

	if (clock_counter > 0) {
		clock_counter = clock_counter - 1;
		if (clock_counter <= 0) {
			clock_flag = 1;
		}
	}

}
