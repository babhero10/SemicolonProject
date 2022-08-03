
/*
 * Timer.c
 *
 * Created: 7/28/2022 8:17:56 PM
 *  Author: CARNIVAL
 */ 

#include "./Timer.h"

ISR(TIMER0_OVF_vect) 
{
    PORTB ^= (1 << PB3);
	TIFR |= (1 << TOV0);
}

ISR(TIMER0_COMP_vect)
{
	PORTB ^= (1 << PB3);
}

void delay_normal_mode(uint8_t val)
{
	TCNT0 = val;
	TCCR0 = 0x05;
	while ((TIFR & (1 << TOV0)) == 0);
	TCCR0 = 0;
	TIFR |= (1 << TOV0);
}

void delay_interrupt_normal_mode(uint8_t val)
{
	TCNT0 = val;
	TCCR0 = 0x05;
	TIMSK |= 1 << TOIE0;
	sei();
}

void TIMER0_CTC_INIT(uint8_t val)
{
	TCCR0 = 0x1D;
	OCR0 = val;
	TIMSK = 1 << OCIE0;
	sei();
}


