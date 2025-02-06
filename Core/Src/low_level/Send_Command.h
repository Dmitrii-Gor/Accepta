#ifndef SRC_LOW_LEVEL_SEND_COMMAND_H_
#define SRC_LOW_LEVEL_SEND_COMMAND_H_

#ifdef __cplusplus
extern "C" {
#endif


void send_command_to_device(const char* str);
void open_terminal_linux();
void close_terminal_linux();

#ifdef __cplusplus
}
#endif

#endif /* SRC_LOW_LEVEL_SEND_COMMAND_H_ */
