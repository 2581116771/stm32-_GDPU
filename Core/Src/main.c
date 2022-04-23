/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "MqttKit.h"
#include "onenet.h"
#include "esp8266.h"
#include "string.h"
#include "stdio.h"
#include "DS18B20.h"
#include "lcd.h"
#include "GUI.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint16_t human_flag = 0, mode = 0, key_mode = 0,  time = 0;
int dingshishijian = 0, timecount = 0;
float shedingwenduH = 27.0, shedingwenduM = 26.0, shedingwenduL = 25.0;
unsigned char *dataPtr = NULL;
uint8_t show_buf[50];


uint8_t buf_size = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_TIM2_Init();
  MX_TIM1_Init();
  MX_USART2_UART_Init();
  MX_SPI1_Init();
  MX_TIM4_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  LCD_Init();
  HAL_TIM_Base_Start(&htim2);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

  HAL_UART_Receive_IT(&huart2, (uint8_t *)UART2_temp, REC_LENGTH);


  ESP8266_Init();

  while(OneNet_DevLink())			//接入OneNET
	  HAL_Delay(500);


  sprintf(show_buf, "温度模式");
  Show_Str(0, 0, BLUE, WHITE, show_buf, 32, 0);
  sprintf(show_buf, "定时时间 %3d秒", dingshishijian);
  Show_Str(0, 120, BLUE, WHITE, show_buf, 32, 0);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  //显示定时时间
	  shedingwenduM = (shedingwenduH + shedingwenduL) / 2;
	  sprintf(show_buf, "TH %.1f, TM %.1f, TL%.1f", shedingwenduH, shedingwenduM, shedingwenduL);
	  Show_Str(0, 150, BLUE, WHITE, show_buf, 16, 0);
	  //检测并显示温度
	  DS18B20();

	  Temp_byte1 = DS18B20_Read();
	  Temp_byte2 = DS18B20_Read();
	  TEMP = (Temp_byte2<<8)|Temp_byte1;
	  Temperature = (float)TEMP/16;

	  sprintf(show_buf, "tem is %.2f", Temperature);
	  Show_Str(0, 30, BLUE, WHITE, show_buf, 32, 0);

	  //检测人体状态并显示
	  if( timecount++ < 10)
	  {
		  timecount = 0;
		  if( HAL_GPIO_ReadPin(AM312_GPIO_Port, AM312_Pin) == 1)
			  human_flag = 1;
		  else
			  human_flag = 0;
	  }

	  if(human_flag == 1)
	  {
		  sprintf(show_buf, "有人");
		  Show_Str(0, 60, BLUE, WHITE, show_buf, 32, 0);
	  }
	  else
	  {
		  sprintf(show_buf, "没人");
		  Show_Str(0, 60, BLUE, WHITE, show_buf, 32, 0);
	  }
	  dataPtr = ESP8266_GetIPD(0);
	  if(dataPtr != NULL)
		  OneNet_RevPro(dataPtr);
	  HAL_Delay(10);
	  switch(mode)
	  {
		  case 0:
		  {
			  sprintf(show_buf, "温度模式");
			  Show_Str(0, 0, BLUE, WHITE, show_buf, 32, 0);
			  if( human_flag == 1)
			  {
				  if( Temperature > shedingwenduH)
				  {
					  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 3600);
					  sprintf(show_buf, "3档  ");
					  Show_Str(0, 90, BLUE, WHITE, show_buf, 32, 0);
				  }
				  else if( Temperature < shedingwenduH && Temperature > shedingwenduM)
				  {
					  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 2400);
					  sprintf(show_buf, "2档  ");
					  Show_Str(0, 90, BLUE, WHITE, show_buf, 32, 0);
				  }
				  else if( Temperature > shedingwenduL && Temperature < shedingwenduM)
				  {
					  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 1200);
					  sprintf(show_buf, "1档  ");
					  Show_Str(0, 90, BLUE, WHITE, show_buf, 32, 0);
				  }
				  else
				  {
				  	  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 0);
				  	  sprintf(show_buf, "关闭");
				  	  Show_Str(0, 90, BLUE, WHITE, show_buf, 32, 0);
				  }
			  }
			  else
			  {
				  	  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 0);
				  	  sprintf(show_buf, "关闭");
				  	  Show_Str(0, 90, BLUE, WHITE, show_buf, 32, 0);
			  }
			  break;
		  }
		  case 1:
		  {
			  sprintf(show_buf, "手动模式");
			  Show_Str(0, 0, BLUE, WHITE, show_buf, 32, 0);
			  if( key_mode == 0)
			  {
			  	  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 0);
			  	  sprintf(show_buf, "关闭");
			  	  Show_Str(0, 90, BLUE, WHITE, show_buf, 32, 0);
			  }
			  else if(key_mode == 1)
			  {
			  	  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 1200);
			  	  sprintf(show_buf, "1档  ");
			  	  Show_Str(0, 90, BLUE, WHITE, show_buf, 32, 0);
			  }
			  else if(key_mode == 2)
			  {
			  	  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 2400);
			  	  sprintf(show_buf, "2档  ");
			  	  Show_Str(0, 90, BLUE, WHITE, show_buf, 32, 0);
			  }
			  else if(key_mode == 3)
			  {
			  	  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 3600);
			  	  sprintf(show_buf, "3档  ");
			  	  Show_Str(0, 90, BLUE, WHITE, show_buf, 32, 0);
			  }
			  break;
		  }
		  case 2:
		  {
			  sprintf(show_buf, "定时模式");
			  Show_Str(0, 0, BLUE, WHITE, show_buf, 32, 0);
			  HAL_TIM_Base_Start_IT(&htim4);
			  while( dingshishijian >= 0)
			  {
				  sprintf(show_buf, "定时时间 %2d秒", dingshishijian);
				  Show_Str(0, 120, BLUE, WHITE, show_buf, 32, 0);
			  	  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 2400);
			  	  sprintf(show_buf, "2档  ");
			  	  Show_Str(0, 90, BLUE, WHITE, show_buf, 32, 0);
			  }
			  time = 0;
		  	  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 0);
		  	  sprintf(show_buf, "关闭");
		  	  Show_Str(0, 90, BLUE, WHITE, show_buf, 32, 0);
		  	  HAL_TIM_Base_Stop_IT(&htim4);
		  	  break;
		  }
	  }

////	  if(++timeCount >= 500)									//发送时间间隔5s
////	  {
//////		  printf("OneNet_Publish\r\n");
//////		  OneNet_Publish(device_pub_topic, "MQTT Publish Test");
////		  printf( "OneNet_SendData\r\n");
////
////		  OneNet_SendData();//发送数据给onenet
////
////		  timeCount = 0;
////		  ESP8266_Clear();
////	  }
//
////	  printf("humanflag is %d\r\n", human_flag);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
    return ch;
}


void delay (uint16_t time)
{
	/* change your code here for the delay in microseconds */
	__HAL_TIM_SET_COUNTER(&htim2, 0);
	while ((__HAL_TIM_GET_COUNTER(&htim2))<time);
}





void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if(huart == &huart2)
  {
	esp8266_buf[esp8266_cnt] = UART2_temp[0];
	esp8266_cnt++;
//    if(0x0a == UART2_temp[0])
//    {
//      UART2_Rx_flg = 1;
//    }
//    if(UART2_Rx_flg)
//	{
//    	for(int i = 0;i<esp8266_cnt;i++)
//    		esp8266_buf[i] = 0;
////    	esp8266_cnt = 0;
//    	UART2_Rx_flg = 0;
//	}
	HAL_UART_Receive_IT(&huart2,(uint8_t *)UART2_temp,1);
  }
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if( GPIO_Pin == KEY1_Pin)
	{
		if( HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == 0)
		{
			mode += 1;
		}
	}
	else if( GPIO_Pin == KEY2_Pin)
	{
		if( HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin) == 0)
		{
			switch(mode)
			{
				case 0:
				{
					shedingwenduH += 1;
					break;
				}
				case 1:
				{
					key_mode += 1;
					break;
				}
				case 2:
				{
					time +=1;
					break;
				}
			}
		}
	}
	else if( GPIO_Pin == KEY3_Pin)
	{
		if( HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin) == 0)
		{
			switch(mode)
			{
				case 0:
				{
					shedingwenduL -= 1;
					break;
				}
				case 1:
				{
					key_mode -= 1;
					break;
				}
				case 2:
				{
					time -=1;
					break;
				}
			}
		}
	}


	if( mode == 3)
		mode = 0;
	if( key_mode < 0 || key_mode >3)
		key_mode = 0;
	dingshishijian = time;



//	HAL_Delay(100);
//	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_Pin);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if( htim == (&htim4) )
		--dingshishijian;
}

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
