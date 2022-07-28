/*
 * MQ2.c
 *
 * Created: 7/28/2022 9:53:07 AM
 * Author : CARNIVAL
 */ 

#include "./ECU/MQ2/MQ2.h"
#include "./ECU/LCD4bit/LCD4bit.h"
#include <util/delay.h>

int main(void)
{
	init_MQ2();
	init_LCD();

    while (1) 
    {
		send_int(read_MQ2());
		_delay_ms(500);
		send_command(0x01);
	}
}

