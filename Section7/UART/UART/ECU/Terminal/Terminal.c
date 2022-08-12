/*
 * Terminal.c
 *
 * Created: 8/12/2022 9:25:26 AM
 *  Author: CARNIVAL
 */ 

#include "Terminal.h"
#include "./../../MCAL/UART/UART.h"

void init_terminal() {
	init_UART();	
}

uint8_t read_terminal() {
	return read_UART();	
}

void send_terminal(uint8_t data) {
	send_UART(data);
}