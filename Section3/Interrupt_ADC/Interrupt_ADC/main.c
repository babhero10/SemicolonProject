/*
 * Interrupt_ADC.c
 *
 * Created: 7/24/2022 12:07:52 PM
 * Author : CARNIVAL
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	/*DDRC =0xFF;
	DDRD = 0;
	DDRB = 0;
	PORTD |= 1 << INT0 | 1 << INT1 ;
	PORTB |= 1 << INT2;
	
	GICR |= 1 << INT0 | 1 << INT1 | 1 << INT2;
	MCUCR |= 1 << ISC00 | 1 << ISC10 | 1 << ISC11;
	MCUCR &= ~(1<<ISC01);
	MCUCSR |= 1 << ISC2;
	sei();*/
	
	ADMUX |= 1 << ADPS2;
	ADCSRA |= 1 << ADEN;
	uint16_t ainL;
	uint16_t ainH;
	
    while (1) 
    {
		ADCSRA |= | 1 << ADSC
		while (ADCSRA & 1 << ADIF == 0);
		ainL = ADCL;
		ainH = ADCH << 8;
		
    }
}

/*ISR (INT0_vect)
{
	PORTC ^= 1;
}

ISR (INT1_vect)
{
	PORTC ^= 10;
}

ISR (INT2_vect)
{
	PORTC ^= 100;
}*/

