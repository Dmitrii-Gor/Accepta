/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32f7xx_hal.h"

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
#define DO4_Pin GPIO_PIN_3
#define DO4_GPIO_Port GPIOE
#define DO9_Pin GPIO_PIN_13
#define DO9_GPIO_Port GPIOC
#define DI5_Pin GPIO_PIN_0
#define DI5_GPIO_Port GPIOF
#define DI7_Pin GPIO_PIN_1
#define DI7_GPIO_Port GPIOF
#define DI15_Pin GPIO_PIN_6
#define DI15_GPIO_Port GPIOF
#define DI13_Pin GPIO_PIN_7
#define DI13_GPIO_Port GPIOF
#define LD1_Pin GPIO_PIN_0
#define LD1_GPIO_Port GPIOB
#define DO3_Pin GPIO_PIN_0
#define DO3_GPIO_Port GPIOG
#define LD3_Pin GPIO_PIN_14
#define LD3_GPIO_Port GPIOB
#define STLK_RX_Pin GPIO_PIN_8
#define STLK_RX_GPIO_Port GPIOD
#define STLK_TX_Pin GPIO_PIN_9
#define STLK_TX_GPIO_Port GPIOD
#define DI10_Pin GPIO_PIN_11
#define DI10_GPIO_Port GPIOD
#define DI9_Pin GPIO_PIN_2
#define DI9_GPIO_Port GPIOG
#define DI11_Pin GPIO_PIN_3
#define DI11_GPIO_Port GPIOG
#define USB_PowerSwitchOn_Pin GPIO_PIN_6
#define USB_PowerSwitchOn_GPIO_Port GPIOG
#define USB_OverCurrent_Pin GPIO_PIN_7
#define USB_OverCurrent_GPIO_Port GPIOG
#define DO10_Pin GPIO_PIN_9
#define DO10_GPIO_Port GPIOC
#define USB_SOF_Pin GPIO_PIN_8
#define USB_SOF_GPIO_Port GPIOA
#define USB_VBUS_Pin GPIO_PIN_9
#define USB_VBUS_GPIO_Port GPIOA
#define DI8_Pin GPIO_PIN_10
#define DI8_GPIO_Port GPIOA
#define USB_DM_Pin GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define DI14_Pin GPIO_PIN_15
#define DI14_GPIO_Port GPIOA
#define DO15_Pin GPIO_PIN_10
#define DO15_GPIO_Port GPIOC
#define DO14_Pin GPIO_PIN_11
#define DO14_GPIO_Port GPIOC
#define DO13_Pin GPIO_PIN_12
#define DO13_GPIO_Port GPIOC
#define DI4_Pin GPIO_PIN_0
#define DI4_GPIO_Port GPIOD
#define DI6_Pin GPIO_PIN_1
#define DI6_GPIO_Port GPIOD
#define DO12_Pin GPIO_PIN_2
#define DO12_GPIO_Port GPIOD
#define DO7_Pin GPIO_PIN_5
#define DO7_GPIO_Port GPIOD
#define DO5_Pin GPIO_PIN_6
#define DO5_GPIO_Port GPIOD
#define DO6_Pin GPIO_PIN_7
#define DO6_GPIO_Port GPIOD
#define DI3_Pin GPIO_PIN_9
#define DI3_GPIO_Port GPIOG
#define DI2_Pin GPIO_PIN_10
#define DI2_GPIO_Port GPIOG
#define DO2_Pin GPIO_PIN_11
#define DO2_GPIO_Port GPIOG
#define DI1_Pin GPIO_PIN_12
#define DI1_GPIO_Port GPIOG
#define DO0_Pin GPIO_PIN_13
#define DO0_GPIO_Port GPIOG
#define DI0_Pin GPIO_PIN_15
#define DI0_GPIO_Port GPIOG
#define DO8_Pin GPIO_PIN_5
#define DO8_GPIO_Port GPIOB
#define DI12_Pin GPIO_PIN_7
#define DI12_GPIO_Port GPIOB
#define DO11_Pin GPIO_PIN_8
#define DO11_GPIO_Port GPIOB
#define DO1_Pin GPIO_PIN_1
#define DO1_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
