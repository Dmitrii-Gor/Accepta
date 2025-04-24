#include <string.h>
#include "usart.h"
#include "host_link.h"

#define HOST_LINK_UART huart5

void host_link_out( const char *answer )
{
	HAL_UART_Transmit( &HOST_LINK_UART, ( uint8_t* )answer, strlen( answer ), HAL_MAX_DELAY );
}
