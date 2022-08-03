/*
 * Servo.h
 *
 * Created: 7/31/2022 11:26:25 PM
 *  Author: CARNIVAL
 */ 

#include <stdint.h>

#ifndef SERVO_H_
#define SERVO_H_


void init_servo();
void write_servo(uint16_t ADCout);


#endif /* SERVO_H_ */