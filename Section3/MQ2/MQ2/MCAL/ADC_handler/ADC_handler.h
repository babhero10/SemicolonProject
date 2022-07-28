/*
 * ADC_handler.h
 *
 * Created: 7/28/2022 10:00:41 AM
 *  Author: CARNIVAL
 */ 

#include <stdint.h>

#ifndef ADC_HANDLER_H_
#define ADC_HANDLER_H_

#define ADC_DDR DDRA

void init_adc();
uint16_t read_adc(uint8_t readed_pin);



#endif /* ADC_HANDLER_H_ */