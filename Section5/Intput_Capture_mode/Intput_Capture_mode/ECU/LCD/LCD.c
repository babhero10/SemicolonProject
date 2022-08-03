/*
 * LCD.c
 *
 * Created: 7/22/2022 6:09:01 PM
 *  Author: CARNIVAL
 */ 

#include "LCD.h"

void send_command(unsigned char cmd)
{
	SCRIPT_PORT = 0x00;
	CONTROL_PORT &= ~(1 << RS);
	SCRIPT_PORT = cmd;	
	
	CONTROL_PORT |= (1 << EN);
	_delay_ms(1);
	CONTROL_PORT &= ~(1 << EN);
	
	_delay_ms(10);
}

void init_LCD()
{
	SCRIPT_DDR = 0xFF;
	CONTROL_DDR |= (1 << EN) | (1 << RS);
	send_command(0x01);
	send_command(0x38);
	send_command(0x0E);
}

void send_char(char c)
{
	SCRIPT_PORT = 0x00;
	CONTROL_PORT |= (1 << RS);
	SCRIPT_PORT = c;
	
	CONTROL_PORT |= (1 << EN);
	_delay_ms(1);
	CONTROL_PORT &= ~(1 << EN);
	
	_delay_ms(10);
}

void send_string(char s[])
{
	for (int i = 0; i < strlen(s); i++)
	{
		send_char(s[i]);
	}
}

void send_int(int i)
{
	char s[17];
	itoa(i, s, 10);
	send_string(s);
}

void send_float(float n)
{
	// Extract integer part
	char sign = 0;
	if (n < 0) {sign = 1; n *= -1;}
	char ipart = (int)n;
	
	// Extract floating part
	char fpart = (n - (float)ipart) * 100;
	if (sign == 1) send_char('-');
	send_int(ipart);
	if (fpart == 0) return;
	send_char('.');
	send_int(fpart);
}