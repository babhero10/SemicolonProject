/*
 * ADC_handler.c
 *
 * Created: 7/28/2022 10:00:33 AM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include "ADC_handler.h"

void init_adc() 
{
	ADCSRA |= 1 << ADPS1 | 1 << ADPS0 | 1 << ADEN;
	ADMUX |= 1 << REFS0;
}

uint16_t read_adc(uint8_t readed_pin) 
{
	ADC_DDR &= ~(1 << readed_pin);
	ADMUX &= 0xF0;
	ADMUX |= (readed_pin & 0x0F);
	ADCSRA |= 1 << ADSC;
	while ((ADCSRA & (1 << ADIF)) == 0);
	uint8_t Alow = ADCL;
	uint16_t Ahigh = ADCH << 8;
	return (Alow + Ahigh);
}