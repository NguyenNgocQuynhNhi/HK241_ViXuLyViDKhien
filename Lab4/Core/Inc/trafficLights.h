/*
 * trafficLights.h
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */

#ifndef INC_TRAFFICLIGHTS_H_
#define INC_TRAFFICLIGHTS_H_


#include "main.h"
#include "led7segments.h"

extern int redCounter;
extern int yellowCounter;
extern int greenCounter;

extern int vertical_counter;
extern int horizontal_counter;

//extern int redGreen, redYellow, greenRed, yellowRed;
extern uint32_t currentTime, previousTime;

extern int newRedCounter;
extern int newYellowCounter;
extern int newGreenCounter;

void turnOffAllLeds();
void initial();
void turnOnRedGreen();
void turnOnRedYellow();
void turnOnGreenRed();
void turnOnYellowRed();

void toggleAllLeds();
void toggleRed();
void toggleYellow();
void toggleGreen();


#endif /* INC_TRAFFICLIGHTS_H_ */
