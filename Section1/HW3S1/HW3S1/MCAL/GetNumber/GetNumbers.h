/*
 * GetNumbers.h
 *
 * Created: 7/19/2022 3:34:22 PM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>

#ifndef GETNUMBERS_H_
#define GETNUMBERS_H_

#define NUMBERS_DDR  DDRA
#define NUMBERS_PORT PORTA
#define NUMBERS_PIN  PINA

void init_numbers();

uint8_t get_number1();
uint8_t get_number2();


#endif /* GETNUMBERS_H_ */