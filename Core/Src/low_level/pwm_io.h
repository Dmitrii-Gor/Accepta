#ifndef SRC_LOW_LEVEL_PWM_IO_H_
#define SRC_LOW_LEVEL_PWM_IO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

void set_pwm_width(uint8_t channel, uint16_t width);

#ifdef __cplusplus
}
#endif

#endif /* SRC_LOW_LEVEL_PWM_IO_H_ */
