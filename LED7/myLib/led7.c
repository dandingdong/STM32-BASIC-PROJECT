#include "led7.h"
const static uint8_t segment_code[10] =
{
	0x3F,
	0x06,
	0x5B,
	0x4F,
	0x66,
	0x6D,
	0x7D,
	0x07,
	0x7F,
	0x6F
};
void LED7_Init(LED7 *myLED7,
							 GPIO_TypeDef *port,
							 uint16_t sega,
							 uint16_t segb,
							 uint16_t segc,
							 uint16_t segd,
							 uint16_t sege,
							 uint16_t segf,
							 uint16_t segg,
							 LED7_type type)
{	
	myLED7->seg[0].port = port;
	myLED7->seg[1].port = port;
	myLED7->seg[2].port = port;
	myLED7->seg[3].port = port;
	myLED7->seg[4].port = port;
	myLED7->seg[5].port = port;
	myLED7->seg[6].port = port;
	myLED7->seg[0].pin = sega;
	myLED7->seg[1].pin = segb;
	myLED7->seg[2].pin = segc;
	myLED7->seg[3].pin = segd;
	myLED7->seg[4].pin = sege;
	myLED7->seg[5].pin = segf;
	myLED7->seg[6].pin = segg;
	myLED7->type = type;
}
void LED7_print(LED7 *myLED7, uint8_t num)
{	
	if(num > 9)	return;
	uint8_t seg_code = segment_code[num];
	if(myLED7->type == LED_ANODE)
	{
		 for(int i = 0; i < 7; i++)
				HAL_GPIO_WritePin(myLED7->seg[i].port, myLED7->seg[i].pin, (seg_code >> i) & 0x01 ? 0 : 1);
	}
	else if(myLED7->type == LED_CATHODE)
	{
		for(int i = 0; i < 7; i++)
				HAL_GPIO_WritePin(myLED7->seg[i].port, myLED7->seg[i].pin, (seg_code >> i) & 0X01 ? 1 : 0);
	}
}