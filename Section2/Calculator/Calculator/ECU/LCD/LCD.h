/*
 * LCD.h
 *
 * Created: 7/22/2022 6:08:48 PM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>

#ifndef LCD_H_
#define LCD_H_

#define SCRIPT_DDR  DDRC
#define CONTROL_DDR DDRB

#define SCRIPT_PORT  PORTC
#define CONTROL_PORT PORTB

#define EN PB1
#define RS PB0

void send_command(unsigned char cmd);
void init_LCD();
void send_char(char c);
void send_string(char s[]);
void send_int(int i);

#endif /* LCD_H_ */