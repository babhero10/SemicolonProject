/*
 * Port.c
 *
 * Created: 7/19/2022 11:24:38 AM
 *  Author: CARNIVAL
 */ 

#include "Port.h"

void init_port()
{
	PORTDDR = 0xFF;
	PORTNAME = 0x00;
}

void write_port(unsigned char out)
{
	PORTNAME = out;
}