///*
// * led7segments.c
// *
// *  Created on: Nov 10, 2024
// *      Author: DEll P5530
// */
//
//#include "led7segments.h"
//
//void display0() {
//	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_SET);
//}
//
////void Display0() {
////	HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_8_GPIO_Port, SEG_8_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_9_GPIO_Port, SEG_9_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_10_GPIO_Port, SEG_10_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_11_GPIO_Port, SEG_11_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_12_GPIO_Port, SEG_12_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_13_GPIO_Port, SEG_13_Pin, GPIO_PIN_SET);
////}
//
//void display1() {
//	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//
//	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_SET);
//}
//
////void Display1() {
////	HAL_GPIO_WritePin(SEG_8_GPIO_Port, SEG_8_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_9_GPIO_Port, SEG_9_Pin, GPIO_PIN_RESET);
////
////	HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, GPIO_PIN_SET);
////	HAL_GPIO_WritePin(SEG_10_GPIO_Port, SEG_10_Pin, GPIO_PIN_SET);
////	HAL_GPIO_WritePin(SEG_11_GPIO_Port, SEG_11_Pin, GPIO_PIN_SET);
////	HAL_GPIO_WritePin(SEG_12_GPIO_Port, SEG_12_Pin, GPIO_PIN_SET);
////	HAL_GPIO_WritePin(SEG_13_GPIO_Port, SEG_13_Pin, GPIO_PIN_SET);
////}
//
//void display2() {
//	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//
//	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_SET);
//}
//
////void Display2() {
////	HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_8_GPIO_Port, SEG_8_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_10_GPIO_Port, SEG_10_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_11_GPIO_Port, SEG_11_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_13_GPIO_Port, SEG_13_Pin, GPIO_PIN_RESET);
////
////	HAL_GPIO_WritePin(SEG_9_GPIO_Port, SEG_9_Pin, GPIO_PIN_SET);
////	HAL_GPIO_WritePin(SEG_12_GPIO_Port, SEG_12_Pin, GPIO_PIN_SET);
////}
//
//void display3() {
//	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_SET);
//
//	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//}
//
////void Display3() {
////	HAL_GPIO_WritePin(SEG_11_GPIO_Port, SEG_11_Pin, GPIO_PIN_SET);
////	HAL_GPIO_WritePin(SEG_12_GPIO_Port, SEG_12_Pin, GPIO_PIN_SET);
////
////	HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_8_GPIO_Port, SEG_8_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_9_GPIO_Port, SEG_9_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_10_GPIO_Port, SEG_10_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_13_GPIO_Port, SEG_13_Pin, GPIO_PIN_RESET);
////}
//
//void display4() {
//	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
//
//	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//}
//
////void Display4() {
////	HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, GPIO_PIN_SET);
////	HAL_GPIO_WritePin(SEG_10_GPIO_Port, SEG_10_Pin, GPIO_PIN_SET);
////	HAL_GPIO_WritePin(SEG_11_GPIO_Port, SEG_11_Pin, GPIO_PIN_SET);
////
////	HAL_GPIO_WritePin(SEG_8_GPIO_Port, SEG_8_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_9_GPIO_Port, SEG_9_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_12_GPIO_Port, SEG_12_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_13_GPIO_Port, SEG_13_Pin, GPIO_PIN_RESET);
////}
//
//void display5() {
//	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
//
//	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//}
//
////void Display5() {
////	HAL_GPIO_WritePin(SEG_8_GPIO_Port, SEG_8_Pin, GPIO_PIN_SET);
////	HAL_GPIO_WritePin(SEG_11_GPIO_Port, SEG_11_Pin, GPIO_PIN_SET);
////
////	HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_9_GPIO_Port, SEG_9_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_10_GPIO_Port, SEG_10_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_12_GPIO_Port, SEG_12_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_13_GPIO_Port, SEG_13_Pin, GPIO_PIN_RESET);
////}
//
//void display6() {
//	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_SET);
//
//	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//}
//
////void Display6() {
////	HAL_GPIO_WritePin(SEG_8_GPIO_Port, SEG_8_Pin, GPIO_PIN_SET);
////
////	HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_9_GPIO_Port, SEG_9_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_10_GPIO_Port, SEG_10_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_11_GPIO_Port, SEG_11_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_12_GPIO_Port, SEG_12_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_13_GPIO_Port, SEG_13_Pin, GPIO_PIN_RESET);
////}
//
//void display7() {
//	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//
//	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_SET);
//}
//
////void Display7() {
////	HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_8_GPIO_Port, SEG_8_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_9_GPIO_Port, SEG_9_Pin, GPIO_PIN_RESET);
////
////	HAL_GPIO_WritePin(SEG_10_GPIO_Port, SEG_10_Pin, GPIO_PIN_SET);
////	HAL_GPIO_WritePin(SEG_11_GPIO_Port, SEG_11_Pin, GPIO_PIN_SET);
////	HAL_GPIO_WritePin(SEG_12_GPIO_Port, SEG_12_Pin, GPIO_PIN_SET);
////	HAL_GPIO_WritePin(SEG_13_GPIO_Port, SEG_13_Pin, GPIO_PIN_SET);
////}
//
//void display8() {
//	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//}
//
////void Display8() {
////	HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_8_GPIO_Port, SEG_8_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_9_GPIO_Port, SEG_9_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_10_GPIO_Port, SEG_10_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_11_GPIO_Port, SEG_11_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_12_GPIO_Port, SEG_12_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_13_GPIO_Port, SEG_13_Pin, GPIO_PIN_RESET);
////}
//
//void display9() {
//	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//}
//
////void Display9() {
////	HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_8_GPIO_Port, SEG_8_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_9_GPIO_Port, SEG_9_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_10_GPIO_Port, SEG_10_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_11_GPIO_Port, SEG_11_Pin, GPIO_PIN_SET);
////	HAL_GPIO_WritePin(SEG_12_GPIO_Port, SEG_12_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(SEG_13_GPIO_Port, SEG_13_Pin, GPIO_PIN_RESET);
////}
//
//void display7SEG(int num) {
////	HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin | EN4_Pin, GPIO_PIN_RESET);	//turn on all 7-segment leds
//	if (num == 0) {
//		display0();
//	}
//	else if (num == 1) {
//		display1();
//	}
//	else if (num == 2) {
//		display2();
//	}
//	else if (num == 3) {
//		display3();
//	}
//	else if (num == 4) {
//		display4();
//	}
//	else if (num == 5) {
//		display5();
//	}
//	else if (num == 6) {
//		display6();
//	}
//	else if (num == 7) {
//		display7();
//	}
//	else if (num == 8) {
//		display8();
//	}
//	else if (num == 9) {
//		display9();
//	}
//}
//
//// SEG_7 -> SEG_13
////void Display7SEG(int num) {
////	HAL_GPIO_WritePin(GPIOA, EN3_Pin | EN4_Pin, GPIO_PIN_RESET);
////	if (num == 0) {
////		Display0();
////	}
////	else if (num == 1) {
////		Display1();
////	}
////	else if (num == 2) {
////		Display2();
////	}
////	else if (num == 3) {
////		Display3();
////	}
////	else if (num == 4) {
////		Display4();
////	}
////	else if (num == 5) {
////		Display5();
////	}
////	else if (num == 6) {
////		Display6();
////	}
////	else if (num == 7) {
////		Display7();
////	}
////	else if (num == 8) {
////		Display8();
////	}
////	else if (num == 9) {
////		Display9();
////	}
////}
