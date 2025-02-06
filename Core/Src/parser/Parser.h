#ifndef SRC_PARSER_PARSER_H_
#define SRC_PARSER_PARSER_H_

#include <cstring>

namespace parser
{

class Parser
{
public:
	Parser(const char * consts);
	virtual ~Parser();

	const char* string_to_parse(void) const;
	const size_t get_string_token(char *buffer, size_t buffer_size);
	int get_int_value(void);
	const char get_char_value(void);
	bool skip_space(void);
	bool skip_assignment(void);
	bool skip_delimiter(void);
	bool is_empty(void) const;
	bool is_digit(void) const;

private:
	const char* const stp;
	const char* curr;
};

} /* namespace parser */

#endif /* SRC_PARSER_PARSER_H_ */
