#ifndef SRC_PARSER_SRV_MOV_CMD_H_
#define SRC_PARSER_SRV_MOV_CMD_H_

#include <cstdint>
#include "Command.h"

namespace parser
{

class Srv_Mov_Cmd: public Command
{
public:
	Srv_Mov_Cmd();
	virtual ~Srv_Mov_Cmd();
	void execute( void ) override;
	static Srv_Mov_Cmd* parse(const char* const arg_str);

	uint8_t channel = 0;
	uint16_t angle = 0;
	uint16_t MIN_WIDTH = 0;
	uint16_t MAX_WIDTH = 0;
	uint16_t MAX_ANGLE = 0;

private:
	static constexpr uint8_t MIN_CHANNEL = 0;
	static constexpr uint8_t MAX_CHANNEL = 1;
};

} /* namespace parser */

#endif /* SRC_PARSER_SRV_MOV_CMD_H_ */
