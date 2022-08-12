/*
 * LCD2x16.c
 *
 * Created: 8/4/2022 1:01:18 PM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "LCD2x16.h"

unsigned char bit8_mode = 0;

/************************************************************************/
/* Basic Functions                                                      */
/************************************************************************/
void init_LCD_8bit() {
	bit8_mode = 1;
	LCD_CONTROL_DRR	|= (1 << EN) | (1 << RS);
	LCD_SCRIPT_DRR = 0xFF;
	
	send_command(0x38);
	send_command(0x01);
	send_command(0x0E);
}

void init_LCD_4bit() {
	bit8_mode = 0;
	LCD_CONTROL_DRR	|= (1 << EN) | (1 << RS);
	LCD_SCRIPT_DRR |= 0xF0;
	
	send_command(0x02);
	send_command(0x28);
	send_command(0x01);
	send_command(0x0E);
}

void save() {
	LCD_CONTROL_PORT |= (1 << EN);
	_delay_us(10);
	LCD_CONTROL_PORT &= ~(1 << EN);
}

void send_command(unsigned char cmd) {
	LCD_CONTROL_PORT &= ~(1 << RS);
	if (bit8_mode) {
		LCD_SCRIPT_PORT = cmd;
		save();
	} else {
		LCD_SCRIPT_PORT &= 0x0F;
		LCD_SCRIPT_PORT |= (cmd & 0xF0);
		save();
		
		LCD_SCRIPT_PORT &= 0x0F;
		LCD_SCRIPT_PORT |= ((cmd << 4) & 0xF0);
		save();
	}
	_delay_ms(10);	
}

void send_letter(char c) {
	LCD_CONTROL_PORT |= (1 << RS);
	if (bit8_mode) {
		LCD_SCRIPT_PORT = c;
		save();
	} else {
		LCD_SCRIPT_PORT &= 0x0F;
		LCD_SCRIPT_PORT |= (c & 0xF0);
		save();
		
		LCD_SCRIPT_PORT &= 0x0F;
		LCD_SCRIPT_PORT |= ((c << 4) & 0xF0);
		save();
	}
	_delay_ms(10);
}

void send_string(char s[]) {
	for (uint8_t i = 0; s[i] != '\0'; i++)
	{
		send_letter(s[i]);
	}
}

void send_int(int num) {
	char s[17];
	itoa(num, s, 10);
	send_string(s);
}

void send_number(double num) {
	// Extract integer part
	char sign = 0;
	if (num < 0) {sign = 1; num *= -1;}
	unsigned int ipart = (int)(num);
	
	// Extract floating part
	unsigned int fpart = (num - ipart) * 100;
	if (sign == 1) send_letter('-');
	send_int(ipart);
	if (fpart == 0) return;
	send_letter('.');
	send_int(fpart);
}

void set_cursor(char x, char y) {
	if (y == 0)
		send_command(0x80 + x);
	else
		send_command(0xC0 + x);
}

/************************************************************************/
/* Shortcut functions                                                   */
/************************************************************************/
void clear_lcd() {
	send_command(0x01);
}

void lcd_cursor(unsigned char mode) {
	switch (mode) {
		case 0:
			send_command(0x0C);
			break;
		case 1:
			send_command(0x0E);
			break;
		case 2:
			send_command(0x0F);
			break;
	}
}

void send_string_at(char s[], char x, char y) {
	set_cursor(x, y);
	send_string(s);
}

void send_letter_at(char c, char x, char y) {
	set_cursor(x, y);
	send_letter(c);
}

void send_int_at(int num, char x, char y) {
	set_cursor(x, y);
	send_int(num);
}

void send_number_at(double num, char x, char y) {
	set_cursor(x, y);
	send_number(num);
}
