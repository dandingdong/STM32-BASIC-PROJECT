#ifndef __LED7_H
#define __LED7_H
#include "stm32f1xx_hal.h"

typedef struct
{
	GPIO_TypeDef *port;
	uint16_t pin;
}LED7_GPIO;

typedef enum
{
	LED_ANODE,
	LED_CATHODE
}LED7_type;

typedef struct
{
	LED7_GPIO seg[7];
	LED7_type type;
}LED7;

void LED7_Init(LED7 *myLED7,
							 GPIO_TypeDef *port,
							 uint16_t sega,
							 uint16_t segb,
							 uint16_t segc,
							 uint16_t segd,
							 uint16_t sege,
							 uint16_t segf,
							 uint16_t segg,
							 LED7_type type);
void LED7_print(LED7 *myLED7, uint8_t num);
#endif