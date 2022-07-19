/*
 * LCD.h
 *
 * Created: 7/19/2022 8:49:01 PM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <string.h>

#ifndef LCD_H_
#define LCD_H_

#define LCD_DRR DDRD
#define LCD_PORT PORTD

#define RS PD0
#define EN PD1

void LCD_init();
void LCD_cmd(unsigned char command);
void LCD_sendLetter(unsigned char character);
void LCD_sendString(const char* str);



#endif /* LCD_H_ */