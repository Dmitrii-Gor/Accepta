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
            htim4.Instance->CCR3 = width; // Пример для CCR3
            break;
        case 1:
            htim4.Instance->CCR4 = width; // Пример для CCR4
            break;
        default:
            break;
    }
}
