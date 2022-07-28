/*
 * ADC.c
 *
 * Created: 7/24/2022 8:03:25 PM
 *  Author: CARNIVAL
 */ 

#include "ADC.h"

void adc_init()
{
	ADMUX |= 1 << REFS0;
	ADCSRA |= 1 << ADEN | 1 << ADPS2;
	
}

uint16_t adc_read(unsigned char read_pin)
{
	uint16_t ainL;
	uint16_t ainH;
	ADMUX &= 0xF0;
	ADMUX |= 0x0F & (read_pin);
	DDRA &= ~(1 << read_pin);
	
	ADCSRA |= 1 << ADSC;
	while ((ADCSRA & (1 << ADIF)) == 0);
	ainL = ADCL;
	ainH = ADCH << 8;
	return ainH + ainL;
}