#include "pwm_io.h"
#include "tim.h"

__IO uint32_t * const CCR[] =
		{
				&(TIM4 -> CCR3),
				&(TIM4 -> CCR4)
		};

void set_pwm_width(uint8_t channel, uint16_t width)
{
	*CCR[channel] = width;
}
