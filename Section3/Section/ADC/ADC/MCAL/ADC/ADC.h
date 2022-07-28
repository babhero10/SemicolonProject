/*
 * ADC.h
 *
 * Created: 7/24/2022 8:03:17 PM
 *  Author: CARNIVAL
 */ 

#include <avr/io.h>
#include <stdint.h>

#ifndef ADC_H_
#define ADC_H_

void adc_init();
uint16_t adc_read(unsigned char read_pin);



#endif /* ADC_H_ */