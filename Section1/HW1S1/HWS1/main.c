/*
 * HW1S1.c
 *
 * Created: 7/18/2022 11:49:46 PM
 * Author : CARNIVAL
 */ 

#define F_CPU 1000000UL
#include "./ECU/Counter.h"

int main(void)
{
    init_counter();
	
    while (1) 
    {
		count();
	}
}

