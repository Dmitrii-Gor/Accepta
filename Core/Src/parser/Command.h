#ifndef SRC_PARSER_COMMAND_H_
#define SRC_PARSER_COMMAND_H_

#include "console.h"

namespace parser
{

class Command {

public:
	virtual ~Command();
	static constexpr int COMMAND_STRING_LENGHT = 100;
	static constexpr int BUFFER_SIZE = COMMAND_STRING_LENGHT + 1;
	static Command* parse( const char* const cmd_str );
	virtual void execute( void ) = 0;

protected:
	Command();
};

}

#endif /* SRC_PARSER_COMMAND_H_ */
