/*
 * CTC_HW.c
 *
 * Created: 8/1/2022 3:37:25 PM
 * Author : CARNIVAL
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include "./MCAL/Timer/Timer.h"

int main(void)
{
	init_CTC_timer();
		
    while (1)
	{
		set_CTC(16);
		CTC_end();
		set_CTC(6);
		CTC_end();	
	}
}

