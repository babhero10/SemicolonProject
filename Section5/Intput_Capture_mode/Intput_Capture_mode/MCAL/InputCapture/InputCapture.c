/*
 * InputCapture.c
 *
 * Created: 8/4/2022 12:17:14 AM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include "InputCapture.h"

void init_input_capture() 
{	
	DDRB |= 1;
	DDRD &= ~(1 << PD6);
	PORTD |= 1 << PD6;
	TCCR1B |= 1 << CS10 | 1 << CS12;
	
}

double read_on_time() 
{
	int overflow = 0;
	TCNT1 = 0;
	int t1, t2;
	TCCR1B &= ~(1 << ICES1);
	while ((TIFR & (1 << ICF1)) == 0)
	{
		if ((TIFR & (1 << TOV1)) == 1)
		{
			overflow++;
			TIFR |= 1 << TOV1;
		}
	}
	PORTB |= 1;
	TIFR |= 1 << ICF1;
	t1 = ICR1 + overflow * 0xFFFF;
	TCCR1B |= (1 << ICES1);
	
	while ((TIFR & (1 << ICF1)) == 0)
	{
		if ((TIFR & (1 << TOV1)) == 1)
		{
			overflow++;
			TIFR |= 1 << TOV1;
		}
	}
	TIFR |= 1 << ICF1;
	TIFR |= 1 << TOV1;
	PORTB &= 0xFE;
	t2 = ICR1 + overflow * 0xFFFF;
	return ((t2 - t1) * 0.001024);
}