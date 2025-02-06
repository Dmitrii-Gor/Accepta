#include "usart.h"
#include <string.h>
#include <stdio.h>

#define TIMEOUT 4000


void command_receive_cmd(uint32_t baud_rate, const char* str, const char* expected_message)
{

	HAL_UART_Abort(&huart6);
    HAL_UART_DeInit(&huart6);
    huart6.Init.BaudRate = baud_rate;

    if (HAL_UART_Init(&huart6) != HAL_OK)
    {
    	HAL_UART_Transmit(&huart3, (uint8_t*)"error\n\r", 7, HAL_MAX_DELAY);
    }



	uint8_t rx_response_length = strlen(expected_message);
	uint8_t buffer[rx_response_length+1];

	HAL_UART_Transmit(&huart6, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);


    if (HAL_UART_Receive(&huart6, buffer, rx_response_length, TIMEOUT) == HAL_OK) {

    	buffer[rx_response_length+1] = '\0';
        HAL_UART_Transmit(&huart3, buffer, strlen((char*)buffer), HAL_MAX_DELAY);
        if (strncmp((char*)buffer, expected_message, rx_response_length) == 0) {
            HAL_UART_Transmit(&huart3, (uint8_t*)"\r\nResponse OK\n\r", 13, HAL_MAX_DELAY);
        }
        else {
            HAL_UART_Transmit(&huart3, (uint8_t*)"Response Mismatch\r\n", 19, HAL_MAX_DELAY);
        }
    }
    else {
        HAL_UART_Transmit(&huart3, (uint8_t*)"No Response\r\n", 13, HAL_MAX_DELAY);
    }

	memset(buffer, 0, sizeof(buffer));
}


