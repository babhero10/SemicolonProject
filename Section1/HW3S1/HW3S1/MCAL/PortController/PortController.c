/*
 * PortController.c
 *
 * Created: 7/19/2022 3:47:06 PM
 *  Author: CARNIVAL
 */ 

#include "PortController.h"

void init_port()
{
	DDR_DIGIT1 = 0x7F;
	DDR_DIGIT2 = 0x7F;	
	PORT_DIGIT1 = 0b11111110;
	PORT_DIGIT2 = 0b11111110;	
}

void write_port1(const bool pins[7])
{
	for (uint8_t i = 0; i < 7; i++)
	{
		if (pins[i])
		{
			PORT_DIGIT1 |= (1 << i);
		}
		else
		{
			PORT_DIGIT1 &= ~(1 << i);
		}
	}
}

void write_port2(const bool pins[7])
{
	for (uint8_t i = 0; i < 7; i++)
	{
		if (pins[i])
		{
			PORT_DIGIT2 |= (1 << i);
		}
		else
		{
			PORT_DIGIT2 &= ~(1 << i);
		}
	}
}

