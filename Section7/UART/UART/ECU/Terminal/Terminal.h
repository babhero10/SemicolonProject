/*
 * Terminal.h
 *
 * Created: 8/12/2022 9:25:19 AM
 *  Author: CARNIVAL
 */ 

#include <stdint.h>

#ifndef TERMINAL_H_
#define TERMINAL_H_

void init_terminal();
uint8_t read_terminal();
void send_terminal(uint8_t data);


#endif /* TERMINAL_H_ */