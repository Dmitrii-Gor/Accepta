#include "Command.h"
#include "PWM_On_Cmd.h"
#include "Data_Output_Cmd.h"
#include "Data_Input_Cmd.h"
#include "Srv_Mov_Cmd.h"
#include <cstring>
#include <iostream>

#include "Receive_Command.h"
#include "Send_Command.h"

namespace parser
{

static const char *DO_CMD = "DO";
static const char *DI_CMD = "DI";
static const char *PWM_ON_CMD = "PWM_ON";
static const char *SRV_CMD = "SRV";
static const char *CS = "CS";
static const char *CR = "CR";

Command::~Command()
{
	// TODO Auto-generated destructor stub
}

Command::Command()
{
	// TODO Auto-generated constructor stub

}

Command* Command::parse(const char *const cmd_str)
{
	if (cmd_str == nullptr)
	{
		return nullptr;
	}
	if (*cmd_str == '\0')
	{
		return nullptr;
	}
	if (*cmd_str != '#')
	{
		return nullptr;
	}

	// командная строка начинается с литеры '#'
	const char *p = cmd_str + 1;
	if (!strncmp(p, DO_CMD, strlen(DO_CMD)))	// команда DO Вид: #D0 номер_пина=значение
	{
		p += strlen(DO_CMD);
		return Data_Output_Cmd::parse(p);
	}
	else if (!strncmp(p, DI_CMD, strlen(DI_CMD)))	// команда DI Вид: #DI номер_пина
	{
		p += strlen(DI_CMD);
		return Data_Input_Cmd::parse(p);
	}
	else if (!strncmp(p, CS, strlen(CS))) // команда CS(Command Send) Вид: #CS текст / #CS текст > текст
	{
		p += strlen(CS);
		return Command_Send::parse(p);
	}
	else if (!strncmp(p, CR, strlen(CR))) // команда CR(Command Receive) Вид: #CR=baud_rate текст > текст_ожидаемый_в_ответе
	{
		p += strlen(CR);
		return Receive_Command::parse(p);
	}
	else if (!strncmp(p, PWM_ON_CMD, strlen(PWM_ON_CMD)))	// команда PWM_ON
	{
		p += strlen(PWM_ON_CMD);
		return PWM_On_Cmd::parse(p);
	}
	else if (!strncmp(p, SRV_CMD, strlen(SRV_CMD)))	// команда SRV Вид: #SRV номер_канала=угол мин_значение_мкс макс_значение_мкс макс_угол
	{
		p += strlen(SRV_CMD);
		return Srv_Mov_Cmd::parse(p);
	}

	std::cout << "NULL!\n";
	return nullptr;
}

}
