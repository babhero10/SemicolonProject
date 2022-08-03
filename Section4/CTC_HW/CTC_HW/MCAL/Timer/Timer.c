/*
 * Timer.c
 *
 * Created: 8/1/2022 4:15:30 PM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include "Timer.h"

void init_CTC_timer()
{
	DDRB |= (1<<PB3);
	TCCR0 |= 1 << CS01 | 1 << WGM01 | 1 << COM00;
}

void set_CTC(uint8_t OC)
{
	OCR0 = OC;
}

void CTC_end()
{
	while ((TIFR & (1 << OCF0)) == 0);
	TIFR |= 1 << OCF0;
}