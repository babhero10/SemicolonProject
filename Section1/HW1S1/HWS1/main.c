/*
 * HWS1.c
 *
 * Created: 7/18/2022 11:49:46 PM
 * Author : CARNIVAL
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0xFF;
	unsigned char count = 0;
	
    while (1) 
    {
		PORTB = count;
		count++;
		_delay_ms(100);
	}
}

