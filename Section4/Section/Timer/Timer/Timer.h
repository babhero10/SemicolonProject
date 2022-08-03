/*
 * Timer.h
 *
 * Created: 7/28/2022 8:18:31 PM
 *  Author: CARNIVAL
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#ifndef TIMER_H_
#define TIMER_H_

void delay_normal_mode(uint8_t val);
void delay_interrupt_normal_mode(uint8_t val);
void TIMER0_CTC_INIT(uint8_t val);


#endif /* TIMER_H_ */