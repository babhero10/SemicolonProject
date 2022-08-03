/*
 * Controller.c
 *
 * Created: 7/31/2022 11:26:01 PM
 *  Author: CARNIVAL
 */ 

#include "Controller.h"
#include "./../../MCAL/ADC_controller/ADC_controller.h"

void init_controller()
{
	init_adc();
}

uint16_t read_controller(uint8_t pin)
{
	return read_adc(pin);
}