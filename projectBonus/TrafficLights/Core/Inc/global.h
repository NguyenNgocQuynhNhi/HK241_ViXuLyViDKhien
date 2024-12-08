/*
 * global.h
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#include "softwareTimer.h"
#include "i2c-lcd.h"


#define START			1
#define RED_GREEN_AUTO	2
#define RED_YELLOW_AUTO	3
#define GREEN_RED_AUTO 	4
#define YELLOW_RED_AUTO	5

#define START_MANUAL	11
#define RED_MANUAL		12
#define YELLOW_MANUAL	13
#define GREEN_MANUAL	14

extern int status;


#endif /* INC_GLOBAL_H_ */
