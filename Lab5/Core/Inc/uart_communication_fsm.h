/*
 * uart_communication_fsm.h
 *
 *  Created on: Dec 8, 2024
 *      Author: DEll P5530
 */

#ifndef INC_UART_COMMUNICATION_FSM_H_
#define INC_UART_COMMUNICATION_FSM_H_


#include "global.h"

#define	TIMEOUT				3000	//ms

extern ADC_HandleTypeDef hadc1;

extern UART_HandleTypeDef huart2;

extern char adc_response[20];
extern uint32_t adc_value; // ADC Value
void send_adc_value();


void uart_communication_fsm();

#endif /* INC_UART_COMMUNICATION_FSM_H_ */
