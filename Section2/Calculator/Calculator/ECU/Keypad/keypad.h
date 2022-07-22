/*
 * keypad.h
 *
 * Created: 7/22/2022 6:09:40 PM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KEYPAD_DDR  DDRD
#define KEYPAD_PORT PORTD
#define KEYPAD_PIN  PIND

void init_keypad();
unsigned char read_input();




#endif /* KEYPAD_H_ */