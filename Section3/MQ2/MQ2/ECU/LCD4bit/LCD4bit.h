/*
 * LCD4bit.h
 *
 * Created: 7/28/2022 10:02:38 AM
 *  Author: CARNIVAL
 */ 

#include <stdint.h>


#ifndef LCD4BIT_H_
#define LCD4BIT_H_

#define SCRIPT_LCD_DDR DDRD
#define CONTROL_LCD_DDR DDRD

#define SCRIPT_LCD_PORT PORTD
#define CONTROL_LCD_PORT PORTD

#define EN PD0
#define RS PD1

void send_command(uint8_t cmd);
void init_LCD();
void send_char(unsigned char c);
void send_string(char s[]);
void send_int(int n);
void send_float(float n);



#endif /* LCD4BIT_H_ */