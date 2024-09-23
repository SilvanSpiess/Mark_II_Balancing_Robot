/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

#define ADCresolution 4096
#define maxPOTSpeed 4096
#define Example_PSC 1
typedef struct ProcessData_{
	uint16_t pot1;
	uint16_t pot2;
  uint16_t rotation_counter;
  uint16_t rotation_speed;
  uint16_t pot_power1;
  uint16_t pot_power2;
  uint16_t number_of_samples;
  uint16_t PSC_on;
  enum {CLOCK_WISE, COUNTER_CLOCK_WISE, SOFT_STOP, FAST_STOP} mode;
} ProcessData;

typedef struct AppData_{
	ProcessData current;
	ProcessData averaged_over_5;
} AppData;

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
#define SWITCH_CENTER_Pin GPIO_PIN_13
#define SWITCH_CENTER_GPIO_Port GPIOC
#define SWITCH_RIGHT_Pin GPIO_PIN_0
#define SWITCH_RIGHT_GPIO_Port GPIOC
#define SWITCH_LEFT_Pin GPIO_PIN_1
#define SWITCH_LEFT_GPIO_Port GPIOC
#define POT1_Pin GPIO_PIN_0
#define POT1_GPIO_Port GPIOA
#define POT2_Pin GPIO_PIN_1
#define POT2_GPIO_Port GPIOA
#define USART2_RX_Pin GPIO_PIN_3
#define USART2_RX_GPIO_Port GPIOA
#define SWITCH_UP_Pin GPIO_PIN_4
#define SWITCH_UP_GPIO_Port GPIOA
#define LCD_SCK_Pin GPIO_PIN_5
#define LCD_SCK_GPIO_Port GPIOA
#define LCD_RESET_Pin GPIO_PIN_6
#define LCD_RESET_GPIO_Port GPIOA
#define LCD_MOSI_Pin GPIO_PIN_7
#define LCD_MOSI_GPIO_Port GPIOA
#define SWITCH_DOWN_Pin GPIO_PIN_0
#define SWITCH_DOWN_GPIO_Port GPIOB
#define SPEAKER_Pin GPIO_PIN_10
#define SPEAKER_GPIO_Port GPIOB
#define LCD_CS_N_Pin GPIO_PIN_6
#define LCD_CS_N_GPIO_Port GPIOC
#define LED_GREEN_Pin GPIO_PIN_7
#define LED_GREEN_GPIO_Port GPIOC
#define LCD_A0_Pin GPIO_PIN_8
#define LCD_A0_GPIO_Port GPIOA
#define LED_BLUE_Pin GPIO_PIN_9
#define LED_BLUE_GPIO_Port GPIOA
#define DC_EN_Pin GPIO_PIN_10
#define DC_EN_GPIO_Port GPIOA
#define ROTATION_SENSOR_Pin GPIO_PIN_11
#define ROTATION_SENSOR_GPIO_Port GPIOA
#define ROTATION_SENSOR_EXTI_IRQn EXTI15_10_IRQn

/* USER CODE BEGIN Private defines */
#define DC MOTOR

#ifdef DC_MOTOR

#undef SWITCH_CENTER Pin
#undef SWITCH_CENTER_GPIO_Port
#define SWITCH_CENTER_Pin GPIO_PIN_13
#define SWITCH_CENTER_GPIO_Port GPIOC
#endif

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
