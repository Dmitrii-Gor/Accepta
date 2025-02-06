#include <cctype>
#include "Parser.h"
#include <iostream>
#include "console.h"
#include <cstring>
#include "../low_level/Send_Command.h"
#include "Send_Command.h"

namespace parser
{

static Command_Send instance;


Command_Send::Command_Send() {
	// TODO Auto-generated constructor stub

}

Command_Send::~Command_Send() {
	// TODO Auto-generated destructor stub
}


void Command_Send::execute()
{
	send_command_to_device(message);
}

Command_Send* Command_Send::parse(const char* const arg_str)
{
	Parser pp(arg_str);
	if (pp.is_empty())

	{
		console_out("Arguments are empty");
		return nullptr;
	}
	if (!pp.skip_space())
	{
		console_out("Space is missing");
		return nullptr;
	}

	size_t index = 0;
	while(index < MESSAGE_SIZE -1)
	{
		char c = pp.get_char_value();
		if (c == '\0')
		{
		   break; // Прекратить инициализацию, если достигнут конец строки или новая строка
		}
		instance.message[index++] = c;
	}
	instance.message[index] = '\0';


	return &instance;
}
}
