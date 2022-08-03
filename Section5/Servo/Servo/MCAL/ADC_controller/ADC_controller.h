/*
 * ADC_controller.h
 *
 * Created: 7/31/2022 11:13:00 PM
 *  Author: CARNIVAL
 */ 

#include <stdint.h>

#ifndef ADC_CONTROLLER_H_
#define ADC_CONTROLLER_H_

void init_adc();
uint16_t read_adc(uint8_t pin);



#endif /* ADC_CONTROLLER_H_ */