/*
 * timerSoftware.h
 *
 *  Created on: Oct 15, 2024
 *      Author: DEll P5530
 */

#ifndef INC_TIMERSOFTWARE_H_
#define INC_TIMERSOFTWARE_H_

extern int timer1_flag;

//extern int first7SegLed_flag;
//extern int second7SegLed_flag;
//extern int third7SegLed_flag;
//extern int fourth7SegLed_flag;
extern int dot_flag;

extern int segmentsLed_flag;
void setTimerFor7SegLed(int duration);

//void setTimerForFirst7SegLed(int duration);
//void setTimerForSecond7SegLed(int duration);
//void setTimerForThird7SegLed(int duration);
//void setTimerForFourth7SegLed(int duration);
void setTimerForDot(int duration);

void setTimer1(int duration);

void timerRun();

extern int clock_flag;
void setTimerForClock(int duration);

#endif /* INC_TIMERSOFTWARE_H_ */
