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
#include "usb_keycode.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#define KEY_PRESS_NB_MAX 10


#define FLAG_LAYOUT_PAGE_UP 	0b0000000000000001
#define FLAG_LAYOUT_PAGE_DOWN 	0b0000000000000010
#define FLAG_MAJLOCK_SET		0b0000000000000100
#define FLAG_SCROLLLOCK_SET		0b0000000000001000

typedef enum{
	PRESS,
	RELEASE
} ActionType;

typedef enum{
	MODIFIER,
	PAGE,
	UNICODE,
	MACRO
} KeyType;

typedef struct {
  uint8_t 		Buf[KEY_PRESS_NB_MAX];
  uint8_t		KeyNbr;
  KeyType		KeyType;
  ActionType	Action;
} KEYMSGQUEUE_OBJ_t;


typedef struct
{
	uint8_t PAGE;
	uint8_t MODIFIER;
	char	MAJ_LOCK;
	char 	SCROLL_LOCL;

} KBDglobalState;

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
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
