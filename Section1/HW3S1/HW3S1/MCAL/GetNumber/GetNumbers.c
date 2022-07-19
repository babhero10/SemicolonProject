/*
 * GetNumbers.c
 *
 * Created: 7/19/2022 3:34:03 PM
 *  Author: CARNIVAL
 */ 

#include "GetNumbers.h"

void init_numbers()
{
	NUMBERS_DDR = 0x00;
	NUMBERS_PORT = 0xFF; // Pull resistors on
}

uint8_t get_number1()
{
	return ~(NUMBERS_PIN & 0x0F);
}

uint8_t get_number2()
{
	return ~((NUMBERS_PIN >> 4) & 0x0F);
}