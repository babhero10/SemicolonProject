/*
 * Timer.c
 *
 * Created: 7/28/2022 8:16:25 PM
 * Author : CARNIVAL
 */ 

#include <avr/io.h>
#include "./Timer.h"

int main(void)
{
	DDRB |= 1 << PB3;
    TIMER0_CTC_INIT(210);
	while (1) 
    {
		
    }
}

