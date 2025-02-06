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
	set_pwm_width(channel, angle, MIN_WIDTH, MAX_WIDTH, MAX_ANGLE);
}

Srv_Mov_Cmd* Srv_Mov_Cmd::parse(const char* const arg_str)
{
	Parser parser(arg_str);

	if (parser.is_empty()) {
		console_out("Arguments are empty");
		return nullptr;
	}
	if (!parser.skip_space()) {
		console_out("Space is missing");
		return nullptr;
	}

	// parse channel number
	if (!parser.is_digit()) {
		console_out("Digit expected");
		return nullptr;
	}
	int chan = parser.get_int_value();
	if ((chan < Srv_Mov_Cmd::MIN_CHANNEL) || (chan > Srv_Mov_Cmd::MAX_CHANNEL)) {
		console_out("Chan number out of bounds");
		return nullptr;
	}
	instance.channel = static_cast<uint8_t>(chan);
	if (!parser.skip_assignment()) {
		console_out("Assignment is missing");
		return nullptr;
	}
	//

	// parse angle
	if (!parser.is_digit()) {
		console_out("Digit expected");
		return nullptr;
	}
	int angle = parser.get_int_value();
	if (angle > 360) {
		console_out("Angle is out of bounds");
		return nullptr;
	}
	instance.angle = static_cast<uint16_t>(angle);
	//

	//parse min width
	if (!parser.skip_space()) {
		console_out("Space is missing");
		return nullptr;
	}
	if (!parser.is_digit()) {
		console_out("Digit expected");
		return nullptr;
	}
	int MIN_WIDTH = parser.get_int_value();
	instance.MIN_WIDTH = static_cast<uint16_t>(MIN_WIDTH);
	//

	// Parse max width
	if (!parser.skip_space()) {
		console_out("Space is missing");
		return nullptr;
	}
	if (!parser.is_digit()) {
		console_out("Digit expected");
		return nullptr;
	}

	int MAX_WIDTH = parser.get_int_value();
	instance.MAX_WIDTH = static_cast<uint16_t>(MAX_WIDTH);
	//

	// Parse max angle
	if (!parser.skip_space()) {
		console_out("Space is missing");
		return nullptr;
	}
	if (!parser.is_digit()) {
		console_out("Digit expected");
		return nullptr;
	}
	int MAX_ANGLE = parser.get_int_value();
	if (angle > 360) {
		console_out("Angle is out of bounds");
		return nullptr;
	}
	instance.MAX_ANGLE = static_cast<uint16_t>(MAX_ANGLE);


	return &instance;
}


} /* namespace parser */
