/*
 * displayLCD.c
 *
 *  Created on: Dec 6, 2024
 *      Author: DEll P5530
 */


#include "displayLCD.h"


int led_buffer[4] = {0, 0, 0, 0};

void updateClockBuffer(int vertical_counter, int horizontal_counter)
{

		led_buffer[0] = vertical_counter / 10;
		led_buffer[1] = vertical_counter % 10;

		led_buffer[2] = horizontal_counter / 10;
		led_buffer[3] = horizontal_counter % 10;

}

void lcd_start_auto()
{
	lcd_goto_XY(1, 0);
	lcd_send_string("Initializing...");
}

void lcd_auto()
{
	lcd_goto_XY(1, 0);
	lcd_send_string("Lane1_Time: ");
	lcd_goto_XY(1, 12);
	lcd_send_int(led_buffer[0]);
	lcd_goto_XY(1, 13);
	lcd_send_int(led_buffer[1]);

	lcd_goto_XY(2, 0);
	lcd_send_string("Lane2_Time: ");
	lcd_goto_XY(2, 12);
	lcd_send_int(led_buffer[2]);
	lcd_goto_XY(2, 13);
	lcd_send_int(led_buffer[3]);
}

void lcd_start_manual()
{
	lcd_goto_XY(1, 0);
	lcd_send_string("Manual mode");
}

void lcd_red_manual()
{
	lcd_goto_XY(1, 0);
	lcd_send_string("Mode: ");
	lcd_goto_XY(1, 10);
	lcd_send_int(led_buffer[2]);
	lcd_goto_XY(1, 11);
	lcd_send_int(led_buffer[3]);

	lcd_goto_XY(2, 0);
	lcd_send_string("Redtime: ");
	lcd_goto_XY(2, 10);
	lcd_send_int(led_buffer[0]);
	lcd_goto_XY(2, 11);
	lcd_send_int(led_buffer[1]);
}

void lcd_yellow_manual()
{
	lcd_goto_XY(1, 0);
	lcd_send_string("Mode: ");
	lcd_goto_XY(1, 13);
	lcd_send_int(led_buffer[2]);
	lcd_goto_XY(1, 14);
	lcd_send_int(led_buffer[3]);

	lcd_goto_XY(2, 0);
	lcd_send_string("Yellowtime: ");
	lcd_goto_XY(2, 13);
	lcd_send_int(led_buffer[0]);
	lcd_goto_XY(2, 14);
	lcd_send_int(led_buffer[1]);
}

void lcd_green_manual()
{
	lcd_goto_XY(1, 0);
	lcd_send_string("Mode: ");
	lcd_goto_XY(1, 12);
	lcd_send_int(led_buffer[2]);
	lcd_goto_XY(1, 13);
	lcd_send_int(led_buffer[3]);

	lcd_goto_XY(2, 0);
	lcd_send_string("Greentime: ");
	lcd_goto_XY(2, 12);
	lcd_send_int(led_buffer[0]);
	lcd_goto_XY(2, 13);
	lcd_send_int(led_buffer[1]);
}
