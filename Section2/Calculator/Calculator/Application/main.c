/*
 * Calculator.c
 *
 * Created: 7/22/2022 5:29:16 PM
 * Author : CARNIVAL
 */ 

#define F_CPU 1000000UL

#include "./../ECU/Keypad/keypad.h"
#include "./../ECU/LCD/LCD.h"
#include "./Calculator/calculator.h"

int main(void)
{
    init_LCD();
	init_keypad();
	
	char a, b, o;
		
    while (1) 
    {
		while (1)
		{
		
			a = read_input() - '0';
			send_int(a);
			
			o = read_input();
			if (o == 'C') {
				send_command(0x01);
				continue;
			}
			
			send_char(o);
			
			b = read_input() - '0';
			
			if (b + '0' == 'C'){
				send_command(0x01);
				continue;
			}
			
			send_int(b);
			
			send_char('=');
			send_float(calc(a, b, o));
			read_input();		
			send_command(0x01);	
		}
	}
}

