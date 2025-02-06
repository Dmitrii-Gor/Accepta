#ifndef SRC_PARSER_DATA_OUTPUT_CMD_H_
#define SRC_PARSER_DATA_OUTPUT_CMD_H_

#include <cstdint>
#include "Command.h"

namespace parser
{

class Data_Output_Cmd : public Command
{
public:
	Data_Output_Cmd();
	virtual ~Data_Output_Cmd();
	void execute( void ) override;
	static Data_Output_Cmd* parse(const char* const arg_str);

	uint8_t channel = 0;
	bool isOn = false;

private:
	static constexpr uint8_t MIN_CHANNEL = 0;
	static constexpr uint8_t MAX_CHANNEL = 15;
	static constexpr char STATE_ON = '1';
	static constexpr char STATE_OFF = '0';
};

}

#endif /* SRC_PARSER_DATA_OUTPUT_CMD_H_ */
