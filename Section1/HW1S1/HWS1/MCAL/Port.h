/*
 * Port.h
 *
 * Created: 7/19/2022 11:23:10 AM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>

#ifndef PORT_H_
#define PORT_H_

#define PORTDDR  DDRB
#define PORTNAME PORTB

void init_port();
void write_port(unsigned char out);


#endif /* PORT_H_ */