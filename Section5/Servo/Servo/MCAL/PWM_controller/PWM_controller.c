/*
 * PWM_controller.c
 *
 * Created: 7/31/2022 11:25:30 PM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include "PWM_controller.h"

void init_fastPWM(uint16_t top)
{
	DDRD |= (1 << PD5);
	TCNT1 = 0;
	ICR1 = top;
	TCCR1A |= (1 << COM1A1) | (1 << WGM11);
	TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS10);
}

void change_PWM(uint16_t OCR)
{
	OCR1A = OCR;
}