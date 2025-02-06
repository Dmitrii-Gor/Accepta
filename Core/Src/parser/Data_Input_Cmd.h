#ifndef SRC_PARSER_DATA_INPUT_CMD_H_
#define SRC_PARSER_DATA_INPUT_CMD_H_

#include <cstdint>
#include "Command.h"

namespace parser
{

class Data_Input_Cmd : public Command
{
public:
	Data_Input_Cmd();
	virtual ~Data_Input_Cmd();
	void execute( void ) override;
	static Data_Input_Cmd* parse(const char* const arg_str);

	uint8_t channel = 0;

private:
	static constexpr uint8_t MIN_CHANNEL = 0;
	static constexpr uint8_t MAX_CHANNEL = 15;
};

}

#endif /* SRC_PARSER_DATA_INPUT_CMD_H_ */
