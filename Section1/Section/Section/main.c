/*
 * Section.c
 *
 * Created: 7/17/2022 8:39:17 PM
 * Author : CARNIVAL
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "C:\Users\CARNIVAL\Desktop\Semicolon project\Section\Section\ECU\Light\Light.h"

int main(void)
{
	Light_init();
	DDRB = DDRC;
    /* Replace with your application code */
    while (1) 
    {
		flicker();
		_delay_ms(500);
		PORTB = PORTC;	
    }
}

