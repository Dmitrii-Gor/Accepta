#ifndef SRC_LOW_LEVEL_DIGITAL_PIN_IO_H_
#define SRC_LOW_LEVEL_DIGITAL_PIN_IO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

void set_digital_pin(uint8_t channel, bool isOn);
bool get_digital_pin(uint8_t channel);

#ifdef __cplusplus
}
#endif

#endif /* SRC_LOW_LEVEL_DIGITAL_PIN_IO_H_ */
