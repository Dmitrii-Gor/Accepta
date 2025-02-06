#include "digital_pin_io.h"
#include "gpio.h"
#include <stdbool.h>

typedef struct
{
	GPIO_TypeDef * GPIOx;
	uint16_t GPIO_Pin;
} pin_t;

#define PINTABLE_SIZE (size_t)16

pin_t outpintable[PINTABLE_SIZE] =
{
		{	DO0_GPIO_Port,	DO0_Pin 	},	//  0
		{	DO1_GPIO_Port,	DO1_Pin		},	//  1
		{	DO2_GPIO_Port, 	DO2_Pin		},	//  2
		{	DO3_GPIO_Port,	DO3_Pin		},	//  3
		{	DO4_GPIO_Port,	DO4_Pin		},	//  4
		{	DO5_GPIO_Port,	DO5_Pin		},	//  5
		{	DO6_GPIO_Port, 	DO6_Pin		},	//  6
		{	DO7_GPIO_Port,	DO7_Pin		},	//  7
		{	DO8_GPIO_Port, 	DO8_Pin		},	//  8
		{	DO9_GPIO_Port,	DO9_Pin		},	//  9
		{	DO10_GPIO_Port,	DO10_Pin	},	// 10
		{	DO11_GPIO_Port, DO11_Pin	},	// 11
		{	DO12_GPIO_Port,	DO12_Pin	},	// 12
		{	DO13_GPIO_Port,	DO13_Pin	},	// 13
		{	DO14_GPIO_Port, DO14_Pin	},	// 14
		{	DO15_GPIO_Port,	DO15_Pin	}	// 15
};

pin_t inpintable[PINTABLE_SIZE] =
{
		{	DI0_GPIO_Port,	DI0_Pin 	},	//  0
		{	DI1_GPIO_Port,	DI1_Pin		},	//  1
		{	DI2_GPIO_Port, 	DI2_Pin		},	//  2
		{	DI3_GPIO_Port,	DI3_Pin		},	//  3
		{	DI4_GPIO_Port,	DI4_Pin		},	//  4
		{	DI5_GPIO_Port,	DI5_Pin		},	//  5
		{	DI6_GPIO_Port, 	DI6_Pin		},	//  6
		{	DI7_GPIO_Port,	DI7_Pin		},	//  7
		{	DI8_GPIO_Port, 	DI8_Pin		},	//  8
		{	DI9_GPIO_Port,	DI9_Pin		},	//  9
		{	DI10_GPIO_Port,	DI10_Pin	},	// 10
		{	DI11_GPIO_Port, DI11_Pin	},	// 11
		{	DI12_GPIO_Port,	DI12_Pin	},	// 12
		{	DI13_GPIO_Port,	DI13_Pin	},	// 13
		{	DI14_GPIO_Port, DI14_Pin	},	// 14
		{	DI15_GPIO_Port,	DI15_Pin	}	// 15
};

void set_digital_pin(uint8_t channel, bool isOn)
{
	HAL_GPIO_WritePin(outpintable[channel].GPIOx, outpintable[channel].GPIO_Pin, isOn ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

bool get_digital_pin(uint8_t channel)
{
	return (HAL_GPIO_ReadPin(inpintable[channel].GPIOx, inpintable[channel].GPIO_Pin) == GPIO_PIN_SET);
}
