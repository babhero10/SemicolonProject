/*
 * LCD.c
 *
 * Created: 7/19/2022 8:48:41 PM
 *  Author: CARNIVAL
 */ 

#include "LCD.h"

void LCD_cmd(unsigned char command)
{
	LCD_PORT &= ~(1 << RS); // Command mode
	
	// Send most significant bits
	LCD_PORT |= (LCD_PORT & 0x0F) | (command & 0xF0); // Clear last commands
	
	// Send pulse Note: (Works in fall edge)
	LCD_PORT |= (1 << EN);
	_delay_ms(1);
	LCD_PORT &= ~(1 << EN);
	
	_delay_ms(10);
	
	// Send least significant bits
	LCD_PORT |= (LCD_PORT & 0x0F) | ((command << 4) & 0xF0); // Clear last commands
	
	// Send pulse Note: (Works in fall edge)
	LCD_PORT |= (1 << EN);
	_delay_ms(1);
	LCD_PORT &= ~(1 << EN);
	
	_delay_ms(10);
}

void LCD_init()
{
	LCD_DRR = 0xFF;
	
	LCD_cmd(0x02); /* 4 bit mode initialization of LCD */
	LCD_cmd(0x28); /* 4 bit mode */
	LCD_cmd(0x0c); /* Display on cursor off */
	LCD_cmd(0x06); /* Increment cursor by one */
	LCD_cmd(0x01); /* Clear screen */
}

void LCD_sendLetter(unsigned char character)
{
		LCD_PORT |= (1 << RS); // Data Resgistor mode
		
		// Send most significant bits
		LCD_PORT |= (LCD_PORT & 0x0F) | (character & 0xF0); // Clear last character
		
		// Send pulse Note: (Works in fall edge)
		LCD_PORT |= (1 << EN);
		_delay_ms(1);
		LCD_PORT &= ~(1 << EN);
		
		_delay_ms(10);
		
		// Send least significant bits
		LCD_PORT |= (LCD_PORT & 0x0F) | ((character << 4) & 0xF0); // Clear last character
		
		// Send pulse Note: (Works in fall edge)
		LCD_PORT |= (1 << EN);
		_delay_ms(1);
		LCD_PORT &= ~(1 << EN);
		
		_delay_ms(10);	
}

void LCD_sendString(const char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		LCD_sendLetter(str[i]);
	}
}
