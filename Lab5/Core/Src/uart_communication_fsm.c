/*
 * uart_communication_fsm.c
 *
 *  Created on: Dec 8, 2024
 *      Author: DEll P5530
 */


#include "uart_communication_fsm.h"





char adc_response[20];
uint32_t adc_value = 0; // ADC Value
void send_adc_value()
{
//	adc_value = HAL_ADC_GetValue(&hadc1);

	sprintf(adc_response, "!ADC = %ld#\r\n", adc_value);
	HAL_UART_Transmit(&huart2, (uint8_t *)adc_response, strlen(adc_response), 1000);
}


void uart_communication_fsm()
{
	switch (uart_state) {
	case UART_SENDING:
		send_adc_value();

		uart_state = UART_WAIT_OK;
		setTimerForWaitingOK(3000);
		break;
	case UART_WAIT_OK:

		if (strcmp((char*)cmd_buffer, "OK") == 0) {
			uart_state = UART_STOP;
			waitOK_flag = 0;
		}

		if (waitOK_flag == 1) {
			setTimerForWaitingOK(TIMEOUT);
			//TODO:
			uart_state = UART_SENDING;
		}
		break;
	case UART_STOP:
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);	//test

		break;
	}
}
