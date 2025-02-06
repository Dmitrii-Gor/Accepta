#include "console.h"
#include "trace.h"
#include "main.h"

static const char* whitespace = " ";
static const char* newline = "\n";

const char* error_message_table[ MAX_ERROR_CODE ] =
{
	"None",
	"Cannot create task"
};

void trace( const errorcode_t err_code, const char* msg )
{
	console_out(error_message_table[ err_code ]);
	console_out(whitespace);
	console_out(msg);
	console_out(newline);

	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
}
