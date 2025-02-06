#include <cctype>
#include "Data_Input_Cmd.h"
#include "Parser.h"
#include <iostream>
#include "../low_level/digital_pin_io.h"
#include "console.h"

namespace parser
{

static Data_Input_Cmd instance;

Data_Input_Cmd::Data_Input_Cmd() {
	// TODO Auto-generated constructor stub

}

Data_Input_Cmd::~Data_Input_Cmd() {
	// TODO Auto-generated destructor stub
}

void Data_Input_Cmd::execute()
{
	static char buf[3];
	bool p = get_digital_pin(channel);
	buf[0] = p ? '1' : '0';
	buf[1] = '\0';
	console_out(buf);
}

Data_Input_Cmd* Data_Input_Cmd::parse(const char* const arg_str)
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

	// parse channel number
	if (!pp.is_digit())
	{
		console_out("Digit expected");
		return nullptr;
	}
	uint8_t chan = pp.get_int_value();
	if ((chan < Data_Input_Cmd::MIN_CHANNEL) || (chan > Data_Input_Cmd::MAX_CHANNEL))
	{
		console_out("Chan number out of bounds");
		return nullptr;
	}
	if (!pp.is_empty())	// в конце командной строки лишний мусор
	{
		console_out("Extra characters in command string");
		return nullptr;
	}

	instance.channel = chan;

	return &instance;
}

}	// namespace parser
