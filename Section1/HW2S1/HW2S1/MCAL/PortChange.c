/*
 * PortChange.c
 *
 * Created: 7/19/2022 1:08:09 PM
 *  Author: CARNIVAL
 */ 

#include "PortChange.h"

void init_port()
{
	DDR_USED &= ~(1 << INPUT_PIN);
}

void change_DDR(uint8_t pin, bool state)
{
	if (state)
	{
		DDR_USED |= (1 << CHANGED_PIN);
	}
	else
	{
		DDR_USED &= ~(1 << CHANGED_PIN);
	}
}

bool read_pin(uint8_t pin)
{
	return (PIN_USED & (1 << INPUT_PIN));
}