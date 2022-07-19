/*
 * Led.h
 *
 * Created: 7/17/2022 8:41:15 PM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>

#define LED_PIN PC0 
#define LED_PROT PORTC
#define LED_DDR DDRC

#ifndef LED_H_
#define LED_H_

void Led_init();
void toggle();




#endif /* LED_H_ */