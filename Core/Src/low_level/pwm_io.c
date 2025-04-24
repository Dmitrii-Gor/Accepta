#include "pwm_io.h"
#include "tim.h"



uint16_t degree_to_width(uint16_t angle, uint16_t min_width, uint16_t max_width, uint16_t max_angle)
{
	 // Переводим угол в значение CCR (значение получается в мкс - ширина импульса pwm)
	uint16_t width = min_width + ((max_width - min_width) * angle) / max_angle;
	return width;
}


void set_pwm_width(uint8_t channel, uint16_t angle, uint16_t min_width, uint16_t max_width, uint16_t max_angle)
{
	uint16_t width = degree_to_width(angle, min_width, max_width, max_angle);
    switch (channel)
    {
        case 0:
            htim4.Instance->CCR3 = width; // для канала 3
            break;
        case 1:
            htim4.Instance->CCR4 = width; // для канала 4
            break;
        default:
            break;
    }
}

void pwm_set_state_with_width(uint8_t channel, bool state_pwm, uint16_t pulse_width) {

	if (!state_pwm) {
		switch (channel) {
			case 0:
				htim3.Instance->CCR3 = 0;
				HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
				break;
			case 1:
				htim3.Instance->CCR4 = 0;
				HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4);
				break;
			default:
				break;
		}

	}
	else {
		switch (channel) {
			case 0:
				HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
				htim3.Instance->CCR3 = pulse_width; // для канала 1
				break;
			case 1:
				HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
				htim3.Instance->CCR4 = pulse_width; // для канала 2
				break;
			default:
				break;
		}
	}

}
