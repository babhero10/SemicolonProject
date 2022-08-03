/*
 * ADC_controller.c
 *
 * Created: 7/31/2022 11:12:45 PM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include "ADC_controller.h"


void init_adc()
{
	ADMUX |= (1 << REFS0);
	ADCSRA |= (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN);
}

uint16_t read_adc(uint8_t pin)
{
	DDRA &= ~(1 << pin);
	
	ADMUX &= 0xF0;
	ADMUX |= (pin & 0x0F);
	
	ADCSRA |= (1 << ADSC);
	
	while ((ADCSRA & (1 << ADIF)) == 0);
	
	uint8_t AinL = ADCL;
	uint16_t AinH = ADCH << 8;
	return AinL + AinH;
}

