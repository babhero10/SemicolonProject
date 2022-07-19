/*
 * Led.c
 *
 * Created: 7/17/2022 8:41:38 PM
 *  Author: CARNIVAL
 */ 

#include "Led.h"

void Led_init()
{
	LED_DDR |= (1 << LED_PIN);
}

void toggle()
{
	LED_PROT ^= (1 << LED_PIN);
}