/*
 * LM35.h
 *
 * Created: 7/24/2022 8:08:04 PM
 *  Author: CARNIVAL
 */ 

#include <stdint.h>

#ifndef LM35_H_
#define LM35_H_

#define READ_PIN 1

void init_lm35();
uint16_t read_lm35();



#endif /* LM35_H_ */