#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os2.h"
#include "trace.h"
#include "main_loop.h"
#include "console.h"
#include "tim.h"
#include "usart.h"
#include "parser/execute_command.h"

#define MAIN_LOOP_TASK_STACK_DEPTH 0x200UL
#define HOST_UART huart3

TaskHandle_t main_loop_task_handle;
static const char *main_loop_task_name = "main_loop";
static StackType_t main_loop_task_stack_buffer[ MAIN_LOOP_TASK_STACK_DEPTH ];
static StaticTask_t main_loop_task_TCB;

#define BUFFER_SIZE 81
static char buffer[BUFFER_SIZE];

static char get_char(void)
{
	static char cbuf;
	HAL_UART_Receive(&HOST_UART, (uint8_t *)&cbuf, 1, HAL_MAX_DELAY);
	return cbuf;
}

static const char* get_cmd_str(void)
{
	char *p = buffer;
	size_t ccnt = 0;
	char c;

	// пропустить все литеры до '#'
	do
	{
		c = get_char();
	} while (c != '#');

	*p++ = c;
	++ccnt;

	// занести командную строку в буфер
	do
	{
		c = get_char();
		if (c < ' ')
		{
			break;
		}
		*p++ = c;
		++ccnt;
	} while (ccnt < BUFFER_SIZE);
	*p = '\0';
	return buffer;
}

static void main_loop( void * pvParameters )
{
	uint16_t const red_up = 0x6A0;
	uint16_t const red_down = 0x280;
	uint16_t const white_up = 0x5D0;
	uint16_t const white_down = 0x280;
	uint16_t pos;
	TIM4 -> CCR3 = red_up;
	for (;;)
	{
		// получить командную строку от хоста
		get_cmd_str();
		// выполнить полученную строку
		execute_command(buffer);
#if 0
		vTaskDelay(5000);
		for (pos = red_up; pos > red_down; pos -= 5)
		{
			TIM4 -> CCR3 = pos;
			vTaskDelay(2);
		}
		vTaskDelay(5000);
		for (pos = red_down; pos < red_up; pos += 1)
		{
			TIM4 -> CCR3 = pos;
			vTaskDelay(2);
		}
		vTaskDelay(5000);
		for (pos = white_up; pos > white_down; pos -= 5)
		{
			TIM4 -> CCR4 = pos;
			vTaskDelay(2);
		}
		vTaskDelay(5000);
		for (pos = white_down; pos < white_up; pos += 1)
		{
			TIM4 -> CCR4 = pos;
			vTaskDelay(2);
		}
#endif
	}
}

void main_loop_create_task()
{
	main_loop_task_handle = xTaskCreateStatic(
			main_loop,
			main_loop_task_name,
			MAIN_LOOP_TASK_STACK_DEPTH,
			NULL,
			osPriorityNormal,
			main_loop_task_stack_buffer,
			&main_loop_task_TCB
			);

	if (!main_loop_task_handle)
	{
		trace(CANNOT_CREATE_TASK, main_loop_task_name);
	}
}

