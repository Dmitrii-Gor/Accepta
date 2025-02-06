#include "Receive_Command.h"

#include <cctype>
#include "Parser.h"
#include <iostream>
#include "console.h"
#include "../low_level/Uart_Receive.h"

namespace parser
{

static Receive_Command instance;

Receive_Command::Receive_Command() {
	// TODO Auto-generated constructor stub

}

Receive_Command::~Receive_Command() {
	// TODO Auto-generated destructor stub
}

void Receive_Command::execute()
{
	command_receive_cmd(message);
}

Receive_Command* Receive_Command::parse(const char* const arg_str)
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

}	// namespace parser
