#include <string.h>
#include "usart.h"
#include "console.h"

#define CONSOLE_UART huart3

void console_out( const char *msg )
{
	HAL_UART_Transmit( &CONSOLE_UART, ( uint8_t* )msg, strlen( msg ), HAL_MAX_DELAY );
}
