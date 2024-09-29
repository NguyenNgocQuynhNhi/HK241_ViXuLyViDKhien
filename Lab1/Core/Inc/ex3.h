/*
 * ex3.h
 *
 *  Created on: Sep 29, 2024
 *      Author: DEll P5530
 */

#ifndef INC_EX3_H_
#define INC_EX3_H_

uint8_t verticalStop = 0;
char slow = 0;

void RunExercise3() {
	  currentTime = HAL_GetTick();
	  if (verticalStop == 0) {
		  HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_9_Pin, GPIO_PIN_SET);	// turn on the red led of the vertical street
		  if (slow != 1) {
			  HAL_GPIO_WritePin(GPIOB, LED_6_Pin | LED_10_Pin, GPIO_PIN_SET);	// turn on the green led of the horizontal street
		  }


		  if (currentTime - previousTime >= 3000) {
			  HAL_GPIO_WritePin(GPIOB, LED_6_Pin | LED_10_Pin, GPIO_PIN_RESET);	// turn off the green led of the horizontal street
			  HAL_GPIO_WritePin(GPIOB, LED_5_Pin | LED_11_Pin, GPIO_PIN_SET);	// turn on the yellow led of the horizontal street
			  slow = 1;
		  }

		  if (currentTime - previousTime >= 5000) {
			  HAL_GPIO_WritePin(GPIOB, LED_5_Pin | LED_11_Pin, GPIO_PIN_RESET);	// turn off the yellow led of the horizontal street
			  slow = 0;
			  HAL_GPIO_WritePin(GPIOB, LED_4_Pin | LED_12_Pin, GPIO_PIN_SET);	// turn on the red led of the horizontal street

			  HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_9_Pin, GPIO_PIN_RESET);	// turn off the red led of the vertical street
			  HAL_GPIO_WritePin(GPIOB, LED_3_Pin | LED_7_Pin, GPIO_PIN_SET);	// turn on the green led of the vertical street

			  verticalStop = 1 - verticalStop;
			  previousTime = currentTime;
		  }
	  } else {
			  if (currentTime - previousTime >= 3000) {
				  HAL_GPIO_WritePin(GPIOB, LED_3_Pin | LED_7_Pin, GPIO_PIN_RESET);	// turn off the green led of the vertical street
				  HAL_GPIO_WritePin(GPIOB, LED_2_Pin | LED_8_Pin, GPIO_PIN_SET);	// turn on the yellow led of the vertical street
				  slow = 1;
			  }

			  if (currentTime - previousTime >= 5000) {
				  HAL_GPIO_WritePin(GPIOB, LED_2_Pin | LED_8_Pin, GPIO_PIN_RESET);	// turn off the yellow led of the vertical street
				  slow = 0;
				  //HAL_GPIO_WritePin(GPIOB, LED_1_Pin | LED_9_Pin, GPIO_PIN_SET);	// turn on the red led of the vertical street

				  HAL_GPIO_WritePin(GPIOB, LED_4_Pin | LED_12_Pin, GPIO_PIN_RESET);	// turn off the red led of the horizontal street
				  //HAL_GPIO_WritePin(GPIOB, LED_6_Pin | LED_10_Pin, GPIO_PIN_SET);	// turn on the green led of the horizontal street

				  verticalStop = 1 - verticalStop;
				  previousTime = currentTime;
			  }
		  }
}


#endif /* INC_EX3_H_ */
