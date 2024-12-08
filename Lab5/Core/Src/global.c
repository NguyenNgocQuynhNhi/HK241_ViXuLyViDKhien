/*
 * global.c
 *
 *  Created on: Dec 8, 2024
 *      Author: DEll P5530
 */


#include "global.h"


int status = 0;

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;


//uint8_t cmd_buffer[MAX_BUFFER_SIZE];
//uint8_t cmd_index = 0;


//int uart_state = UART_IDLE;
int uart_state = UART_STOP;
int cmd_state = CMD_WAIT;



