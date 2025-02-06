#include <cctype>
#include "Data_Output_Cmd.h"
#include "Parser.h"
#include <iostream>
#include "../low_level/digital_pin_io.h"
#include "console.h"

namespace parser
{

static Data_Output_Cmd instance;

Data_Output_Cmd::Data_Output_Cmd() {
	// TODO Auto-generated constructor stub

}

Data_Output_Cmd::~Data_Output_Cmd() {
	// TODO Auto-generated destructor stub
}

void Data_Output_Cmd::execute()
{
	set_digital_pin(channel, isOn);
}

Data_Output_Cmd* Data_Output_Cmd::parse(const char* const arg_str)
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
	if ((chan < Data_Output_Cmd::MIN_CHANNEL) || (chan > Data_Output_Cmd::MAX_CHANNEL))
	{
		console_out("Chan number out of bounds");
		return nullptr;
	}
	if (!pp.skip_assignment())
	{
		console_out("assignment sign is missing");
		return nullptr;
	}
	char state = pp.get_char_value();
	if (!((state == Data_Output_Cmd::STATE_OFF) || (state == Data_Output_Cmd::STATE_ON)))
	{
		console_out("State is wrong");
		return nullptr;
	}
	if (!pp.is_empty())	// в конце командной строки лишний мусор
	{
		console_out("Extra characters in command string");
		return nullptr;
	}

	instance.channel = chan;
	instance.isOn = (state == Data_Output_Cmd::STATE_ON);

	return &instance;
}

}	// namespace parser
