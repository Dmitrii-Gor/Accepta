#include "Parser.h"
#include <cctype>

namespace parser
{

Parser::Parser(const char *const s) :
		stp(s), curr(s)
{
	// TODO Auto-generated constructor stub

}

Parser::~Parser()
{
	// TODO Auto-generated destructor stub
}

const char* Parser::string_to_parse(void) const
{
	return stp;
}

const size_t Parser::get_string_token(char *buffer, size_t buffer_size)
{
	if (!curr)
	{
		*buffer = '\0';
		return 0;
	}

	if (!*curr)
	{
		*buffer = '\0';
		return 0;
	}

	if (!isalpha(*curr))
	{
		*buffer = '\0';
		return 0;
	}

	size_t char_cnt = 0;

	while (((isalnum(*curr)) || (*curr == '_'))
			&& (char_cnt < (buffer_size - 1)))
	{
		*buffer++ = *curr++;
		++char_cnt;
	}

	*buffer = '\0';
	return char_cnt;
}

bool Parser::skip_space(void)
{
	if (*curr == ' ')
	{
		++curr;
		return true;
	}
	else
	{
		return false;
	}
}

bool Parser::skip_assignment(void)
{
	if (*curr == '=')
	{
		++curr;
		return true;
	}
	else
	{
		return false;
	}
}

int Parser::get_int_value()
{
	if (!*curr)
	{
		return 0;
	}
	if (!isdigit(*curr))
	{
		return 0;
	}

	int result = 0;
	while (isdigit(*curr))
	{
		result *= 10;
		result += *curr++ - '0';
	}
	return result;
}

bool Parser::skip_delimiter(void)
{
	if (*curr == ',')
	{
		++curr;
		return true;
	}
	else
	{
		return false;
	}
}

bool Parser::is_empty(void) const
{
	return (*curr == '\0');
}

bool Parser::is_digit(void) const
{
	return (isdigit(*curr));
}

const char Parser::get_char_value(void)
{
	return *curr++;
}

} /* namespace parser */
