/*
 * HW3S1.c
 *
 * Created: 7/19/2022 3:31:47 PM
 * Author : CARNIVAL
 */ 

#include "./ECU/7-Segment/Segment.h"
#include "./ECU/AddNumers/AddNumbers.h"
#include <avr/io.h>
int main(void)
{
	init_segment();
	init_adder();
	
    while (1) 
    {
		write_number(add_numbers());
	}
}

