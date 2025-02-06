#include "usart.h"
#include <string.h>
#include "Send_Command.h"

#define BUFFER_SIZE 15
#define TIMEOUT 5000
uint8_t buffer[BUFFER_SIZE];

void command_receive_cmd(const char* str)
{
	HAL_UART_Receive_IT(&huart6, buffer, BUFFER_SIZE);
	open_terminal_linux();
	send_command_to_device(str);


	HAL_UART_Transmit( &huart3, buffer, BUFFER_SIZE, HAL_MAX_DELAY);
	close_terminal_linux();
	HAL_UART_AbortReceive_IT(&huart6);
	memset(buffer, 0, sizeof(buffer));
}
