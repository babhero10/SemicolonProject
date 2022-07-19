/*
 * AddNumbers.c
 *
 * Created: 7/19/2022 3:42:14 PM
 *  Author: CARNIVAL
 */ 

#include "./../../MCAL/GetNumber/GetNumbers.h"
#include "AddNumbers.h"

void init_adder()
{
	init_numbers();
}

uint8_t add_numbers()
{
	return (get_number1() + get_number2()) & 0b00011111;
}