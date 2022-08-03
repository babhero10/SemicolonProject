/*
 * Servo.c
 *
 * Created: 7/31/2022 11:26:11 PM
 *  Author: CARNIVAL
 */ 


#include "Servo.h"
#include "./../../MCAL/PWM_controller/PWM_controller.h"

void init_servo()
{
	init_fastPWM(20000);
}

void write_servo(uint16_t ADCout)
{
	uint16_t new_ocr = 500 + (2000)*((ADCout)/(1023.0));
	change_PWM(new_ocr);
}