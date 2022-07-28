/*
 * LM35.c
 *
 * Created: 7/24/2022 8:07:51 PM
 *  Author: CARNIVAL
 */ 

#include "LM35.h"
#include "./../../MCAL/ADC/ADC.h"

void init_lm35()
{
	adc_init();
}

uint16_t read_lm35()
{
	return adc_read(READ_PIN) * 4.88 / 10;
}