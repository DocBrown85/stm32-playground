/*
 * main_module.c
 *
 *  Created on: Nov 29, 2024
 *      Author: avilla
 */



#include <stdio.h>

#include "main.h"

extern UART_HandleTypeDef huart4;

void MM_Process(void) {
	printf("Hello World!\n");
	HAL_Delay(2000);
}

/**
 * @brief  Implementation of printf() function
 * @param None
 * @retval None
 */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{
  HAL_UART_Transmit(&huart4, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
  return ch;
}
