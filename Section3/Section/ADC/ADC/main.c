/*
 * Interrupt_ADC.c
 *
 * Created: 7/24/2022 12:07:52 PM
 * Author : CARNIVAL
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include "./ECU/LM35/LM35.h"
#include "./ECU/LCD/LCD.h"

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
	init_lm35();
	init_LCD();
	
    while (1) 
    {
		send_float(read_lm35());
		_delay_ms(100);
		send_command(0x01);
		
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

