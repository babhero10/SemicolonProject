/*
 * HW2S1.c
 *
 * Created: 7/18/2022 11:58:54 PM
 * Author : CARNIVAL
 */ 

#include <avr/io.h>
#include "./ECU/PortChanger.h"

int main(void)
{
	init_port_changer();
	
    while (1) 
    {
		change_DDR_depends();
	
	}
}

