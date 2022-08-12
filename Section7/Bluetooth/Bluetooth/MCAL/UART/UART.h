/*
 * UART.h
 *
 * Created: 8/12/2022 10:48:15 PM
 *  Author: CARNIVAL
 */ 

#include <stdint.h>

#ifndef UART_H_
#define UART_H_


void UART_init();

uint8_t UART_read_char();
char* UART_read_string(char s[]);

void UART_send_char(unsigned char c);
void UART_send_string(char s[]);



#endif /* UART_H_ */