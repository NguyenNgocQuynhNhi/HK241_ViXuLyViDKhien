/*
 * global.h
 *
 *  Created on: Dec 8, 2024
 *      Author: DEll P5530
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#include "main.h"
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE		30

#include "command_parser_fsm.h"
#include "uart_communication_fsm.h"
#include "softwareTimer.h"


#define WAITING_COMMAND		0
#define SEND_ADC	1
#define STOP		2

extern int status;

//UART buffer and flags
extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
//UART buffer and flags




//#define UART_IDLE	20
#define UART_SENDING	21
#define UART_WAIT_OK	22
#define UART_STOP		23
extern int uart_state;



#define CMD_WAIT	10
#define CMD_RECEIVING	11
#define CMD_DONE		12
extern int cmd_state;





#endif /* INC_GLOBAL_H_ */
