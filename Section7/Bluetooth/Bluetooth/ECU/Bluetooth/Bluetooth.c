/*
 * Bluetooth.c
 *
 * Created: 8/12/2022 10:47:34 PM
 *  Author: CARNIVAL
 */ 

#include "Bluetooth.h"
#include "./../../MCAL/UART/UART.h"

void bluetooth_init() {
	UART_init();
}

uint8_t bluetooth_read_char() {
	return UART_read_char();	
}

char* bluetooth_read_string(char s[]) {
	return UART_read_string(s);
}

void bluetooth_send_char(unsigned char c) {
	UART_send_char(c);	
}

void bluetooth_send_string(char s[]) {
	UART_send_string(s);
}
