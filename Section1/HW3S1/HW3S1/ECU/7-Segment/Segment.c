/*
 * _7Segment.c
 *
 * Created: 7/19/2022 4:26:31 PM
 *  Author: CARNIVAL
 */ 

#include "./../../MCAL/PortController/PortController.h"
#include "Segment.h"

const bool segment_table[10][7] = {{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{0,1,1,1,1,0,1},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1},};

void init_segment()
{
	init_port();
}

void write_number(uint8_t num)
{
	uint8_t digit1 = num % 10;
	num /= 10; 
	uint8_t digit2 = num % 10;
	
	write_port1(segment_table[digit1]);
	write_port2(segment_table[digit2]);
}
