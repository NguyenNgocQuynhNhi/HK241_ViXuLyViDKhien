/*
 * command_parser_fsm.c
 *
 *  Created on: Dec 8, 2024
 *      Author: DEll P5530
 */

#ifndef SRC_COMMAND_PARSER_FSM_C_
#define SRC_COMMAND_PARSER_FSM_C_


#include "command_parser_fsm.h"




uint8_t cmd_buffer[MAX_BUFFER_SIZE];
uint8_t cmd_index = 0;


void command_parser_fsm() {
    switch (cmd_state) {
        case CMD_WAIT:
            if (buffer[0] == '!') {
                cmd_state = CMD_RECEIVING;
                cmd_index = 0;
            }

            break;
        case CMD_RECEIVING:
        	if (temp != '!' && temp != '#') {
        		cmd_buffer[cmd_index++] = temp;
        	}

        	if (temp == '#') {
        		cmd_state = CMD_DONE;
        		cmd_index = 0;
        	}

            break;
        case CMD_DONE:

        	if (strcmp((char*)cmd_buffer, "RST") == 0) {
        		adc_value = HAL_ADC_GetValue(&hadc1);
        		uart_state = UART_SENDING;
        	}
        	else if (strcmp((char*)cmd_buffer, "OK") == 0) {
        		uart_state = UART_STOP;
        		waitOK_flag = 0;
        	}

        	memset(buffer, 0, MAX_BUFFER_SIZE);
        	index_buffer = 0;
        	memset(cmd_buffer, 0, MAX_BUFFER_SIZE);
        	cmd_index = 0;

        	cmd_state = CMD_WAIT;

            break;
        default:
        	break;
    }

}


#endif /* SRC_COMMAND_PARSER_FSM_C_ */
