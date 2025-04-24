#include <cctype>
#include "PWM_On_Cmd.h"
#include "Parser.h"
#include "../low_level/pwm_io.h"

namespace parser
{

static PWM_On_Cmd instance;

PWM_On_Cmd::PWM_On_Cmd() {
	// TODO Auto-generated constructor stub

}

PWM_On_Cmd::~PWM_On_Cmd() {
	// TODO Auto-generated destructor stub
}

void PWM_On_Cmd::execute()
{
	pwm_set_state_with_width(channel, isOn, pulse_width);
}

PWM_On_Cmd* PWM_On_Cmd::parse(const char* const arg_str)
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
	if ((chan < PWM_On_Cmd::MIN_CHANNEL) || (chan > PWM_On_Cmd::MAX_CHANNEL))
	{
		console_out("Chan number out of bounds");
		return nullptr;
	}

	// parse channel state
	if (!parser.skip_delimiter()) {
		console_out("Comma is missing");
		return nullptr;
	}
	if (!parser.is_digit()) {
			console_out("Digit expected");
			return nullptr;
	}
	int state = parser.get_int_value();
	if (!((state == PWM_On_Cmd::STATE_OFF) || (state == PWM_On_Cmd::STATE_ON)))
	{
		console_out("State is wrong");
		return nullptr;
	}

	instance.isOn = static_cast<bool>(state);

	if(state == PWM_On_Cmd::STATE_OFF) {
		instance.pulse_width = 0;
		instance.channel = chan;
		instance.isOn = (state == PWM_On_Cmd::STATE_ON);
		return &instance;
	}

	// parse pulse width if state is on

	if (!parser.skip_delimiter()) {
		console_out("Comma is missing");
		return nullptr;
	}

	if (!parser.is_digit()) {
			console_out("Digit expected");
			return nullptr;
	}
	int pulse_width = parser.get_int_value();


	instance.pulse_width = static_cast<uint16_t>(pulse_width);
	instance.channel = chan;

	return &instance;
}

}	// namespace parser
