/*
 * PortChange.h
 *
 * Created: 7/19/2022 1:07:47 PM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef PORTCHANGE_H_
#define PORTCHANGE_H_

#define DDR_USED  DDRB
#define PIN_USED  PINB

#define INPUT_PIN   7
#define CHANGED_PIN 4

void init_port();

void change_DDR(uint8_t pin, bool state);

bool read_pin(uint8_t pin);

#endif /* PORTCHANGE_H_ */