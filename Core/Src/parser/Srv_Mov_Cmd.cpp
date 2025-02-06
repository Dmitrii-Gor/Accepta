#include <cctype>
#include "Srv_Mov_Cmd.h"
#include "Parser.h"
#include "../low_level/pwm_io.h"

namespace parser
{

static Srv_Mov_Cmd instance;

Srv_Mov_Cmd::Srv_Mov_Cmd()
{
	// TODO Auto-generated constructor stub

}

Srv_Mov_Cmd::~Srv_Mov_Cmd()
{
	// TODO Auto-generated destructor stub
}

void Srv_Mov_Cmd::execute(void)
{
	set_pwm_width(channel, degree_to_width(angle));
}

Srv_Mov_Cmd* Srv_Mov_Cmd::parse(const char* const arg_str)
{
	Parser parser(arg_str);

	if (parser.is_empty())
	{
		console_out("Arguments are empty");
		return nullptr;
	}
	if (!parser.skip_space())
	{
		console_out("Space is missing");
		return nullptr;
	}

	// parse channel number
	if (!parser.is_digit())
	{
		console_out("Digit expected");
		return nullptr;
	}
	int chan = parser.get_int_value();
	if ((chan < Srv_Mov_Cmd::MIN_CHANNEL) || (chan > Srv_Mov_Cmd::MAX_CHANNEL))
	{
		console_out("Chan number out of bounds");
		return nullptr;
	}
	instance.channel = static_cast<uint8_t>(chan);
	if (!parser.skip_assignment())
	{
		console_out("Assignment is missing");
		return nullptr;
	}

	// parse angle
	if (!parser.is_digit())
	{
		console_out("Digit expected");
		return nullptr;
	}
	int angle = parser.get_int_value();
	if (angle > MAX_ANGLE)
	{
		console_out("Angle is out of bounds");
		return nullptr;
	}
	instance.angle = static_cast<uint16_t>(angle);

	return &instance;
}

uint16_t Srv_Mov_Cmd::degree_to_width(uint16_t angle)
{
	return angle * 10 + MIN_WIDTH;
}


} /* namespace parser */
