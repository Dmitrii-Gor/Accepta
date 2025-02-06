#include "Command.h"

namespace parser
{

extern "C" void execute_command(const char *cmd_str)
{
	Command *cmd = Command::parse(cmd_str);
 	if (cmd != nullptr)
	{
		cmd->execute();
	}
}

}
