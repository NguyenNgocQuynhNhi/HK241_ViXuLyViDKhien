/*
 * button.h
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_


#include "main.h"

#define NORMAL_STATE 	GPIO_PIN_SET
#define PRESSED_STATE 	GPIO_PIN_RESET

//extern int button1_flag;
int isButton1Pressed();
void subKeyProcess();

int isButton2Pressed();
void subKeyProcess_btn2();

int isButton3Pressed();
void subKeyProcess_btn3();


void getKeyInput(); //xu ly chong rung va nhan de cho phim


#endif /* INC_BUTTON_H_ */
