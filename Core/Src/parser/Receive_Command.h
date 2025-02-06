#ifndef SRC_PARSER_RECEIVE_COMMAND_H_
#define SRC_PARSER_RECEIVE_COMMAND_H_


#include <cstdint>
#include "Command.h"

#define MESSAGE_SIZE 100


namespace parser
{

class Receive_Command : public Command
{
	public:
	Receive_Command();
		virtual ~Receive_Command();
		void execute ( void ) override;
		static Receive_Command* parse(const char* const arg_str);

	char message[MESSAGE_SIZE];
	char expected_message[MESSAGE_SIZE];
	uint32_t baud_rate = 0;
};

}

#endif /* SRC_PARSER_RECEIVE_COMMAND_H_ */
