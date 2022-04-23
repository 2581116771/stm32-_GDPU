/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY2_Pin GPIO_PIN_1
#define KEY2_GPIO_Port GPIOA
#define KEY2_EXTI_IRQn EXTI1_IRQn
#define KEY3_Pin GPIO_PIN_4
#define KEY3_GPIO_Port GPIOA
#define KEY3_EXTI_IRQn EXTI4_IRQn
#define DC_Pin GPIO_PIN_0
#define DC_GPIO_Port GPIOB
#define RST_Pin GPIO_PIN_1
#define RST_GPIO_Port GPIOB
#define CS_Pin GPIO_PIN_2
#define CS_GPIO_Port GPIOB
#define KEY1_Pin GPIO_PIN_13
#define KEY1_GPIO_Port GPIOA
#define KEY1_EXTI_IRQn EXTI15_10_IRQn
#define DS18B20_Pin GPIO_PIN_6
#define DS18B20_GPIO_Port GPIOB
#define AM312_Pin GPIO_PIN_7
#define AM312_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
void delay (uint16_t time);
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
