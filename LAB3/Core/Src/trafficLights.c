/*
 * trafficLights.c
 *
 *  Created on: Nov 10, 2024
 *      Author: DEll P5530
 */

#include "trafficLights.h"

int redCounter = 5;
int yellowCounter = 2;
int greenCounter = 3;

int vertical_counter = 0;
int horizontal_counter = 0;

int redGreen = 0;
int redYellow = 0;
int greenRed = 0;
int yellowRed = 0;


uint32_t currentTime = 0;
uint32_t previousTime = 0;


void initial()
{
	HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin, GPIO_PIN_RESET);	//turn off all traffic lights
	HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin | EN4_Pin, GPIO_PIN_SET);	//turn off all 7-segment leds
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

//void countDownRedGreen(int counter)
//{
//	if (counter > 0)
//}
