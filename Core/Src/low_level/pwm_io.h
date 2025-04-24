#ifndef SRC_LOW_LEVEL_PWM_IO_H_
#define SRC_LOW_LEVEL_PWM_IO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

void set_pwm_width(uint8_t channel, uint16_t angle, uint16_t min_width, uint16_t max_width, uint16_t max_angle);
uint16_t degree_to_width(uint16_t angle, uint16_t min_width, uint16_t max_width, uint16_t max_angle);
void pwm_set_state_with_width(uint8_t channel, bool state_pwm, uint16_t pulse_width);

#ifdef __cplusplus
}
#endif

#endif /* SRC_LOW_LEVEL_PWM_IO_H_ */
