/*
 * button.c
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */


#include "button.h"



int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;		//trang thai on dinh trc do
int TimerForKeyPress = 200;		//thoi gian nhan de la 2s

int button1_flag = 0;
int isButton1Pressed() {
	if (button1_flag == 1) {
		button1_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess() {
	//TODO
	//HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
	button1_flag = 1;
}


int keyReg0_btn2 = NORMAL_STATE;
int keyReg1_btn2 = NORMAL_STATE;
int keyReg2_btn2 = NORMAL_STATE;
int keyReg3_btn2 = NORMAL_STATE;

int timeForKeyPressed_btn2 = 200;

int button2_flag = 0;
int isButton2Pressed() {
	if (button2_flag == 1) {
		button2_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess_btn2() {
	button2_flag = 1;
}


int keyReg0_btn3 = NORMAL_STATE;
int keyReg1_btn3 = NORMAL_STATE;
int keyReg2_btn3 = NORMAL_STATE;
int keyReg3_btn3 = NORMAL_STATE;

int timeForKeyPressed_btn3 = 200;

int button3_flag = 0;
int isButton3Pressed() {
	if (button3_flag == 1) {
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess_btn3() {
	button3_flag = 1;
}


void getKeyInput() //xu ly chong rung va nhan de cho phim	|	duoc goi trong softwareTimer moi 10ms 1 lan, tuc la sau moi 10ms ta moi xy ly chong rung va nhan de cho phim
{
//====================BUTTON 1===================================
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);

	if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)) {
		if (KeyReg3 != KeyReg2) // nhan tha
		{
			KeyReg3 = KeyReg2;	//cap nhat lai trang thai cua nut

			if (KeyReg2 == PRESSED_STATE) // nut dang dc nhan
			{
				//TODO
				subKeyProcess();
				TimerForKeyPress = 200;
			}
		}
		else //nhan de
		{
			TimerForKeyPress--;
			if (TimerForKeyPress == 0) // het thoi gian nhan de
			{
				//TODO
//				if (KeyReg2 == PRESSED_STATE) {
//					subKeyProcess();
//				}
//
//				TimerForKeyPress = 200;

				KeyReg3 = NORMAL_STATE;
			}
		}
	}
//====================BUTTON 1===================================

//====================BUTTON 2===================================
	keyReg0_btn2 = keyReg1_btn2;
	keyReg1_btn2 = keyReg2_btn2;
	keyReg2_btn2 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);

	if ((keyReg0_btn2 == keyReg1_btn2) && (keyReg1_btn2 == keyReg2_btn2)) {
		if (keyReg3_btn2 != keyReg2_btn2) {
			keyReg3_btn2 = keyReg2_btn2;

			if (keyReg2_btn2 == PRESSED_STATE) {
				subKeyProcess_btn2();
				timeForKeyPressed_btn2 = 200;
			}
		}
		else {
			timeForKeyPressed_btn2--;
			if (timeForKeyPressed_btn2 == 0) {
				keyReg3_btn2 = NORMAL_STATE;
			}
		}
	}
//====================BUTTON 2===================================

//====================BUTTON 3===================================
	keyReg0_btn3 = keyReg1_btn3;
	keyReg1_btn3 = keyReg2_btn3;
	keyReg2_btn3 = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);

	if ((keyReg0_btn3 == keyReg1_btn3) && (keyReg1_btn3 == keyReg2_btn3)) {
		if (keyReg3_btn3 != keyReg2_btn3) {		//nhan nha
			keyReg3_btn3 = keyReg2_btn3;

			if (keyReg2_btn3 == PRESSED_STATE) {
				timeForKeyPressed_btn3 = 200;
				subKeyProcess_btn3();
			}
		}
		else {
			timeForKeyPressed_btn3--;
			if (timeForKeyPressed_btn3 == 0) {
				keyReg3_btn3 = NORMAL_STATE;
			}
		}
	}
//====================BUTTON 3===================================
}
