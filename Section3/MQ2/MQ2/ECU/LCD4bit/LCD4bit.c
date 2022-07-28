/*
 * LCD4bit.c
 *
 * Created: 7/28/2022 10:02:30 AM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "LCD4bit.h"

void send_command(uint8_t cmd)
{
	SCRIPT_LCD_PORT &= 0x0F;
	SCRIPT_LCD_PORT |= cmd & 0xF0;
	CONTROL_LCD_PORT &= ~(1 << RS);
	
	CONTROL_LCD_PORT |= 1 << EN;
	_delay_us(1);	
	CONTROL_LCD_PORT &= ~(1 << EN);
	_delay_us(200);
	SCRIPT_LCD_PORT &= 0x0F;
	SCRIPT_LCD_PORT |= ((cmd << 4) & 0xF0);
	
	CONTROL_LCD_PORT |= 1 << EN;
	_delay_us(1);
	CONTROL_LCD_PORT &= ~(1 << EN);
	
	_delay_ms(10);
}

void init_LCD()
{
	SCRIPT_LCD_DDR |= 0xF0;
	CONTROL_LCD_DDR |= (1 << EN) | (1 << RS);
	send_command(0x02);
	send_command(0x28);
	send_command(0x01);
	send_command(0x0C);
	_delay_ms(2);
}

void send_char(unsigned char c)
{
	SCRIPT_LCD_PORT &= 0x0F;
	SCRIPT_LCD_PORT |= c & 0xF0;
	CONTROL_LCD_PORT |= (1 << RS);
	
	CONTROL_LCD_PORT |= 1 << EN;
	_delay_us(1);
	CONTROL_LCD_PORT &= ~(1 << EN);
	
	SCRIPT_LCD_PORT &= 0x0F;
	SCRIPT_LCD_PORT |= ((c << 4) & 0xF0);
	_delay_us(200);
	CONTROL_LCD_PORT |= 1 << EN;
	_delay_us(1);
	CONTROL_LCD_PORT &= ~(1 << EN);
	
	_delay_ms(10);
}

void send_string(char s[])
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		send_char(s[i]);
	}
}

void send_int(int n)
{
	char s[17];
	send_string(itoa(n, s, 10));
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