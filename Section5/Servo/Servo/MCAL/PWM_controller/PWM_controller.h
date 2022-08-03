/*
 * PWM_controller.h
 *
 * Created: 7/31/2022 11:25:37 PM
 *  Author: CARNIVAL
 */ 

#include <stdint.h>

#ifndef PWM_CONTROLLER_H_
#define PWM_CONTROLLER_H_

void init_fastPWM(uint16_t top);
void change_PWM(uint16_t OCR);

#endif /* PWM_CONTROLLER_H_ */