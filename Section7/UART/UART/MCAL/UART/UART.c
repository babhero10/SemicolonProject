/*
 * UART.c
 *
 * Created: 8/12/2022 9:24:59 AM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include "UART.h"

void init_UART() {
	DDRD &= ~(1 << 0);
	DDRD |= 1 << 1;
	
	UCSRA |= (1 << U2X);
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	UBRRL = 12;
	UBRRH = 0;
}

uint8_t read_UART() {
	while ((UCSRA & (1 << RXC)) == 0);
	return UDR;	
}

void send_UART(uint8_t data) {
	while ((UCSRA & (1 << UDRE)) == 0);
	UDR = data;
}