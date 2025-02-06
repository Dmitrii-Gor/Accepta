#ifndef SRC_PARSER_SEND_COMMAND_H_
#define SRC_PARSER_SEND_COMMAND_H_

#include <cstdint>
#include "Command.h"

#define MESSAGE_SIZE 70

namespace parser
{

class Command_Send : public Command
{
public:
	Command_Send();
	virtual ~Command_Send();
	void execute ( void ) override;
	static Command_Send* parse(const char* const arg_str);

	char message[MESSAGE_SIZE];
};
}

#endif /* SRC_PARSER_SEND_COMMAND_H_ */
