/*
 * MQ2.c
 *
 * Created: 7/28/2022 10:02:14 AM
 *  Author: CARNIVAL
 */ 

#include "MQ2.h"
#include "./../../MCAL/ADC_handler/ADC_handler.h"

void init_MQ2()
{
	init_adc();
}

uint16_t read_MQ2()
{
	return read_adc(MQ2_PIN);
}