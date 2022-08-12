/*
 * UART.h
 *
 * Created: 8/12/2022 9:25:07 AM
 *  Author: CARNIVAL
 */ 

#include <stdint.h>

#ifndef UART_H_
#define UART_H_


void init_UART();
uint8_t read_UART();
void send_UART(uint8_t data);




#endif /* UART_H_ */