/*
 * command_parser_fsm.h
 *
 *  Created on: Dec 8, 2024
 *      Author: DEll P5530
 */

#ifndef INC_COMMAND_PARSER_FSM_H_
#define INC_COMMAND_PARSER_FSM_H_


#include "global.h"


extern uint8_t cmd_buffer[MAX_BUFFER_SIZE];
extern uint8_t cmd_index;


void command_parser_fsm();

#endif /* INC_COMMAND_PARSER_FSM_H_ */
