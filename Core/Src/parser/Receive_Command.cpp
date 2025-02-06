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
	command_receive_cmd(baud_rate, message, expected_message);
}

Receive_Command* Receive_Command::parse(const char* const arg_str)
{
	Parser pp(arg_str);

	if (pp.is_empty()) {
		console_out("Arguments are empty");
		return nullptr;
	}
	if (!pp.skip_assignment())
	{
		console_out("assignment sign is missing");
		return nullptr;
	}
	if (!pp.is_digit())
	{
		console_out("Digit expected");
		return nullptr;
	}
	uint32_t baud_rate = pp.get_int_value();
	instance.baud_rate = static_cast<uint32_t>(baud_rate);


	if (!pp.skip_space()) {
			console_out("Space is missing");
			return nullptr;
	}

	size_t index_1 = 0, index_2 = 0;
	uint8_t flag_hash_end = 0;
	while(index_1 < MESSAGE_SIZE/2)
	{
		char c = pp.get_char_value();

		if(c == '>') {
			if (!pp.skip_space()) {
				console_out("Space is missing");
				return nullptr;
			}

			if (pp.is_empty()) {
				console_out("Arguments are empty");
				return nullptr;
			}

			while(index_2 < MESSAGE_SIZE/2){
				char c = pp.get_char_value();

				instance.expected_message[index_2++] = c;
				if (c == '\0') {
					flag_hash_end = 1;
					break;
				}
			}
		}

		if(flag_hash_end) {
			break;
		}
		instance.message[index_1++] = c;

	}

	if(!flag_hash_end) {
		console_out("Hash skipped");
		return nullptr;
	}

    instance.message[index_1] = '\0';
    instance.expected_message[index_2] = '\0';

	return &instance;
}

}	// namespace parser
