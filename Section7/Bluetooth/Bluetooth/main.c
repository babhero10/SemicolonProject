/*
 * Bluetooth.c
 *
 * Created: 8/12/2022 10:45:24 PM
 * Author : CARNIVAL
 */ 

#include "./ECU/Bluetooth/Bluetooth.h"
#include "./ECU/LCD/LCD2x16.h"
#include <util/delay.h>

int main(void)
{
	bluetooth_init();
    init_LCD_8bit();
	send_string("hi!");
	char s[34];
    while (1) 
    {
		send_string_at(bluetooth_read_string(s), 0, 1);
    }
}

