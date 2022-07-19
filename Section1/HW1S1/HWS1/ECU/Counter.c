/*
 * Counter.c
 *
 * Created: 7/19/2022 12:36:46 PM
 *  Author: CARNIVAL
 */ 
#include "Counter.h"
#include "./../MCAL/Port.h"

void init_counter()
{
	init_port();
}

void count()
{
	unsigned char c = 1;
	
	while (c)
	{
		write_port(c);
		_delay_ms(100);
		c++;
	}
}