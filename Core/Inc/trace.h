#ifndef INC_TRACE_H_
#define INC_TRACE_H_

enum ERROR_CODE
{
	NONE,
	CANNOT_CREATE_TASK,

	MAX_ERROR_CODE
};

typedef enum ERROR_CODE errorcode_t;

void trace( const errorcode_t err_code, const char* msg );

#endif /* INC_TRACE_H_ */
