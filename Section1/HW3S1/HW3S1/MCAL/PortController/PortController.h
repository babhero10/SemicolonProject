/*
 * PortController.h
 *
 * Created: 7/19/2022 3:46:54 PM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef PORTCONTROLLER_H_
#define PORTCONTROLLER_H_

#define DDR_DIGIT1 DDRD
#define DDR_DIGIT2 DDRC

#define PORT_DIGIT1 PORTD
#define PORT_DIGIT2 PORTC


void init_port();

void write_port1(const bool pins[7]);
void write_port2(const bool pins[7]);



#endif /* PORTCONTROLLER_H_ */