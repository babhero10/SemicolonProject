/*
 * UART.c
 *
 * Created: 8/12/2022 10:48:08 PM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include <string.h>
#include "UART.h"

void UART_init() {
	DDRD &= ~(1 << PD0);
	DDRD |= (1 << PD1);
	
	UCSRA |= (1 << U2X);
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	
	// Band rate 9600
	UBRRL = 12;
	UBRRH = 0;
}

uint8_t UART_read_char() {
	while ((UCSRA & (1 << RXC)) == 0);
	
	return UDR;
		
}

char* UART_read_string(char s[]) {
	uint8_t i = 0;
	char c;
	strcpy(s, "                ");
	while (1)
	{
		c = UART_read_char();
		if (c == '\r' || c == '\n' || c == '\0') break;
		s[i++] = c;
	}
	
	s[i] = ' ';
	
	return s;
}

void UART_send_char(unsigned char c) {
	while ((UCSRA & (1 << UDRE)) == 0);
	
	UDR = c;
}

void UART_send_string(char s[]) {
	for (uint8_t i = 0; s[i] != '\0'; i++)
	{
		UART_send_char(s[i]);
	}
}
