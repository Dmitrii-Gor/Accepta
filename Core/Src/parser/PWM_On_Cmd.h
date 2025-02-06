#ifndef SRC_PARSER_PWM_ON_CMD_H_
#define SRC_PARSER_PWM_ON_CMD_H_

#include <cstdint>
#include "Command.h"

namespace parser
{

class PWM_On_Cmd : public Command
{
public:
	PWM_On_Cmd();
	virtual ~PWM_On_Cmd();
	void execute( void ) override;
	static PWM_On_Cmd* parse(const char* const arg_str);

	uint8_t channel = 0;
	bool isOn = false;

private:
	static constexpr uint8_t MIN_CHANNEL = 0;
	static constexpr uint8_t MAX_CHANNEL = 1;
	static constexpr char STATE_ON = '1';
	static constexpr char STATE_OFF = '0';
};

}

#endif /* SRC_PARSER_PWM_ON_CMD_H_ */
