/*
 * trafficLights.c
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */

#include "trafficLights.h"

int redCounter = 15;
int yellowCounter = 5;
int greenCounter = 10;

int vertical_counter = 0;
int horizontal_counter = 0;

uint32_t currentTime = 0;
uint32_t previousTime = 0;

int newRedCounter = 0;
int newYellowCounter = 0;
int newGreenCounter = 0;


void turnOffAllLeds()
{
	HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin, GPIO_PIN_RESET);	//turn off all traffic lights
}

void initial()
{
	turnOffAllLeds();
}

void turnOnRedGreen()
{
	HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_6_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET);
}

void turnOnRedYellow()
{
	HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_2_Pin | LED_4_Pin | LED_6_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET);
}

void turnOnGreenRed()
{
	HAL_GPIO_WritePin(GPIOA, LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
}

void turnOnYellowRed()
{
	HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
}



void toggleAllLeds() {
	currentTime = HAL_GetTick();
	if (currentTime - previousTime >= 500) {
		HAL_GPIO_TogglePin(GPIOA, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin);
		previousTime = currentTime;
	}
}

void toggleRed() {
	currentTime = HAL_GetTick();
	if (currentTime - previousTime >= 500) {
		HAL_GPIO_TogglePin(GPIOA, LED_5_Pin | LED_2_Pin);
		previousTime = currentTime;
	}
}

void toggleYellow() {
	currentTime = HAL_GetTick();
	if (currentTime - previousTime >= 500) {
		HAL_GPIO_TogglePin(GPIOA, LED_6_Pin | LED_3_Pin);
		previousTime = currentTime;
	}
}

void toggleGreen() {
	currentTime = HAL_GetTick();
	if (currentTime - previousTime >= 500) {
		HAL_GPIO_TogglePin(GPIOA, LED_1_Pin | LED_4_Pin);
		previousTime = currentTime;
	}
}
