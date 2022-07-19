/*
 * LCD.c
 *
 * Created: 7/19/2022 8:34:33 PM
 * Author : CARNIVAL
 */ 

#include <avr/io.h>

#include "./ECU/LCD/LCD.h"

int main(void)
{
    LCD_init();
	_delay_ms(200);
	while (1) 
    {
	LCD_sendLetter('a');
	
    }
}

