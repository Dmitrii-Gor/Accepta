#include <cctype>
#include "PWM_On_Cmd.h"
//#include "main.h"
//#include "tim.h"

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
//	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
}

PWM_On_Cmd* PWM_On_Cmd::parse(const char* const arg_str)
{
	const char *p = arg_str;
	if (*p == '\0')
	{
		console_out("Arguments are empty");
		return nullptr;
	}
	if (*p++ != ' ')
	{
		console_out("Space is missing");
		return nullptr;
	}

	// parse channel number
	char c = *p++;
	if (!isdigit(c))
	{
		console_out("Digit expected");
		return nullptr;
	}
	uint8_t chan = c - '0';
	if ((chan < PWM_On_Cmd::MIN_CHANNEL) || (chan > PWM_On_Cmd::MAX_CHANNEL))
	{
		console_out("Chan number out of bounds");
		return nullptr;
	}
	if (*p++ != ',')
	{
		console_out("Comma is missing");
		return nullptr;
	}
	char state = *p++;
	if (!((state == PWM_On_Cmd::STATE_OFF) || (state == PWM_On_Cmd::STATE_ON)))
	{
		console_out("State is wrong");
		return nullptr;
	}

	instance.channel = chan;
	instance.isOn = (state == PWM_On_Cmd::STATE_ON);

	return &instance;
}

}	// namespace parser
