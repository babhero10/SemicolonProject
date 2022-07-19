/*
 * LCD.c
 *
 * Created: 7/19/2022 8:34:33 PM
 * Author : CARNIVAL
 */ 

#include <avr/io.h>

#define F_CPU 1000000UL
#include "./ECU/LCD/LCD.h"

int main(void)
{
    LCD_init();
	while (1) 
    {
	LCD_sendLetter(89);
	
	
    }
}

