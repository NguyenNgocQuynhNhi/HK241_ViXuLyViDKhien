/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "global.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
//#define MAX_BUFFER_SIZE		30
//#define	TIMEOUT				3000	//ms
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//uint8_t temp = 0;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	if (huart->Instance == USART2) {
		buffer[index_buffer++] = temp;	// Add received byte to buffer
		if (index_buffer >= MAX_BUFFER_SIZE) {
			index_buffer = 0;	// Wrap around if buffer overflows
		}
		buffer_flag = 1;	// Signal new data in buffer
		HAL_UART_Receive_IT(&huart2, &temp, 1);		// Re-enable UART receive interrupt
	}

	//-------------Example code---------------------
//	if (huart->Instance == USART2) {
//		HAL_UART_Transmit(&huart2, &temp, 1, 50);
//		HAL_UART_Receive_IT(&huart2, &temp, 1);
//	}
	//-------------Example code---------------------
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart2, &temp, 1);
  HAL_ADC_Start(&hadc1);
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

//  uint32_t ADC_value = 0;
//  char str[20];


  setTimerForWaitingOK(2000);
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  if (buffer_flag == 1) {
		  command_parser_fsm();		//Parse received buffer
		  buffer_flag = 0;

		  //test
		  HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
	  }
	  uart_communication_fsm();
//
//	  HAL_Delay(500);

	  //---------------TEST TIMER-----------------------
//	  if (waitOK_flag == 1) {
//		  setTimerForWaitingOK(2000);
//		  //TODO:
//		  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//	  }
	  //---------------TEST TIMER-----------------------

	  //---------------Example code--------------------------
//	  HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
//	  ADC_value = HAL_ADC_GetValue(&hadc1);
//	  HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!ADC=%ld#\r\n", ADC_value), 1000);
//	  HAL_Delay(500);
	  //---------------Example code--------------------------
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin|LED_GREEN_Pin|LED_RED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_YELLOW_Pin LED_GREEN_Pin LED_RED_Pin */
  GPIO_InitStruct.Pin = LED_YELLOW_Pin|LED_GREEN_Pin|LED_RED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

//void command_parser_fsm() {
//    switch (cmd_state) {
//        case CMD_WAIT:
//            if (buffer[0] == '!') {
//                cmd_state = CMD_RECEIVING;
//                cmd_index = 0;
//            }
//
//            break;
//        case CMD_RECEIVING:
//            if (buffer[index_buffer - 1] == '#') {
//                cmd_state = CMD_DONE;
//                cmd_buffer[cmd_index++] = '\0'; // Kết thúc chuỗi
//            } else if (cmd_index < MAX_BUFFER_SIZE) {
//                cmd_buffer[cmd_index++] = buffer[index_buffer - 1];
//            } else {
//                cmd_state = CMD_WAIT; // Quá tải, reset
//            }
//            break;
//        case CMD_DONE:
//            // Xử lý lệnh
//            if (strcmp((char*)cmd_buffer, "RST") == 0) {
//                // Thực hiện lệnh RST
//            } else if (strcmp((char*)cmd_buffer, "OK") == 0) {
//                // Thực hiện lệnh OK
//            }
//            cmd_state = CMD_WAIT;
//            break;
//    }
//}
//
//            uint16_t adc_value = 0; // Lấy giá trị ADC
//            char adc_response[20];
//        	uint32_t currRed = 0;
//        	uint32_t prevRed = 0;
//        	uint32_t currGreen = 0;
//        	uint32_t prevGreen = 0;
//void uart_communication_fsm() {
//    switch (uart_state) {
//        case UART_IDLE:
//            if (strcmp((char*)cmd_buffer, "RST") == 0) {
//                uart_state = UART_SENDING;
//            }
//            break;
//        case UART_SENDING:
//        	currRed = HAL_GetTick();
//        	prevRed = 0;
//        	if (currRed - prevRed >= 500) {
//        		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//        		prevRed = currRed;
//        	}
//
////            uint16_t adc_value = HAL_ADC_GetValue(&hadc1); // Lấy giá trị ADC
////            char adc_response[20];
//            adc_value = HAL_ADC_GetValue(&hadc1); // Lấy giá trị ADC
////            adc_response[20];
//            sprintf(adc_response, "!ADC=%d#\r\n", adc_value);
//            HAL_UART_Transmit(&huart2, (uint8_t*)adc_response, strlen(adc_response), HAL_MAX_DELAY);
//            timeout_start = HAL_GetTick(); // Lưu th�?i điểm bắt đầu ch�?
//            uart_state = UART_WAIT_OK;
//            break;
//        case UART_WAIT_OK:
//        	currGreen = HAL_GetTick();
//			prevGreen = 0;
//			if (currGreen - prevGreen >= 500) {
//				HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
//				prevGreen = currGreen;
//			}
//
//
//            if (strcmp((char*)cmd_buffer, "OK") == 0) {
//                uart_state = UART_IDLE;
//                HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
//            } else if (HAL_GetTick() - timeout_start > 3000) {
//                // Timeout, gửi lại dữ liệu
//                char resend_response[20];
//                sprintf(resend_response, "!ADC=%d#\r\n", adc_value);
//                HAL_UART_Transmit(&huart2, (uint8_t*)resend_response, strlen(resend_response), HAL_MAX_DELAY);
//                timeout_start = HAL_GetTick(); // Reset th�?i gian ch�?
//            }
//            break;
//    }
//}


//void send_adc_value(void)
//{
//	adc_value = HAL_ADC_GetValue(&hadc1);
//
//	sprintf(adc_response, "!ADC = %ld#\r\n", adc_value);
//	HAL_UART_Transmit(&huart2, (uint8_t *)adc_response, strlen(adc_response), 1000);
//}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
