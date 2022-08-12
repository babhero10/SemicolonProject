/*
 * Bluetooth.h
 *
 * Created: 8/12/2022 10:47:42 PM
 *  Author: CARNIVAL
 */ 

#include <stdint.h>

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

void bluetooth_init();

uint8_t bluetooth_read_char();
char* bluetooth_read_string(char s[]);

void bluetooth_send_char(unsigned char c);
void bluetooth_send_string(char s[]);


#endif /* BLUETOOTH_H_ */