/*
 * LCD2x16.h
 *
 * Created: 8/4/2022 1:01:25 PM
 *  Author: CARNIVAL
 */ 

#include <stdint.h>

#ifndef LCD2X16_H_
#define LCD2X16_H_

#define LCD_CONTROL_DRR DDRD
#define LCD_CONTROL_PORT PORTD

#define LCD_SCRIPT_DRR DDRC
#define LCD_SCRIPT_PORT PORTC

#define EN 2
#define RS 3

#define LCD_CURSOR_OFF 0
#define LCD_CURSOR_ON 1
#define LCD_CURSOR_BLINK 2

/************************************************************************/
/* Basic Functions                                                      */
/************************************************************************/
void init_LCD_8bit();
void init_LCD_4bit();

void send_command(unsigned char cmd);
void send_letter(char c);
void send_string(char s[]);
void send_int(int num);
void send_number(double num);
void set_cursor(char x, char y);

/************************************************************************/
/* Shortcut functions                                                   */
/************************************************************************/
void clear_lcd();
void lcd_cursor(unsigned char mode);

void send_string_at(char s[], char x, char y);
void send_letter_at(char c, char x, char y);
void send_int_at(int num, char x, char y);
void send_number_at(double num, char x, char y);

#endif /* LCD2X16_H_ */